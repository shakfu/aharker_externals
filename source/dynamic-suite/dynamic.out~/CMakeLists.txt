include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-pretarget.cmake)


add_msp_external(
    INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/../Common
)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-posttarget.cmake)
