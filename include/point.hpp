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

struct Point {
	Int x;
	Int y;
	static Point init(Int x, Int y) {
		Point self;
		self.x = x;
		self.y = y;
		return self;
	}
	Double length() {
		return ((x + x) + (y + y)).sqrt();
	}
	Reference<String> toString() {
		return String::init_fromBytes("(", 1)->operator+(x.toString())->operator+(
				String::init_fromBytes(", ", 2))->operator+(y.toString())->operator+(
				String::init_fromBytes(")", 1));
	}
	Point operator+(Point other) {
		return Point::init((x + other.x), (y + other.y));
	}
	const Type runtimeType() const {
		return xaneType;
	}
	static constexpr Type xaneType = Type("Sample", "Sample", "Point");
};

#endif /* INCLUDE_POINT_HPP_ */
