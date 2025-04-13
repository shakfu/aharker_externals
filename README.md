# AHarker Externals

A Set of 80+ Externals for a variety of tasks in Cycling 74's Max.


## FORK NOTE

This is a friendly fork of [Alex Harker's externals project](https://github.com/AlexHarker/AHarker_Externals/). The key improvements are:

- Cross-platform in-package cmake-based building.

- Included `max-sdk-base` as git submodule

- Each external has been moved to its own folder.

- Added missing dependencies such as `HISSTools_Library`.

- Add a Makefile, so just `make` to build everything on MacOS.


Conversion completed:

- [x] conversion
- [x] convolution
- [x] descriptors (except for `entrymatch` externals due to a number of api functions no longer being available)[^1].
- [x] dynamic-suite[^2]
- [x] gesture-suite
- [x] ibuffer-suite
- [x] miscellaneous
- [x] random-numbers
- [x] sample-accurate-suite
- [x] threading
- [x] utility
- [x] vMSP

Only tested on MacOS so far.

[^1]: The Max 8.2.0 SDK seems to be missing the following api functions from `jdataview.h`: `jdataview_getselectedrowsforview`,  `jdataview_redrawcolumn`, and `jdataview_selectedrowcount`

[^2]: `dynamic-suite/Common/thread_set.cpp` was patched as per recommended by [accepted answer](https://developer.apple.com/forums/thread/703361) and [this review](https://codereview.chromium.org/276043002/)


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
