#ifndef TWO_DIMENSIONAL_COORDINATE_H
#define TWO_DIMENSIONAL_COORDINATE_H

class TwoDimensionalCoordinate {
public:
    TwoDimensionalCoordinate(double x, double y) {
        _x = x;
        _y = y;
    }

    double getX() const{
        return _x;
    }

    double getY() const{
        return _y;
    }

private:
    double _x, _y;
};

#endif
