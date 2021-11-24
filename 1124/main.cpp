//#include <set>
//#include "Set.h"
//#include "Heap.h"
//#include <queue>
//
//using namespace std;
//
//int main()
//{
////	set<int> set = { 8,3,2,5,4,10,14,11,16 };
////	for (int data : set)
////		cout << data << " ";
////	cout << endl;
////
////	if (set.end() != set.find(2))
////		cout << " Found 2\n";
////
////	if (set.end() == set.find(13))
////		cout << " NotFound 13\n";
////
////	cout << "Size : " << set.size() << endl;
////
////	cout << boolalpha << set.empty() << endl;
////
////	auto iter = set.begin();
////	++iter;
////	++iter;
////
////	set.erase(iter);
////
////	cout << "Size : " << set.size() << endl;
////
////	if (set.find(4) == set.end())
////	{
////		cout <<  " Not Found 4\n";
////	}
////
////	set.clear();
////
////
////	cout << set.empty() << endl;
////
////	puts("----------------------------------------");
////
////	Set<int> mySet;
////	mySet.insert(8);
////	mySet.insert(3);
////	mySet.insert(2);
////	mySet.insert(5);
////	mySet.insert(4);
////	mySet.insert(10);
////	mySet.insert(14);
////	mySet.insert(11);
////	mySet.insert(16);
////
////	if (mySet.find(2))
////	{
////		cout << "Found 2\n";
////	}
////
////	if (mySet.find(12) == nullptr)
////	{
////		cout << "Not Found 12\n";
////	}
////
////	cout << "Size : " << mySet.size() << endl;
////
////	cout << mySet.empty() << endl;
////
////	mySet.erase(4);
////
////	cout << "Size : " << mySet.size() << endl;
////
////	if (mySet.find(4) == nullptr)
////	{
////		cout << "Not Found 4\n";
////	}
////
////	mySet.traverseByPreorder();
////	puts("");
////
////	mySet.traverseByInorder();
////	puts("");
////
////	mySet.traverseByPostorder();
////	puts("");
////
////	mySet.traverseByLevelorder();
////	puts("");
////
////	cout << "Height : " << mySet.height() << " " << mySet.Height2()<<endl;
////
////	mySet.clear();
////
////	cout << mySet.empty() << endl;
////	//cout << mySet.Height2() << endl;
//
//	const auto data = { 77, 18, 58, 28, 12, 17, 19, 9, 44, 69 };
//	priority_queue<int> q;
//	for (int d : data)
//	{
//		q.push(d);
//	}
//	
//	while (!q.empty())
//	{
//		cout << q.top() << " ";
//		q.pop();
//	}
//
//	puts("");
//	puts("------------------------------------");
//
//	Heap h;
//	for (int d : data)
//	{
//		h.push(d);
//	}
//
//	while (!h.empty())
//	{
//		cout << h.top() << " ";
//		h.pop();
//	}
//}