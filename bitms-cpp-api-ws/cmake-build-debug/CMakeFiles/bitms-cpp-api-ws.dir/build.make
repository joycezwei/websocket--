# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /home/parallels/application/clion-2018.1.5/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/parallels/application/clion-2018.1.5/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/parallels/CLionProjects/bitms-cpp-api-ws

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/CLionProjects/bitms-cpp-api-ws/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bitms-cpp-api-ws.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bitms-cpp-api-ws.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bitms-cpp-api-ws.dir/flags.make

CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o: CMakeFiles/bitms-cpp-api-ws.dir/flags.make
CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o: ../TestWebsocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/CLionProjects/bitms-cpp-api-ws/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o -c /home/parallels/CLionProjects/bitms-cpp-api-ws/TestWebsocket.cpp

CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/CLionProjects/bitms-cpp-api-ws/TestWebsocket.cpp > CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.i

CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/CLionProjects/bitms-cpp-api-ws/TestWebsocket.cpp -o CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.s

CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o.requires:

.PHONY : CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o.requires

CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o.provides: CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o.requires
	$(MAKE) -f CMakeFiles/bitms-cpp-api-ws.dir/build.make CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o.provides.build
.PHONY : CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o.provides

CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o.provides.build: CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o


# Object files for target bitms-cpp-api-ws
bitms__cpp__api__ws_OBJECTS = \
"CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o"

# External object files for target bitms-cpp-api-ws
bitms__cpp__api__ws_EXTERNAL_OBJECTS =

bitms-cpp-api-ws: CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o
bitms-cpp-api-ws: CMakeFiles/bitms-cpp-api-ws.dir/build.make
bitms-cpp-api-ws: CMakeFiles/bitms-cpp-api-ws.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/CLionProjects/bitms-cpp-api-ws/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bitms-cpp-api-ws"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bitms-cpp-api-ws.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bitms-cpp-api-ws.dir/build: bitms-cpp-api-ws

.PHONY : CMakeFiles/bitms-cpp-api-ws.dir/build

CMakeFiles/bitms-cpp-api-ws.dir/requires: CMakeFiles/bitms-cpp-api-ws.dir/TestWebsocket.cpp.o.requires

.PHONY : CMakeFiles/bitms-cpp-api-ws.dir/requires

CMakeFiles/bitms-cpp-api-ws.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bitms-cpp-api-ws.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bitms-cpp-api-ws.dir/clean

CMakeFiles/bitms-cpp-api-ws.dir/depend:
	cd /home/parallels/CLionProjects/bitms-cpp-api-ws/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/CLionProjects/bitms-cpp-api-ws /home/parallels/CLionProjects/bitms-cpp-api-ws /home/parallels/CLionProjects/bitms-cpp-api-ws/cmake-build-debug /home/parallels/CLionProjects/bitms-cpp-api-ws/cmake-build-debug /home/parallels/CLionProjects/bitms-cpp-api-ws/cmake-build-debug/CMakeFiles/bitms-cpp-api-ws.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bitms-cpp-api-ws.dir/depend

