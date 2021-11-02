#include <iostream>
#include <vector>
#include "MyVector.h"
#include "AssignVector.h"	

using namespace std;

int main()
{
	AssignVector vec;

	vec.Add(1);
	cout << "Size : " << vec.GetSize() << "   Capacity : " << vec.GetCapacity() << endl;
	vec.Add(2);
	cout << "Size : " << vec.GetSize() << "   Capacity : " << vec.GetCapacity() << endl;
	vec.Add(3);
	cout << "Size : " << vec.GetSize() << "   Capacity : " << vec.GetCapacity() << endl;
	vec.Add(4);
	cout << "Size : " << vec.GetSize() << "   Capacity : " << vec.GetCapacity() << endl;
	vec.Add(5);
	cout << "Size : " << vec.GetSize() << "   Capacity : " << vec.GetCapacity() << endl;
	vec.TrimToSize();
	cout << "TrimToSize" << endl;
	cout << "Size : " << vec.GetSize() << "   Capacity : " << vec.GetCapacity() << endl;

	vec.Add(3);
	cout << "Size : " << vec.GetSize() << "   Capacity : " << vec.GetCapacity() << endl;
	vec.Add(3);
	cout << "Size : " << vec.GetSize() << "   Capacity : " << vec.GetCapacity() << endl;
	vec.Add(4);
	cout << "Size : " << vec.GetSize() << "   Capacity : " << vec.GetCapacity() << endl;


	vec.RemoveAll(3);//3Áö¿ì±â
	int ar = 3;
	AssignVector *temp = vec.GroupById(&ar);

}