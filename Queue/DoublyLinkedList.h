#pragma once
#include <iostream>

struct Node
{
	Node *next;
	Node *prev;
	int value;
	Node() : next(nullptr), prev(nullptr) {}
	Node(int _value) : value(_value), next(nullptr), prev(nullptr) {}
};

class  DoublyLinkedList {
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void addAtBeggining(Node *new_node);
	void removeFromEnd();
	int size();
	bool isEmpty();
	void clear();

	friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& dt);

private:
	Node *head;
	Node *tail;
};

std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& list)
{
	Node *cur_node = list.head->next;
	while (cur_node != list.tail) {
		os << cur_node->value << " ";
		cur_node = cur_node->next;
	}
	os << std::endl;

	return os;
}

DoublyLinkedList::DoublyLinkedList() :
	head(new Node()),
	tail(new Node())
{
	head->next = tail;
	tail->prev = head;
}

DoublyLinkedList::~DoublyLinkedList()
{
	while (head)
	{
		Node *new_head = head->next;
		delete head;
		head = new_head;
	}
}

void DoublyLinkedList::addAtBeggining(Node *new_node)
{
	new_node->next = head->next;
	head->next = new_node;

	new_node->next->prev = new_node;
	new_node->prev = head;
}

void DoublyLinkedList::removeFromEnd()
{
	Node *del_node = tail->prev;
	if (del_node == head)
	{
		std::cout << "Queue is empty!" << std::endl;
		return;
	}

	tail->prev = del_node->prev;
	del_node->prev->next = tail;
	delete del_node;
}

void DoublyLinkedList::clear()
{
	while (!isEmpty())
		removeFromEnd();
}

int DoublyLinkedList::size()
{
	Node *cur_node = head->next;
	int count = 0;
	while (cur_node != tail)
	{
		cur_node = cur_node->next;
		count++;
	}
	return count;
}

bool DoublyLinkedList::isEmpty()
{
	if (size() > 0)
		return false;
	return true;
}
