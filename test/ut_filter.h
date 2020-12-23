#include "../src/shape_filter.h"
#include "../src/shape_setter.h"

TEST(FilterShould, FilterNormalShape) {
    Shape *r22 = new Rectangle(std::string(), 4, 4);
    r22->setColor("black");
    Shape *r66 = new Rectangle(std::string(), 5, 5);
    std::list<Shape *> data = {r22, r66};

    Filter *areaFilter = new ShapeFilter([](Shape *shape) { return shape->area() <= 30; });
    Filter *perimeterFilter = new ShapeFilter([](Shape *shape) { return shape->perimeter() >= 15; });
    Filter *colorFilter = new ShapeFilter([](Shape *shape) { return shape->color() == "black"; });

    areaFilter->setNext(perimeterFilter)->setNext(colorFilter);
    std::list<Shape *> results = areaFilter->push(data);

    ASSERT_EQ(1, results.size());
    ASSERT_NEAR(16, (*results.begin())->area(), 0.001);
}

TEST(FilterShould, SetterNormalShape) {
    Shape *r22 = new Rectangle(std::string(), 4, 4);
    Shape *r66 = new Rectangle(std::string(), 6, 6);
    std::list<Shape *> data = {r22, r66};

    Filter *areaFilter = new ShapeFilter([](Shape *shape) { return shape->area() < 30; });
    Filter *perimeterFilter = new ShapeFilter([](Shape *shape) { return shape->perimeter() > 15; });
    Filter *colorSetter = new ShapeSetter([](Shape *shape) { shape->setColor("black"); });

    areaFilter->setNext(perimeterFilter)->setNext(colorSetter);
    std::list<Shape *> results = areaFilter->push(data);

    ASSERT_EQ(1, results.size());
    ASSERT_NEAR(16, (*results.begin())->area(), 0.001);
    ASSERT_EQ("black", (*results.begin())->color());
}