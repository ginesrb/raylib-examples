cmake_minimum_required(VERSION 3.11)

# Project name
project(movement)

# Dependencies
set(RAYLIB_VERSION 5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # Let CMake search in the default install path
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
      set(FETCHCONTENT_QUIET NO)
      FetchContent_Populate(raylib)
      set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
      add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

# Add the executable
add_executable(${PROJECT_NAME} ${PROJECT_NAME}/src/main.c)
target_link_libraries(${PROJECT_NAME} raylib)
