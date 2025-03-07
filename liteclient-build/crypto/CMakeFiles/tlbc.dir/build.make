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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alexzhang/Documents/TON/official/lite-client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alexzhang/Documents/TON/official/liteclient-build

# Include any dependencies generated for this target.
include crypto/CMakeFiles/tlbc.dir/depend.make

# Include the progress variables for this target.
include crypto/CMakeFiles/tlbc.dir/progress.make

# Include the compile flags for this target's objects.
include crypto/CMakeFiles/tlbc.dir/flags.make

crypto/CMakeFiles/tlbc.dir/tl/tlbc.cpp.o: crypto/CMakeFiles/tlbc.dir/flags.make
crypto/CMakeFiles/tlbc.dir/tl/tlbc.cpp.o: /Users/alexzhang/Documents/TON/official/lite-client/crypto/tl/tlbc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alexzhang/Documents/TON/official/liteclient-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object crypto/CMakeFiles/tlbc.dir/tl/tlbc.cpp.o"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tlbc.dir/tl/tlbc.cpp.o -c /Users/alexzhang/Documents/TON/official/lite-client/crypto/tl/tlbc.cpp

crypto/CMakeFiles/tlbc.dir/tl/tlbc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tlbc.dir/tl/tlbc.cpp.i"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexzhang/Documents/TON/official/lite-client/crypto/tl/tlbc.cpp > CMakeFiles/tlbc.dir/tl/tlbc.cpp.i

crypto/CMakeFiles/tlbc.dir/tl/tlbc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tlbc.dir/tl/tlbc.cpp.s"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexzhang/Documents/TON/official/lite-client/crypto/tl/tlbc.cpp -o CMakeFiles/tlbc.dir/tl/tlbc.cpp.s

# Object files for target tlbc
tlbc_OBJECTS = \
"CMakeFiles/tlbc.dir/tl/tlbc.cpp.o"

# External object files for target tlbc
tlbc_EXTERNAL_OBJECTS =

crypto/tlbc: crypto/CMakeFiles/tlbc.dir/tl/tlbc.cpp.o
crypto/tlbc: crypto/CMakeFiles/tlbc.dir/build.make
crypto/tlbc: crypto/libton_crypto.a
crypto/tlbc: tdutils/libtdutils.a
crypto/tlbc: /usr/lib/libcrypto.dylib
crypto/tlbc: /usr/lib/libz.dylib
crypto/tlbc: third-party/crc32c/libcrc32c.a
crypto/tlbc: crypto/CMakeFiles/tlbc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alexzhang/Documents/TON/official/liteclient-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tlbc"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tlbc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
crypto/CMakeFiles/tlbc.dir/build: crypto/tlbc

.PHONY : crypto/CMakeFiles/tlbc.dir/build

crypto/CMakeFiles/tlbc.dir/clean:
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && $(CMAKE_COMMAND) -P CMakeFiles/tlbc.dir/cmake_clean.cmake
.PHONY : crypto/CMakeFiles/tlbc.dir/clean

crypto/CMakeFiles/tlbc.dir/depend:
	cd /Users/alexzhang/Documents/TON/official/liteclient-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alexzhang/Documents/TON/official/lite-client /Users/alexzhang/Documents/TON/official/lite-client/crypto /Users/alexzhang/Documents/TON/official/liteclient-build /Users/alexzhang/Documents/TON/official/liteclient-build/crypto /Users/alexzhang/Documents/TON/official/liteclient-build/crypto/CMakeFiles/tlbc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : crypto/CMakeFiles/tlbc.dir/depend

