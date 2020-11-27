.PHONY: dirs clean

SRC = src/shape.h src/shape.cpp src/rectangle.h src/ellipse.h src/two_dimensional_coordinate.h src/triangle.h src/compound_shape.h \
		src/iterator.h src/null_iterator.h src/shape_iterator.h src/utility.h \
		src/visitor.h src/area_visitor.h src/info_visitor.h src/scanner.h src/shape_builder.h src/shape_parser.h
TEST = test/ut_rectangle.h test/ut_ellipse.h test/ut_triangle.h test/ut_compound_shape.h test/ut_iterator.h test/ut_utility.h \
		test/ut_visitor.h test/ut_scanner.h test/ut_shape_builder.h test/ut_shape_parser.h

all: dirs ut_main

ut_main: test/ut_main.cpp $(TEST) $(SRC)
	g++ -std=c++11 -Wfatal-errors src/shape.cpp test/ut_main.cpp -o bin/ut_main -lgtest -lpthread

dirs:
	mkdir -p bin
	mkdir -p obj

clean:
	rm -f bin/*

