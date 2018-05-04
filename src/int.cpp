/*
 * int.cpp
 *
 *  Created on: 4 maj 2018
 *      Author: SERAGUD
 */

#include "core.hpp"

#include <stdio.h>
#include <math.h>

using namespace std;

Int Int_init(int val) {
	return val;
}

Int Int_op_add(Int self, Int other) {
	return self + other;
}

Int Int_op_mul(Int self, Int other) {
	return self * other;
}

Double Int_toDouble(Int self) {
	return self;
}

String Int_toString(Int self) {
	Int size = log10(self) + 1;
	char chars[size + 1];
	snprintf(chars, size + 1, "%I64u", self);
	return String_init_fromBytes(chars, size);
}

Double Int_sqrt(Int self) {
	return sqrt(self);
}


