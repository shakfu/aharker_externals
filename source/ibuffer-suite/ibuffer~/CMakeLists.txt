include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-pretarget.cmake)


add_msp_external(
    OTHER_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/AudioFile/BaseAudioFile.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/AudioFile/IAudioFile.cpp
    INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/AudioFile
    LINK_LIBS
        hisstools
)


include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-posttarget.cmake)
