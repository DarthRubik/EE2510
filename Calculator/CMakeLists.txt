add_library(CalculatorFunctions CalculatorFunctions.cpp)
create_test("Calculator tests" "CalculatorTest;CppUTest;CppUTestExt;CalculatorFunctions")
