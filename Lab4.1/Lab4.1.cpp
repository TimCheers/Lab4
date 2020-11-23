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

	int size,value,k=0;
	string tipe = "слово";
	cout << "Введите размер изначального стека"<<endl;
	cin >> size;

	int* Stack = new int[size];

	cout << "Введите начальный стек"<<endl;
	for (int i = 0; i < size; i++)
	{
		cin >> Stack[i];
		k++;
	}
	cout << "\tВведите команду (добавить(+число), удалить, стоп)"<<endl;
	while (tipe!="стоп")
	{
		cin >> tipe;
		cout << endl;
		if (tipe == "стоп" || tipe == "удалить" || tipe == "добавить")
		{
			if (tipe != "стоп")
			{
				if (tipe == "удалить")
				{
					if (k > 0)
					{
						int* newStack = new int[size - 1];
						for (int i = 0; i < size; i++)
						{
							newStack[i] = *&Stack[i];
						}
						size--;
						k--;
						cout << "  ";
						for (int i = size - 1; i >= 0; i--)
						{
							cout << newStack[i] << " ";
						}
						cout << endl << endl;
						for (int i = 0; i < size; i++)
						{
							Stack[i] = *&newStack[i];
						}
					}
					else
					{
						cout << "\tУдаление не возможно, стек пуст! Введите другую команду!" << endl;
					}

				}
				else
				{
					cin >> value;
					int* newStack = new int[size + 1];
					for (int i = 0; i < size; i++)
					{
						newStack[i] = *&Stack[i];
					}
					newStack[size] = value;
					size++;
					k++;
					cout << "  ";
					for (int i = size - 1; i >= 0; i--)
					{
						cout << newStack[i] << " ";
					}
					cout << endl << endl;
					for (int i = 0; i < size; i++)
					{
						Stack[i] = *&newStack[i];
					}
				}
			}
			else
			{
				cout << "Программа остановлена!" << endl << endl;
			}
		}
		else
		{
			cout << "Неизвестная команда! Введите команду заново!"<<endl<<endl;
		}
	}
}
