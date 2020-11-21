#include <iostream>
#include<Windows.h>
using namespace std;

//Реализовать с использованием массива стек(первый
//пришел, последний ушел), для чего организовать
//добавление, удаление элементов в массив и печать массива
//после каждой операции.


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");

	int size,value;
	string tipe = "слово";
	cout << "Введите размер изначального стека"<<endl;
	cin >> size;

	int* Stack = new int[size];
	/*enum Tipe
	{
		добавить, удалить, стоп
	};*/

	cout << "Введите начальный стек"<<endl;
	for (int i = 0; i < size; i++)
	{
		cin >> Stack[i];
	}
	cout << "Введите команду (добавить(+число), удалить, стоп)"<<endl;
	while (tipe!="стоп")
	{
		cin >> tipe;
		if (tipe=="удалить")
		{
			size--;
			int* newStack = new int [size];
			for (int i = 0; i < size; i++)
			{
				newStack[i] = Stack[i];
			}
			for (int i = 0; i < size; i++)
			{
				cout << newStack[i]<<" ";
			}
			cout << endl;
		}
		else
		{
			cin >> value;
			int *newStack = new int [size + 1];
			for (int i = 0; i < size; i++)
			{
				newStack[i] = Stack[i];
			}
			newStack[size] = value;
			size++;
			for (int i = 0; i < size; i++)
			{
				cout << newStack[i]<<" ";
			}
			cout << endl;
		}

	}
}
