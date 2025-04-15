# AHarker Externals

A Set of 80+ Externals for a variety of tasks in Cycling 74's Max.


## FORK NOTE

This is a friendly fork of [Alex Harker's externals project](https://github.com/AlexHarker/AHarker_Externals/). The key improvements (only tested on MacOS so far) are:

- [CMake](https://cmake.org)-based building.

- Added a `Makefile` to call cmake, so just `make` to build everything on MacOS.

- All dependencies included.

	- Included `max-sdk-base` as git submodule (`make setup` after `git clone`)

	- Added missing dependencies such as `HISSTools_Library`.

- Each external has been moved to its own folder.

- Some modifications to make it possible to build on Max SDK 8.20 (see below)


**IMPORTANT NOTE**: the following api functions from `jdataview.h`: `jdataview_getselectedrowsforview`,  `jdataview_redrawcolumn`, and `jdataview_selectedrowcount`, which are used in `source/descriptos/entrymatcher/database_view.cpp` may trigger an `Undefined symbols` error during compilation. If that happens, run `./source/scripts/regen_linker_flags.sh` to sync up the two `*-linker-flags.txt` in the `max-sdk-base`. This is known issue as per this [forum post](https://cycling74.com/forums/missing-jdataview-methods-in-max-sdk-820?replyPage=1#reply-67fdbe503bd53f00135c8827) and will likely get fixed in another iteration of  `max-sdk-base`. not be found so these have been disabled in `entrymatcher/database_view.cpp`. The `make setup`, which is run once post-cloning to update the `max-sdk-base` submodule and symlink the cloned directory to the `Packages` directory of Max 9 will also run this script once. (Thanks to Rob Ramirez and Joshua Kit Clayton for help in identifying and resolving this issue!)


Conversion completed:

- [x] conversion
- [x] convolution
- [x] descriptors (see important note about `entrymatcher` above)
- [x] dynamic-suite[^1]
- [x] gesture-suite
- [x] ibuffer-suite
- [x] miscellaneous
- [x] random-numbers
- [x] sample-accurate-suite
- [x] threading
- [x] utility
- [x] vMSP


[^1]: In `dynamic-suite/Common/thread_set.cpp`, the use of `mach_task_self()` was not possible and was replaced with `pthread_mach_thread_np(pthread_self()` as per recommendation by [accepted answer](https://developer.apple.com/forums/thread/703361) and [this review](https://codereview.chromium.org/276043002/)


## Some Areas Addressed:

- general purpose scaling for Max and MSP
- efficient partitioned + non- partitioned convolution
- comprehensive descriptor analysis (realtime + non-realtime)
- enhanced audio multi-threading / dynamic patch loading
- efficient buffer playback and storage
- high quality random number generators for Max and MSP
- sample accurate voice management and more
- thread debugging and switching
- utility objects
- SIMD versions of 35 basic MSP objects

## AHarker Externals Online:

- To access the source code: https://github.com/AlexHarker/AHarker_Externals/

- FrameLib can be discussed at https://framelib.discourse.group

## Credits:

- **AHarker Externals** by *Alex Harker* <br>

## AHarker Externals makes use of:

- Code for calculating roughness by *Richard Parncutt* and published with permission.

- Code for calcutaing the lower tail quantile for a normal distribution function by *Peter J. Acklam* / *Chad Sprouse* (C port from PERL code)


## Contact:

- ajharker@gmail.com
