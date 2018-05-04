/*
 * core.cpp
 *
 *  Created on: 4 maj 2018
 *      Author: SERAGUD
 */

#include "core.hpp"

#include <stdio.h>

void print(String string, bool newLine) {
	for (Int i = 0; i < string.length; i++) {
		putchar(string.get(i));
	}
	if (newLine)
		putchar('\n');
}
