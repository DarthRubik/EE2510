add_library(CalculatorFunctions CalculatorFunctions.cpp)
create_test("Calculator tests" "CalculatorTest;CppUTest;CppUTestExt;CalculatorFunctions")
add_executable(CalculatorMain CalculatorMain.cpp)
target_link_libraries(CalculatorMain UserInput CalculatorFunctions) 
