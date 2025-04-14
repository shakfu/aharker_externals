include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-pretarget.cmake)


include_directories( 
	"${MAX_SDK_INCLUDES}"
	"${MAX_SDK_MSP_INCLUDES}"
	"${MAX_SDK_JIT_INCLUDES}"
	"${COMMON_INCLUDES}"
)

set(EM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../entrymatcher)

set(PROJECT_SRC
	entrymatcher_tilde.cpp
	${EM_DIR}/database_view.cpp
	${EM_DIR}/entries.cpp
	${EM_DIR}/entry_database.cpp
	${EM_DIR}/matchers.cpp
)

add_library( 
	${PROJECT_NAME} 
	MODULE
	${PROJECT_SRC}
	${MAX_SDK_INCLUDES}/common/commonsyms.c
)

target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	${EM_DIR}
)


include(${CMAKE_CURRENT_SOURCE_DIR}/../../max-sdk-base/script/max-posttarget.cmake)
