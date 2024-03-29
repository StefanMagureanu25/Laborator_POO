cmake_minimum_required(VERSION 3.15)

# NOTE: update executable name in .github/workflows/cmake.yml when changing executable name in this file
# for now, the project name is used as the executable name
project(oop)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

###############################################################################

# external dependencies
#include(FetchContent)
#
#FetchContent_Declare(
#        SomeLib
#        GIT_REPOSITORY https://github.com/<SomeUser>/<SomeLib>.git
#        GIT_TAG        <some_git_hash> # <which tag/branch @ <some_date>>
#)
#
#FetchContent_MakeAvailable(SomeLib)

###############################################################################

# NOTE: update executable name in .github/workflows/cmake.yml when changing name here
#am pus problema bunicuta pe executabilul pentru proiect
add_executable(${PROJECT_NAME} main.cpp Persoana.cpp Abonat.cpp Dosar.cpp Meniu.cpp)
add_executable(tema0 tema0.cpp)
add_executable(tema1 tema1.cpp)
add_executable(circuit circuit.cpp)
###############################################################################

# custom compiler flags
message("Compiler: ${CMAKE_CXX_COMPILER_ID} version ${CMAKE_CXX_COMPILER_VERSION}")
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)

    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        target_compile_options(${PROJECT_NAME} PRIVATE -stdlib=libstdc++)
    elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
        target_compile_options(${PROJECT_NAME} PRIVATE -stdlib=libc++)
    endif()
endif()

###############################################################################

# sanitizers
# should disable them when releasing executables
if(APPLE)
    # if("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    # first check Apple since Apple is also a kind of Unix
    target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
    target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
    # endif()
elseif(UNIX)
    if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
        # we cannot mix sanitizers with Valgrind
    elseif("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
        if("${CMAKE_CXX_COMPILER_VERSION}" MATCHES "10.")
            # check leaks on Linux since macOS does not support the leaks sanitizer yet
            # leaks sanitizer is enabled by default on Linux, so we do not need to enable it explicitly
            target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
            target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=address,undefined)
        else()
            target_compile_options(${PROJECT_NAME} PRIVATE -fsanitize=memory,undefined)
            target_link_options(${PROJECT_NAME} PRIVATE -fsanitize=memory,undefined)
        endif()
    endif()
endif()

###############################################################################

# use SYSTEM so clang-tidy does not report warnings from these directories
#target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${<SomeLib>_SOURCE_DIR}/include)
#target_link_directories(${PROJECT_NAME} PRIVATE ${<SomeLib>_BINARY_DIR}/lib)
#target_link_libraries(${PROJECT_NAME} <SomeLib>)

###############################################################################

# copy binaries to bin folder; these are uploaded as artifacts on each release
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
# install(DIRECTORY some_dir1 some_dir2 DESTINATION bin)
# install(FILES some_file1.txt some_file2.md DESTINATION bin)
