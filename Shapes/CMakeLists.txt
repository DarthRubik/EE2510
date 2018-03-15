add_library(Rectangle Rectangle.cpp)
add_library(Box Box.cpp)
add_executable(ShapesMain ShapesMain.cpp)
target_link_libraries(ShapesMain Rectangle Box)

