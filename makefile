.PHONY: dirs clean

SRC = src/shape.h src/shape.cpp src/rectangle.h src/ellipse.h src/two_dimensional_coordinate.h src/triangle.h src/compound_shape.h
TEST = test/ut_rectangle.h test/ut_ellipse.h test/ut_triangle.h test/ut_compound_shape.h

all: dirs ut_main

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 -Wfatal-errors src/shape.cpp test/ut_main.cpp -o bin/ut_main -lgtest -lpthread

dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/*

