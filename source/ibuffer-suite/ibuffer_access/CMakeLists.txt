include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-pretarget.cmake)

include_directories(
	"${MAX_SDK_INCLUDES}"
	"${MAX_SDK_MSP_INCLUDES}"
	"${MAX_SDK_JIT_INCLUDES}"
	"${COMMON_INCLUDES}"
)


add_library( 
	ibuffer_access
	STATIC
	${COMMON_INCLUDES}/ibuffer_access.cpp
)
