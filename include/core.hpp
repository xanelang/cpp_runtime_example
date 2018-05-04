/*
 * core.hpp
 *
 *  Created on: 4 maj 2018
 *      Author: SERAGUD
 */

#ifndef INCLUDE_CORE_HPP_
#define INCLUDE_CORE_HPP_

#include <stdint.h>

typedef uint64_t Int;

typedef double Double;

template<typename T>
class Reference;

template<typename T>
struct RefCount {
private:
	Int sharedCount;
	Int weakCount;
	T* ptr;

	friend class Reference<T> ;

public:
	RefCount(T* ptr) :
			sharedCount(1), weakCount(0), ptr(ptr) {
		if (ptr == nullptr) {
			// TODO throw?
		}
	}

	void incrementShared() {
		if (ptr == nullptr) {
			// TODO throw?
			return;
		}
		sharedCount++;
	}

	void decrementShared() {
		if (ptr == nullptr) {
			// TODO throw?
			return;
		}
		if (sharedCount != 0) {
			sharedCount--;
			if (sharedCount == 0) {
				delete ptr;
			}
		}
		if (sharedCount == 0 && weakCount == 0) {
			delete this;
		}
	}

	void incrementWeak() {
		if (ptr == nullptr) {
			// TODO throw?
			return;
		}
		weakCount++;
	}

	void decrementWeak() {
		if (weakCount == 0) {
			return;
		}
		weakCount--;
		if (sharedCount == 0 && weakCount == 0) {
			delete this;
		}
	}
};

template<typename T>
class Reference {
private:
	RefCount<T>* __rc__;

public:
	Reference() :
			__rc__(nullptr) {
	}

	Reference(T* ptr) :
			__rc__(new RefCount<T>(ptr)) {
	}

	Reference(Reference<T>& other) :
			__rc__(other.__rc__) {
		__rc__->incrementShared();
	}

	~Reference() {
		clear();
	}

	void clear() {
		if (__rc__ == nullptr)
			return;
		__rc__->decrementShared();
		__rc__ = nullptr;
	}

	void operator=(Reference<T> other) {
		clear();
		other.__rc__->incrementShared();
		__rc__ = other.__rc__;
	}

	void operator=(T* other) {
		clear();
		__rc__ = new RefCount<T>(other);
	}

	bool isValid() const {
		return __rc__ != nullptr;
	}

	T& get() const {
		if (__rc__ == nullptr) {
			// TODO throw
		}
		return *__rc__->ptr;
	}

	T* getPtr() const {
		if (__rc__ == nullptr) {
			// TODO throw
		}
		return __rc__->ptr;
	}

	T& operator*() const {
		if (__rc__ == nullptr) {
			// TODO throw
		}
		return *__rc__->ptr;
	}

	T* operator->() const {
		if (__rc__ == nullptr) {
			// TODO throw
		}
		return __rc__->ptr;
	}
};

class Chars {
public:
	char* chars;

	Chars(char* chars);

	~Chars();
};

class String {
	String(Int length);

	String(char const* bytes, Int length);

	String(String a, String b);

public:
	Int length;

	char *chars;

private:
	Reference<Chars> deletable;

public:
	String(String& other);

	String(String&& other);

	void set(Int index, char ch);

	char get(Int index);

	friend String String_init_fromBytes(char const * chars, Int size);
	friend String String_op_add(String self, String other);
};

Int Int_init(int val);

Int Int_op_add(Int self, Int other);

Int Int_op_mul(Int self, Int other);

Double Int_toDouble(Int self);

String Int_toString(Int self);

Double Int_sqrt(Int self);

Double Double_op_add(Double self, Double other);

Double Double_op_mul(Double self, Double other);

Int Double_toInt(Double self);

Double Double_sqrt(Double self);

String Double_toString(Double self);

String String_init_fromBytes(char const * chars, Int size);

Int String_length(String s);

String String_op_add(String self, String other);

void print(String string, bool newLine = true);

#endif /* INCLUDE_CORE_HPP_ */
