# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hcx/hcxself/hcxServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hcx/hcxself/hcxServer/build

# Include any dependencies generated for this target.
include test/CMakeFiles/echo_clients.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/echo_clients.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/echo_clients.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/echo_clients.dir/flags.make

test/CMakeFiles/echo_clients.dir/echo_clients.cpp.o: test/CMakeFiles/echo_clients.dir/flags.make
test/CMakeFiles/echo_clients.dir/echo_clients.cpp.o: ../test/echo_clients.cpp
test/CMakeFiles/echo_clients.dir/echo_clients.cpp.o: test/CMakeFiles/echo_clients.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/echo_clients.dir/echo_clients.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/echo_clients.dir/echo_clients.cpp.o -MF CMakeFiles/echo_clients.dir/echo_clients.cpp.o.d -o CMakeFiles/echo_clients.dir/echo_clients.cpp.o -c /home/hcx/hcxself/hcxServer/test/echo_clients.cpp

test/CMakeFiles/echo_clients.dir/echo_clients.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/echo_clients.dir/echo_clients.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/test/echo_clients.cpp > CMakeFiles/echo_clients.dir/echo_clients.cpp.i

test/CMakeFiles/echo_clients.dir/echo_clients.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/echo_clients.dir/echo_clients.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/test/echo_clients.cpp -o CMakeFiles/echo_clients.dir/echo_clients.cpp.s

# Object files for target echo_clients
echo_clients_OBJECTS = \
"CMakeFiles/echo_clients.dir/echo_clients.cpp.o"

# External object files for target echo_clients
echo_clients_EXTERNAL_OBJECTS =

bin/echo_clients: test/CMakeFiles/echo_clients.dir/echo_clients.cpp.o
bin/echo_clients: test/CMakeFiles/echo_clients.dir/build.make
bin/echo_clients: lib/libpine_shared.so
bin/echo_clients: lib/libpine_shareds.so
bin/echo_clients: /usr/lib/x86_64-linux-gnu/libmysqlcppconn.so
bin/echo_clients: /usr/local/lib/libjsoncpp.so.1.9.5
bin/echo_clients: test/CMakeFiles/echo_clients.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/echo_clients"
	cd /home/hcx/hcxself/hcxServer/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/echo_clients.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/echo_clients.dir/build: bin/echo_clients
.PHONY : test/CMakeFiles/echo_clients.dir/build

test/CMakeFiles/echo_clients.dir/clean:
	cd /home/hcx/hcxself/hcxServer/build/test && $(CMAKE_COMMAND) -P CMakeFiles/echo_clients.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/echo_clients.dir/clean

test/CMakeFiles/echo_clients.dir/depend:
	cd /home/hcx/hcxself/hcxServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hcx/hcxself/hcxServer /home/hcx/hcxself/hcxServer/test /home/hcx/hcxself/hcxServer/build /home/hcx/hcxself/hcxServer/build/test /home/hcx/hcxself/hcxServer/build/test/CMakeFiles/echo_clients.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/echo_clients.dir/depend
