/*
 * double.cpp
 *
 *  Created on: 4 maj 2018
 *      Author: SERAGUD
 */

#include "core.hpp"

#include <stdio.h>
#include <math.h>

Double Double_op_add(Double self, Double other) {
	return self + other;
}

Double Double_op_mul(Double self, Double other) {
	return self * other;
}

Int Double_toInt(Double self) {
	return self;
}

Double Double_sqrt(Double self) {
	return sqrt(self);
}

String Double_toString(Double self) {
	Int size = snprintf(NULL, 0, "%f", self);
	char chars[size];
	snprintf(chars, size, "%f", self);
	return String_init_fromBytes(chars, size - 1);
}

