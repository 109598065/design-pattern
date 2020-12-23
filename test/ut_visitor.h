#include "../src/rectangle.h"
#include "../src/ellipse.h"
#include "../src/triangle.h"
#include "../src/compound_shape.h"
#include "../src/area_visitor.h"
#include "../src/info_visitor.h"

class VisitorShould : public ::testing::Test {
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

TEST_F(VisitorShould, AreaVisitorEllipse) {
    AreaVisitor areaVisitor;
    ellipse_3->accept(&areaVisitor);
    ASSERT_EQ(37.699111843077517, areaVisitor.area());
}

TEST_F(VisitorShould, AreaVisitorTriangle) {
    AreaVisitor areaVisitor;
    triangle_2->accept(&areaVisitor);
    ASSERT_EQ(6, areaVisitor.area());
}

TEST_F(VisitorShould, AreaVisitorRectangle) {
    AreaVisitor areaVisitor;
    rectangle_4->accept(&areaVisitor);
    ASSERT_EQ(12, areaVisitor.area());
}

TEST_F(VisitorShould, AreaVisitorCompoundShape) {
    AreaVisitor areaVisitor;
    compoundShape_0->accept(&areaVisitor);
    ASSERT_DOUBLE_EQ(55.699111843077517, areaVisitor.area());
}

TEST_F(VisitorShould, InfoVisitorEllipse) {
    InfoVisitor areaVisitor;
    ellipse_3->accept(&areaVisitor);
    ASSERT_EQ("Ellipse (4.000, 3.000)", areaVisitor.info());
}

TEST_F(VisitorShould, InfoVisitorTriangle) {
    InfoVisitor areaVisitor;
    triangle_2->accept(&areaVisitor);
    ASSERT_EQ("Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])", areaVisitor.info());
}

TEST_F(VisitorShould, InfoVisitorRectangle) {
    InfoVisitor areaVisitor;
    rectangle_4->accept(&areaVisitor);
    ASSERT_EQ("Rectangle (3.000, 4.000)", areaVisitor.info());
}

TEST_F(VisitorShould, InfoVisitorCompoundShape) {
    InfoVisitor areaVisitor;
    compoundShape_0->accept(&areaVisitor);
    ASSERT_EQ(
            "Compound Shape {Compound Shape {Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}, Ellipse (4.000, 3.000), Rectangle (3.000, 4.000)}",
            areaVisitor.info());
}
