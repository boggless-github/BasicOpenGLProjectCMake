

# This is our main executable, add sources(.cpp) here.
set (MY_SRCS 
    main.cpp
    memzero.cpp # an example on how to add another c++ file
    )
add_executable(${PROJECT_NAME} ${MY_SRCS})

# Find freeglut
find_path(FREEGLUT_INCLUDE_DIR NAMES GL/freeglut.h PATHS ${CMAKE_SOURCE_DIR}/freeglut/include)
if(NOT FREEGLUT_INCLUDE_DIR)
    message(FATAL_ERROR "Freeglut headers not found! Looked from ${CMAKE_SOURCE_DIR}")
endif()

# OS Specific Configuration
if(WIN32)
    # Windows uses the 'freeglut' library, and it's both a .lib and a .dll
    # Set freeglut libraries for x86 and x64 platforms
    if(IS_64_BIT)
        # Look for the x64 bit freeglut library
        find_library(FREEGLUT_LIB NAMES freeglut PATHS "${CMAKE_SOURCE_DIR}/freeglut/lib/x64")
        if (NOT FREEGLUT_LIB)
            message(FATAL_ERROR "Freeglut lib couldn't be found.")
        endif()
        # Look for the x64 bit freeglut dll
        find_path(FREEGLUT_DLL_DIR NAMES freeglut.dll PATHS "${CMAKE_SOURCE_DIR}/freeglut/bin/x64")
        if (NOT FREEGLUT_DLL_DIR)
            message(FATAL_ERROR "Freeglut dll couldn't be found.")
        endif()
    else()
        # Look for the x64 bit freeglut library
        find_library(FREEGLUT_LIB NAMES freeglut PATHS "${CMAKE_SOURCE_DIR}/freeglut/lib/")
        if (NOT FREEGLUT_LIB)
            message(FATAL_ERROR "Freeglut lib couldn't be found.")
        endif()
        # Look for the x64 bit freeglut dll
        find_path(FREEGLUT_DLL_DIR NAMES freeglut.dll PATHS ${CMAKE_SOURCE_DIR}/freeglut/bin)
        if (NOT FREEGLUT_DLL_DIR)
            message(FATAL_ERROR "Freeglut dll couldn't be found.")
        endif()
    endif()
    # On Windows we need to have the exe and dll in the same directory, or
    # the dll needs to be on the $PATH environment variable.
    # Copy freeglut.dll to the output directory
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${FREEGLUT_DLL_DIR}/freeglut.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
elseif(UNIX)
    # For Linux/Unix, just install libglut with a package manager.
    set(FREEGLUT_LIB "libglut")
endif()

# Add include directory
target_include_directories(${PROJECT_NAME} PUBLIC ${FREEGLUT_INCLUDE_DIR} PUBLIC "${CMAKE_SOURCE_DIR}/inc")

# Link OpenGL and freeglut libraries
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARY} ${FREEGLUT_LIB})
