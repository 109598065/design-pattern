#include "../src/shape_parser.h"

TEST(ShapeParserTest, parser_rectangle) {
    ShapeParser sp("Rectangle (4.000, 3.000)");
    sp.parser();

    std::deque<Shape *> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Rectangle (4.000, 3.000)", results[0]->info());
}

TEST(ShapeParserTest, parser_one_shape_contain_invalid_argument_that_should_be_ignored) {
    ShapeParser sp("Rectangle (4.000, 3.000, 7.000), Rectangle (4.000, 3.a00)");
    sp.parser();

    std::deque<Shape *> results = sp.getResult();

    ASSERT_EQ(0, results.size());
}

TEST(ShapeParserTest, parser_multi_simple_shapes) {
    ShapeParser sp("Rectangle (3.000, 4.000), Ellipse (4.200, 3.700)");
    sp.parser();

    std::deque<Shape *> results = sp.getResult();

    ASSERT_EQ(2, results.size());
    ASSERT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[1]->info());
}

TEST(ShapeParserTest, parser_triangle) {
    ShapeParser sp("Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape *> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[0]->info());
}

TEST(ShapeParserTest, parser_multi_simple_shapes_with_one_shape_contain_invalid_argument_that_should_be_ignored) {

    ShapeParser sp(
            "Rectangle (3.000, 4.000), Ellipse (4.200, 3.700), Ellipse (4.200, 3.700, 12.502), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape *> results = sp.getResult();

    ASSERT_EQ(3, results.size());

    EXPECT_EQ("Rectangle (3.000, 4.000)", results[0]->info());
    EXPECT_EQ("Ellipse (4.200, 3.700)", results[1]->info());
    EXPECT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[2]->info());
}

TEST(ShapeParserTest, parser_compoundShapes) {
    ShapeParser sp("CompoundShape { Ellipse (4.000, 3.000),Rectangle (4.000, 3.000)}");
    sp.parser();

    std::deque<Shape *> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000), Rectangle (4.000, 3.000)}", results[0]->info());
}

TEST(ShapeParserTest, parser_compoundShapes_contain_compoundShapes) {
    ShapeParser sp(
            "CompoundShape { Rectangle (3.000, 4.000), CompoundShape { Rectangle (2.000, 2.000), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}}");
    sp.parser();

    std::deque<Shape *> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ(
            "Compound Shape {Rectangle (3.000, 4.000), Compound Shape {Rectangle (2.000, 2.000), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}}",
            results[0]->info());
}

TEST(ShapeParserTest, parser_forest) {
    ShapeParser sp(
            "Rectangle (5.000, 5.000) , "
            "CompoundShape { Rectangle (3.000, 4.000), CompoundShape { Rectangle (2.000, 2.000), Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)}},"
            "Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");
    sp.parser();

    std::deque<Shape *> results = sp.getResult();

    ASSERT_EQ(3, results.size());
    ASSERT_EQ("Rectangle (5.000, 5.000)", results[0]->info());
    ASSERT_EQ(
            "Compound Shape {Rectangle (3.000, 4.000), Compound Shape {Rectangle (2.000, 2.000), Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])}}",
            results[1]->info());
    ASSERT_EQ("Triangle ([0.000, 0.000], [0.000, -3.000], [-4.000, 0.000])", results[2]->info());
}

TEST(ShapeParserTest, parser_compoundShape_that_contains_a_empty_compoundShape) {
    ShapeParser sp("CompoundShape { Ellipse (4.000, 3.000), CompoundShape {}}");
    sp.parser();

    std::deque<Shape *> results = sp.getResult();

    ASSERT_EQ(1, results.size());
    ASSERT_EQ("Compound Shape {Ellipse (4.000, 3.000)}", results[0]->info());
}