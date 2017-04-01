#pragma once

#include <iostream>
#include <string>

template<class T>
class Deque // ��������� ����� "���"
{
public:
	Deque(): head(NULL), last(NULL) // ��������� �����������
	{
	}

	~Deque() // � ������ ����������
	{
		while (head)
		{
			Node* tmpNode;
			tmpNode = head->next;
			delete head;
			head = tmpNode;
		}
	}

	void add_left(T val) // ������ ������� � ��� � ������ ����
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

	void add_right(T val) // ������ ������� � ��� � ������� ����
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

	T pop_left() // ������� ������� �� ���� � ������ ���� (������� �� ����, �� �������� ���������)
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

	T pop_right() // ������� ������� �� ���� � ������� ���� (������� �� ����, �� �������� ���������)
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

	void print_left() // ������� ���� ��� ����� �������
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

	void print_right() // ������� ���� ��� ������ ������
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
	struct Node // ��������� ��� �������� ���������
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