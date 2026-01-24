#pragma once
#include "LinkedList.h"

template <typename T>
class Stack
{
	LinkedList<T> list;
public:

	void push(const T& value) {
		list.addFront(value);
	}
	void pop() {
		list.removeFront();
	}
	T& top() {
		return list.peekFront();
	}
	bool isEmpty() const {
		return list.isEmpty();
	}
	int size() const {
		return list.size();
	}
	void clear() {
		list.clear();
	}

};