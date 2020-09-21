#include "../src/ellipse.h"

TEST(Ellipse, CreateUseInt) {
    Ellipse ellipse(3, 4);
    ASSERT_DOUBLE_EQ(37.699111843077517, ellipse.area());
    ASSERT_DOUBLE_EQ(21.132741228718345, ellipse.perimeter());
    ASSERT_EQ("Ellipse (3.000, 4.000)", ellipse.info());
}

TEST(Ellipse, CreateUseDouble) {
    Ellipse ellipse(3.5, 4.5);
    ASSERT_DOUBLE_EQ(49.480084294039244, ellipse.area());
    ASSERT_DOUBLE_EQ(24.274333882308138, ellipse.perimeter());
    ASSERT_EQ("Ellipse (3.500, 4.500)", ellipse.info());
}

TEST(Ellipse, ExceptionForSemiMajorAxesIsNotInRange) {
    try {
        Ellipse(0, 1);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesIsNotInRange) {
    try {
        Ellipse(1, 0);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a ellipse!", e);
    }
}
