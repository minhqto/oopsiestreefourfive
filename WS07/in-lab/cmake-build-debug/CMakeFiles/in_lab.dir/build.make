# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/in_lab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/in_lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/in_lab.dir/flags.make

CMakeFiles/in_lab.dir/w7_lab.cpp.o: CMakeFiles/in_lab.dir/flags.make
CMakeFiles/in_lab.dir/w7_lab.cpp.o: ../w7_lab.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/in_lab.dir/w7_lab.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/in_lab.dir/w7_lab.cpp.o -c /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/w7_lab.cpp

CMakeFiles/in_lab.dir/w7_lab.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/in_lab.dir/w7_lab.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/w7_lab.cpp > CMakeFiles/in_lab.dir/w7_lab.cpp.i

CMakeFiles/in_lab.dir/w7_lab.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/in_lab.dir/w7_lab.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/w7_lab.cpp -o CMakeFiles/in_lab.dir/w7_lab.cpp.s

CMakeFiles/in_lab.dir/SongCollection.cpp.o: CMakeFiles/in_lab.dir/flags.make
CMakeFiles/in_lab.dir/SongCollection.cpp.o: ../SongCollection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/in_lab.dir/SongCollection.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/in_lab.dir/SongCollection.cpp.o -c /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/SongCollection.cpp

CMakeFiles/in_lab.dir/SongCollection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/in_lab.dir/SongCollection.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/SongCollection.cpp > CMakeFiles/in_lab.dir/SongCollection.cpp.i

CMakeFiles/in_lab.dir/SongCollection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/in_lab.dir/SongCollection.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/SongCollection.cpp -o CMakeFiles/in_lab.dir/SongCollection.cpp.s

# Object files for target in_lab
in_lab_OBJECTS = \
"CMakeFiles/in_lab.dir/w7_lab.cpp.o" \
"CMakeFiles/in_lab.dir/SongCollection.cpp.o"

# External object files for target in_lab
in_lab_EXTERNAL_OBJECTS =

in_lab: CMakeFiles/in_lab.dir/w7_lab.cpp.o
in_lab: CMakeFiles/in_lab.dir/SongCollection.cpp.o
in_lab: CMakeFiles/in_lab.dir/build.make
in_lab: CMakeFiles/in_lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable in_lab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/in_lab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/in_lab.dir/build: in_lab

.PHONY : CMakeFiles/in_lab.dir/build

CMakeFiles/in_lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/in_lab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/in_lab.dir/clean

CMakeFiles/in_lab.dir/depend:
	cd /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/cmake-build-debug /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/cmake-build-debug /Users/minhto/Documents/Seneca/ThirdSemester/OOP345/Workshops/WS07/in-lab/cmake-build-debug/CMakeFiles/in_lab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/in_lab.dir/depend

