# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3

# Include any dependencies generated for this target.
include CMakeFiles/draw_triangulation_3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/draw_triangulation_3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/draw_triangulation_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/draw_triangulation_3.dir/flags.make

CMakeFiles/draw_triangulation_3.dir/codegen:
.PHONY : CMakeFiles/draw_triangulation_3.dir/codegen

CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.o: CMakeFiles/draw_triangulation_3.dir/flags.make
CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.o: draw_triangulation_3.cpp
CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.o: CMakeFiles/draw_triangulation_3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/nekoyuc/src/CGAL_stuff/Test_Tri_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.o -MF CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.o.d -o CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.o -c /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3/draw_triangulation_3.cpp

CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3/draw_triangulation_3.cpp > CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.i

CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3/draw_triangulation_3.cpp -o CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.s

# Object files for target draw_triangulation_3
draw_triangulation_3_OBJECTS = \
"CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.o"

# External object files for target draw_triangulation_3
draw_triangulation_3_EXTERNAL_OBJECTS =

draw_triangulation_3: CMakeFiles/draw_triangulation_3.dir/draw_triangulation_3.cpp.o
draw_triangulation_3: CMakeFiles/draw_triangulation_3.dir/build.make
draw_triangulation_3: libCGAL_Qt6_moc_and_resources.a
draw_triangulation_3: /opt/homebrew/lib/libgmpxx.dylib
draw_triangulation_3: /opt/homebrew/lib/libmpfr.dylib
draw_triangulation_3: /opt/homebrew/lib/libgmp.dylib
draw_triangulation_3: /opt/homebrew/lib/QtSvg.framework/Versions/A/QtSvg
draw_triangulation_3: /opt/homebrew/lib/QtOpenGLWidgets.framework/Versions/A/QtOpenGLWidgets
draw_triangulation_3: /opt/homebrew/lib/QtWidgets.framework/Versions/A/QtWidgets
draw_triangulation_3: /opt/homebrew/lib/QtOpenGL.framework/Versions/A/QtOpenGL
draw_triangulation_3: /opt/homebrew/lib/QtGui.framework/Versions/A/QtGui
draw_triangulation_3: /opt/homebrew/lib/QtCore.framework/Versions/A/QtCore
draw_triangulation_3: CMakeFiles/draw_triangulation_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/nekoyuc/src/CGAL_stuff/Test_Tri_3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable draw_triangulation_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/draw_triangulation_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/draw_triangulation_3.dir/build: draw_triangulation_3
.PHONY : CMakeFiles/draw_triangulation_3.dir/build

CMakeFiles/draw_triangulation_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/draw_triangulation_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/draw_triangulation_3.dir/clean

CMakeFiles/draw_triangulation_3.dir/depend:
	cd /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3 /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3 /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3 /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3 /Users/nekoyuc/src/CGAL_stuff/Test_Tri_3/CMakeFiles/draw_triangulation_3.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/draw_triangulation_3.dir/depend
