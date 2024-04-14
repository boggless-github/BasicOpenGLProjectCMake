cmake_minimum_required(VERSION 3.10)
project(BasicOpenGLProject)
find_package(OpenGL)

# Ensure that we've got a supported architecture, and determine 64 bit or 32 bit.
if(CMAKE_SIZEOF_VOID_P EQUAL 8) # 64 bit
    if(CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64" OR CMAKE_SYSTEM_PROCESSOR STREQUAL "AMD64")
        # 64-bit x86 architecture
        set(IS_64_BIT true)
        message(STATUS "Supported architector found: x86_64/AMD64")
    else()
        message(FATAL_ERROR "Unsupported architecture: ${CMAKE_SYSTEM_PROCESSOR}")
    endif()
elseif(CMAKE_SIZEOF_VOID_P EQUAL 4) # 32 bit
    if(CMAKE_SYSTEM_PROCESSOR STREQUAL "i386")
        # 32-bit x86 architecture
        message("i386 architecture")
    else()
        message(FATAL_ERROR "Unsupported architecture: ${CMAKE_SYSTEM_PROCESSOR}")
    endif()
else()
    message(FATAL_ERROR "Unknown architecture")
endif()

# Set to output the files in out
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out CACHE STRING "")

# Create the project under the src directory.
add_subdirectory(src)
