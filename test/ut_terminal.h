#include "../src/terminal.h"

std::string get_last_word(const std::string &s) {
    auto index = s.find_last_of(' ');
    return s.substr(++index);
}

TEST(Terminal, Create) {
    //Terminal terminal("Rectangle (1, 4) Rectangle (2, 105) Rectangle (0, 0) Rectangle (2, 105) perimeter dec");
    //Terminal terminal("Ellipse (10, 1) Rectangle (1, 2)  area inc");
    //Terminal terminal("Triangle ([0,3], [3,4], [0,4]) area inc");
    Terminal terminal("Rectangle (3.0, 4) Ellipse (4.0, 3.0) Triangle ([0.0,0.0], [3.0,0.0], [0.0,4.0]) area inc");
    ASSERT_EQ("6.000\n12.000\n37.699", terminal.showResult());
}


TEST(Terminal, PartInvalidShape) {
    Terminal terminal("Rectangle (2, 2) Rectangle (1, 1) Ellipse$%^&(1, 1) area inc");
    ASSERT_EQ("1.000\n4.000", terminal.showResult());

    Terminal terminal2("Rectangle (2, 2) Rectangle (1, 1) Ellipse (-1, -1) area inc");
    ASSERT_EQ("1.000\n4.000", terminal2.showResult());
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
        Terminal("Rectangle (0, 0) Ellipse (-1, -1) area inc");
        FAIL();
    }catch(std::string e) {
        ASSERT_EQ("invalid input", e);
    }
}