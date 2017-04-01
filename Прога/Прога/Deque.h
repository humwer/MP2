#pragma once

#include <iostream>
#include <string>

template<class T>
class Deque // Объявляем класс "Дек"
{
public:
	Deque(): head(NULL), last(NULL) // Объявляем конструктор
	{
	}

	~Deque() // и следом деструктор
	{
		while (head)
		{
			Node* tmpNode;
			tmpNode = head->next;
			delete head;
			head = tmpNode;
		}
	}

	void add_left(T val) // Вносим элемент в дек с левого края
	{
		
		Node* Temp = new Node;
		Node* current = head;
		Temp->element = val;
		if (head == 0)
		{
			head = Temp;
			head->next = NULL;
			
			last = head;
			return;
		}
		Temp->next = head;
		head = Temp;
		Temp->next->prev = head;
	}

	void add_right(T val) // Вносим элемент в дек с правого края
	{
		Node* Temp = new Node;
		Node* current = last;
		Temp->element = val;
		if (head == 0)
		{
			head = Temp;
			head->next = NULL; 
			head->prev = NULL;

			last = head;
			return;
		}
		last->next = Temp;
		last = Temp;
		last->prev = current;
	}

	T pop_left() // Забрать элемент из дека с левого края (удалить из него, но значение сохранить)
	{
		if (last == NULL)
		{
			printf("Oh my god!");
		}
		else
		{
			T TempElement = head->element;

			head = head->next;

			Node* delPtr = head->prev;
			delete delPtr;
			head->prev = NULL;

			return TempElement;
		}
	}

	T pop_right() // Забрать элемент из дека с правого края (удалить из него, но значение сохранить)
	{
		if (last == NULL)
		{
			printf("Oh, my god!");
		}
		else
		{
			T TempElement = last->element;

			last = last->prev;

			Node* delPtr = last->next;
			delete delPtr;
			last->next = NULL;
			
			return TempElement;
		}
	}

	void print_left() // Выводим весь дек слева направо
	{
		if (head == NULL)
		{
			printf("Oh, my god!\n");
		}
		else
		{
			for (Node* ptr = head; ptr != NULL; ptr = ptr->next)
				std::cout << ptr->element << ' ';
			std::cout << '\n';
		}
	}

	void print_right() // Выводим весь дек справа налево
	{
		if (head == NULL)
		{
			printf("Oh, my god!\n");
		}
		else
		{
			for (Node* ptr = last; ptr != NULL; ptr = ptr->prev)
				std::cout << ptr->element << ' ';
			std::cout << '\n';
		}
	}

private:
	struct Node // Структура для указания элементов
	{
		Node() : element(NULL), next(NULL), prev(NULL)
		{
		}
		Node* next;
		Node* prev;
		T element;
	};
	Node* head;
	Node* last;
};