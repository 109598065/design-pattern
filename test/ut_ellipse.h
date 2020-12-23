#include "../src/ellipse.h"

TEST(Ellipse, CreateUseInt) {
    Ellipse ellipse(std::string(), 4, 3);
    ASSERT_DOUBLE_EQ(37.699111843077517, ellipse.area());
    ASSERT_DOUBLE_EQ(22.849555921538759, ellipse.perimeter());
    ASSERT_EQ("Ellipse (4.000, 3.000)", ellipse.info());
}

TEST(Ellipse, CreateUseDouble) {
    Ellipse ellipse(std::string(), 4.5, 3.5);
    ASSERT_DOUBLE_EQ(49.480084294039244, ellipse.area());
    ASSERT_DOUBLE_EQ(25.991148575128552, ellipse.perimeter());
    ASSERT_EQ("Ellipse (4.500, 3.500)", ellipse.info());
}

TEST(Ellipse, ExceptionForSemiMajorAxesIsNotInRange) {
    try {
        Ellipse(std::string(), 0, 1);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesIsNotInRange) {
    try {
        Ellipse(std::string(), 1, 0);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(Ellipse, ExceptionForSemiMinorAxesIsBiggerThanSemiMajorAxes) {
    try {
        Ellipse(std::string(), 4, 8);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not an ellipse!", e);
    }
}

TEST(Ellipse, Id) {
    Ellipse ellipse("8", 4, 3);
    ASSERT_EQ("8", ellipse.id());
}

TEST(Ellipse, ColorWithDefault) {
    Ellipse ellipse("8", 4, 3);
    ASSERT_EQ("white", ellipse.color());
}

TEST(Ellipse, ColorWithCustom) {
    Ellipse ellipse("8", 4, 3, "blue");
    ASSERT_EQ("blue", ellipse.color());
}

TEST(Ellipse, ExceptionForCallAddShape) {
    try {
        Shape *ellipse = new Ellipse(std::string(), 3, 2);
        ellipse->addShape(nullptr);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Only compound shape can add shape!", e);
    }
}

TEST(Ellipse, ExceptionForCallDeleteShapeById) {
    try {
        Shape *ellipse = new Ellipse(std::string(), 3, 2);
        ellipse->deleteShapeById(std::string());
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Only compound shape can delete shape!", e);
    }
}

TEST(Ellipse, ExceptionForCallGetShapeById) {
    try {
        Shape *ellipse = new Ellipse(std::string(), 3, 2);
        ellipse->getShapeById(std::string());
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Only compound shape can get shape!", e);
    }
}

TEST(Ellipse, Type) {
    Ellipse ellipse("7", 4, 3, "green");
    ASSERT_EQ("Ellipse", ellipse.type());
}