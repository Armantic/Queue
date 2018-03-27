// Queue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Queue.h"


int main()
{
	Queue queue = Queue();
	queue.enqueue(9);
	queue.enqueue(10);
	queue.enqueue(30);
	queue.enqueue(40);
	queue.enqueue(5);

	std::cout << queue;
	std::cout << "Size: " << queue.size() << std::endl;

	queue.dequeue();
	queue.dequeue();


	std::cout << queue;
	std::cout << "Size: " << queue.size() << std::endl;

//	queue.clear();
//	std::cout << "Size: " << queue.size() << std::endl;

    return 0;
}

