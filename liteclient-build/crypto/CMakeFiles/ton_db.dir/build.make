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
include crypto/CMakeFiles/ton_db.dir/depend.make

# Include the progress variables for this target.
include crypto/CMakeFiles/ton_db.dir/progress.make

# Include the compile flags for this target's objects.
include crypto/CMakeFiles/ton_db.dir/flags.make

crypto/CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.o: crypto/CMakeFiles/ton_db.dir/flags.make
crypto/CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.o: /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/DynamicBagOfCellsDb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alexzhang/Documents/TON/official/liteclient-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object crypto/CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.o"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.o -c /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/DynamicBagOfCellsDb.cpp

crypto/CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.i"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/DynamicBagOfCellsDb.cpp > CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.i

crypto/CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.s"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/DynamicBagOfCellsDb.cpp -o CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.s

crypto/CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.o: crypto/CMakeFiles/ton_db.dir/flags.make
crypto/CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.o: /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/CellStorage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alexzhang/Documents/TON/official/liteclient-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object crypto/CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.o"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.o -c /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/CellStorage.cpp

crypto/CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.i"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/CellStorage.cpp > CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.i

crypto/CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.s"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/CellStorage.cpp -o CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.s

crypto/CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.o: crypto/CMakeFiles/ton_db.dir/flags.make
crypto/CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.o: /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/TonDb.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/alexzhang/Documents/TON/official/liteclient-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object crypto/CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.o"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.o -c /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/TonDb.cpp

crypto/CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.i"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/TonDb.cpp > CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.i

crypto/CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.s"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/alexzhang/Documents/TON/official/lite-client/crypto/vm/db/TonDb.cpp -o CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.s

# Object files for target ton_db
ton_db_OBJECTS = \
"CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.o" \
"CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.o" \
"CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.o"

# External object files for target ton_db
ton_db_EXTERNAL_OBJECTS =

crypto/libton_db.a: crypto/CMakeFiles/ton_db.dir/vm/db/DynamicBagOfCellsDb.cpp.o
crypto/libton_db.a: crypto/CMakeFiles/ton_db.dir/vm/db/CellStorage.cpp.o
crypto/libton_db.a: crypto/CMakeFiles/ton_db.dir/vm/db/TonDb.cpp.o
crypto/libton_db.a: crypto/CMakeFiles/ton_db.dir/build.make
crypto/libton_db.a: crypto/CMakeFiles/ton_db.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/alexzhang/Documents/TON/official/liteclient-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libton_db.a"
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && $(CMAKE_COMMAND) -P CMakeFiles/ton_db.dir/cmake_clean_target.cmake
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ton_db.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
crypto/CMakeFiles/ton_db.dir/build: crypto/libton_db.a

.PHONY : crypto/CMakeFiles/ton_db.dir/build

crypto/CMakeFiles/ton_db.dir/clean:
	cd /Users/alexzhang/Documents/TON/official/liteclient-build/crypto && $(CMAKE_COMMAND) -P CMakeFiles/ton_db.dir/cmake_clean.cmake
.PHONY : crypto/CMakeFiles/ton_db.dir/clean

crypto/CMakeFiles/ton_db.dir/depend:
	cd /Users/alexzhang/Documents/TON/official/liteclient-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/alexzhang/Documents/TON/official/lite-client /Users/alexzhang/Documents/TON/official/lite-client/crypto /Users/alexzhang/Documents/TON/official/liteclient-build /Users/alexzhang/Documents/TON/official/liteclient-build/crypto /Users/alexzhang/Documents/TON/official/liteclient-build/crypto/CMakeFiles/ton_db.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : crypto/CMakeFiles/ton_db.dir/depend

