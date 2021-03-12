#include <iostream>
#include <random>
#include <time.h>
#include "SearchVect.h"
#include "SortableVector.h"
//#include "SimpleVector.h"
using namespace std;

int main()
{
	const int SIZE = 10;
	srand(time(NULL));

	SearchableVector<int> intTable(SIZE);
	SearchableVector<double> doubleTable(SIZE);
	SortableVector<int> intTable2(SIZE);
	SearchableVector<string> stringTable(SIZE);
	SortableVector<string> stringTable2(SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		intTable.push_back(i * 2);
		intTable2.push_back(rand() % 10 + 1 * 2);
		//intTable[i] = (i * 2);
		doubleTable.push_back(i * 2.14);
	}
	stringTable.push_back("Alpha");
	stringTable.push_back("Azazel");
	stringTable.push_back("Bravo");
	stringTable.push_back("Delta");
	stringTable.push_back("Epsilon");
	stringTable.push_back("Foxtrot");
	stringTable.push_back("Omega");
	stringTable.push_back("Sigma");
	stringTable.push_back("Theta");
	stringTable.push_back("Victor");

	stringTable2.push_back("Delta");
	stringTable2.push_back("Victor");
	stringTable2.push_back("Sigma");
	stringTable2.push_back("Alpha");
	stringTable2.push_back("Bravo");
	stringTable2.push_back("Foxtrot");
	stringTable2.push_back("Azazel");
	stringTable2.push_back("Omega");
	stringTable2.push_back("Theta");
	stringTable2.push_back("Epsilon");

	cout << "These values are in intTable:\n";
	intTable.print();
	cout << "These values are in intTable2:\n";
	intTable2.print();
	cout << "This is intTable2 after being sorted:\n";
	intTable2.sort();
	intTable2.print();
	cout << "These values are in doubleTable:\n";
	doubleTable.print();
	doubleTable.pop_back();
	doubleTable.pop_back();
	cout << "doubleTable after having two elements popped back:\n";
	doubleTable.print();
	cout << "These values are in stringTable:\n";
	stringTable.print();
	cout << "These values are in stringTable2:\n";
	stringTable2.print();
	cout << "This is stringTable2 after being sorted:\n";
	stringTable2.sort();
	stringTable2.print();

	int result;
	cout << "Searching for the number 6 in intTable:\n";
	result = intTable.findItem(6);
	if (result == -1)
	{
		cout << "6 was not found in intTable\n";
	}
	else
	{
		cout << "6 was found at subscript " << result << endl;
	}

	string result2;
	cout << "Searching for the string Foxtrot in stringTable:\n";
	result = stringTable.findItem("Foxtrot");
	if (result == -1)
	{
		cout << "Foxtrot was not found in stringTable\n";
	}
	else
	{
		cout << "Foxtrot was found at subscript " << result << endl;
	}

	return 0;
}