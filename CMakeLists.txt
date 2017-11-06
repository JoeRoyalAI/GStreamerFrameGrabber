cmake_minimum_required(VERSION 3.8)

project(GStreamerFrameGrabber)

set(CMAKE_C_STANDARD 99)

include_directories(/usr/include/gstreamer-1.0 /usr/lib/x86_64-linux-gnu/gstreamer-1.0/include /usr/include/glib-2.0 /usr/lib/x86_64-linux-gnu/glib-2.0/include)

link_directories(. /usr/include/gstreamer-1.0 /usr/lib/x86_64-linux-gnu)

link_libraries(gstreamer-1.0 gobject-2.0 glib-2.0 gstapp-1.0 CortexDecoderHasp)

set(SOURCE_FILES main.c Barcode.h Barcode.c)

add_executable(GStreamerFrameGrabber ${SOURCE_FILES})