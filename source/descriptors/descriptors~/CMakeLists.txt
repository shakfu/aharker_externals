include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-pretarget.cmake)

include_directories( 
	"${MAX_SDK_INCLUDES}"
	"${MAX_SDK_MSP_INCLUDES}"
	"${MAX_SDK_JIT_INCLUDES}"
	"${COMMON_INCLUDES}"
	${CMAKE_CURRENT_SOURCE_DIR}/library
	${CMAKE_CURRENT_SOURCE_DIR}/modules
)

add_library( 
	${PROJECT_NAME} 
	MODULE
	descriptors_non_rt.cpp
	descriptors_graph.cpp
	descriptors_summary_graph.cpp
	modules/modules_core.cpp
	modules/modules_change.cpp
	modules/modules_content.cpp
	modules/modules_level.cpp
	modules/modules_pitch.cpp
	modules/modules_spectral.cpp
	modules/modules_summary.cpp
)

target_link_libraries(
	${PROJECT_NAME}
	PUBLIC
	ibuffer_access
	hisstools
	"-framework Accelerate"
)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-posttarget.cmake)




