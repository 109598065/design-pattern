#include "../src/triangle.h"

TEST(Triangle, CreateUseInt) {
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Triangle triangle(triangleVector);
    ASSERT_EQ(6, triangle.area());
    ASSERT_EQ(12, triangle.perimeter());
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle.info());
}

TEST(Triangle, CreateUseDouble) {
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3.5, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4.5));
    Triangle triangle(triangleVector);
    ASSERT_DOUBLE_EQ(7.8750000000000027, triangle.area());
    ASSERT_DOUBLE_EQ(13.70087712549569, triangle.perimeter());
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.500, 0.000], [0.000, 4.500])", triangle.info());
}

TEST(Triangle, ExceptionForVectorNotInRange) {
    try {
        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 2));
        Triangle triangle(triangleVector);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a triangle!", e);
    }
}

TEST(Triangle, ExceptionForNotCorrespondTriangleInequality) {
    try {
        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 2));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        Triangle triangle(triangleVector);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a triangle!", e);
    }
}
