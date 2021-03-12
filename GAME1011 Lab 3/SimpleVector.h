#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

template<class T>
class SimpleVector
{
protected:
	T* aptr;
	int arraySize, finalElement;
	void subError() const;
public:
	SimpleVector(int size);
	SimpleVector(const SimpleVector& copy);
	~SimpleVector();

	int size() const
	{
		return arraySize;
	}
	T& operator[](int sub);
	void print() const;

	void push_back(T item);
	void pop_back();
};

template <class T>
SimpleVector<T>::SimpleVector(int size)
{
	arraySize = size;
	aptr = new T[size];
	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = T();
	}
	finalElement = 0;
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector& copy)
{
	arraySize = copy.arraySize();
	aptr = new T[arraySize];
	for (int i = 0; i < arraySize; i++)
	{
		aptr[i] = copy.aptr[i];
	}
	finalElement = copy.finalElement;
}

template <class T>
SimpleVector<T>::~SimpleVector()
{
	if (arraySize > 0)
	{
		delete[] aptr;
	}
}

template <class T>
void SimpleVector<T>::subError() const
{
	cout << "ERROR: Subscript out of range.\n";
	exit(0);
}

template <class T>
T& SimpleVector<T>::operator[](int sub)
{
	if (sub < 0 || sub >= arraySize)
	{
		subError();
	}

	return aptr[sub];
}

template <class T>
void SimpleVector<T>::print() const
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << aptr[i] << " ";
	}

	cout << endl;
}

template<class T>
void SimpleVector<T>::push_back(T item)
{
	if (finalElement > arraySize)
	{
		cout << "Array full." << endl;
		subError();
	}
	aptr[finalElement] = item;
	finalElement++;
	if (finalElement >= arraySize)
	{
		finalElement--;
	}
}

template<class T>
void SimpleVector<T>::pop_back()
{
	if (finalElement < 0)
	{
		cout << "Array empty." << endl;
		subError();
	}
	aptr[finalElement] = T();
	finalElement--;
}
