//============================================================================
// Name        : cpp_runtime.cpp
// Author      : Ravi Teja Gudapati <tejainece@gmail.com>
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>
#include <vector>
#include "core.hpp"
#include <memory>

#include "point.hpp"
#include "rect.hpp"
#include "person.hpp"
#include "taskrunner.hpp"

using namespace std;

template<typename T>
class Any {
public:
	T* ptr;

	Any(T* ptr) :
			ptr(ptr) {
	}

	T& operator*() {
		return *ptr;
	}

	T* operator->() {
		return ptr;
	}
};

template<size_t size>
class Chars {
	char _chars[size];
public:

};

class PointInterface {
public:
	virtual Int& getX() = 0;

	virtual Int twice() const = 0;

	virtual Int add(PointInterface* other) = 0;
};

class Point2: public PointInterface {
public:
	Int x;

	Point2(Int x) :
			x(x) {

	}

	Int twice() const {
		return x + x;
	}

	~Point2() {
	}

	Int add(PointInterface* other) {
		return x + other->getX();
	}

	Int& getX() {
		return x;
	}
};

class Point3: public PointInterface {
public:
	Int x;

	Point3() :
			x(0) {

	}

	Point3(Int x) :
			x(x) {
	}

	Int twice() const {
		return x + x;
	}

	~Point3() {
	}

	Int add(PointInterface* other) {
		return x - other->getX();
	}

	Int& getX() {
		return x;
	}

	Bool operator==(Point3 other) {
		return x == other.x;
	}

	static Point3 init(Int x) {
		Point3 self;
		self.x = x;
		return self;
	}
};

int main() {
	/*
	 Point2 p2(5);
	 Point3 p3(20);
	 printf("%ld\n", p2.add(&p3).value);
	 printf("%ld\n", p3.add(&p2).value);

	 Array<Point3, 5> array = { Point3::init(10), Point3::init(20), Point3::init(
	 30), Point3::init(40), Point3::init(50), };
	 array.set(2, p3);
	 printf("%ld\n", array.get(2).x.value);
	 printf("%ld\n", array.indexOf(p3).value);
	 printf("%ld\n", array.last().x.value);

	 doublePoint(Point::init(5, 10)).x = 10;
	 Point::init(5, 10).x = 10;
	 */

	// std::array<int, 5> a;
	/*
	 Int a = 5;
	 Int b = 20;
	 print((a + b).toString());

	 Point point = Point::init(5, 10);
	 print(point.toString());

	 Point point1 = Point::init(10, 5);
	 print(point1.toString());

	 print(point.length().toString());

	 printPoint(doublePoint(Point::init(5, 10)));
	 */

	/*
	 hello(teja());

	 if (point.runtimeType() == point1.runtimeType()) {
	 print(NewROString("Yes"));
	 }
	 */

	/* TODO
	Reference<Animal> animal = Dog::init().as<Animal>();
	animal->eat();
	{
		Reference<Dog> dog = animal.as<Dog>();
		dog->bark();
	}
	animal = Cat::init().as<Animal>();
	animal->eat();
	{
		Reference<Cat> cat = animal.as<Cat>();
		cat->meow();
	}
	*/

	 MyTask task = MyTask::init(5);
	 TaskRunner<MyTask> runner = TaskRunner<MyTask>::init(task);
	 runner.execute();
}

/*

 class List<T> {
 var t: T
 }

 */

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
 print(NewROString("Yes"));
 }
 */
