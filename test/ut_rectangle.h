#include "../src/rectangle.h"

TEST(Rectangle, CreateUseInt) {
    Rectangle rectangle(std::string(), 3, 4);
    ASSERT_EQ(12, rectangle.area());
    ASSERT_EQ(14, rectangle.perimeter());
    ASSERT_EQ("Rectangle (3.000, 4.000)", rectangle.info());
}

TEST(Rectangle, CreateUseDouble) {
    Rectangle rectangle(std::string(), 3.5, 4.5);
    ASSERT_DOUBLE_EQ(15.75, rectangle.area());
    ASSERT_DOUBLE_EQ(16, rectangle.perimeter());
    ASSERT_EQ("Rectangle (3.500, 4.500)", rectangle.info());
}

TEST(Rectangle, ExceptionForLengthIsNotInRange) {
    try {
        Rectangle(std::string(), 0, 1);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, ExceptionForWidthIsNotInRange) {
    try {
        Rectangle(std::string(), 1, 0);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }
}

TEST(Rectangle, Id) {
    Rectangle rectangle("7", 3, 4);
    ASSERT_EQ("7", rectangle.id());
}

TEST(Rectangle, ColorWithDefault) {
    Rectangle rectangle("7", 3, 4);
    ASSERT_EQ("white", rectangle.color());
}

TEST(Rectangle, ColorWithCustom) {
    Rectangle rectangle("7", 3, 4,"green");
    ASSERT_EQ("green", rectangle.color());
}