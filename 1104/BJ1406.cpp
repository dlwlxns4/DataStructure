#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main()
{
	string ar;
	int N;
	char input;
	
	cin >> ar;
	list<char> strList(ar.begin(), ar.end());
	list<char>::iterator cursor = strList.end();


	cin >> N;
	for (int i = 0; i < N; i++)
	{

		cin >> input;
		//for (auto ch : strList)
		//	cout << ch;
		//cout << endl;
		
		switch (input)
		{
		case 'L':
			if(cursor!=strList.begin())
				cursor--;
			break;
		case 'D':
			if(cursor!=strList.end())
				cursor++;
			break;
		case 'B':
			if (cursor!=strList.begin())
			{
				cursor--;
				cursor=strList.erase(cursor);
				
			}
			break;
		case 'P':
			char inputChar;
			cin >> inputChar;
			
			strList.insert(cursor, inputChar);
			break;

		}

		//for (auto ch : strList)
		//	cout << ch;
		//cout << endl;
		
	}

	for (auto ch : strList)
	{
		cout << ch;
	}
}