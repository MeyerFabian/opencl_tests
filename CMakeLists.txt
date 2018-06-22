# Minimal version of CMake
 
cmake_minimum_required (VERSION 3.0.1)

function(assign_source_group)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
        else()
            set(source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction(assign_source_group)

# Define project name
project (Minimal_OpenCL)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake CACHE PATH "Project specific path. Set manually if it was not found.")
 
find_package( OpenCL REQUIRED )

include_directories( ${OpenCL_INCLUDE_DIR} )

file(GLOB_RECURSE SOURCE_FILES "src/lib/*.cpp" "src/lib/*.h")
 
# Compiler flags
if (CMAKE_COMPILER_IS_GNUCC)
    set (CMAKE_CXX_FLAGS "-D_REETRANT -Wall -Wextra -pedantic -Wno-long-long")
	if (CMAKE_BUILD_TYPE STREQUAL "Debug")
   	    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -O0")
	elseif( CMAKE_BUILD_TYPE STREQUAL "Release" )
	    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNDEBUG -O3 -fno-strict-aliasing")
	endif ()
endif (CMAKE_COMPILER_IS_GNUCC)


# Set up executable
add_executable (minimial_opencl 
src/main/main.cpp
)
target_link_libraries(minimial_opencl 
CL_LIBRARY
)


add_subdirectory(src/lib)

get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

