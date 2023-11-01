
# Kinda arbitrary choice here.
cmake_minimum_required(VERSION 3.21)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Tine for project specs.
project(
    fern-lang
    VERSION 1.0
    DESCRIPTION "Compiler Toolchain for fern-os"
    LANGUAGES CXX 
)

# specify the C++ standard
add_library(ReqCompilerFlags INTERFACE)
target_compile_features(ReqCompilerFlags INTERFACE cxx_std_20)

# add compiler warning flags just when building this project via
# the BUILD_INTERFACE genex
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(ReqCompilerFlags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

enable_testing()

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(flc src/main.cpp)
target_link_libraries(flc 
    PUBLIC ReqCompilerFlags
    
    # Add stuff soon.
)
