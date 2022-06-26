﻿
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
	
	enum { EMPTY = -1, FULL = 20 }; //Нижняя и верхняя границы стека
	
	char st[FULL + 1]; //Массив для хранения данных
	
	int top; //Указатель на вершину стека

public:
	
	Stack(); //Конструктор
	
	void Push(char c); //Добавление элемента
	
	char Pop(); //Извлечение элемента
	
	void Clear();//Очистка стека
	
	bool IsEmpty(); //Проверка существования элементов в стеке
	
	bool IsFull(); //Проверка на переполнение стека
	
	int GetCount();//Количество элементов в стеке
};

Stack::Stack()
{
	
	top = EMPTY;//Изначально стек пуст
}

void Stack::Clear()
{
	
	top = EMPTY; //Эффективная "очистка" стека
				//(данные в массиве все еще существуют,
				//но функции класса, ориентированные
				//на работу с вершиной стека,
				//будут их игнорировать)
}
	bool Stack::IsEmpty()
	{
		//Пуст?
		return top == EMPTY;
	}
	bool Stack::IsFull()
	{
		//Полон?
		return top == FULL;
	}
	int Stack::GetCount()
	{
		//Количество присутствующих в стеке элементов
		return top + 1;
	}
	void Stack::Push(char c)
	{
		//Если в стеке есть место, то увеличиваем указатель
		//на вершину стека и вставляем новый элемент 
		if (!IsFull())
			st[++top] = c;
	}
	char Stack::Pop()
	{
		//Если в стеке есть элементы, то возвращаем
		
			//верхний и уменьшаем указатель на вершину стека 
			if (!IsEmpty())
				return st[top--];
			else //Если в стеке элементов нет 
				return 0;
	}


	void main()
	{
		srand(time(0));
		Stack ST;
		char c;
		//пока стек не заполнится
		while (!ST.IsFull()) {
			c = rand() % 4 + 2;
			ST.Push(c);
		}
		//пока стек не освободится
		while (c = ST.Pop()) {
			cout << c << " ";
		}
		cout << "\n\n";
	}