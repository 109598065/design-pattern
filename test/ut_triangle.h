#include "../src/triangle.h"

TEST(Shapes, CreateTriangle) {
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Triangle triangle(triangleVector);
    ASSERT_EQ(6.000, triangle.area());
    ASSERT_EQ(12.000, triangle.perimeter());
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle.info());

    std::vector<TwoDimensionalCoordinate *> triangleVector2;
    triangleVector2.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector2.push_back(new TwoDimensionalCoordinate(5, 0));
    triangleVector2.push_back(new TwoDimensionalCoordinate(0, 5));
    Triangle triangle2(triangleVector2);
    ASSERT_EQ(12.5, triangle2.area());
    ASSERT_EQ(10.000 + 5 * sqrt(2), triangle2.perimeter());
    ASSERT_EQ("Triangle ([0.000, 0.000], [5.000, 0.000], [0.000, 5.000])", triangle2.info());

    try {
        std::vector<TwoDimensionalCoordinate *> triangleVector3;
        triangleVector3.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector3.push_back(new TwoDimensionalCoordinate(0, 2));
        triangleVector3.push_back(new TwoDimensionalCoordinate(0, 4));
        Triangle triangle3(triangleVector3);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a triangle!", e);
    }
}
