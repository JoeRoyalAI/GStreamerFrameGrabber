# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/parallels/CLionProjects/GStreamerFrameGrabber

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/CLionProjects/GStreamerFrameGrabber/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GStreamerFrameGrabber.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GStreamerFrameGrabber.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GStreamerFrameGrabber.dir/flags.make

CMakeFiles/GStreamerFrameGrabber.dir/main.c.o: CMakeFiles/GStreamerFrameGrabber.dir/flags.make
CMakeFiles/GStreamerFrameGrabber.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/CLionProjects/GStreamerFrameGrabber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GStreamerFrameGrabber.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GStreamerFrameGrabber.dir/main.c.o   -c /home/parallels/CLionProjects/GStreamerFrameGrabber/main.c

CMakeFiles/GStreamerFrameGrabber.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GStreamerFrameGrabber.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/parallels/CLionProjects/GStreamerFrameGrabber/main.c > CMakeFiles/GStreamerFrameGrabber.dir/main.c.i

CMakeFiles/GStreamerFrameGrabber.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GStreamerFrameGrabber.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/parallels/CLionProjects/GStreamerFrameGrabber/main.c -o CMakeFiles/GStreamerFrameGrabber.dir/main.c.s

CMakeFiles/GStreamerFrameGrabber.dir/main.c.o.requires:

.PHONY : CMakeFiles/GStreamerFrameGrabber.dir/main.c.o.requires

CMakeFiles/GStreamerFrameGrabber.dir/main.c.o.provides: CMakeFiles/GStreamerFrameGrabber.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/GStreamerFrameGrabber.dir/build.make CMakeFiles/GStreamerFrameGrabber.dir/main.c.o.provides.build
.PHONY : CMakeFiles/GStreamerFrameGrabber.dir/main.c.o.provides

CMakeFiles/GStreamerFrameGrabber.dir/main.c.o.provides.build: CMakeFiles/GStreamerFrameGrabber.dir/main.c.o


CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o: CMakeFiles/GStreamerFrameGrabber.dir/flags.make
CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o: ../Barcode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/CLionProjects/GStreamerFrameGrabber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o   -c /home/parallels/CLionProjects/GStreamerFrameGrabber/Barcode.c

CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/parallels/CLionProjects/GStreamerFrameGrabber/Barcode.c > CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.i

CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/parallels/CLionProjects/GStreamerFrameGrabber/Barcode.c -o CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.s

CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o.requires:

.PHONY : CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o.requires

CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o.provides: CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o.requires
	$(MAKE) -f CMakeFiles/GStreamerFrameGrabber.dir/build.make CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o.provides.build
.PHONY : CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o.provides

CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o.provides.build: CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o


# Object files for target GStreamerFrameGrabber
GStreamerFrameGrabber_OBJECTS = \
"CMakeFiles/GStreamerFrameGrabber.dir/main.c.o" \
"CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o"

# External object files for target GStreamerFrameGrabber
GStreamerFrameGrabber_EXTERNAL_OBJECTS =

GStreamerFrameGrabber: CMakeFiles/GStreamerFrameGrabber.dir/main.c.o
GStreamerFrameGrabber: CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o
GStreamerFrameGrabber: CMakeFiles/GStreamerFrameGrabber.dir/build.make
GStreamerFrameGrabber: CMakeFiles/GStreamerFrameGrabber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/CLionProjects/GStreamerFrameGrabber/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable GStreamerFrameGrabber"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GStreamerFrameGrabber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GStreamerFrameGrabber.dir/build: GStreamerFrameGrabber

.PHONY : CMakeFiles/GStreamerFrameGrabber.dir/build

CMakeFiles/GStreamerFrameGrabber.dir/requires: CMakeFiles/GStreamerFrameGrabber.dir/main.c.o.requires
CMakeFiles/GStreamerFrameGrabber.dir/requires: CMakeFiles/GStreamerFrameGrabber.dir/Barcode.c.o.requires

.PHONY : CMakeFiles/GStreamerFrameGrabber.dir/requires

CMakeFiles/GStreamerFrameGrabber.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GStreamerFrameGrabber.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GStreamerFrameGrabber.dir/clean

CMakeFiles/GStreamerFrameGrabber.dir/depend:
	cd /home/parallels/CLionProjects/GStreamerFrameGrabber/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/CLionProjects/GStreamerFrameGrabber /home/parallels/CLionProjects/GStreamerFrameGrabber /home/parallels/CLionProjects/GStreamerFrameGrabber/cmake-build-debug /home/parallels/CLionProjects/GStreamerFrameGrabber/cmake-build-debug /home/parallels/CLionProjects/GStreamerFrameGrabber/cmake-build-debug/CMakeFiles/GStreamerFrameGrabber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GStreamerFrameGrabber.dir/depend
