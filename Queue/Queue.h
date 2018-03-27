#pragma once
#include "DoublyLinkedList.h"

class Queue {
public:
	Queue();
	~Queue();
	void enqueue(int value);
	void dequeue();
	void clear();
	int size();

	friend std::ostream& operator<<(std::ostream& os, const Queue& queue);

private:
	DoublyLinkedList *list;
};

std::ostream& operator<<(std::ostream& os, const Queue& queue)
{
	os << *queue.list;
	return os;
}

Queue::Queue() : list(new DoublyLinkedList())
{
}

Queue::~Queue()
{
	delete list;
}

void Queue::enqueue(int value)
{
	Node *new_node = new Node(value);
	list->addAtBeggining(new_node);
}

void Queue::dequeue()
{
	list->removeFromEnd();
}

int Queue::size()
{
	return list->size();
}
void Queue::clear()
{
	list->clear();
}
