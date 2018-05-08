/*
 * person.hpp
 *
 *  Created on: 7 maj 2018
 *      Author: SERAGUD
 */

#ifndef INCLUDE_PERSON_HPP_
#define INCLUDE_PERSON_HPP_

#include "core.hpp"

class Todo: public ReferencedObject {
public:
	Todo() {
	}

	Todo& operator=(Todo&& other) {
		name = other.name;
		return *this;
	}

	Reference<String> name;

	const Type runtimeType() const {
		return xaneType;
	}

	static const Type xaneType;


	Reference<String> toString() const {
		return name.toString();
	}

	void deinit() {
		print(NewROString("Being deleted: ").concat(name));
	}

	static Reference<Todo> init(Reference<String> name) {
		Reference<Todo> self(new Todo());
		self->name = name;
		return self;
	}
};

const Type Todo::xaneType("Sample", "Sample", "Todo");

class Person: public ReferencedObject {
public:
	Person() {
	}

	Reference<String> name;

	Reference<Todo> todo1;
	Reference<Todo> todo2;

	const Type runtimeType() const {
		return xaneType;
	}

	Reference<String> toString() const {
		return name.toString();
	}

	void deinit() {
		print(NewROString("Being deleted: ").concat(name));
	}

	static const Type xaneType;

	static Reference<Person> init() {
		Reference<Person> self(new Person());
		self->name = String::init_fromLiteral("Teja");
		self->todo1 = Todo::init(String::init_fromLiteral("Laundry"));
		self->todo2 = Todo::init(String::init_fromLiteral("Xane"));
		return self;
	}

	/*
	 Int Rect_area(Reference<Rect> self) {
	 // TODO self->length
	 }
	 */
};

const Type Person::xaneType("Sample", "Sample", "Person");

Reference<Person> teja() {
	return Person::init();
}

void hello(Reference<Person> person) {
	print(person->name);
	print(person->todo1->name);
	print(person->todo2->name);
}

#endif /* INCLUDE_PERSON_HPP_ */
