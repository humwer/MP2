#pragma once

#include <iostream>
#include <string>

template<class T>
class Queue // ��������� ����� "�������"
{
public:
	Queue() :head(0), tail(NULL) // ��������� �����������
	{
	}

	~Queue() // � ������ ����������
	{
		while (head)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
	}

	void add(T val) // ������ ������� � �������
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

	
	T& pop() // ������� ������� �� ������� (������� �� ����, �� �������� ���������)
	{
		if (tail == NULL)
		{
			printf("Oh, my god!"); // �� ��������� �������� � ������ ��������, ������� ��������� ������� ���������.
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
	
	void print()  // ������� ��� ������� ��� �������� 
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
	struct Node // ��������� ��� �������� ���������
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