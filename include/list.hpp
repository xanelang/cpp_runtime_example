/*
 * list.hpp
 *
 *  Created on: 8 maj 2018
 *      Author: SERAGUD
 */

#ifndef INCLUDE_LIST_HPP_
#define INCLUDE_LIST_HPP_

#include "core.hpp"
#include <vector>
#include <algorithm>
#include "iterator.hpp"
#include "array.hpp"

using namespace std;

/*
template<typename ElementType>
class Container: public FixedSizedContainer<ElementType> {
public:
	virtual void add(ElementType el) = 0;

	virtual Bool isEmpty() = 0;

	virtual Bool isNotEmpty() = 0;

	virtual void addAll(Container<ElementType> elements) = 0;

	virtual void clear() = 0;

	virtual void insert(Int index, ElementType element) = 0;

	virtual void insertAll(Int index, Container<ElementType> element) = 0;

	virtual void remove(ElementType element) = 0;

	virtual ElementType removeAt(Int index) = 0;

	virtual ElementType removeLast() = 0;

	// TODO removeRange

	// TODO setAll

	// TODO setRange

	// TODO subList
};

template<typename ElementType>
class ListIterator;

template<typename ElementType>
class List: public Container<ElementType> {
	vector<ElementType> _elements;
public:
	Int length() {
		return _elements.size();
	}

	Bool isEmpty() {
		return _elements.size() == 0;
	}

	Bool isNotEmpty() {
		return _elements.size() != 0;
	}

	ElementType first() {
		// TODO throw or return optional?
		return _elements[0];
	}

	ElementType last() {
		return _elements[length() - 1];
	}

	Int indexOf(ElementType element) {
		for (uint64_t i = 0; i < size; i++) {
			ElementType& el = _elements[i];
			if (el == element) {
				return i;
			}
		}
		// TODO change return type to signed integer?
		return -1;
	}

	Int lastIndexOf(ElementType element) {
		for (uint64_t i = size - 1; size >= 0; i--) {
			ElementType& el = _elements[i];
			if (el == element) {
				return i;
			}
		}
		// TODO change return type to signed integer?
		return -1;
	}

	void add(ElementType el) {
		_elements.push_back(el);
	}

	void addAll(Container<ElementType> elements) {
		_elements.insert();
		// TODO implement
	}

	void clear() {
		_elements.clear();
	}

	void insert(Int index, ElementType element) {
		_elements.insert(index, element);
	}

	void insertAll(Int index, Container<ElementType> element) {
		// TODO
	}

	void remove(ElementType element) {
		_elements.erase(std::remove(_elements.begin(), _elements.end(), element), _elements.end());
	}

	ElementType removeAt(Int index) {
		ElementType ret = _elements[index.value];
		_elements.erase(index.value);
		return ret;
	}

	ElementType removeLast() {
		ElementType ret = _elements[length() - 1];
		_elements.pop_back();
		return ret;
	}

	void set(uint64_t index, ElementType el) {
		_elements[index] = el;
	}

	ElementType get(uint64_t index) {
		return _elements.at(index);
	}
};

template<typename ElementType>
class ListIterator: Iterator<ElementType> {
	List<ElementType>& _list;

	uint64_t _index;

	uint64_t _last;
public:
	ElementType current() {
		// TODO throw if _list has been modified
		return _list.get(_index);
	}

	Bool moveNext() {
		// TODO throw if _list has been modified
		if(_index >= _last) {
			return false;
		}
		_index++;
		return true;
	}

	Bool hasNext() {
		// TODO throw if _list has been modified
		return _index < _last;
	}

	void set(ElementType element) {
		_list.set(_index, element);
	}
};
*/

#endif /* INCLUDE_LIST_HPP_ */
