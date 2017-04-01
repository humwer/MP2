// Прога.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "Stack.h"
#include <fstream>
#include <sstream>

using namespace std;


int main()
{
	Stack<char> Char;
	Stack<int> Int;
	string st;
	// Чтение из файла
	ifstream ReadSt("example.txt");
	ReadSt >> st;
	while (ReadSt.get() != EOF) // Посимвольно берём из файла и так до конца (EOF)
	{
		ReadSt >> st;
	}
	cout << st << endl;
	// Запись в стеки (Через два стека проще реализовать, в одном хранятся значения "0" и "1", в другом операции над ними.)
	int k = 0;
	char rec = st[k];
	while (k != st.size())
	{
		switch (rec)
		{
		case 'T':
			Int.add(1);
			break;
		case 'F':
			Int.add(0);
			break;
		case 'N':
			Char.add('N');
			break;
		case 'A':
			Char.add('A');
			break;
		case 'X':
			Char.add('X');
			break;
		case 'O':
			Char.add('O');
			break;
		case '.':
			Char.add('.');
			break;
		}
		k++;
		rec = st[k];
	}
	Int.print(); // Для проверки выводим сначала стек со значениями
	Char.print(); // Потом стек с операциями
	// Решение логического выражения 
	char buf = Char.pop(); 
	int StBuf = Int.pop();
	int ibuf = StBuf;
	while (buf != '.') // Костыль, проще поставить перед выражением символ, на котором заканчивается работа со стеком.
	{
			if (buf == 'N') // Стандартная операция "не"
			{
				switch (StBuf)
				{
				case 1: StBuf = 0; break;
				case 0: StBuf = 1; break;
				default: break;
				}
				buf = Char.pop();
				ibuf = StBuf;
			}
			else if (buf == 'A') // Операция "и" (по мне так, универсальная, можно было бы просто указать, что когда две единицы - единица, в ином случае - ноль.)
			{
				StBuf = Int.pop();
				if ((ibuf == 1) && (StBuf == 1))
					ibuf = 1;
				else if ((ibuf == 0) && (StBuf == 1))
					ibuf = 0;
				else if ((ibuf == 1) && (StBuf == 0))
					ibuf = 0;
				else if ((ibuf == 0) && (StBuf == 0))
					ibuf = 0;
				buf = Char.pop();
			}
			else if (buf == 'O') // Операция "или" (тоже хорошая операция, если два нуля - ноль, в ином случае - единица.)
			{
				StBuf = Int.pop();
				if ((ibuf == 1) && (StBuf == 1))
					ibuf = 1;
				else if ((ibuf == 0) && (StBuf == 1))
					ibuf = 1;
				else if ((ibuf == 1) && (StBuf == 0))
					ibuf = 1;
				else if ((ibuf == 0) && (StBuf == 0))
					ibuf = 0;
				buf = Char.pop();
			}
			else if (buf == 'X') // Полезная операция, но не такая универсальная в плане написания, хотя... (Если они не равны, то - единица, в ином случае - ноль.)
			{
				StBuf = Int.pop();
				if ((ibuf == 1) && (StBuf == 1))
					ibuf = 0;
				else if ((ibuf == 0) && (StBuf == 1))
					ibuf = 1;
				else if ((ibuf == 1) && (StBuf == 0))
					ibuf = 1;
				else if ((ibuf == 0) && (StBuf == 0))
					ibuf = 0;
				buf = Char.pop();
		}
	}
	if (ibuf == 0) // В конечном итоге пишем, чему равно всё выражение
		cout << "False" << endl;
	else
		cout << "True" << endl;
	system("pause");
}
