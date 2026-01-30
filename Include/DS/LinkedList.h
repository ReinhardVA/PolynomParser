#pragma once
#include <iostream>
using namespace std;


template <typename T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node(T val) : data(val), next(nullptr) {}
	};
	Node* head;
	Node* tail;
	int listSize;

public:
	class Iterator {
	private:
		Node* current;
	public:
		Iterator(Node* node) : current(node) {}

		T& operator*() const {
			return current->data;
		}

		Iterator& operator++() {
			if (current) {
				current = current->next;
			}
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return current != other.current;
		}
	};


public:
	LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

	LinkedList(const LinkedList& other) : head(nullptr), listSize(0) {
		Node* current = other.head;
		while (current != nullptr) {
			addEnd(current->data);
			current = current->next;
		}
	}

	~LinkedList() {
		clear();
	}
	
	void addFront(const T& value) {
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		if (tail == nullptr) {
			tail = head;
		}
		listSize++;
	}

	void addAt(const T& value, int index) {
		if (index < 0 || index > listSize) {
			cout << "Gecersiz index!" << endl;
			return;
		}

		if (index == 0) {
			addFront(value);
			return;
		}

		if (index == listSize) {
			addEnd(value);
			return;
		}

		Node* newNode = new Node(value);
		Node* current = head;

		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}

		newNode->next = current->next;
		current->next = newNode;
		listSize++;
	}

	void addEnd(const T& value) {
		if (head == nullptr) {
			addFront(value);
			return;
		}
		Node* newNode = new Node(value);
		tail->next = newNode;
		tail = newNode;
		listSize++;
	}

	void print() const {
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << endl;
			current = current->next;
		}
	}

	void removeFront() {
		if (head != nullptr) {
			Node* current = head;
			head = head->next;
			delete current;
			listSize--;
			if (head == nullptr) {
				tail = nullptr;
			}
		}
	}

	void removeAt(int index) {
		if (index < 0 || index >= listSize) return;

		if (index == 0) {
			removeFront();
		}
		else {
			Node* current = head;
			for (int i = 0; i < index - 1; i++) {
				current = current->next;
			}

			Node* nodeToDelete = current->next;
			if (nodeToDelete == tail) {
				tail = current;
			}
			current->next = nodeToDelete->next;
			delete nodeToDelete;
			listSize--;
		}
	}

	void removeEnd() {
		if (head == nullptr) return;

		if (head->next == nullptr) {
			removeFront();
		}
		else {
			Node* current = head;
			while (current->next->next != nullptr) {
				current = current->next;
			}
			delete current->next;
			current->next = nullptr;
			tail = current;
			listSize--;
		}
	}


	Iterator begin() {
		return Iterator(head);
	}
	
	Iterator end() {
		return Iterator(nullptr);
	}
	
	T& peekFront() {
		if (head == nullptr) {
			throw out_of_range("List is empty");
		}
		return head->data;
	}
	T& getDatas(int index) {
		Node* current = head;
		for(int i = 0; i < index; i++) {
			if(current == nullptr) {
				throw out_of_range("Index out of range");
			}
			current = current->next;
		}
		return current->data;
	}

	int search(const T& value) const {
		Node* current = head;
		int index = 0;
		while (current != nullptr) {
			if (current->data == value) {
				return index;
			}
			current = current->next;
			index++;
		}
		return -1;
	}

	[[nodiscard]]
	int size() const {
		return listSize;
	}

	[[nodiscard]]
	bool isEmpty() const {
		return listSize == 0;
	}

	void clear() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		listSize = 0;
	};
	
};