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
include src/CMakeFiles/pine_shared.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/pine_shared.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/pine_shared.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/pine_shared.dir/flags.make

src/CMakeFiles/pine_shared.dir/Acceptor.cpp.o: src/CMakeFiles/pine_shared.dir/flags.make
src/CMakeFiles/pine_shared.dir/Acceptor.cpp.o: ../src/Acceptor.cpp
src/CMakeFiles/pine_shared.dir/Acceptor.cpp.o: src/CMakeFiles/pine_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/pine_shared.dir/Acceptor.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/pine_shared.dir/Acceptor.cpp.o -MF CMakeFiles/pine_shared.dir/Acceptor.cpp.o.d -o CMakeFiles/pine_shared.dir/Acceptor.cpp.o -c /home/hcx/hcxself/hcxServer/src/Acceptor.cpp

src/CMakeFiles/pine_shared.dir/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shared.dir/Acceptor.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/src/Acceptor.cpp > CMakeFiles/pine_shared.dir/Acceptor.cpp.i

src/CMakeFiles/pine_shared.dir/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shared.dir/Acceptor.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/src/Acceptor.cpp -o CMakeFiles/pine_shared.dir/Acceptor.cpp.s

src/CMakeFiles/pine_shared.dir/Buffer.cpp.o: src/CMakeFiles/pine_shared.dir/flags.make
src/CMakeFiles/pine_shared.dir/Buffer.cpp.o: ../src/Buffer.cpp
src/CMakeFiles/pine_shared.dir/Buffer.cpp.o: src/CMakeFiles/pine_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/pine_shared.dir/Buffer.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/pine_shared.dir/Buffer.cpp.o -MF CMakeFiles/pine_shared.dir/Buffer.cpp.o.d -o CMakeFiles/pine_shared.dir/Buffer.cpp.o -c /home/hcx/hcxself/hcxServer/src/Buffer.cpp

src/CMakeFiles/pine_shared.dir/Buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shared.dir/Buffer.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/src/Buffer.cpp > CMakeFiles/pine_shared.dir/Buffer.cpp.i

src/CMakeFiles/pine_shared.dir/Buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shared.dir/Buffer.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/src/Buffer.cpp -o CMakeFiles/pine_shared.dir/Buffer.cpp.s

src/CMakeFiles/pine_shared.dir/Channel.cpp.o: src/CMakeFiles/pine_shared.dir/flags.make
src/CMakeFiles/pine_shared.dir/Channel.cpp.o: ../src/Channel.cpp
src/CMakeFiles/pine_shared.dir/Channel.cpp.o: src/CMakeFiles/pine_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/pine_shared.dir/Channel.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/pine_shared.dir/Channel.cpp.o -MF CMakeFiles/pine_shared.dir/Channel.cpp.o.d -o CMakeFiles/pine_shared.dir/Channel.cpp.o -c /home/hcx/hcxself/hcxServer/src/Channel.cpp

src/CMakeFiles/pine_shared.dir/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shared.dir/Channel.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/src/Channel.cpp > CMakeFiles/pine_shared.dir/Channel.cpp.i

src/CMakeFiles/pine_shared.dir/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shared.dir/Channel.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/src/Channel.cpp -o CMakeFiles/pine_shared.dir/Channel.cpp.s

src/CMakeFiles/pine_shared.dir/Connection.cpp.o: src/CMakeFiles/pine_shared.dir/flags.make
src/CMakeFiles/pine_shared.dir/Connection.cpp.o: ../src/Connection.cpp
src/CMakeFiles/pine_shared.dir/Connection.cpp.o: src/CMakeFiles/pine_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/pine_shared.dir/Connection.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/pine_shared.dir/Connection.cpp.o -MF CMakeFiles/pine_shared.dir/Connection.cpp.o.d -o CMakeFiles/pine_shared.dir/Connection.cpp.o -c /home/hcx/hcxself/hcxServer/src/Connection.cpp

src/CMakeFiles/pine_shared.dir/Connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shared.dir/Connection.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/src/Connection.cpp > CMakeFiles/pine_shared.dir/Connection.cpp.i

src/CMakeFiles/pine_shared.dir/Connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shared.dir/Connection.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/src/Connection.cpp -o CMakeFiles/pine_shared.dir/Connection.cpp.s

src/CMakeFiles/pine_shared.dir/EventLoop.cpp.o: src/CMakeFiles/pine_shared.dir/flags.make
src/CMakeFiles/pine_shared.dir/EventLoop.cpp.o: ../src/EventLoop.cpp
src/CMakeFiles/pine_shared.dir/EventLoop.cpp.o: src/CMakeFiles/pine_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/pine_shared.dir/EventLoop.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/pine_shared.dir/EventLoop.cpp.o -MF CMakeFiles/pine_shared.dir/EventLoop.cpp.o.d -o CMakeFiles/pine_shared.dir/EventLoop.cpp.o -c /home/hcx/hcxself/hcxServer/src/EventLoop.cpp

src/CMakeFiles/pine_shared.dir/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shared.dir/EventLoop.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/src/EventLoop.cpp > CMakeFiles/pine_shared.dir/EventLoop.cpp.i

src/CMakeFiles/pine_shared.dir/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shared.dir/EventLoop.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/src/EventLoop.cpp -o CMakeFiles/pine_shared.dir/EventLoop.cpp.s

src/CMakeFiles/pine_shared.dir/Poller.cpp.o: src/CMakeFiles/pine_shared.dir/flags.make
src/CMakeFiles/pine_shared.dir/Poller.cpp.o: ../src/Poller.cpp
src/CMakeFiles/pine_shared.dir/Poller.cpp.o: src/CMakeFiles/pine_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/pine_shared.dir/Poller.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/pine_shared.dir/Poller.cpp.o -MF CMakeFiles/pine_shared.dir/Poller.cpp.o.d -o CMakeFiles/pine_shared.dir/Poller.cpp.o -c /home/hcx/hcxself/hcxServer/src/Poller.cpp

src/CMakeFiles/pine_shared.dir/Poller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shared.dir/Poller.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/src/Poller.cpp > CMakeFiles/pine_shared.dir/Poller.cpp.i

src/CMakeFiles/pine_shared.dir/Poller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shared.dir/Poller.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/src/Poller.cpp -o CMakeFiles/pine_shared.dir/Poller.cpp.s

src/CMakeFiles/pine_shared.dir/Socket.cpp.o: src/CMakeFiles/pine_shared.dir/flags.make
src/CMakeFiles/pine_shared.dir/Socket.cpp.o: ../src/Socket.cpp
src/CMakeFiles/pine_shared.dir/Socket.cpp.o: src/CMakeFiles/pine_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/pine_shared.dir/Socket.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/pine_shared.dir/Socket.cpp.o -MF CMakeFiles/pine_shared.dir/Socket.cpp.o.d -o CMakeFiles/pine_shared.dir/Socket.cpp.o -c /home/hcx/hcxself/hcxServer/src/Socket.cpp

src/CMakeFiles/pine_shared.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shared.dir/Socket.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/src/Socket.cpp > CMakeFiles/pine_shared.dir/Socket.cpp.i

src/CMakeFiles/pine_shared.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shared.dir/Socket.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/src/Socket.cpp -o CMakeFiles/pine_shared.dir/Socket.cpp.s

src/CMakeFiles/pine_shared.dir/TcpServer.cpp.o: src/CMakeFiles/pine_shared.dir/flags.make
src/CMakeFiles/pine_shared.dir/TcpServer.cpp.o: ../src/TcpServer.cpp
src/CMakeFiles/pine_shared.dir/TcpServer.cpp.o: src/CMakeFiles/pine_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/pine_shared.dir/TcpServer.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/pine_shared.dir/TcpServer.cpp.o -MF CMakeFiles/pine_shared.dir/TcpServer.cpp.o.d -o CMakeFiles/pine_shared.dir/TcpServer.cpp.o -c /home/hcx/hcxself/hcxServer/src/TcpServer.cpp

src/CMakeFiles/pine_shared.dir/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shared.dir/TcpServer.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/src/TcpServer.cpp > CMakeFiles/pine_shared.dir/TcpServer.cpp.i

src/CMakeFiles/pine_shared.dir/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shared.dir/TcpServer.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/src/TcpServer.cpp -o CMakeFiles/pine_shared.dir/TcpServer.cpp.s

src/CMakeFiles/pine_shared.dir/ThreadPool.cpp.o: src/CMakeFiles/pine_shared.dir/flags.make
src/CMakeFiles/pine_shared.dir/ThreadPool.cpp.o: ../src/ThreadPool.cpp
src/CMakeFiles/pine_shared.dir/ThreadPool.cpp.o: src/CMakeFiles/pine_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/CMakeFiles/pine_shared.dir/ThreadPool.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/pine_shared.dir/ThreadPool.cpp.o -MF CMakeFiles/pine_shared.dir/ThreadPool.cpp.o.d -o CMakeFiles/pine_shared.dir/ThreadPool.cpp.o -c /home/hcx/hcxself/hcxServer/src/ThreadPool.cpp

src/CMakeFiles/pine_shared.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shared.dir/ThreadPool.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/src/ThreadPool.cpp > CMakeFiles/pine_shared.dir/ThreadPool.cpp.i

src/CMakeFiles/pine_shared.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shared.dir/ThreadPool.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/src/ThreadPool.cpp -o CMakeFiles/pine_shared.dir/ThreadPool.cpp.s

src/CMakeFiles/pine_shared.dir/util.cpp.o: src/CMakeFiles/pine_shared.dir/flags.make
src/CMakeFiles/pine_shared.dir/util.cpp.o: ../src/util.cpp
src/CMakeFiles/pine_shared.dir/util.cpp.o: src/CMakeFiles/pine_shared.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/CMakeFiles/pine_shared.dir/util.cpp.o"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/pine_shared.dir/util.cpp.o -MF CMakeFiles/pine_shared.dir/util.cpp.o.d -o CMakeFiles/pine_shared.dir/util.cpp.o -c /home/hcx/hcxself/hcxServer/src/util.cpp

src/CMakeFiles/pine_shared.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pine_shared.dir/util.cpp.i"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hcx/hcxself/hcxServer/src/util.cpp > CMakeFiles/pine_shared.dir/util.cpp.i

src/CMakeFiles/pine_shared.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pine_shared.dir/util.cpp.s"
	cd /home/hcx/hcxself/hcxServer/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hcx/hcxself/hcxServer/src/util.cpp -o CMakeFiles/pine_shared.dir/util.cpp.s

# Object files for target pine_shared
pine_shared_OBJECTS = \
"CMakeFiles/pine_shared.dir/Acceptor.cpp.o" \
"CMakeFiles/pine_shared.dir/Buffer.cpp.o" \
"CMakeFiles/pine_shared.dir/Channel.cpp.o" \
"CMakeFiles/pine_shared.dir/Connection.cpp.o" \
"CMakeFiles/pine_shared.dir/EventLoop.cpp.o" \
"CMakeFiles/pine_shared.dir/Poller.cpp.o" \
"CMakeFiles/pine_shared.dir/Socket.cpp.o" \
"CMakeFiles/pine_shared.dir/TcpServer.cpp.o" \
"CMakeFiles/pine_shared.dir/ThreadPool.cpp.o" \
"CMakeFiles/pine_shared.dir/util.cpp.o"

# External object files for target pine_shared
pine_shared_EXTERNAL_OBJECTS =

lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/Acceptor.cpp.o
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/Buffer.cpp.o
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/Channel.cpp.o
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/Connection.cpp.o
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/EventLoop.cpp.o
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/Poller.cpp.o
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/Socket.cpp.o
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/TcpServer.cpp.o
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/ThreadPool.cpp.o
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/util.cpp.o
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/build.make
lib/libpine_shared.so: src/CMakeFiles/pine_shared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hcx/hcxself/hcxServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared library ../lib/libpine_shared.so"
	cd /home/hcx/hcxself/hcxServer/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pine_shared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/pine_shared.dir/build: lib/libpine_shared.so
.PHONY : src/CMakeFiles/pine_shared.dir/build

src/CMakeFiles/pine_shared.dir/clean:
	cd /home/hcx/hcxself/hcxServer/build/src && $(CMAKE_COMMAND) -P CMakeFiles/pine_shared.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/pine_shared.dir/clean

src/CMakeFiles/pine_shared.dir/depend:
	cd /home/hcx/hcxself/hcxServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hcx/hcxself/hcxServer /home/hcx/hcxself/hcxServer/src /home/hcx/hcxself/hcxServer/build /home/hcx/hcxself/hcxServer/build/src /home/hcx/hcxself/hcxServer/build/src/CMakeFiles/pine_shared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/pine_shared.dir/depend
