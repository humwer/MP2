#pragma once

#include <string>

template<class T>
class Stack  // Объявляем класс "Стек"
{
public:
	Stack() :back(0), head(0) // Объявляем конструктор
	{
	}

	~Stack() // и следом деструктор
	{
		while (head)
		{
			back = head->next;
			delete head;
			head = back;
		}
	}

	void add(T val) // Вносим элемент в стек
	{
		Node* Temp;
		Temp = new Node;
		Temp->element = val;
		if (back == 0)
		{
			back = Temp;
		}
		else
		{
			Temp->next = back;
			back = Temp;
		}
	}

	T pop() // Забрать элемент из стека (удалить из него, но значение сохранить)
	{       
		if (back == 0)
		{
			throw std::string("Oh, my god!"); // Во избежании проблемы с пустым стеком, спасаем положение выводом сообщения.
		}
		else
		{                      
			T tmp = back->element;
			Node* delptr = back;
			back = back->next;
			delete delptr;
			return tmp; 
		}
	}

	void print() // Выводим весь стек для проверки 
	{
		if (back == NULL)
		{
			printf("Oh, my god!\n");
		}
		else
		{
			for (Node* ptr = back; ptr != 0; ptr = ptr->next)
			{
				std::cout << ptr->element << ' ';
			}
			std::cout << '\n';
		}
	}
private:
	struct Node // Структура для указания элементов
	{
		Node() :element(0), next(0)
		{
		}
		Node* next;
		T element;
	};
	Node* head;
	Node* back;
};

