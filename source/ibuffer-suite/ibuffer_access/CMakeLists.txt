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

target_compile_definitions(
    ibuffer_access
    PRIVATE
    $<$<PLATFORM_ID:Darwin>:NDEBUG>
    $<$<PLATFORM_ID:Windows>:NOMINMAX>
    $<$<PLATFORM_ID:Windows>:_USE_MATH_DEFINES>
    $<$<PLATFORM_ID:Windows>:WIN_VERSION>
    $<$<PLATFORM_ID:Windows>:WIN64>
    $<$<PLATFORM_ID:Windows>:_WINDOWS>
    $<$<PLATFORM_ID:Windows>:_USERDLL>
    $<$<PLATFORM_ID:Windows>:WIN_EXT_VERSION>
    $<$<PLATFORM_ID:Windows>:_CRT_SECURE_NO_WARNINGS>
)