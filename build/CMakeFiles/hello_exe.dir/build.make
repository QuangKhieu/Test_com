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
CMAKE_SOURCE_DIR = /home/quangkhieu/Test_prj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/quangkhieu/Test_prj/build

# Include any dependencies generated for this target.
include CMakeFiles/hello_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hello_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hello_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello_exe.dir/flags.make

CMakeFiles/hello_exe.dir/src/main.cpp.o: CMakeFiles/hello_exe.dir/flags.make
CMakeFiles/hello_exe.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/hello_exe.dir/src/main.cpp.o: CMakeFiles/hello_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/quangkhieu/Test_prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hello_exe.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hello_exe.dir/src/main.cpp.o -MF CMakeFiles/hello_exe.dir/src/main.cpp.o.d -o CMakeFiles/hello_exe.dir/src/main.cpp.o -c /home/quangkhieu/Test_prj/src/main.cpp

CMakeFiles/hello_exe.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hello_exe.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/quangkhieu/Test_prj/src/main.cpp > CMakeFiles/hello_exe.dir/src/main.cpp.i

CMakeFiles/hello_exe.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hello_exe.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/quangkhieu/Test_prj/src/main.cpp -o CMakeFiles/hello_exe.dir/src/main.cpp.s

# Object files for target hello_exe
hello_exe_OBJECTS = \
"CMakeFiles/hello_exe.dir/src/main.cpp.o"

# External object files for target hello_exe
hello_exe_EXTERNAL_OBJECTS =

bin/hello_exe: CMakeFiles/hello_exe.dir/src/main.cpp.o
bin/hello_exe: CMakeFiles/hello_exe.dir/build.make
bin/hello_exe: lib/libhello.a
bin/hello_exe: CMakeFiles/hello_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/quangkhieu/Test_prj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/hello_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello_exe.dir/build: bin/hello_exe
.PHONY : CMakeFiles/hello_exe.dir/build

CMakeFiles/hello_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello_exe.dir/clean

CMakeFiles/hello_exe.dir/depend:
	cd /home/quangkhieu/Test_prj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/quangkhieu/Test_prj /home/quangkhieu/Test_prj /home/quangkhieu/Test_prj/build /home/quangkhieu/Test_prj/build /home/quangkhieu/Test_prj/build/CMakeFiles/hello_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hello_exe.dir/depend
