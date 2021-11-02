#include <iostream>
#include <vector>
#include "MyVector.h"

using namespace std;

int main()
{
	vector<int> vec;
	vector<int> vec2(5);
	vector<int> vec3 = { 1,2,3,4,5 };

	vec.push_back(1);
	//[1]   [ ]
	//begin end
	vec.push_back(2);
	//[1]   [2]   [ ]
	//begin       end
	vec.pop_back();
	//[1]   [ ]
	//begin end
	
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
	}
	cout << endl;

	try
	{
		vec.at(1);
	}
	catch (std::out_of_range& e)
	{
		cout << e.what() << endl;
	}
	catch (std::exception& e)
	{

	}

	cout << boolalpha << vec.empty() << endl;

	MyVector myVec;

	myVec.push_back(1);
	//[1]   [ ]
	//begin end
	myVec.push_back(2);
	//[1]   [2]   [ ]
	//begin       end
	myVec.pop_back();
	//[1]   [ ]
	//begin end

	for (int i = 0; i < myVec.size(); i++)
	{
		cout << myVec[i];
	}
	cout << endl;

	try
	{
		myVec.at(1);
	}
	catch (std::out_of_range& e)
	{
		cout << e.what() << endl;
	}
	catch (std::exception& e)
	{

	}

	cout << boolalpha << myVec.empty() << endl;

}