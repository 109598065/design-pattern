#include "../src/shape_builder.h"

TEST(ShapeBuilderTest, BuildRectangle) {
    ShapeBuilder sb;
    sb.buildRectangle(2, 2);
    std::deque<Shape *> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Rectangle (2.000, 2.000)", results[0]->info());
}

TEST(ShapeBuilderTest, BuildEllipse) {
    ShapeBuilder sb;
    sb.buildEllipse(4, 3);
    std::deque<Shape *> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Ellipse (4.000, 3.000)", results[0]->info());
}

TEST(ShapeBuilderTest, BuildTriangle) {
    ShapeBuilder sb;
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    std::deque<Shape *> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
}

TEST(ShapeBuilderTest, BuildCompoundShape) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(2, 2);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();
    std::deque<Shape *> result = sb.getResult();
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(10, result[0]->area());
}

TEST(ShapeBuilderTest, BuildForest) {
    ShapeBuilder sb;
    sb.buildRectangle(5, 5);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(3, 4);
    sb.buildCompoundShapeBegin();
    sb.buildRectangle(2, 2);
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    sb.buildTriangle(0, 0, 0, -3, -4, 0);
    std::deque<Shape *> result = sb.getResult();
    ASSERT_EQ(3, result.size());
    ASSERT_EQ(25, result[0]->area());
    ASSERT_EQ(22, result[1]->area());
    ASSERT_NEAR(6, result[2]->area(), 0.001);

    ASSERT_EQ("Rectangle (5.000, 5.000)", result[0]->info());
    ASSERT_EQ(
            "Compound Shape {Rectangle (3.000, 4.000), Compound Shape {Rectangle (2.000, 2.000), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}}",
            result[1]->info());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", result[2]->info());
}

TEST(ShapeBuilderTest, BuildShapesHaveUniqueId) {
    ShapeBuilder sb;
    sb.buildRectangle(2, 2);
    sb.buildRectangle(2, 2);
    sb.buildRectangle(2, 2);
    std::deque<Shape *> results = sb.getResult();

    ASSERT_EQ(3, results.size());
    ASSERT_TRUE(results[0]->id() != results[1]->id());
    ASSERT_TRUE(results[0]->id() != results[2]->id());
    ASSERT_TRUE(results[1]->id() != results[2]->id());
}

TEST(ShapeBuilderTest, build_empty_compoundShape) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    std::deque<Shape *> results = sb.getResult();

    ASSERT_EQ(1, results.size());
}

TEST(ShapeBuilderTest, build_compoundShape_that_contains_a_empty_compoundShape) {
    ShapeBuilder sb;
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeBegin();
    sb.buildCompoundShapeEnd();
    sb.buildCompoundShapeEnd();
    std::deque<Shape *> results = sb.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Compound Shape {}}", results[0]->info());
}

