# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /opt/cmake-3.20.1/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.20.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/crain/C++/Asio/S02_Sync_RW_CS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/crain/C++/Asio/S02_Sync_RW_CS

# Include any dependencies generated for this target.
include client/CMakeFiles/client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include client/CMakeFiles/client.dir/compiler_depend.make

# Include the progress variables for this target.
include client/CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include client/CMakeFiles/client.dir/flags.make

client/CMakeFiles/client.dir/src/main.cc.o: client/CMakeFiles/client.dir/flags.make
client/CMakeFiles/client.dir/src/main.cc.o: client/src/main.cc
client/CMakeFiles/client.dir/src/main.cc.o: client/CMakeFiles/client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/crain/C++/Asio/S02_Sync_RW_CS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object client/CMakeFiles/client.dir/src/main.cc.o"
	cd /home/crain/C++/Asio/S02_Sync_RW_CS/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT client/CMakeFiles/client.dir/src/main.cc.o -MF CMakeFiles/client.dir/src/main.cc.o.d -o CMakeFiles/client.dir/src/main.cc.o -c /home/crain/C++/Asio/S02_Sync_RW_CS/client/src/main.cc

client/CMakeFiles/client.dir/src/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/main.cc.i"
	cd /home/crain/C++/Asio/S02_Sync_RW_CS/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/crain/C++/Asio/S02_Sync_RW_CS/client/src/main.cc > CMakeFiles/client.dir/src/main.cc.i

client/CMakeFiles/client.dir/src/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/main.cc.s"
	cd /home/crain/C++/Asio/S02_Sync_RW_CS/client && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/crain/C++/Asio/S02_Sync_RW_CS/client/src/main.cc -o CMakeFiles/client.dir/src/main.cc.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/src/main.cc.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: client/CMakeFiles/client.dir/src/main.cc.o
client: client/CMakeFiles/client.dir/build.make
client: client/CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/crain/C++/Asio/S02_Sync_RW_CS/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ."
	cd /home/crain/C++/Asio/S02_Sync_RW_CS/client && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
client/CMakeFiles/client.dir/build: client
.PHONY : client/CMakeFiles/client.dir/build

client/CMakeFiles/client.dir/clean:
	cd /home/crain/C++/Asio/S02_Sync_RW_CS/client && $(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : client/CMakeFiles/client.dir/clean

client/CMakeFiles/client.dir/depend:
	cd /home/crain/C++/Asio/S02_Sync_RW_CS && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/crain/C++/Asio/S02_Sync_RW_CS /home/crain/C++/Asio/S02_Sync_RW_CS/client /home/crain/C++/Asio/S02_Sync_RW_CS /home/crain/C++/Asio/S02_Sync_RW_CS/client /home/crain/C++/Asio/S02_Sync_RW_CS/client/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : client/CMakeFiles/client.dir/depend

