include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-pretarget.cmake)

set(DESCRIPTORS ${CMAKE_CURRENT_SOURCE_DIR}/../descriptors~)

add_msp_external(
	OTHER_SOURCE
		${DESCRIPTORS}/descriptors_graph.cpp
		${DESCRIPTORS}/modules/modules_core.cpp
		${DESCRIPTORS}/modules/modules_change.cpp
		${DESCRIPTORS}/modules/modules_content.cpp
		${DESCRIPTORS}/modules/modules_level.cpp
		${DESCRIPTORS}/modules/modules_pitch.cpp
		${DESCRIPTORS}/modules/modules_spectral.cpp
	INCLUDE_DIRS
		${DESCRIPTORS}
		${DESCRIPTORS}/library
		${DESCRIPTORS}/modules
    LINK_LIBS
        hisstools
)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-posttarget.cmake)




