#pragma once
#include "SimpleVector.h"

template<class T>
class SortableVector : public SimpleVector<T>
{
public:
	SortableVector(int size) : SimpleVector<T>(size) { }
	SortableVector(SortableVector& copy);
	SortableVector(SimpleVector<T>& copy) : SimpleVector<T>(copy) { }
	void sort();
};

template<class T>
SortableVector<T>::SortableVector(SortableVector& copy) : SimpleVector<T>(copy) {}

template<class T>
void SortableVector<T>::sort()
{
	int i, j; 
	T temp;
	bool swapped;
	for (i = 0; i < this->arraySize - 1; i++)
	{
		swapped = false;
		for (j = 0; j < this->arraySize - i - 1; j++)
		{
			if (this->aptr[j] > this->aptr[j + 1])
			{
				temp = this->aptr[j];
				this->aptr[j] =this->aptr[j + 1];
				this->aptr[j + 1] = temp;
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}
}