/*
 * string.cpp
 *
 *  Created on: 4 maj 2018
 *      Author: SERAGUD
 */

#include "core.hpp"

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory>

using namespace std;

Chars::Chars(char* chars) :
		chars(chars) {
}

Chars::~Chars() {
	delete[] chars;
}

String::String(Int length) :
		length(length), chars((char *) malloc(length)), deletable(
				new Chars(chars)) {
}

String::String(String& other) :
		length(other.length), chars(other.chars), deletable(other.deletable) {
}

String::String(String&& other) :
		length(other.length), chars(other.chars), deletable(other.deletable) {
}

String::String(char const* bytes, Int length) :
		length(length), chars((char *) malloc(length)), deletable(
				new Chars(chars)) {
	// TODO use memcpy?
	for (Int i = 0; i < length; i++) {
		chars[i] = bytes[i];
	}
}

String::String(String a, String b) :
		length(a.length + b.length), chars(
				(char *) malloc(a.length + b.length)), deletable(
				new Chars(chars)) {
	// TODO use memcpy?
	for (Int i = 0; i < a.length; i++) {
		chars[i] = a.chars[i];
	}
	for (Int i = 0; i < b.length; i++) {
		chars[a.length + i] = b.chars[i];
	}
}

void String::set(Int index, char ch) {
	if (index >= length) {
		// TODO throw?
	}

	chars[index] = ch;
}

char String::get(Int index) {
	if (index >= length) {
		// TODO throw?
	}

	return chars[index];
}

Int String_length(String s) {
	return s.length;
}

String String_init_fromBytes(char const * chars, Int size) {
	return String(chars, size);
}

String String_op_add(String self, String other) {
	return String(self, other);
}
