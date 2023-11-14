// hw15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

// Создайте шаблонный класс обычной очереди для работы с целыми значениями. Требуется создать реализации для типичных операций над элементами :
//■ IsEmpty – проверка очереди на пустоту
//■ IsFull – проверка очереди на заполнение
//■ Enqueue – добавление элемента в очередь
//■ Dequeue – удаление элемента из очереди
//■ Show – отображение всех элементов очереди на экран

template <typename T>
class Queue
{
private:
	T* arr;
	int capacity, front, back, newsize;

public:
	Queue(int size)
	{
		arr = new T[size];
		capacity = size;
		front = 0;
		back = -1;
		newsize = 0;
	}

	void dequeue()
	{


		front = (front + 1) % capacity;
		newsize--;
	}
	void enqueue(T elem)
	{


		back = (back + 1) % capacity;
		arr[back] = elem;
		newsize++;
	}
	void isEmpty()
	{
		if (newsize == 0)
		{
			cout << "Очередь пуста!" << endl;
		}
		else
		{
			cout << "Очередь не пуста!" << endl;
		}

	}
	void isFull()
	{
		if (newsize == capacity)
		{
			cout << "Очередь полна!" << endl;
		}
		else
		{
			cout << "Очередь не полна!" << endl;
		}
	}

	void show()
	{
		for (int i = 0; i < newsize; i++)
		{
			cout << arr[i] << " ";
		}
	}
};

void main()
{
	setlocale(LC_ALL, "RU");

	Queue<int> q(10);

	q.isEmpty();

	cout << "Добавление элемента" << endl;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	cout << "Вывод " << endl;
	q.show();

	cout << "\n\nУдаление элемента" << endl;
	q.dequeue();
	q.dequeue();

	cout << "Вывод " << endl;
	q.show();

	cout << endl;
	q.isEmpty();
	q.isFull();
}