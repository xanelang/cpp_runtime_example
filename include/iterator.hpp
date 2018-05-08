/*
 * iterator.hpp
 *
 *  Created on: 8 maj 2018
 *      Author: SERAGUD
 */

#ifndef INCLUDE_ITERATOR_HPP_
#define INCLUDE_ITERATOR_HPP_

#include "core.hpp"

using namespace std;

template<typename ElementType>
struct Iterator {
	virtual ElementType current() = 0;

	virtual Bool moveNext() = 0;

	virtual Bool hasNext() = 0;
};

#endif /* INCLUDE_ITERATOR_HPP_ */
