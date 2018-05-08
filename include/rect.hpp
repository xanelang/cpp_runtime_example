/*
 * rect.hpp
 *
 *  Created on: 7 maj 2018
 *      Author: SERAGUD
 */

#ifndef INCLUDE_RECT_HPP_
#define INCLUDE_RECT_HPP_

#include "core.hpp"

class Rect: public ReferencedObject {
public:
	Rect() {
	}

	Int length;

	Int height;

	Int area() {
		return length * height;
	}

	Reference<String> toString() {
		return String::init_fromLiteral("Rect(length: ")
				->concat(length)
				->concat(String::init_fromLiteral(", height"))
				->concat(height)
				->concat(String::init_fromLiteral(")"));
	}

	const Type runtimeType() const {
		return xaneType;
	}

	static constexpr Type xaneType = Type("Sample", "Sample", "Rect");

	/*
	void deinit() {

	}
	*/

	static Reference<Rect> init(Int length, Int height) {
		Reference<Rect> self(new Rect());
		self->length = length;
		self->height = height;
		return self;
	}
};
#endif /* INCLUDE_RECT_HPP_ */
