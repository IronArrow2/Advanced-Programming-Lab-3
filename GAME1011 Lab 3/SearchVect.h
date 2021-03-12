#pragma once
#include "SimpleVector.h"

template<class T>
class SearchableVector : public SimpleVector<T>
{
public:
	SearchableVector(int size) : SimpleVector<T>(size){ }
	SearchableVector(SearchableVector& copy);
	SearchableVector(SimpleVector<T>& copy) : SimpleVector<T>(copy) { }
	int findItem(T item);
	int binarySearch(T sortedArray[], int lowerBound, int upperBound, T item);
};

template<class T>
SearchableVector<T>::SearchableVector(SearchableVector& copy) : SimpleVector<T>(copy) {}

template<class T>
int SearchableVector<T>::findItem(T item)
{
	return binarySearch(this->aptr, 0, this->arraySize, item);
}

template<class T>
int SearchableVector<T>::binarySearch(T sortedArray[], int lowerBound, int upperBound, T item)
{
	if (lowerBound <= upperBound)
	{
		int mid = (lowerBound + upperBound) / 2;
		if (sortedArray[mid] == item)
		{
			return mid;
		}
		else if (sortedArray[mid] > item)
		{
			return binarySearch(sortedArray, lowerBound, mid - 1, item);
		}
		else if (sortedArray[mid] < item)
		{
			return binarySearch(sortedArray, mid + 1, upperBound, item);
		}
	}
	return -1;
}