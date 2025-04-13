include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-pretarget.cmake)

set(DESCRIPTORS ${CMAKE_CURRENT_SOURCE_DIR}/../descriptors~)

include_directories( 
	"${MAX_SDK_INCLUDES}"
	"${MAX_SDK_MSP_INCLUDES}"
	"${MAX_SDK_JIT_INCLUDES}"
	"${COMMON_INCLUDES}"
	${DESCRIPTORS}
	${DESCRIPTORS}/library
	${DESCRIPTORS}/modules
)

add_library( 
	${PROJECT_NAME} 
	MODULE
	descriptors_rt.cpp
	${DESCRIPTORS}/descriptors_graph.cpp
	${DESCRIPTORS}/modules/modules_core.cpp
	${DESCRIPTORS}/modules/modules_change.cpp
	${DESCRIPTORS}/modules/modules_content.cpp
	${DESCRIPTORS}/modules/modules_level.cpp
	${DESCRIPTORS}/modules/modules_pitch.cpp
	${DESCRIPTORS}/modules/modules_spectral.cpp
)

target_link_libraries(
	${PROJECT_NAME}
	PUBLIC
	hisstools
	"-framework Accelerate"
)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-posttarget.cmake)




