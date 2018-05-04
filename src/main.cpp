//============================================================================
// Name        : cpp_runtime.cpp
// Author      : Ravi Teja Gudapati <tejainece@gmail.com>
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "core.hpp"

using namespace std;

struct Point {
private:
	Point() {
	}
public:
	Int x = 0;
	Int y = 0;

	friend Point Point_init(Int x, Int y);
};

Point Point_init(Int x, Int y) {
	Point self;
	self.x = x;
	self.y = y;
	return self;
}

Double Point_length(Point self) {
	return Int_sqrt(
			Int_op_add(Int_op_mul(self.x, self.x), Int_op_mul(self.y, self.y)));
}

Point Point_op_add(Point* self, Point* other) {
	return Point_init(Int_op_add(self->x, other->x),
			Int_op_add(self->y, other->y));
}

String Point_toString(Point self) {
	return String_op_add(
			String_op_add(
					String_op_add(
							String_op_add(String_init_fromBytes("(", 1),
									Int_toString(self.x)), String_init_fromBytes(", ", 2)),
					Int_toString(self.y)), String_init_fromBytes(")", 1));
}

class Rect {
public:
	Int length;

	Int height;

private:
	Rect();

	// friend Rect* Rect_init(Int length, Int height);
};

int main() {
	Int a = 5;
	Int b = 20;
	print(Int_toString(Int_op_add(a, b)));

	Point point = Point_init(5, 10);
	print(Point_toString(point));

	Point point1 = Point_init(10, 5);
	print(Point_toString(point1));

	print(Double_toString(Point_length(point)));

	// Point_init(&point, 5, 10);
	// printf("%u\n", (uint64_t) Point_length(point));

	/*
	 Point point2;
	 Point add = Point_op_add(&point, &point2);
	 printf("%u\n", Point_toString(add));
	 */
}
