#include "../src/null_iterator.h"
#include "../src/shape_iterator.h"

class IteratorShould : public ::testing::Test {
protected:
    void SetUp() override {
        ellipse = new Ellipse("8", 4, 3);
        rectangle = new Rectangle("7", 3, 4);

        std::vector<TwoDimensionalCoordinate *> triangleVector;
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(3, 0));
        triangleVector.push_back(new TwoDimensionalCoordinate(0, 4));
        triangle = new Triangle("6", triangleVector);

        shapes.push_back(ellipse);
        shapes.push_back(rectangle);
        shapes.push_back(triangle);
        compoundShape = new CompoundShape(std::string(), shapes);
    }

    void TearDown() override {
        delete compoundShape;
        delete rectangle;
        delete ellipse;
        delete triangle;
    }

    Shape *rectangle;
    Shape *ellipse;
    Shape *triangle;
    std::list<Shape *> shapes;
    Shape *compoundShape;
};

TEST_F(IteratorShould, ExceptionForNullIteratorFirst) {
    try {
        NullIterator nullIterator;
        nullIterator.first();
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorShould, ExceptionForNullIteratorNext) {
    try {
        NullIterator nullIterator;
        nullIterator.next();
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorShould, NullIteratorIsDone) {
    NullIterator nullIterator;
    ASSERT_TRUE(nullIterator.isDone());
}

TEST_F(IteratorShould, ExceptionForNullIteratorCurrentItem) {
    try {
        NullIterator nullIterator;
        nullIterator.currentItem();
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorShould, NullIteratorForRectangle) {
    Iterator *it = rectangle->createIterator();
    ASSERT_TRUE(it->isDone());
}

TEST_F(IteratorShould, NullIteratorForEllipse) {
    Iterator *it = ellipse->createIterator();
    ASSERT_TRUE(it->isDone());
}

TEST_F(IteratorShould, NullIteratorForTriangle) {
    Iterator *it = triangle->createIterator();
    ASSERT_TRUE(it->isDone());
}

TEST_F(IteratorShould, NullIteratorExceptionWithRectangleCreate) {
    try {
        Iterator *iterator = rectangle->createIterator();
        iterator->first();
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("No child member!", e);
    }
}

TEST_F(IteratorShould, ShapeIteratorForCompoundShape) {
    Iterator *it = compoundShape->createIterator();

    ASSERT_DOUBLE_EQ(37.699111843077517, it->currentItem()->area());
    it->next();
    ASSERT_DOUBLE_EQ(12, it->currentItem()->area());
    it->next();
    ASSERT_DOUBLE_EQ(6, it->currentItem()->area());
    it->next();
    ASSERT_TRUE(it->isDone());
}

TEST_F(IteratorShould, ExceptionForShapeIteratorNextIsEnd) {
    try {
        Iterator *it = compoundShape->createIterator();
        it->next();
        it->next();
        it->next();
        it->next();
        FAIL();
    } catch (std::string e) {
        ASSERT_EQ("Moving past the end!", e);
    }
}