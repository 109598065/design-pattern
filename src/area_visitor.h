#ifndef AREA_VISITOR_H
#define AREA_VISITOR_H

#include "./visitor.h"

class AreaVisitor : public Visitor {
public:
    void visit(Ellipse *ellipse) {
        _area = M_PI * ellipse->semiMajorAxes() * ellipse->semiMinorAxes();
    }

    void visit(Triangle *triangle) {
        std::vector<TwoDimensionalCoordinate *> vectors = triangle->vectors();
        double side1, side2, side3;
        side1 = sqrt(pow(vectors.at(0)->getX() - vectors.at(1)->getX(), 2)
                     + pow(vectors.at(0)->getY() - vectors.at(1)->getY(), 2));
        side2 = sqrt(pow(vectors.at(1)->getX() - vectors.at(2)->getX(), 2)
                     + pow(vectors.at(1)->getY() - vectors.at(2)->getY(), 2));
        side3 = sqrt(pow(vectors.at(0)->getX() - vectors.at(2)->getX(), 2)
                     + pow(vectors.at(0)->getY() - vectors.at(2)->getY(), 2));
        double s = (side1 + side2 + side3) / 2;
        _area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    void visit(Rectangle *rectangle) {
        _area = rectangle->length() * rectangle->width();
    }

    void visit(CompoundShape *compoundShape) {
        _area = 0.0;
        std::list<Shape *>::const_iterator it;
        std::list<Shape *> shapes = compoundShape->shapes();
        for (it = shapes.begin(); it != shapes.end(); it++) {
            _area += (*it)->area();
        }
    }

    double area() const {
        return _area;
    }

private:
    double _area;
};

#endif
