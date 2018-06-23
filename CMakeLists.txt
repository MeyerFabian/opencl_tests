# tested against MSVC, mingw64, nmake/cl(compile_commands activated) 
cmake_minimum_required (VERSION 3.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

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
set(APPNAME minimial_opencl)
find_package(OpenCL REQUIRED )

include_directories( ${OpenCL_INCLUDE_DIR} )

file(GLOB_RECURSE SOURCE_FILES "src/lib/*.cpp" "src/lib/*.hpp")

# Set up executable
add_executable (${APPNAME} 
src/main/main.cpp
)
target_link_libraries(${APPNAME}
CL_LIBRARY
${OpenCL_LIBRARY}
)
#DEBUG
get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()

add_subdirectory(src/lib)

#OVERWRITE in your path_to_cmake\Modules\Platform\Windows.cmake to use compile_commands
#
#set(CMAKE_START_TEMP_FILE "")
#set(CMAKE_END_TEMP_FILE "")
#
#SEE https://gitlab.kitware.com/cmake/cmake/issues/17482
if(CMAKE_GENERATOR MATCHES "NMake")
	add_custom_command(TARGET ${APPNAME} PRE_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy  ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}
	)
ENDIF()




