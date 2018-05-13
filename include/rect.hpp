/*
 * rect.hpp
 *
 *  Created on: 7 maj 2018
 *      Author: SERAGUD
 */

#ifndef INCLUDE_RECT_HPP_
#define INCLUDE_RECT_HPP_

#include "core.hpp"

struct Animal: ReferencedObject {
  static constexpr Type xaneType = Type("Sample", "Sample", "Animal");
  Type runtimeType() {
    return xaneType;
  }
  virtual Void eat() = 0;
};
struct Dog: Animal {
  static constexpr Type xaneType = Type("Sample", "Sample", "Dog");
  static Reference<Dog> init() {
    return Reference<Dog>(new Dog());
  }
  Void eat() {
    print(String::init_fromBytes("yum yum!", 8));
  }
  Void bark() {
    print(String::init_fromBytes("bow bow!", 8));
  }
  Type runtimeType() {
    return xaneType;
  }
  ~Dog() {
    print(String::init_fromBytes("Dog deinitialized!", 18));
  }
};
constexpr Type Animal::xaneType;
constexpr Type Dog::xaneType;

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
	static constexpr Type xaneType = Type("Sample", "Sample", "Rect");
	Rect() {
	}

	Int length;

	Int height;

	Int area() {
		return length * height;
	}

	Reference<String> toString() {
		return String::init_fromLiteral("Rect(length: ")->concat(length)->concat(
				String::init_fromLiteral(", height"))->concat(height)->concat(
				String::init_fromLiteral(")"));
	}

	const Type runtimeType() const {
		return xaneType;
	}


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

constexpr Type Rect::xaneType;

#endif /* INCLUDE_RECT_HPP_ */
