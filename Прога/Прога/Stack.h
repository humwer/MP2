#pragma once

#include <string>

template<class T>
class Stack  // ��������� ����� "����"
{
public:
	Stack() :back(0), head(0) // ��������� �����������
	{
	}

	~Stack() // � ������ ����������
	{
		while (head)
		{
			back = head->next;
			delete head;
			head = back;
		}
	}

	void add(T val) // ������ ������� � ����
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

	T pop() // ������� ������� �� ����� (������� �� ����, �� �������� ���������)
	{       
		if (back == 0)
		{
			throw std::string("Oh, my god!"); // �� ��������� �������� � ������ ������, ������� ��������� ������� ���������.
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

	void print() // ������� ���� ���� ��� �������� 
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
	struct Node // ��������� ��� �������� ���������
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

