add_library(Company Company.cpp)
add_library(FinancialCompany FinancialCompany.cpp)
add_library(ManufacturingCompany ManufacturingCompany.cpp)
add_executable(LabExamMain LabExamMain.cpp)
target_link_libraries(LabExamMain FinancialCompany ManufacturingCompany Company) 
