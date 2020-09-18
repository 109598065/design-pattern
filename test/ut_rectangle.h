#include "../src/rectangle.h"

TEST(Shapes, CreateRectangle) {
    Rectangle rectangle1(3, 4);
    ASSERT_EQ(12.000, rectangle1.area());
    ASSERT_EQ("Rectangle (3.000, 4.000)", rectangle1.info());

    Rectangle rectangle2(3, 4.5);
    ASSERT_EQ(13.500, rectangle2.area());
    ASSERT_EQ("Rectangle (3.000, 4.500)", rectangle2.info());

    try {
        Rectangle(0, 1);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a rectangle!", e);
    }

    ASSERT_NO_THROW(Rectangle(1, 1));
}