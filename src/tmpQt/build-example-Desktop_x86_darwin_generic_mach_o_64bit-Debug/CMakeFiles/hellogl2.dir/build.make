# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug

# Include any dependencies generated for this target.
include CMakeFiles/hellogl2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hellogl2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hellogl2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hellogl2.dir/flags.make

CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.o: CMakeFiles/hellogl2.dir/flags.make
CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.o: hellogl2_autogen/mocs_compilation.cpp
CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.o: CMakeFiles/hellogl2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.o -MF CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.o -c /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/hellogl2_autogen/mocs_compilation.cpp

CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/hellogl2_autogen/mocs_compilation.cpp > CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.i

CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/hellogl2_autogen/mocs_compilation.cpp -o CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.s

CMakeFiles/hellogl2.dir/glwidget.cpp.o: CMakeFiles/hellogl2.dir/flags.make
CMakeFiles/hellogl2.dir/glwidget.cpp.o: /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/glwidget.cpp
CMakeFiles/hellogl2.dir/glwidget.cpp.o: CMakeFiles/hellogl2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hellogl2.dir/glwidget.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hellogl2.dir/glwidget.cpp.o -MF CMakeFiles/hellogl2.dir/glwidget.cpp.o.d -o CMakeFiles/hellogl2.dir/glwidget.cpp.o -c /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/glwidget.cpp

CMakeFiles/hellogl2.dir/glwidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellogl2.dir/glwidget.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/glwidget.cpp > CMakeFiles/hellogl2.dir/glwidget.cpp.i

CMakeFiles/hellogl2.dir/glwidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellogl2.dir/glwidget.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/glwidget.cpp -o CMakeFiles/hellogl2.dir/glwidget.cpp.s

CMakeFiles/hellogl2.dir/logo.cpp.o: CMakeFiles/hellogl2.dir/flags.make
CMakeFiles/hellogl2.dir/logo.cpp.o: /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/logo.cpp
CMakeFiles/hellogl2.dir/logo.cpp.o: CMakeFiles/hellogl2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hellogl2.dir/logo.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hellogl2.dir/logo.cpp.o -MF CMakeFiles/hellogl2.dir/logo.cpp.o.d -o CMakeFiles/hellogl2.dir/logo.cpp.o -c /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/logo.cpp

CMakeFiles/hellogl2.dir/logo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellogl2.dir/logo.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/logo.cpp > CMakeFiles/hellogl2.dir/logo.cpp.i

CMakeFiles/hellogl2.dir/logo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellogl2.dir/logo.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/logo.cpp -o CMakeFiles/hellogl2.dir/logo.cpp.s

CMakeFiles/hellogl2.dir/main.cpp.o: CMakeFiles/hellogl2.dir/flags.make
CMakeFiles/hellogl2.dir/main.cpp.o: /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/main.cpp
CMakeFiles/hellogl2.dir/main.cpp.o: CMakeFiles/hellogl2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hellogl2.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hellogl2.dir/main.cpp.o -MF CMakeFiles/hellogl2.dir/main.cpp.o.d -o CMakeFiles/hellogl2.dir/main.cpp.o -c /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/main.cpp

CMakeFiles/hellogl2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellogl2.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/main.cpp > CMakeFiles/hellogl2.dir/main.cpp.i

CMakeFiles/hellogl2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellogl2.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/main.cpp -o CMakeFiles/hellogl2.dir/main.cpp.s

CMakeFiles/hellogl2.dir/mainwindow.cpp.o: CMakeFiles/hellogl2.dir/flags.make
CMakeFiles/hellogl2.dir/mainwindow.cpp.o: /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/mainwindow.cpp
CMakeFiles/hellogl2.dir/mainwindow.cpp.o: CMakeFiles/hellogl2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/hellogl2.dir/mainwindow.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hellogl2.dir/mainwindow.cpp.o -MF CMakeFiles/hellogl2.dir/mainwindow.cpp.o.d -o CMakeFiles/hellogl2.dir/mainwindow.cpp.o -c /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/mainwindow.cpp

CMakeFiles/hellogl2.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellogl2.dir/mainwindow.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/mainwindow.cpp > CMakeFiles/hellogl2.dir/mainwindow.cpp.i

CMakeFiles/hellogl2.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellogl2.dir/mainwindow.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/mainwindow.cpp -o CMakeFiles/hellogl2.dir/mainwindow.cpp.s

CMakeFiles/hellogl2.dir/window.cpp.o: CMakeFiles/hellogl2.dir/flags.make
CMakeFiles/hellogl2.dir/window.cpp.o: /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/window.cpp
CMakeFiles/hellogl2.dir/window.cpp.o: CMakeFiles/hellogl2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/hellogl2.dir/window.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hellogl2.dir/window.cpp.o -MF CMakeFiles/hellogl2.dir/window.cpp.o.d -o CMakeFiles/hellogl2.dir/window.cpp.o -c /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/window.cpp

CMakeFiles/hellogl2.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hellogl2.dir/window.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/window.cpp > CMakeFiles/hellogl2.dir/window.cpp.i

CMakeFiles/hellogl2.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hellogl2.dir/window.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example/window.cpp -o CMakeFiles/hellogl2.dir/window.cpp.s

# Object files for target hellogl2
hellogl2_OBJECTS = \
"CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/hellogl2.dir/glwidget.cpp.o" \
"CMakeFiles/hellogl2.dir/logo.cpp.o" \
"CMakeFiles/hellogl2.dir/main.cpp.o" \
"CMakeFiles/hellogl2.dir/mainwindow.cpp.o" \
"CMakeFiles/hellogl2.dir/window.cpp.o"

# External object files for target hellogl2
hellogl2_EXTERNAL_OBJECTS =

hellogl2.app/Contents/MacOS/hellogl2: CMakeFiles/hellogl2.dir/hellogl2_autogen/mocs_compilation.cpp.o
hellogl2.app/Contents/MacOS/hellogl2: CMakeFiles/hellogl2.dir/glwidget.cpp.o
hellogl2.app/Contents/MacOS/hellogl2: CMakeFiles/hellogl2.dir/logo.cpp.o
hellogl2.app/Contents/MacOS/hellogl2: CMakeFiles/hellogl2.dir/main.cpp.o
hellogl2.app/Contents/MacOS/hellogl2: CMakeFiles/hellogl2.dir/mainwindow.cpp.o
hellogl2.app/Contents/MacOS/hellogl2: CMakeFiles/hellogl2.dir/window.cpp.o
hellogl2.app/Contents/MacOS/hellogl2: CMakeFiles/hellogl2.dir/build.make
hellogl2.app/Contents/MacOS/hellogl2: /usr/local/lib/QtOpenGLWidgets.framework/Versions/A/QtOpenGLWidgets
hellogl2.app/Contents/MacOS/hellogl2: /usr/local/lib/QtOpenGL.framework/Versions/A/QtOpenGL
hellogl2.app/Contents/MacOS/hellogl2: /usr/local/lib/QtWidgets.framework/Versions/A/QtWidgets
hellogl2.app/Contents/MacOS/hellogl2: /usr/local/lib/QtGui.framework/Versions/A/QtGui
hellogl2.app/Contents/MacOS/hellogl2: /usr/local/lib/QtCore.framework/Versions/A/QtCore
hellogl2.app/Contents/MacOS/hellogl2: CMakeFiles/hellogl2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable hellogl2.app/Contents/MacOS/hellogl2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hellogl2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hellogl2.dir/build: hellogl2.app/Contents/MacOS/hellogl2
.PHONY : CMakeFiles/hellogl2.dir/build

CMakeFiles/hellogl2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hellogl2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hellogl2.dir/clean

CMakeFiles/hellogl2.dir/depend:
	cd /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/example /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug /Users/osgreywi/Desktop/git_hub_my/3DView/src/tmpQt/build-example-Desktop_x86_darwin_generic_mach_o_64bit-Debug/CMakeFiles/hellogl2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hellogl2.dir/depend

