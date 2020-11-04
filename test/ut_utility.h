#include "../src/utility.h"

class UtilityShould : public ::testing::Test {
protected:
    void SetUp() override {
        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        triangle_2 = new Triangle("2", triangleVector);

        ellipse_3 = new Ellipse("3", 4, 3);
        rectangle_4 = new Rectangle("4", 3, 4);

        shapes1.push_back(triangle_2);
        compoundShape_1 = new CompoundShape("1", shapes1);
        shapes0.push_back(compoundShape_1);
        shapes0.push_back(ellipse_3);
        shapes0.push_back(rectangle_4);
        compoundShape_0 = new CompoundShape("0", shapes0);
    }

    void TearDown() override {
        delete compoundShape_0;
        delete compoundShape_1;
        delete triangle_2;
        delete ellipse_3;
        delete rectangle_4;
    }

    std::list<Shape *> shapes0;
    std::list<Shape *> shapes1;
    Shape *compoundShape_0;
    Shape *compoundShape_1;
    Shape *triangle_2;
    Shape *ellipse_3;
    Shape *rectangle_4;
};

TEST_F(UtilityShould, GetShapeById) {
    ASSERT_EQ(triangle_2, getShapeById(compoundShape_0, "2"));
}

TEST_F(UtilityShould, ExceptionForShapeNotIterable) {
    try {
        getShapeById(new Rectangle("0", 5, 4), "0");
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}

TEST_F(UtilityShould, ExceptionForNotFindById) {
    try {
        getShapeById(compoundShape_0, "20");
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }
}

TEST_F(UtilityShould, FilterShapeWithAreaForLV1_TreeStruct) {
    std::deque<Shape *> deque = filterShape(compoundShape_1, AreaFilter(10, 5));
    ASSERT_EQ(1, deque.size());
    ASSERT_EQ(triangle_2, deque.front());
}

TEST_F(UtilityShould, FilterShapeWithAreaForLV2_TreeStruct) {
    std::deque<Shape *> deque = filterShape(compoundShape_0, AreaFilter(10, 5));
    ASSERT_EQ(2, deque.size());
    ASSERT_EQ(compoundShape_1, deque.front());
    ASSERT_EQ(triangle_2, deque.back());
}

TEST_F(UtilityShould, FilterShapeWithPerimeter) {
    std::deque<Shape *> deque = filterShape(compoundShape_0, PerimeterFilter(14, 12));
    ASSERT_EQ(3, deque.size());
    ASSERT_EQ(compoundShape_1, deque.at(0));
    ASSERT_EQ(triangle_2, deque.at(1));
    ASSERT_EQ(rectangle_4, deque.at(2));
}

TEST_F(UtilityShould, FilterShapeWithColor) {
    std::deque<Shape *> deque = filterShape(compoundShape_0, ColorFilter("white"));
    ASSERT_EQ(3, deque.size());
    ASSERT_EQ(triangle_2, deque.at(0));
    ASSERT_EQ(ellipse_3, deque.at(1));
    ASSERT_EQ(rectangle_4, deque.at(2));
}

TEST_F(UtilityShould, FilterShapeWithType) {
    std::deque<Shape *> deque = filterShape(compoundShape_0, TypeFilter("Compound Shape"));
    ASSERT_EQ(1, deque.size());
    ASSERT_EQ(compoundShape_1, deque.at(0));
}

TEST_F(UtilityShould, ExceptionForFileterShape) {
    try {
        filterShape(triangle_2, TypeFilter("Compound Shape"));
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Only compound shape can filter shape!", e);
    }
}