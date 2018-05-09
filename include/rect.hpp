/*
 * rect.hpp
 *
 *  Created on: 7 maj 2018
 *      Author: SERAGUD
 */

#ifndef INCLUDE_RECT_HPP_
#define INCLUDE_RECT_HPP_

#include "core.hpp"

struct Animal: public ReferencedObject {
	// TODO virtual void eat() = 0;
	virtual void eat() {
		print(String::init_fromLiteral("yum yum!"));
	}
};

struct Dog: Animal {
	virtual void eat() {
		print(String::init_fromLiteral("yum yum!"));
	}
	virtual void bark() {
		print(String::init_fromLiteral("bow bow!"));
	}
	static Reference<Dog> init() {
		Reference<Dog> self(new Dog());
		return self;
	}
	~Dog() {
		print(String::init_fromLiteral("Dog deleted!"));
	}
};

struct Cat: Animal {
	virtual void eat() {
		print(String::init_fromLiteral("yum yum!"));
	}
	virtual void meow() {
		print(String::init_fromLiteral("meow meow!"));
	}
	static Reference<Cat> init() {
		Reference<Cat> self(new Cat());
		return self;
	}
	~Cat() {
		print(String::init_fromLiteral("Cat deleted!"));
	}
};

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
