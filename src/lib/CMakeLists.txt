assign_source_group(${SOURCE_FILES})
add_library(CL_LIBRARY ${SOURCE_FILES})
target_link_libraries(CL_LIBRARY
	${OpenCL_LIBRARY}
)
