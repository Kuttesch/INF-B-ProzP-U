# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2023.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bruchrechnung.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bruchrechnung.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bruchrechnung.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bruchrechnung.dir/flags.make

CMakeFiles/bruchrechnung.dir/mainfile.c.obj: CMakeFiles/bruchrechnung.dir/flags.make
CMakeFiles/bruchrechnung.dir/mainfile.c.obj: D:/Github/INF-B-ProzP-U/06-bruchrechnung/bruchrechnung/mainfile.c
CMakeFiles/bruchrechnung.dir/mainfile.c.obj: CMakeFiles/bruchrechnung.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bruchrechnung.dir/mainfile.c.obj"
	"E:\CLion 2023.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bruchrechnung.dir/mainfile.c.obj -MF CMakeFiles\bruchrechnung.dir\mainfile.c.obj.d -o CMakeFiles\bruchrechnung.dir\mainfile.c.obj -c D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\mainfile.c

CMakeFiles/bruchrechnung.dir/mainfile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bruchrechnung.dir/mainfile.c.i"
	"E:\CLion 2023.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\mainfile.c > CMakeFiles\bruchrechnung.dir\mainfile.c.i

CMakeFiles/bruchrechnung.dir/mainfile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bruchrechnung.dir/mainfile.c.s"
	"E:\CLion 2023.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\mainfile.c -o CMakeFiles\bruchrechnung.dir\mainfile.c.s

CMakeFiles/bruchrechnung.dir/rational.c.obj: CMakeFiles/bruchrechnung.dir/flags.make
CMakeFiles/bruchrechnung.dir/rational.c.obj: D:/Github/INF-B-ProzP-U/06-bruchrechnung/bruchrechnung/rational.c
CMakeFiles/bruchrechnung.dir/rational.c.obj: CMakeFiles/bruchrechnung.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/bruchrechnung.dir/rational.c.obj"
	"E:\CLion 2023.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/bruchrechnung.dir/rational.c.obj -MF CMakeFiles\bruchrechnung.dir\rational.c.obj.d -o CMakeFiles\bruchrechnung.dir\rational.c.obj -c D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\rational.c

CMakeFiles/bruchrechnung.dir/rational.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bruchrechnung.dir/rational.c.i"
	"E:\CLion 2023.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\rational.c > CMakeFiles\bruchrechnung.dir\rational.c.i

CMakeFiles/bruchrechnung.dir/rational.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bruchrechnung.dir/rational.c.s"
	"E:\CLion 2023.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\rational.c -o CMakeFiles\bruchrechnung.dir\rational.c.s

# Object files for target bruchrechnung
bruchrechnung_OBJECTS = \
"CMakeFiles/bruchrechnung.dir/mainfile.c.obj" \
"CMakeFiles/bruchrechnung.dir/rational.c.obj"

# External object files for target bruchrechnung
bruchrechnung_EXTERNAL_OBJECTS =

bruchrechnung.exe: CMakeFiles/bruchrechnung.dir/mainfile.c.obj
bruchrechnung.exe: CMakeFiles/bruchrechnung.dir/rational.c.obj
bruchrechnung.exe: CMakeFiles/bruchrechnung.dir/build.make
bruchrechnung.exe: CMakeFiles/bruchrechnung.dir/linkLibs.rsp
bruchrechnung.exe: CMakeFiles/bruchrechnung.dir/objects1.rsp
bruchrechnung.exe: CMakeFiles/bruchrechnung.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable bruchrechnung.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bruchrechnung.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bruchrechnung.dir/build: bruchrechnung.exe
.PHONY : CMakeFiles/bruchrechnung.dir/build

CMakeFiles/bruchrechnung.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bruchrechnung.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bruchrechnung.dir/clean

CMakeFiles/bruchrechnung.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\cmake-build-debug D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\cmake-build-debug D:\Github\INF-B-ProzP-U\06-bruchrechnung\bruchrechnung\cmake-build-debug\CMakeFiles\bruchrechnung.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bruchrechnung.dir/depend

