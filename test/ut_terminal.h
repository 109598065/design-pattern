#include "../src/terminal.h"

TEST(Terminal, AreaIncreasing) {
    Terminal terminal("Rectangle (3.6, 4.5) Ellipse (4.5, 3.6) Triangle ([0.0,0.0], [3.0,0.0], [0.0,4.0]) area inc");
    ASSERT_EQ("6.000\n16.200\n50.894", terminal.showResult());
}

TEST(Terminal, AreaDecreasing) {
    Terminal terminal("Rectangle (3.6, 4.5) Ellipse (4.5, 3.6) Triangle ([0.0,0.0], [3.0,0.0], [0.0,4.0]) area dec");
    ASSERT_EQ("50.894\n16.200\n6.000", terminal.showResult());
}

TEST(Terminal, PerimeterIncreasing) {
    Terminal terminal(
            "Rectangle (3.6, 4.5) Ellipse (4.5, 3.6) Triangle ([0.0,0.0], [3.0,0.0], [0.0,4.0]) perimeter inc");
    ASSERT_EQ("12.000\n16.200\n26.219", terminal.showResult());
}

TEST(Terminal, PerimeterDecreasing) {
    Terminal terminal(
            "Rectangle (3.6, 4.5) Ellipse (4.5, 3.6) Triangle ([0.0,0.0], [3.0,0.0], [0.0,4.0]) perimeter dec");
    ASSERT_EQ("26.219\n16.200\n12.000", terminal.showResult());
}

TEST(Terminal, PartShapeWithWrongFormatArgument) {
    Terminal terminal("Rectangle (2, 2) Rectangle (1, 1) Ellipse$%^&(1, 1) area inc");
    ASSERT_EQ("1.000\n4.000", terminal.showResult());
}

TEST(Terminal, PartShapeWithExcetionArgument) {
    Terminal terminal("Rectangle (2, 2) Rectangle (1, 1) Ellipse (-1, -1) area inc");
    ASSERT_EQ("1.000\n4.000", terminal.showResult());
}

TEST(Terminal, ExceptionForNoOrder) {
    try {
        Terminal terminal("Rectangle (3.7, 4.2) Ellipse (3, 4) perimeter");
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, ExceptionForNoFeature) {
    try {
        Terminal terminal("Rectangle (3.7, 4.2) Ellipse (3, 4) inc");
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("invalid input", e);
    }
}

TEST(Terminal, ExceptionForNoShape) {
    try {
        Terminal terminal("perimeter inc");
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("invalid input", e);
    }
}


TEST(Terminal, ExceptionForAllInvalidShape) {
    try {
        Terminal("Rectangle (0, 0) Ellipse (-1, -1) Triangle ([0,0], [0,0], [0,4]) area inc");
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("invalid input", e);
    }
}
