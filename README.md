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

Conversion completed:

- [x] conversion
- [x] convolution
- [x] descriptors (see important note about `entrymatcher` above)
- [x] dynamic-suite
- [x] gesture-suite
- [x] ibuffer-suite
- [x] miscellaneous
- [x] random-numbers
- [x] sample-accurate-suite
- [x] threading
- [x] utility
- [x] vMSP

### IMPORTANT NOTE

This project uses a [modified max-sdk-base](https://github.com/shakfu/max-sdk-base) as a submodule which fixes a linking error in `max-sdk-base` which was flagged and resolved in this [forum post](https://cycling74.com/forums/missing-jdataview-methods-in-max-sdk-820?replyPage=1#reply-67fdbe503bd53f00135c8827). (Thanks to Rob Ramirez and Joshua Kit Clayton for help in identifying and resolving this issue!)

Subsequently a [PR](https://github.com/Cycling74/max-sdk-base/pull/13) with the fix applied to push the fix to the `max-sdk-base` project.

The issue is related to the following api functions from `jdataview.h`: `jdataview_getselectedrowsforview`,  `jdataview_redrawcolumn`, and `jdataview_selectedrowcount`, which are used in `source/descriptors/entrymatcher/database_view.cpp` may trigger an `Undefined symbols` error during compilation.

As per Joshua Kit Clayton: "For some reason, the max-sdk-base/script/max-linker-flags.txt is out of sync with the max-sdk-base/c74support/max-includes/c74_linker_flags.txt file". To fix this we have applied the perl script with the fix to the modified `max-sdk-base`used in this project.

If you are using a regular non-fixed version of `max-sdk-base`, you can apply the fix by running `./source/scripts/regen_linker_flags.sh` to sync up the two `*-linker-flags.txt` in the `max-sdk-base`.

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
