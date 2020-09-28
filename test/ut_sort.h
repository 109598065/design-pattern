#include "../src/rectangle.h"
#include "../src/ellipse.h"
#include "../src/triangle.h"
#include "../src/sort.h"

class ShapeSort : public ::testing::Test {
protected:
    void SetUp() override {
        rectangle = new Rectangle(3, 4);
        ellipse = new Ellipse(3, 2);

        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        triangle = new Triangle(triangleVector);
    }

    void TearDown() override {
        delete rectangle;
        delete ellipse;
        delete triangle;
    }

    Shape *rectangle;
    Shape *ellipse;
    Shape *triangle;
};

TEST_F(ShapeSort, AscendingByAreaViaFuntion) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), areaAscendingCompare);
    ASSERT_EQ(6, shapes[0]->area());
    ASSERT_EQ(12, shapes[1]->area());
    ASSERT_DOUBLE_EQ(18.849555921538759, shapes[2]->area());
}

TEST_F(ShapeSort, DescendingByAreaViaFuntion) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), areaDescendingCompare);
    ASSERT_DOUBLE_EQ(18.849555921538759, shapes[0]->area());
    ASSERT_EQ(12, shapes[1]->area());
    ASSERT_EQ(6, shapes[2]->area());
}

TEST_F(ShapeSort, AscendingByAreaViaLambdaExpressions) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), [](Shape *a, Shape *b) { return a->area() < b->area(); });
    ASSERT_EQ(6, shapes[0]->area());
    ASSERT_EQ(12, shapes[1]->area());
    ASSERT_DOUBLE_EQ(18.849555921538759, shapes[2]->area());
}

TEST_F(ShapeSort, DescendingByAreaViaLambdaExpressions) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), [](Shape *a, Shape *b) { return a->area() > b->area(); });
    ASSERT_DOUBLE_EQ(18.849555921538759, shapes[0]->area());
    ASSERT_EQ(12, shapes[1]->area());
    ASSERT_EQ(6, shapes[2]->area());
}

TEST_F(ShapeSort, AscendingByAreaViaObject) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), AscendingCompare("area"));
    ASSERT_EQ(6, shapes[0]->area());
    ASSERT_EQ(12, shapes[1]->area());
    ASSERT_EQ(18.849555921538759, shapes[2]->area());
}

TEST_F(ShapeSort, DescendingByAreaViaObject) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), DescendingCompare("area"));
    ASSERT_DOUBLE_EQ(18.849555921538759, shapes[0]->area());
    ASSERT_EQ(12, shapes[1]->area());
    ASSERT_EQ(6, shapes[2]->area());
}

TEST_F(ShapeSort, AscendingByPerimeterViaFuntion) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), perimeterAscendingCompare);
    ASSERT_EQ(12, shapes[0]->perimeter());
    ASSERT_EQ(14, shapes[1]->perimeter());
    ASSERT_DOUBLE_EQ(16.566370614359172, shapes[2]->perimeter());
}

TEST_F(ShapeSort, DescendingByPerimeterViaFuntion) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), perimeterDescendingCompare);
    ASSERT_EQ(16.566370614359172, shapes[0]->perimeter());
    ASSERT_EQ(14, shapes[1]->perimeter());
    ASSERT_DOUBLE_EQ(12, shapes[2]->perimeter());
}

TEST_F(ShapeSort, AscendingByPerimeterViaLambdaExpressions) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), [](Shape *a, Shape *b) { return a->perimeter() < b->perimeter(); });
    ASSERT_EQ(12, shapes[0]->perimeter());
    ASSERT_EQ(14, shapes[1]->perimeter());
    ASSERT_DOUBLE_EQ(16.566370614359172, shapes[2]->perimeter());
}

TEST_F(ShapeSort, DescendingByPerimeterViaLambdaExpressions) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), [](Shape *a, Shape *b) { return a->perimeter() > b->perimeter(); });
    ASSERT_EQ(16.566370614359172, shapes[0]->perimeter());
    ASSERT_EQ(14, shapes[1]->perimeter());
    ASSERT_DOUBLE_EQ(12, shapes[2]->perimeter());
}

TEST_F(ShapeSort, AscendingByPerimeterViaObject) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), AscendingCompare("perimeter"));
    ASSERT_EQ(12, shapes[0]->perimeter());
    ASSERT_EQ(14, shapes[1]->perimeter());
    ASSERT_DOUBLE_EQ(16.566370614359172, shapes[2]->perimeter());
}

TEST_F(ShapeSort, DescendingByPerimeterViaObject) {
    std::array<Shape *, 3> shapes = {rectangle, ellipse, triangle};
    quickSort(shapes.begin(), shapes.end(), DescendingCompare("perimeter"));
    ASSERT_EQ(16.566370614359172, shapes[0]->perimeter());
    ASSERT_EQ(14, shapes[1]->perimeter());
    ASSERT_DOUBLE_EQ(12, shapes[2]->perimeter());
}
