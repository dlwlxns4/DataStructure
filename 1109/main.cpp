#include <iostream>
#include "CircularSingleLinkedList.h"

using namespace std;



int main()
{
    CircularSingleLinkedList list, list2, list3;

    list = list2 = list3;

    list.push_front(1);
    // 1
    list3 = list2 = list;

    std::cout << list3.front() << list3.back() << list2.front() << list2.back() << std::endl;

    list.push_back(4);
    // 14 
    list.push_front(2);
    //214
    list.push_back(3);
    //6218435
    list.push_back(5);
    list.push_front(6);

    auto iter = list.head();
    iter = iter->Next;
    iter = iter->Next;

    iter = list.insert_after(iter, 8);

    list.erase_after(iter);

    iter = list.head();
    do
    {
        std::cout << iter->Data << "->";
        iter = iter->Next;
    } while (iter != list.head());
    std::cout << iter->Data << std::endl;

    list.clear();
    return 0;

	

}