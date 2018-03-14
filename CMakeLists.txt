cmake_minimum_required(VERSION 2.8.7)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")
set(RUN_AUTOMATED_TESTS OFF CACHE PATH "Run the unit tests")


include_directories(.)
include_directories(Utility)
include_directories($ENV{CPPUTEST_INCLUDE}/include)

function(create_test COM LINKLIST)
	list(GET LINKLIST 0 MODULE_NAME)
	add_executable(${MODULE_NAME} ${MODULE_NAME}.cpp)
	target_link_libraries(${LINKLIST})
	if(RUN_AUTOMATED_TESTS)
		add_custom_command(
			TARGET ${MODULE_NAME}
			COMMENT "${COM}"
			POST_BUILD
			COMMAND ${MODULE_NAME} -c
		)
	endif()
endfunction()
add_subdirectory(HelloWorld)
add_subdirectory(CppUTest)
add_subdirectory(InClassDemo)
add_subdirectory(Calculator)
add_subdirectory(InClassBasicEmployee)
add_subdirectory(Utility)
