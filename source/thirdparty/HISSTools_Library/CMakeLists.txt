

add_library(
	hisstools
	STATIC
	AudioFile/BaseAudioFile.cpp
	AudioFile/IAudioFile.cpp
	AudioFile/OAudioFile.cpp
	HIRT_Multichannel_Convolution/Convolver.cpp
	HIRT_Multichannel_Convolution/ConvolveSIMD.h
	HIRT_Multichannel_Convolution/MonoConvolve.cpp
	HIRT_Multichannel_Convolution/NToMonoConvolve.cpp
	HIRT_Multichannel_Convolution/PartitionedConvolve.cpp
	HIRT_Multichannel_Convolution/TimeDomainConvolve.cpp
	HISSTools_FFT/HISSTools_FFT.cpp
)

target_include_directories(
    hisstools
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/AudioFile
    ${CMAKE_CURRENT_SOURCE_DIR}/HISSTools_FFT
    ${CMAKE_CURRENT_SOURCE_DIR}/HIRT_Multichannel_Convolution
)

target_compile_options(
    hisstools
    PRIVATE
    $<$<PLATFORM_ID:Windows>:/O2>
    $<$<PLATFORM_ID:Windows>:/MT>
    $<$<PLATFORM_ID:Darwin>:-Wmost>
    $<$<PLATFORM_ID:Darwin>:-Wno-four-char-constants>
    $<$<PLATFORM_ID:Darwin>:-Wno-unknown-pragmas>
    $<$<PLATFORM_ID:Darwin>:-Wdeclaration-after-statement>
    $<$<PLATFORM_ID:Darwin>:-fvisibility=hidden>
)

target_compile_definitions(
    hisstools
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




