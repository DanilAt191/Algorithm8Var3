#include <iostream>
#include <forward_list>
#include <list>
#include <iterator>

using namespace std;

void easy()
{
	//Определить кол-во элементов однонаправленного списка больших 7-ми;

	forward_list <double> Numbers = { -1, 7, 7.2, -8.1, 9.6, -0.1, 14.4 };
	forward_list <double> ::iterator Place;
	int count = 0;

	cout << "Элементы списка: ";

	for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
	{
		cout << *Place << " ";
		if (*Place > 7)
		{
			count++;
		}
	}
	cout << endl << "Кол-во элементов списка больших чем 7: " << count << endl << endl;
}

void medium()
{
	//Вставить в однонаправленный список число 1.5 после каждого отрицательного значения;

	forward_list <double> Numbers = { -3, -1, 7.1, -2.2, 9.5, 0, -6 };

	forward_list <double> ::iterator Place;

	double number = 1.5;

	cout << "Список перед добавлением: ";

	for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
	{
		cout << *Place << " ";
	}
	cout << endl;

	Place = Numbers.begin();
	Numbers.insert_after(Place, number);
	Place = Numbers.begin();
	advance(Place, 2);
	Numbers.insert_after(Place, number);
	Place = Numbers.begin();
	advance(Place, 5);
	Numbers.insert_after(Place, number);
	Place = Numbers.begin();
	advance(Place, 9);
	Numbers.insert_after(Place, number);

	cout << "Список после добавления: ";

	for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
	{
		cout << *Place << " ";
	}
	cout << endl << endl;
}

void hard()
{
	//Создать двунаправленный список из целых чисел, удалить последний элемент списка меньший чем 15;

	list <int> Numbers = { 18, 14, -10, -2, 8, 0, 15, 22 };
	list <int> ::iterator Place;
	int count = 0;

	cout << "Элементы списка перед удалением: ";

	for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
	{
		cout << *Place << " ";
	}
	cout << endl;

	Place = Numbers.begin();
	advance(Place, 5);
	Numbers.erase(Place);

	cout << "Элементы списка после удаления: ";

	for (Place = Numbers.begin(); Place != Numbers.end(); Place++)
	{
		cout << *Place << " ";
	}
	cout << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "RU");

	int a;
	int count = 0;

	do
	{
		cout << "Введите номер задания(easy - 1, medium - 2, hard - 3): ";

		cin >> a;

		cout << endl;

		if (a == 1)
		{
			easy();
			count++;
		}

		if (a == 2)
		{
			medium();
			count++;
		}

		if (a == 3)
		{
			hard();
			count++;
		}

	} while (count == 0);

	int b;

	do
	{
		count = 0;

		cout << "Продолжить ввод? Да - 1, Нет - 2: ";

		cin >> b;

		cout << endl;

		if (b == 1)
		{
			count++;
			main();
		}

		if (b == 2)
		{
			cout << "Вы решили не продолжать";
			count++;
			break;
		}

	} while (count == 0);
}