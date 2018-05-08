/*
 * point.hpp
 *
 *  Created on: 7 maj 2018
 *      Author: SERAGUD
 */

#ifndef INCLUDE_POINT_HPP_
#define INCLUDE_POINT_HPP_

#include "core.hpp"

using namespace std;

class Point: public Object {
public:
	Point() {
	}

	Int x = 0;
	Int y = 0;

	Double length() {
		return ((x * x) + (y * y)).sqrt();
	}

	Point operator+(Point* other) {
		return Point::init(x + other->x, y + other->y);
	}

	Reference<String> toString() {
		return String::init_fromLiteral("(")
				->concat(x.toString())
				->concat(String::init_fromLiteral(", "))
				->concat(y.toString())
				->concat(String::init_fromLiteral(")"));
	}

	const Type runtimeType() const {
		return xaneType;
	}

	static constexpr Type xaneType = Type("Sample", "Sample", "Point");

	static Point init(Int x, Int y) {
		Point self;
		self.x = x;
		self.y = y;
		return self;
	}
};

#endif /* INCLUDE_POINT_HPP_ */
