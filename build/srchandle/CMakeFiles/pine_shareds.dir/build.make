# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/hcx/hcxServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/hcx/hcxServer/build

# Include any dependencies generated for this target.
include srchandle/CMakeFiles/pine_shareds.dir/depend.make

# Include the progress variables for this target.
include srchandle/CMakeFiles/pine_shareds.dir/progress.make

# Include the compile flags for this target's objects.
include srchandle/CMakeFiles/pine_shareds.dir/flags.make

srchandle/CMakeFiles/pine_shareds.dir/HandleRequest.cpp.o: srchandle/CMakeFiles/pine_shareds.dir/flags.make
srchandle/CMakeFiles/pine_shareds.dir/HandleRequest.cpp.o: ../srchandle/HandleRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/hcx/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object srchandle/CMakeFiles/pine_shareds.dir/HandleRequest.cpp.o"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pine_shareds.dir/HandleRequest.cpp.o -c /root/hcx/hcxServer/srchandle/HandleRequest.cpp

srchandle/CMakeFiles/pine_shareds.dir/HandleRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shareds.dir/HandleRequest.cpp.i"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/hcx/hcxServer/srchandle/HandleRequest.cpp > CMakeFiles/pine_shareds.dir/HandleRequest.cpp.i

srchandle/CMakeFiles/pine_shareds.dir/HandleRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shareds.dir/HandleRequest.cpp.s"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/hcx/hcxServer/srchandle/HandleRequest.cpp -o CMakeFiles/pine_shareds.dir/HandleRequest.cpp.s

srchandle/CMakeFiles/pine_shareds.dir/Sqlserver.cpp.o: srchandle/CMakeFiles/pine_shareds.dir/flags.make
srchandle/CMakeFiles/pine_shareds.dir/Sqlserver.cpp.o: ../srchandle/Sqlserver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/hcx/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object srchandle/CMakeFiles/pine_shareds.dir/Sqlserver.cpp.o"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pine_shareds.dir/Sqlserver.cpp.o -c /root/hcx/hcxServer/srchandle/Sqlserver.cpp

srchandle/CMakeFiles/pine_shareds.dir/Sqlserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shareds.dir/Sqlserver.cpp.i"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/hcx/hcxServer/srchandle/Sqlserver.cpp > CMakeFiles/pine_shareds.dir/Sqlserver.cpp.i

srchandle/CMakeFiles/pine_shareds.dir/Sqlserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shareds.dir/Sqlserver.cpp.s"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/hcx/hcxServer/srchandle/Sqlserver.cpp -o CMakeFiles/pine_shareds.dir/Sqlserver.cpp.s

srchandle/CMakeFiles/pine_shareds.dir/datasetWork.cpp.o: srchandle/CMakeFiles/pine_shareds.dir/flags.make
srchandle/CMakeFiles/pine_shareds.dir/datasetWork.cpp.o: ../srchandle/datasetWork.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/hcx/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object srchandle/CMakeFiles/pine_shareds.dir/datasetWork.cpp.o"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pine_shareds.dir/datasetWork.cpp.o -c /root/hcx/hcxServer/srchandle/datasetWork.cpp

srchandle/CMakeFiles/pine_shareds.dir/datasetWork.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shareds.dir/datasetWork.cpp.i"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/hcx/hcxServer/srchandle/datasetWork.cpp > CMakeFiles/pine_shareds.dir/datasetWork.cpp.i

srchandle/CMakeFiles/pine_shareds.dir/datasetWork.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shareds.dir/datasetWork.cpp.s"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/hcx/hcxServer/srchandle/datasetWork.cpp -o CMakeFiles/pine_shareds.dir/datasetWork.cpp.s

srchandle/CMakeFiles/pine_shareds.dir/modelWork.cpp.o: srchandle/CMakeFiles/pine_shareds.dir/flags.make
srchandle/CMakeFiles/pine_shareds.dir/modelWork.cpp.o: ../srchandle/modelWork.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/hcx/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object srchandle/CMakeFiles/pine_shareds.dir/modelWork.cpp.o"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pine_shareds.dir/modelWork.cpp.o -c /root/hcx/hcxServer/srchandle/modelWork.cpp

srchandle/CMakeFiles/pine_shareds.dir/modelWork.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shareds.dir/modelWork.cpp.i"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/hcx/hcxServer/srchandle/modelWork.cpp > CMakeFiles/pine_shareds.dir/modelWork.cpp.i

srchandle/CMakeFiles/pine_shareds.dir/modelWork.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shareds.dir/modelWork.cpp.s"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/hcx/hcxServer/srchandle/modelWork.cpp -o CMakeFiles/pine_shareds.dir/modelWork.cpp.s

srchandle/CMakeFiles/pine_shareds.dir/userWork.cpp.o: srchandle/CMakeFiles/pine_shareds.dir/flags.make
srchandle/CMakeFiles/pine_shareds.dir/userWork.cpp.o: ../srchandle/userWork.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/hcx/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object srchandle/CMakeFiles/pine_shareds.dir/userWork.cpp.o"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pine_shareds.dir/userWork.cpp.o -c /root/hcx/hcxServer/srchandle/userWork.cpp

srchandle/CMakeFiles/pine_shareds.dir/userWork.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shareds.dir/userWork.cpp.i"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/hcx/hcxServer/srchandle/userWork.cpp > CMakeFiles/pine_shareds.dir/userWork.cpp.i

srchandle/CMakeFiles/pine_shareds.dir/userWork.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shareds.dir/userWork.cpp.s"
	cd /root/hcx/hcxServer/build/srchandle && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/hcx/hcxServer/srchandle/userWork.cpp -o CMakeFiles/pine_shareds.dir/userWork.cpp.s

# Object files for target pine_shareds
pine_shareds_OBJECTS = \
"CMakeFiles/pine_shareds.dir/HandleRequest.cpp.o" \
"CMakeFiles/pine_shareds.dir/Sqlserver.cpp.o" \
"CMakeFiles/pine_shareds.dir/datasetWork.cpp.o" \
"CMakeFiles/pine_shareds.dir/modelWork.cpp.o" \
"CMakeFiles/pine_shareds.dir/userWork.cpp.o"

# External object files for target pine_shareds
pine_shareds_EXTERNAL_OBJECTS =

lib/libpine_shareds.so: srchandle/CMakeFiles/pine_shareds.dir/HandleRequest.cpp.o
lib/libpine_shareds.so: srchandle/CMakeFiles/pine_shareds.dir/Sqlserver.cpp.o
lib/libpine_shareds.so: srchandle/CMakeFiles/pine_shareds.dir/datasetWork.cpp.o
lib/libpine_shareds.so: srchandle/CMakeFiles/pine_shareds.dir/modelWork.cpp.o
lib/libpine_shareds.so: srchandle/CMakeFiles/pine_shareds.dir/userWork.cpp.o
lib/libpine_shareds.so: srchandle/CMakeFiles/pine_shareds.dir/build.make
lib/libpine_shareds.so: srchandle/CMakeFiles/pine_shareds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/hcx/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library ../lib/libpine_shareds.so"
	cd /root/hcx/hcxServer/build/srchandle && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pine_shareds.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
srchandle/CMakeFiles/pine_shareds.dir/build: lib/libpine_shareds.so

.PHONY : srchandle/CMakeFiles/pine_shareds.dir/build

srchandle/CMakeFiles/pine_shareds.dir/clean:
	cd /root/hcx/hcxServer/build/srchandle && $(CMAKE_COMMAND) -P CMakeFiles/pine_shareds.dir/cmake_clean.cmake
.PHONY : srchandle/CMakeFiles/pine_shareds.dir/clean

srchandle/CMakeFiles/pine_shareds.dir/depend:
	cd /root/hcx/hcxServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/hcx/hcxServer /root/hcx/hcxServer/srchandle /root/hcx/hcxServer/build /root/hcx/hcxServer/build/srchandle /root/hcx/hcxServer/build/srchandle/CMakeFiles/pine_shareds.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : srchandle/CMakeFiles/pine_shareds.dir/depend

