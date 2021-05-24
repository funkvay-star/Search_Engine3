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
CMAKE_SOURCE_DIR = /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler/build

# Include any dependencies generated for this target.
include CMakeFiles/Crawler.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Crawler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Crawler.dir/flags.make

CMakeFiles/Crawler.dir/Crawler.cpp.o: CMakeFiles/Crawler.dir/flags.make
CMakeFiles/Crawler.dir/Crawler.cpp.o: ../Crawler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Crawler.dir/Crawler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Crawler.dir/Crawler.cpp.o -c /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler/Crawler.cpp

CMakeFiles/Crawler.dir/Crawler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Crawler.dir/Crawler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler/Crawler.cpp > CMakeFiles/Crawler.dir/Crawler.cpp.i

CMakeFiles/Crawler.dir/Crawler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Crawler.dir/Crawler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler/Crawler.cpp -o CMakeFiles/Crawler.dir/Crawler.cpp.s

# Object files for target Crawler
Crawler_OBJECTS = \
"CMakeFiles/Crawler.dir/Crawler.cpp.o"

# External object files for target Crawler
Crawler_EXTERNAL_OBJECTS =

Crawler: CMakeFiles/Crawler.dir/Crawler.cpp.o
Crawler: CMakeFiles/Crawler.dir/build.make
Crawler: PageLoader/libPageLoader.so
Crawler: HTMLDocument/libHTMLDocument.so
Crawler: InfoExtractor/libInfoExtractor.so
Crawler: LinkRepository/libLinkRepository.so
Crawler: WebRepository/libWebRepository.so
Crawler: DocumentRepository/libDocumentRepository.so
Crawler: CMakeFiles/Crawler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Crawler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Crawler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Crawler.dir/build: Crawler

.PHONY : CMakeFiles/Crawler.dir/build

CMakeFiles/Crawler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Crawler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Crawler.dir/clean

CMakeFiles/Crawler.dir/depend:
	cd /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler/build /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler/build /home/funkvay/Desktop/SearchEngine_Final3/Project/Crawler/build/CMakeFiles/Crawler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Crawler.dir/depend

