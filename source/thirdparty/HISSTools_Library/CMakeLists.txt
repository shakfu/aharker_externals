

add_library(
	hisstools
	SHARED
	AudioFile/BaseAudioFile.cpp
	AudioFile/IAudioFile.cpp
	AudioFile/OAudioFile.cpp
	AudioFile/BaseAudioFile.h
	AudioFile/IAudioFile.h
	AudioFile/OAudioFile.h
	HIRT_Multichannel_Convolution/ConvolveErrors.h
	HIRT_Multichannel_Convolution/Convolver.cpp
	HIRT_Multichannel_Convolution/Convolver.h
	HIRT_Multichannel_Convolution/ConvolveSIMD.h
	HIRT_Multichannel_Convolution/MemorySwap.h
	HIRT_Multichannel_Convolution/MonoConvolve.cpp
	HIRT_Multichannel_Convolution/MonoConvolve.h
	HIRT_Multichannel_Convolution/NToMonoConvolve.cpp
	HIRT_Multichannel_Convolution/NToMonoConvolve.h
	HIRT_Multichannel_Convolution/PartitionedConvolve.cpp
	HIRT_Multichannel_Convolution/PartitionedConvolve.h
	HIRT_Multichannel_Convolution/TimeDomainConvolve.cpp
	HIRT_Multichannel_Convolution/TimeDomainConvolve.h
	HISSTools_FFT/HISSTools_FFT_Core.h
	HISSTools_FFT/HISSTools_FFT.cpp
	HISSTools_FFT/HISSTools_FFT.h
	Allocator.hpp
	Interpolation.hpp
	KernelSmoother.hpp
	PartialTracker.hpp
	RandomGenerator.hpp
	SIMDSupport.hpp
	SpectralFunctions.hpp
	SpectralProcessor.hpp
	Statistics.hpp
	TableReader.hpp
	ThreadLocks.hpp
	WindowFunctions.hpp
)

target_compile_options(
    ibuffer_access
    PRIVATE
    $<$<PLATFORM_ID:Windows>:/O2>
    $<$<PLATFORM_ID:Windows>:/MT>
    # $<$<PLATFORM_ID:Darwin>:-Wmost>
    # $<$<PLATFORM_ID:Darwin>:-Wno-four-char-constants>
    # $<$<PLATFORM_ID:Darwin>:-Wno-unknown-pragmas>
    # $<$<PLATFORM_ID:Darwin>:-Wdeclaration-after-statement>
    # $<$<PLATFORM_ID:Darwin>:-fvisibility=hidden>
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




