add_library(Shape Shape.cpp)
add_library(TwoDShape TwoDShape.cpp)
add_library(ThreeDShape ThreeDShape.cpp)
add_library(Circle Circle.cpp)
add_library(Sphere Sphere.cpp)
add_library(Rectangle2 Rectangle.cpp)
add_library(Box2 Box.cpp)


add_executable(Shapes2Main Shapes2Main.cpp)
target_link_libraries(Shapes2Main Sphere Circle Box2 Rectangle2 Shape ThreeDShape TwoDShape)


