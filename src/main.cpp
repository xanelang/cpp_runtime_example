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

class Point: public Object {
public:
	Point() {
	}

	Int x = 0;
	Int y = 0;

	Double length() const {
		return ((x * x) + (y * y)).sqrt();
	}

	Point operator+(Point* other) {
		return Point::init(x + other->x, y + other->y);
	}

	Reference<String> toString() const {
		return String_init_fromBytes("(", 1)
				->concat(x.toString())
				->concat(String_init_fromBytes(", ", 2))
				->concat(y.toString())
				->concat(String_init_fromBytes(")", 1));
	}

	const Type runtimeType() const {
		return xaneType;
	}

	static const Type xaneType;

	static Point init(Int x, Int y) {
		Point self;
		self.x = x;
		self.y = y;
		return self;
	}
};

const Type Point::xaneType("Sample", "Sample", "Point");

class Rect: public ReferencedObject {
public:
	Rect() {
	}

	Int length;

	Int height;

	Int area() const {
		return length * height;
	}

	Reference<String> toString() const {
		return String_init_fromLiteral("Rect(length: ")
				->concat(length)
				->concat(String_init_fromLiteral(", height"))
				->concat(height)
				->concat(String_init_fromLiteral(")"));
	}

	const Type runtimeType() const {
		return xaneType;
	}

	static const Type xaneType;

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

const Type Rect::xaneType("Sample", "Sample", "Rect");

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
		print(CString("Being deleted: ").concat(name));
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
		print(CString("Being deleted: ").concat(name));
	}

	static const Type xaneType;

	static Reference<Person> init() {
		Reference<Person> self(new Person());
		self->name = String_init_fromLiteral("Teja");
		self->todo1 = Todo::init(String_init_fromLiteral("Laundry"));
		self->todo2 = Todo::init(String_init_fromLiteral("Xane"));
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

static const char * inText = "Hello";

static uint64_t inData = 5;

void printType(Type t) {
	int inStack;
	print(t.name);
	printf("0x%p\n", t.name.chars);
	printf("0x%p\n", &t.library);
	printf("0x%p\n", hello);
	printf("0x%p\n", inText);
	printf("0x%p\n", &inData);
	uint64_t& address = *(uint64_t *)0x0040b010;
	printf("%d\n", address);
	printf("%p\n", &inStack);

}

int main() {
	/*
	Int a = 5;
	Int b = 20;
	print((a + b).toString());

	Point point = Point::init(5, 10);
	print(point.toString());

	Point point1 = Point::init(10, 5);
	print(point1.toString());

	print(point.length().toString());

	hello(teja());

	if(point.runtimeType() == point1.runtimeType()) {
		print(CString("Yes"));
	}
	*/

	// Point_init(&point, 5, 10);
	// printf("%u\n", (uint64_t) Point_length(point));

	/*
	 Point point2;
	 Point add = Point_op_add(&point, &point2);
	 printf("%u\n", Point_toString(add));
	 */

	print("---");

	Type t = Person::xaneType;
	printType(t);
}

/*

class List<T> {
	var t: T
}

 */
