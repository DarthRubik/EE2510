add_executable(DoodleBugMain DoodleBugMain.cpp)
add_library(Square Square.cpp)
add_library(Arena Arena.cpp)
add_library(Bug Bug.cpp)
add_library(MoveableBug MoveableBug.cpp)
add_library(Ant Ant.cpp)
add_library(DoodleBug DoodleBug.cpp)

create_test("DoodleBug Tests" "Test;Square;Arena;Ant;DoodleBug;MoveableBug;Bug;CppUTest;CppUTestExt")

target_link_libraries(DoodleBugMain Square Arena Ant DoodleBug MoveableBug Bug)
