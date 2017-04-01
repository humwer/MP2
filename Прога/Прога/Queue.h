#pragma once

#include <iostream>
#include <string>

template<class T>
class Queue // Объявляем класс "Очередь"
{
public:
	Queue() :head(0), tail(NULL) // Объявляем конструктор
	{
	}

	~Queue() // и следом деструктор
	{
		while (head)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
	}

	void add(T val) // Вносим элемент в очередь
	{
		Node* Temp = new Node;
		Temp->element = val;
		if (head == 0)
		{
			head = Temp;
			tail = Temp;
			return;
		}
		tail->next = Temp;
		tail = Temp;
	}

	
	T& pop() // Забрать элемент из очереди (удалить из него, но значение сохранить)
	{
		if (tail == NULL)
		{
			printf("Oh, my god!"); // Во избежании проблемы с пустой очередью, спасаем положение выводом сообщения.
		}
		else
		{
			T tmp = head->element;
			Node* delPtr = head;
			head = head->next;
			delete delPtr;
			return tmp;
		}
	}
	
	void print()  // Выводим всю очередь для проверки 
	{
		if (tail == NULL)
		{
			printf("Oh, my god!\n");
		}
		else
		{
			for (Node* ptr = head; ptr != 0; ptr = ptr->next)
				std::cout << ptr->element << ' ';
			std::cout << '\n';
		}
	}

private:
	struct Node // Структура для указания элементов
	{
		Node() :next(0), element(0)
		{
		}
		Node* next;
		T element;
	};
	Node* head;
	Node* tail;
};