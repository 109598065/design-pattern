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
