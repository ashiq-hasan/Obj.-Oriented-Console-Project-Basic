# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C++\h5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++\h5\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/h5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/h5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/h5.dir/flags.make

CMakeFiles/h5.dir/main.cpp.obj: CMakeFiles/h5.dir/flags.make
CMakeFiles/h5.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++\h5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/h5.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\h5.dir\main.cpp.obj -c D:\C++\h5\main.cpp

CMakeFiles/h5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/h5.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++\h5\main.cpp > CMakeFiles\h5.dir\main.cpp.i

CMakeFiles/h5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/h5.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++\h5\main.cpp -o CMakeFiles\h5.dir\main.cpp.s

# Object files for target h5
h5_OBJECTS = \
"CMakeFiles/h5.dir/main.cpp.obj"

# External object files for target h5
h5_EXTERNAL_OBJECTS =

h5.exe: CMakeFiles/h5.dir/main.cpp.obj
h5.exe: CMakeFiles/h5.dir/build.make
h5.exe: CMakeFiles/h5.dir/linklibs.rsp
h5.exe: CMakeFiles/h5.dir/objects1.rsp
h5.exe: CMakeFiles/h5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C++\h5\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable h5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\h5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/h5.dir/build: h5.exe

.PHONY : CMakeFiles/h5.dir/build

CMakeFiles/h5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\h5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/h5.dir/clean

CMakeFiles/h5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C++\h5 D:\C++\h5 D:\C++\h5\cmake-build-debug D:\C++\h5\cmake-build-debug D:\C++\h5\cmake-build-debug\CMakeFiles\h5.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/h5.dir/depend

