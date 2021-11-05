#include <iostream>
#include <vector>
#include <string>
#include "DoubleLinkedList.h"


using namespace std;

struct A
{
	A() = default;
	A(int a=0, int b=0) :a{ a }, b{ b }{};

	int a;
	int b;
};

int main()
{
	DoubleLinkedList A;
	A.push_back(1);
	A.push_back(3);
	A.push_front(2);

	for (auto iter = A.begin(); iter != A.end(); ++iter)
	{
		cout << *iter << " ";
	}cout << endl;

}