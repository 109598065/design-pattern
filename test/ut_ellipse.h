#include "../src/ellipse.h"

TEST(Shapes, CreateEllipse) {
    Ellipse ellipse(2.5, 1);
    ASSERT_EQ(2.5 * M_PI, ellipse.area());
    ASSERT_EQ(12.283185307179586, ellipse.perimeter());
    //ASSERT_EQ(12.2832, ellipse.perimeter());
    ASSERT_EQ("Ellipse (2.500, 1.000)", ellipse.info());

    try {
        Ellipse(1, 0);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}