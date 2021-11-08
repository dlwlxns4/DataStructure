#include <iostream>
#include <vector>
#include <string>
#include "DoubleLinkedList.h"
#include "CircularSingleLinkedList.h"

using namespace std;



int main()
{
	CircularSingleLinkedList lst;

	lst.push_back(1);
	lst.push_front(2);
	lst.push_front(3);
	lst.push_back(4);

	// 3214
	auto iter = lst.head();
	iter = iter->Next;
	iter = iter->Next;
	lst.insert_after(iter, 6);

	lst.PrintOnce();
	lst.erase_after(iter);
	lst.PrintOnce();

	lst.pop_back();
	lst.pop_front();
	lst.pop_back();
	lst.pop_front();
	lst.pop_front();
	lst.pop_back();
	lst.pop_front();

	//lst.insert_after(lst.before_head(), 3);
	//lst.PrintOnce();

	//lst.insert_after(lst.before_head(), 4);
	//lst.PrintOnce();

	//lst.insert_after(lst.before_tail(), 2);
	//lst.PrintOnce();

	//lst.insert_after(lst.head(), 1);
	//lst.PrintOnce();

	//lst.insert_after(lst.before_tail(), 5);
	//lst.PrintOnce();

	//lst.insert_after(lst.tail(), 6);
	//lst.PrintOnce();


	//lst.insert_after(lst.tail(), 7);
	//lst.PrintOnce();
	//cout << endl<<"erase!!" << endl;



	/*lst.erase_after(lst.before_head());
	lst.PrintOnce();
	lst.pop_front();
	lst.PrintOnce();
	lst.pop_back();
	lst.PrintOnce();
	lst.erase_after(lst.before_tail());
	lst.PrintOnce();
	lst.erase_after(lst.before_tail());
	lst.PrintOnce();

	lst.erase_after(lst.tail());
	lst.PrintOnce();

	lst.erase_after(lst.tail());
	lst.PrintOnce();
*/


	//lst.clear();
	//lst.PrintOnce();


	//lst.pop_front();
	////lst.erase_after(lst.head());
	////lst.erase_after(lst.head());
	//cout << endl << "erase!!" << endl;
	//lst.erase_after(lst.before_tail());

	
}