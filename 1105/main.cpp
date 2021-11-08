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
	DoubleLinkedList<int> A;
	A.push_back(1);
	A.push_back(3);
	A.push_front(2);

	DoubleLinkedList<string> B;
	B.push_back("asdf");
	B.push_back("Zxcv");
	B.push_front("qwer");
	for (auto iter = A.begin(); iter != A.end(); ++iter)
	{
		cout << *iter << " ";
	}cout << endl;

	for (auto iter = B.begin(); iter != B.end(); ++iter)
	{
		cout << *iter << " ";
	}cout << endl;

}