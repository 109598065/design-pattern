#include "../src/compound_shape.h"
#include "../src/rectangle.h"
#include "../src/ellipse.h"
#include "../src/triangle.h"


class CompoundShapeShould : public ::testing::Test {
protected:
    void SetUp() override {
        ellipse = new Ellipse("8", 4, 3);
        rectangle = new Rectangle("7", 3, 4);

        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        triangle = new Triangle("6", triangleVector);

        shapes = new std::vector<Shape *>;
        shapes->push_back(ellipse);
        shapes->push_back(rectangle);
        shapes->push_back(triangle);
    }

    void TearDown() override {
        delete shapes;
        delete rectangle;
        delete ellipse;
        delete triangle;
    }

    Shape *rectangle;
    Shape *ellipse;
    Shape *triangle;
    std::vector<Shape *> *shapes;
};

TEST_F(CompoundShapeShould, Area) {
    Shape *compoundShape = new CompoundShape(std::string(), shapes);
    ASSERT_DOUBLE_EQ(55.699111843077517, compoundShape->area());
}

TEST_F(CompoundShapeShould, Perimeter) {
    Shape *compoundShape = new CompoundShape(std::string(), shapes);
    ASSERT_DOUBLE_EQ(48.849555921538759, compoundShape->perimeter());
}

TEST_F(CompoundShapeShould, Info) {
    Shape *compoundShape = new CompoundShape(std::string(), shapes);
    ASSERT_EQ(
            "Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}",
            compoundShape->info());
}

TEST_F(CompoundShapeShould, Id) {
    Shape *compoundShape = new CompoundShape("5", shapes);
    ASSERT_EQ("5", compoundShape->id());
}

TEST_F(CompoundShapeShould, ColorWithDefault) {
    Shape *compoundShape = new CompoundShape("5", shapes);
    ASSERT_EQ("transparent", compoundShape->color());
}

TEST_F(CompoundShapeShould, ExceptionForNoShapeInVector) {
    try {
        std::vector<Shape *> *EmptyShapes = new std::vector<Shape *>;
        Shape *compoundShape = new CompoundShape(std::string(), EmptyShapes);
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("This is not a compound shape!", e);
    }
}

TEST_F(CompoundShapeShould, AddNoncompoundShape) {
    Shape *compoundShape = new CompoundShape(std::string(), shapes);
    Shape *ForAdd = new Rectangle(std::string(), 2, 2);
    compoundShape->addShape(ForAdd);
    ASSERT_DOUBLE_EQ(59.699111843077517, compoundShape->area());
    ASSERT_DOUBLE_EQ(56.849555921538759, compoundShape->perimeter());
    ASSERT_EQ(
            "Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Rectangle (2.000, 2.000)}",
            compoundShape->info());
}

TEST_F(CompoundShapeShould, DeleteNonCompoundShape) {
    Shape *compoundShape = new CompoundShape(std::string(), shapes);
    compoundShape->deleteShapeById("7");
    ASSERT_EQ(
            "Compound Shape {Ellipse (4.000, 3.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}",
            compoundShape->info());
}

TEST_F(CompoundShapeShould, ExceptionForWishedDeleteShapeNotFind) {
    try {
        Shape *compoundShape = new CompoundShape(std::string(), shapes);
        compoundShape->deleteShapeById("5");
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Expected delete shape but shape not found", e);
    }
}

TEST_F(CompoundShapeShould, GetNonCompoundShape) {
    Shape *compoundShape = new CompoundShape(std::string(), shapes);
    ASSERT_EQ("Rectangle (3.000, 4.000)", compoundShape->getShapeById("7")->info());
}

TEST_F(CompoundShapeShould, ExceptionForWishedGetShapeNotFind) {
    try {
        Shape *compoundShape = new CompoundShape(std::string(), shapes);
        compoundShape->getShapeById("5");
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Expected get shape but shape not found", e);
    }
}

TEST_F(CompoundShapeShould, AddCompoundShape) {
    Shape *compoundShape = new CompoundShape("4", shapes);

    std::vector<Shape *> *shapesToAdd = new std::vector<Shape *>;
    Shape *r55 = new Rectangle(std::string(), 5, 5);
    Shape *e66 = new Ellipse(std::string(), 6, 6);
    shapesToAdd->push_back(r55);
    shapesToAdd->push_back(e66);
    Shape *compoundShapeToAdd = new CompoundShape("3", shapesToAdd);

    compoundShape->addShape(compoundShapeToAdd);
    ASSERT_EQ(
            "Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Compound Shape {Rectangle (5.000, 5.000), Ellipse (6.000, 6.000)}}",
            compoundShape->info());
}

TEST_F(CompoundShapeShould, DeleteCompoundShape) {
    Shape *compoundShape = new CompoundShape("5", shapes);

    std::vector<Shape *> *shapesToAdd = new std::vector<Shape *>;
    Shape *r55 = new Rectangle(std::string(), 5, 5);
    Shape *e66 = new Ellipse(std::string(), 6, 6);
    shapesToAdd->push_back(r55);
    shapesToAdd->push_back(e66);
    Shape *compoundShapeToAdd = new CompoundShape("4", shapesToAdd);

    compoundShape->addShape(compoundShapeToAdd);
    compoundShape->deleteShapeById("4");

    ASSERT_EQ(
            "Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000])}",
            compoundShape->info());
}

TEST_F(CompoundShapeShould, DeleteCompoundShapeWithLv3TreeStruct) {
    Shape *compoundShape = new CompoundShape("5", shapes);

    std::vector<Shape *> *shapesToAddLow = new std::vector<Shape *>;
    Shape *r55 = new Rectangle(std::string(), 5, 5);
    Shape *e66 = new Ellipse(std::string(), 6, 6);
    shapesToAddLow->push_back(r55);
    shapesToAddLow->push_back(e66);
    Shape *compoundShapeToAddLow = new CompoundShape("4", shapesToAddLow);

    std::vector<Shape *> *shapesToAddMiddle = new std::vector<Shape *>;
    Shape *r77 = new Rectangle(std::string(), 7, 7);
    Shape *e88 = new Ellipse(std::string(), 8, 8);
    shapesToAddMiddle->push_back(r77);
    shapesToAddMiddle->push_back(e88);
    Shape *compoundShapeToAddMiddle = new CompoundShape("3", shapesToAddMiddle);

    compoundShapeToAddMiddle->addShape(compoundShapeToAddLow);
    compoundShape->addShape(compoundShapeToAddMiddle);
    compoundShape->deleteShapeById("4");

    ASSERT_EQ(
            "Compound Shape {Ellipse (4.000, 3.000), Rectangle (3.000, 4.000), Triangle ([0.000, 0.000], [3.000, 0.000], [0.000, 4.000]), Compound Shape {Rectangle (7.000, 7.000), Ellipse (8.000, 8.000)}}",
            compoundShape->info());
}

TEST_F(CompoundShapeShould, GetCompoundShape) {
    Shape *compoundShape = new CompoundShape("5", shapes);

    std::vector<Shape *> *shapesToAdd = new std::vector<Shape *>;
    Shape *r55 = new Rectangle(std::string(), 5, 5);
    Shape *e66 = new Ellipse(std::string(), 6, 6);
    shapesToAdd->push_back(r55);
    shapesToAdd->push_back(e66);
    Shape *compoundShapeToAdd = new CompoundShape("4", shapesToAdd);

    compoundShape->addShape(compoundShapeToAdd);

    ASSERT_EQ("Compound Shape {Rectangle (5.000, 5.000), Ellipse (6.000, 6.000)}", compoundShape->getShapeById("4")->info());
}

TEST_F(CompoundShapeShould, GetCompoundShapeWithLv3TreeStruct) {
    Shape *compoundShape = new CompoundShape("5", shapes);

    std::vector<Shape *> *shapesToAddLow = new std::vector<Shape *>;
    Shape *r55 = new Rectangle(std::string(), 5, 5);
    Shape *e66 = new Ellipse(std::string(), 6, 6);
    shapesToAddLow->push_back(r55);
    shapesToAddLow->push_back(e66);
    Shape *compoundShapeToAddLow = new CompoundShape("4", shapesToAddLow);

    std::vector<Shape *> *shapesToAddMiddle = new std::vector<Shape *>;
    Shape *r77 = new Rectangle(std::string(), 7, 7);
    Shape *e88 = new Ellipse(std::string(), 8, 8);
    shapesToAddMiddle->push_back(r77);
    shapesToAddMiddle->push_back(e88);
    Shape *compoundShapeToAddMiddle = new CompoundShape("3", shapesToAddMiddle);

    compoundShapeToAddMiddle->addShape(compoundShapeToAddLow);
    compoundShape->addShape(compoundShapeToAddMiddle);

    ASSERT_EQ("Compound Shape {Rectangle (5.000, 5.000), Ellipse (6.000, 6.000)}", compoundShape->getShapeById("4")->info());
}