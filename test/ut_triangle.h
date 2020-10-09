#include "../src/triangle.h"

TEST(Triangle, CreateUseInt) {
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
    Triangle triangle(std::string(), triangleVector);
    ASSERT_EQ(6, triangle.area());
    ASSERT_EQ(12, triangle.perimeter());
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", triangle.info());
}

TEST(Triangle, CreateUseDouble) {
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3.5, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4.5));
    Triangle triangle(std::string(), triangleVector);
    ASSERT_DOUBLE_EQ(7.8750000000000027, triangle.area());
    ASSERT_DOUBLE_EQ(13.70087712549569, triangle.perimeter());
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.500, 0.000], [0.000, 4.500])", triangle.info());
}

TEST(Triangle, ExceptionForVectorNotInRange) {
    try {
        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 2));
        Triangle triangle(std::string(), triangleVector);
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
        Triangle triangle(std::string(), triangleVector);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a triangle!", e);
    }
}

TEST(Triangle, Id) {
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3.5, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4.5));
    Triangle triangle("3", triangleVector);
    ASSERT_EQ("3", triangle.id());
}

TEST(Triangle, ColorWithDefault) {
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3.5, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4.5));
    Triangle triangle("3", triangleVector);
    ASSERT_EQ("white", triangle.color());
}

TEST(Triangle, ColorWithCustom) {
    std::vector<TwoDimensionalCoordinate *> triangleVector;
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(3.5, 0));
    triangleVector.push_back(new TwoDimensionalCoordinate(0, 4.5));
    Triangle triangle("3", triangleVector,"yellow");
    ASSERT_EQ("yellow", triangle.color());
}

TEST(Triangle, ExceptionForCallAddShape) {
    try {
        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        Shape* triangle = new Triangle(std::string(), triangleVector);
        triangle->addShape(nullptr);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Only compound shape can add shape!", e);
    }
}

TEST(Triangle, ExceptionForCallDeleteShapeById) {
    try {
        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        Shape* triangle = new Triangle(std::string(), triangleVector);
        triangle->deleteShapeById(std::string());
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Only compound shape can delete shape!", e);
    }
}

TEST(Triangle, ExceptionForCallGetShapeById) {
    try {
        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        Shape* triangle = new Triangle(std::string(), triangleVector);
        triangle->getShapeById(std::string());
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}