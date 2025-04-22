# AHarker Externals

A Set of 80+ Externals for a variety of tasks in Cycling 74's Max by Alex Harker.

## FORK NOTE

This is a friendly fork of [Alex Harker's externals project](https://github.com/AlexHarker/AHarker_Externals/). The key improvements (mostly tested on MacOS so far) are:

- [CMake](https://cmake.org)-based cross-platform building. 

- Added a `Makefile` to call cmake, so just `make` to build everything on MacOS.

- All dependencies included.

	- Included `max-sdk-base` as git submodule (`make setup` after `git clone`)

	- Added missing dependencies such as `HISSTools_Library`.

- Each external has been moved to its own folder.

- Some modifications to make it possible to build on Max SDK 8.20 (see below)

Conversion completed:

- [x] conversion
- [x] convolution
- [x] descriptors (see important note about `entrymatcher` above)
- [x] dynamic-suite
- [x] gesture-suite
- [x] ibuffer-suite
- [x] miscellaneous [^1]
- [x] random-numbers
- [x] sample-accurate-suite
- [x] threading
- [x] utility
- [x] vMSP

[^1]: `ajh.wiiremote` is not converted because some of the `IOBluetooth.framework` c-apis it uses are deprecated with only objc api replacements available.

## Overview


A Set of 80+ Externals for a variety of tasks in Cycling 74's Max by Alex Harker

Overview:

- general purpose scaling for Max and MSP

- efficient partitioned + non-partitioned convolution

- comprehensive descriptor analysis (realtime + non-realtime)

- enhanced audio multi-threading / dynamic patch loading

- efficient buffer playback and storage

- high quality random number generators for Max and MSP

- sample accurate voice management and more

- thread debugging and switching

- utility objects

- SIMD versions of 35 basic MSP objects

AHarker Externals:

- support Mac and Windows in 64bit, including support for Apple Silicon (M1) processors.

- are licensed under the 3-clause BSD license.

Enjoy!

Alex

## Package Releases / Binaries


- At this time alpha releases are available via GitHub **[releases](https://github.com/AlexHarker/AHarker_Externals/releases)**. 

- Until official release some objects interfaces may change.

- Please note that the behaviour of *descriptors~ / descriptorsrt~* may differ from earlier versions. 

- Please report any issues with the issues page on GitHub. 

## Compiling

Should you wish to compile the externals yourself you will require the following:

### MacOS

1. Xcode
2. The max-sdk-base repository (https://github.com/Cycling74/max-sdk-base)

*Notes*

- The `max-sdk-base` repository main folder should be located next to (in the same enclosing folder as) the main folder for this repository.

- The location for the `max-sdk-base` can be modified in `Config_AHarker_Externals.xcconfig` if desired.

- AVX / SSE support can also be toggled in `Config_AHarker_Externals.xcconfig` (for old machines, or Rosetta 2 support).

### Windows

1. Visual Studio

2. OneMKL *or* OneAPI Base Toolkit (which includes OneMKL)
    
    - <https://www.intel.com/content/www/us/en/developer/tools/oneapi/onemkl-download.html>
	
	- <https://www.intel.com/content/www/us/en/developer/tools/oneapi/base-toolkit-download.html>
  
3. The max-sdk-base repository (https://github.com/Cycling74/max-sdk-base)

**Notes**

- The `max-sdk-base` repository main folder should be located next to (in the same enclosing folder as) the main folder for this repository.

- The location for the `max-sdk-base` can be modified in AH_Win_Debug.props / AH_Win_Release.props if desired.

## Contact


- <ajharker@gmail.com>

- <http://www.alexanderjharker.co.uk/>
