include(${CMAKE_SOURCE_DIR}/cmake/pr_common.cmake)

set(PROJ_NAME util_versioned_archive)
pr_add_library(${PROJ_NAME} STATIC)

pr_add_dependency(${PROJ_NAME} vfilesystem TARGET PUBLIC)
pr_add_dependency(${PROJ_NAME} bz2 TARGET)

pr_init_module(${PROJ_NAME})

pr_add_compile_definitions(
	${PROJ_NAME}
		-DUVA_STATIC
)

pr_finalize(${PROJ_NAME})
