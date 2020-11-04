#ifndef INFO_VISITOR_H
#define INFO_VISITOR_H

#include "./visitor.h"

class InfoVisitor : public Visitor {
public:
    void visit(Ellipse *ellipse) {
        _info = "Ellipse (" + thirdDecimalPlace(ellipse->semiMajorAxes()) + ", " +
                thirdDecimalPlace(ellipse->semiMinorAxes()) + ")";
    }

    void visit(Triangle *triangle) {
        std::vector<TwoDimensionalCoordinate *> vectors = triangle->vectors();
        std::string s1 = thirdDecimalPlace(vectors.at(0)->getX());
        std::string s2 = thirdDecimalPlace(vectors.at(0)->getY());
        std::string s3 = thirdDecimalPlace(vectors.at(1)->getX());
        std::string s4 = thirdDecimalPlace(vectors.at(1)->getY());
        std::string s5 = thirdDecimalPlace(vectors.at(2)->getX());
        std::string s6 = thirdDecimalPlace(vectors.at(2)->getY());
        _info = "Triangle ([" + s1 + ", " + s2 + "], [" + s3 + ", " + s4 + "], [" + s5 + ", " + s6 + "])";
    }

    void visit(Rectangle *rectangle) {
        _info = "Rectangle (" + thirdDecimalPlace(rectangle->length()) + ", " + thirdDecimalPlace(rectangle->width()) +
                ")";
    }

    void visit(CompoundShape *compoundShape) {
        _info = "Compound Shape {";
        std::list<Shape *>::const_iterator it;
        std::list<Shape *> shapes = compoundShape->shapes();
        for (it = shapes.begin(); it != shapes.end(); it++) {
            _info += (*it)->info();
            _info += ((*it) != shapes.back() ? ", " : "");
        }
        _info += "}";
    }

    std::string info() const {
        return _info;
    }

private:
    std::string _info;

    std::string thirdDecimalPlace(double value) const {
        std::stringstream stream;
        stream << std::fixed << std::setprecision(3) << value;
        return stream.str();
    }
};

#endif
