#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <gst/gst.h>
#include <gst/app/gstappsink.h>

#include "Barcode.h"

/* Structure to contain all our information, so we can pass it to callbacks */
typedef struct _CustomData
{

    GstElement *pipeline;
    // GstElement *video_source;
    // GstElement *filter;
    // GstElement *converter;
    // GstElement *sink;

    int width;
    int height;

    char *barcode_image;

    gboolean is_valid_barcode;

    // GMainLoop *main_loop;  /* GLib's Main Loop */

} CustomData;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int createGStreamerCameraPipeline(CustomData **data);

int createGStreamerQuickTimeFilePipeline(CustomData **data);

int createGStreamerMP4FilePipeline(CustomData **data);

static GstFlowReturn new_sample(GstElement *sink, CustomData *data);

void parse_message(GstMessage *message);

int main(int argc, char **argv)
{

    // gst-launch-1.0 tcambin num-buffers=1 !
    // video/x-raw,width=1920,height=1080,framerate=5/1 !
    // videoconvert !
    // jpegenc !
    // filesink location=capture.jpg

    // gst-launch-1.0 tcambin |
    // videoconvert |
    // autovideosink

    // gst-launch-1.0 tcambin !
    // video/x-raw,width=1920,height=1080,framerate=5/1 !
    // videoconvert !
    // autovideosink

    // gst-launch-1.0 tcamsrc num-buffers=1 !
    // video/x-raw,format=GRAY8,framerate=5/1,width=1920,height=1080 !
    // queue !  // TODO:  Is this required?
    // videoconvert !
    // pngenc !
    // multifilesink location="frame%d.png"

    // gst-launch-1.0 tcamsrc !
    // video/x-raw,format=GRAY8,width=640,height=480,framerate=5/1 !
    // autovideoconvert !
    // autovideosink


    // Inialize barcode decoder.

    CustomData *data;

    /* Initialize GStreamer */
    gst_init(&argc, &argv);

    /* Initialize custom data structure */

    int response = init();

    /* Build the pipeline */
    createGStreamerCameraPipeline(&data);
    // createGStreamerMP4FilePipeline(&data);

    /* Start playing */
    GstStateChangeReturn ret = gst_element_set_state(data->pipeline, GST_STATE_PLAYING);
    if (ret == GST_STATE_CHANGE_FAILURE)
    {
        g_printerr("Unable to set the pipeline to the playing state.\n");
        gst_object_unref(data->pipeline);
        return -1;
    }

    /* Wait for 1 second, an end of stream or an error. */
    GstBus *bus = gst_element_get_bus(data->pipeline);

    // GstMessage *message = gst_bus_timed_pop_filtered(bus, 5 * GST_SECOND, GST_MESSAGE_EOS | GST_MESSAGE_ERROR);
    GstMessage *message = gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE, GST_MESSAGE_EOS | GST_MESSAGE_ERROR);

    parse_message(message);

    gst_element_set_state(data->pipeline, GST_STATE_NULL);

    /* Free resources */
    gst_object_unref(bus);
    gst_object_unref(data->pipeline);

    free(data);

    for (int i = 0; i < getNumberOfBarcodes(); i++)
    {
        printf ("Processing barcode %d; %s, with quality %d and time %d (ms)...\n",
                i, getBarcodeResult(i)->value, getBarcodeResult(i)->quality, getBarcodeResult(i)->time);
        printf ("Corner positions ");
        for (int j = 0; j < 4; j++)
        {
            printf("(%d, %d), ", getBarcodeResult(i)->corners[j].x, getBarcodeResult(i)->corners[j].y);
        }
        printf("\n");

        printf("Approximate location and size; (%d, %d), %d x %d\n\n",
               getBarcodeResult(i)->topLeft.x, getBarcodeResult(i)->topLeft.y, getBarcodeResult(i)->width, getBarcodeResult(i)->height);
    }
    destroy();

    return 0;

}

int createGStreamerCameraPipeline(CustomData **data)
{

    // Needs to be freed by caller.
    *data = malloc(sizeof(CustomData));

    (*data)->width = 1920;
    (*data)->height = 1080;

//    (*data)->width = 640;
//    (*data)->height = 480;

    (*data)->is_valid_barcode = FALSE;

    GstElement *source;
    GstElement *converter;
    GstElement *filter;
    GstElement *sink;

    /* Create the elements */
    source = gst_element_factory_make("tcamsrc", "source");
    // data->video_source = gst_element_factory_make("videotestsrc", "source");
    g_object_set(source, "num-buffers", 2, NULL);

    converter = gst_element_factory_make("autovideoconvert", "converter");

    filter = gst_element_factory_make("capsfilter", "camera_caps");

    char *caps_string = "video/x-raw,format=GRAY8,width=1920,height=1080,framerate=5/1";
    // sprintf(caps_string, data->width, data->height);

    GstCaps *caps = gst_caps_from_string(caps_string);
    g_object_set(filter, "caps", caps, NULL);

    sink = gst_element_factory_make("appsink", "sink");

    g_object_set(sink, "emit-signals", TRUE, NULL);
    g_signal_connect (sink, "new-sample", G_CALLBACK(new_sample), *data);

    /* Create the empty pipeline */
    (*data)->pipeline = gst_pipeline_new("camera-pipeline");
    // gst_element_set_state (data->pipeline, GST_STATE_NULL);

    if (!(*data)->pipeline || !source || !converter || !filter || !sink)
    {
        g_printerr("Not all elements could be created.\n");
        return -1;
    }

    /* Build the pipeline */
    gst_bin_add_many(GST_BIN((*data)->pipeline), source, converter, filter, sink, NULL);

    if ((!gst_element_link(source, converter)) || (!gst_element_link(converter, filter)) ||
        (!gst_element_link(filter, sink)))
    {
        g_printerr("Elements could not be linked.\n");
        gst_object_unref((*data)->pipeline);
        return -1;
    }

}

// gst-launch-1.0 filesrc location=test50.mp4 ! video/x-raw,format=GRAY8 ! decodebin name=dec ! autovideoconvert ! autovideosink
int createGStreamerMP4FilePipeline(CustomData **data)
{

    // Needs to be freed by caller.
    *data = malloc(sizeof(CustomData));

    (*data)->is_valid_barcode = FALSE;

    GstElement *source;
    // GstElement *filter;
    GstElement *decoder;
    GstElement *converter;
    GstElement *sink;

    /* Create the elements */
    source = gst_element_factory_make("filesrc", "source");
    g_object_set(source, "location", "test50.mp4", NULL);
    // g_object_set (source, "num-buffers", 10, NULL);

    // filter = gst_element_factory_make("capsfilter", "camera_caps");

    // char *caps_string = "video/x-raw,format=GRAY8";

    // GstCaps *caps = gst_caps_from_string(caps_string);
    // g_object_set(filter, "caps", caps, NULL);

    decoder = gst_element_factory_make("decodebin", "decoder");
    // g_object_set(decoder, "name", "dec", NULL);

    // gst_debug_set_threshold_for_name("decodebin", GST_LEVEL_DEBUG);

    converter = gst_element_factory_make("autovideoconvert", "converter");

    // gst_debug_set_threshold_for_name("videoconvert",GST_LEVEL_DEBUG);

    sink = gst_element_factory_make("autovideosink", "sink");

    /* Create the empty pipeline */
    (*data)->pipeline = gst_pipeline_new("camera-pipeline");
    // gst_element_set_state (data->pipeline, GST_STATE_NULL);

    if ((*data)->pipeline == NULL)
    {
        g_printerr("Pipeline could be created.\n");
        return -1;
    }
    else if (source == NULL)
    {
        g_printerr("Source element could be created.\n");
        return -1;
    }
    else if (decoder == NULL)
    {
        g_printerr("Decoder element could be created.\n");
        return -1;
    }
    else if (converter == NULL)
    {
        g_printerr("Converter element could be created.\n");
        return -1;
    }
    else if (sink == NULL)
    {
        g_printerr("Sink element could be created.\n");
        return -1;
    }
    else
    {

        /* Build the pipeline */
        gst_bin_add_many(GST_BIN((*data)->pipeline), source, decoder, converter, sink, NULL);

        // gst_bin_add_many(GST_BIN((*data)->pipeline), source, demux, queue, NULL);

        if (!gst_element_link(source, decoder))
        {
            g_printerr("Source and filter elements could not be linked.\n");
            return -1;
        }
        else if (!gst_element_link(decoder, converter))
        {
            g_printerr("Decoder and converter elements could not be linked.\n");
            return -1;
        }
        else if (!gst_element_link(converter, sink))
        {
            g_printerr("Converter and sink elements could not be linked.\n");
            return -1;
        }

    }

}

// Play a QuickTime video and rotate it clockwise 90 degrees.
// gst-launch-1.0 filesrc location=test.mov !
// qtdemux name=demux demux.video_0 ! queue !
// decodebin ! videoflip method=clockwise !
// videoconvert ! videoscale ! autovideosink
int createGStreamerQuickTimeFilePipeline(CustomData **data)
{

    // memset (&data, 0, sizeof (data));

    // Needs to be freed by caller.
    *data = malloc(sizeof(CustomData));

    (*data)->is_valid_barcode = FALSE;

    GstElement *source;
    GstElement *demux;
    GstElement *queue;
    GstElement *decoder;
    GstElement *videoflip;
    GstElement *converter;
    GstElement *scale;
    GstElement *sink;

    /* Create the elements */
    source = gst_element_factory_make("filesrc", "source");
    g_object_set(source, "location", "test.mov", NULL);
    // g_object_set (source, "num-buffers", 10, NULL);

    demux = gst_element_factory_make("qtdemux", "demux");
    g_object_set(demux, "name", "demux", NULL);

    queue = gst_element_factory_make("queue", "queue");

    decoder = gst_element_factory_make("decodebin", "decoder");

    videoflip = gst_element_factory_make("videoflip", "videoflip");

    converter = gst_element_factory_make("videoconvert", "converter");

    scale = gst_element_factory_make("videoscale", "scale");

    sink = gst_element_factory_make("autovideosink", "sink");

    // g_object_set (sink, "emit-signals", TRUE, NULL);
    // g_signal_connect (sink, "new-sample", G_CALLBACK (new_sample), *data);

    /* Create the empty pipeline */
    (*data)->pipeline = gst_pipeline_new("camera-pipeline");
    // gst_element_set_state (data->pipeline, GST_STATE_NULL);

    if (!(*data)->pipeline || !source || !demux || !queue || !decoder || !videoflip || !converter || !scale || !sink)
    {
        g_printerr("Not all elements could be created.\n");
        return -1;
    }

    /* Build the pipeline */
    gst_bin_add_many(GST_BIN((*data)->pipeline), source, demux, queue, decoder, videoflip, converter, scale, sink, NULL);
    // gst_bin_add_many(GST_BIN((*data)->pipeline), source, demux, queue, NULL);

    if (!gst_element_link(source, demux))
    {
        g_printerr("Source and demux elements could not be linked.\n");
        gst_object_unref((*data)->pipeline);
        return -1;
    }
    else if (!gst_element_link(demux, queue))
    {
        g_printerr("Demux and queue elements could not be linked.\n");
        gst_object_unref((*data)->pipeline);
        return -1;
    }
    else if (!gst_element_link(queue, decoder))
    {
        g_printerr("Queue and decoder elements could not be linked.\n");
        gst_object_unref((*data)->pipeline);
        return -1;
    }
    else if (!gst_element_link(decoder, videoflip))
    {
        g_printerr("Decoder and videoflip elements could not be linked.\n");
        gst_object_unref((*data)->pipeline);
        return -1;
    }
    else if (!gst_element_link(videoflip, converter))
    {
        g_printerr("Videoflip and converter elements could not be linked.\n");
        gst_object_unref((*data)->pipeline);
        return -1;
    }
    else if (!gst_element_link(converter, scale))
    {
        g_printerr("Converter and scale elements could not be linked.\n");
        gst_object_unref((*data)->pipeline);
        return -1;
    }
    else if (!gst_element_link(scale, sink))
    {
        g_printerr("Scale and sink elements could not be linked.\n");
        gst_object_unref((*data)->pipeline);
        return -1;
    }

}

/* The appsink has received a buffer */
static GstFlowReturn new_sample(GstElement *sink, CustomData *data)
{

    g_print("Calling new_sample...\n");
//  g_usleep(1000);

    // GstSample *sample;
    // g_signal_emit_by_name(sink, "pull-sample", &sample);

    if (!gst_app_sink_is_eos(GST_APP_SINK(sink)) && (!data->is_valid_barcode))
    {
        GstSample *sample = gst_app_sink_pull_sample(GST_APP_SINK(sink));
        if (sample != NULL)
        {
            GstBuffer *buffer = gst_sample_get_buffer(sample);
            if (buffer != NULL)
            {

                pthread_mutex_lock(&mutex);

                GstMapInfo info;
                gst_buffer_map(buffer, &info, GST_MAP_READ);

                g_print("%lu \n", info.size);

                // Needs to be freed by the function that put the pipeline in a playing state.
                data->barcode_image = malloc(info.size);
                memcpy(data->barcode_image, info.data, info.size);

                // Check for barcode.
                // data->barcode = decode((unsigned char *) data->barcode_image, data->width, data->height);
                CRPOINT barcodeTopLeft = {833, 755};
                if (decodeROI((unsigned char *) data->barcode_image, data->width, data->height, barcodeTopLeft, 194, 194) == 0)
                {
                    data->is_valid_barcode = TRUE;
                    // GstStateChangeReturn ret = gst_element_set_state(data->pipeline, GST_STATE_PAUSED);
                }

                pthread_mutex_unlock(&mutex);

            }

            gst_buffer_unref((GstBuffer *) sample);

        }
        else
        {
            g_print("Sample is NULL...\n");
        }

    }

}

void parse_message(GstMessage *message)
{

    /* Parse message */
    if (message != NULL)
    {
        GError *err;
        gchar *debug_info;

        switch (GST_MESSAGE_TYPE(message))
        {
            case GST_MESSAGE_ERROR:
                gst_message_parse_error(message, &err, &debug_info);
                g_printerr("Error received from element %s: %s\n",
                           GST_OBJECT_NAME(message->src), err->message);
                g_printerr("Debugging information: %s\n",
                           debug_info ? debug_info : "none");
                g_clear_error(&err);
                g_free(debug_info);
                break;
            case GST_MESSAGE_EOS:
                g_print("End-Of-Stream reached.\n");
                break;
            default:
                /* We should not reach here because we only asked for ERRORs and EOS */
                g_printerr("Unexpected message received.\n");
                break;
        }
        gst_message_unref(message);
    }
}
