#include "../src/scanner.h"

TEST(Scanner, Rectangle) {
    Scanner scanner("Rectangle (4.000, 3.000)");

    ASSERT_EQ("Rectangle", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());

    try {
        scanner.nextToken();
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("next char doesn't exist.", e);
    }
}

TEST(Scanner, Ellipse) {
    Scanner scanner("Ellipse (4.000, 3.000)");

    ASSERT_EQ("Ellipse", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());

    try {
        scanner.nextToken();
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("next char doesn't exist.", e);
    }
}

TEST(Scanner, Triangle) {
    Scanner scanner("Triangle (0.000, 0.000, 0.000, -3.000, -4.000, 0.000)");

    ASSERT_EQ("Triangle", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("-3.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("-4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("0.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());

    try {
        scanner.nextToken();
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("next char doesn't exist.", e);
    }
}

TEST(Scanner, CompoundShape) {
    Scanner scanner("CompoundShape {Ellipse (4.000, 3.000),Rectangle (4.000, 3.000)}");

    ASSERT_EQ("CompoundShape", scanner.nextToken());
    ASSERT_EQ("{", scanner.nextToken());
    ASSERT_EQ("Ellipse", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("Rectangle", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    ASSERT_EQ("}", scanner.nextToken());

    try {
        scanner.nextToken();
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("next char doesn't exist.", e);
    }
}

TEST(Scanner, CompoundShapeContainCompoundShape) {
    Scanner scanner("CompoundShape { CompoundShape { Ellipse (4.000, 3.000),Rectangle (4.000, 3.000)}}");

    ASSERT_EQ("CompoundShape", scanner.nextToken());
    ASSERT_EQ("{", scanner.nextToken());
    ASSERT_EQ("CompoundShape", scanner.nextToken());
    ASSERT_EQ("{", scanner.nextToken());
    ASSERT_EQ("Ellipse", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("Rectangle", scanner.nextToken());
    ASSERT_EQ("(", scanner.nextToken());
    ASSERT_EQ("4.000", scanner.nextToken());
    ASSERT_EQ(",", scanner.nextToken());
    ASSERT_EQ("3.000", scanner.nextToken());
    ASSERT_EQ(")", scanner.nextToken());
    ASSERT_EQ("}", scanner.nextToken());
    ASSERT_EQ("}", scanner.nextToken());

    try {
        scanner.nextToken();
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("next char doesn't exist.", e);
    }
}