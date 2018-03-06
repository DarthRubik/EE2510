cmake_minimum_required(VERSION 2.8.7)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")


include_directories(.)
include_directories($ENV{CPPUTEST_INCLUDE}/include)
add_library(CppUTest STATIC IMPORTED)
add_library(CppUTestExt STATIC IMPORTED)
set_property(TARGET CppUTest PROPERTY
	IMPORTED_LOCATION $ENV{CPPUTEST_BIN}/libCppUTest.a)
set_property(TARGET CppUTestExt PROPERTY
	IMPORTED_LOCATION $ENV{CPPUTEST_BIN}/libCppUTestExt.a)


function(create_test COM LINKLIST)
	list(GET LINKLIST 0 MODULE_NAME)
	add_executable(${MODULE_NAME} ${MODULE_NAME}.cpp)
	target_link_libraries(${LINKLIST})
	add_custom_command(
		TARGET ${MODULE_NAME}
		COMMENT "${COM}"
		POST_BUILD
		COMMAND ${MODULE_NAME} -c
	)
endfunction()
add_subdirectory(HelloWorld)

