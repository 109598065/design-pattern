.PHONY: dirs clean

SRC = src/shape.h src/rectangle.h src/ellipse.h src/two_dimensional_coordinate.h src/triangle.h src/sort.h src/terminal.h
TEST = test/ut_rectangle.h test/ut_ellipse.h test/ut_triangle.h test/ut_sort.h test/ut_terminal.h

all: dirs ut_main geo

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 -Wfatal-errors test/ut_main.cpp -o bin/ut_main -lgtest -lpthread

geo: src/main.cpp
	g++ src/main.cpp -o bin/geo -lgtest -lpthread

dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/*

