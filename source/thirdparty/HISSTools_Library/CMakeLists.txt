

add_library(
	hisstools
	STATIC
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




