//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string ar;
//	int N;
//	char input;
//	int cursor;
//
//	cin >> ar;
//	cursor = ar.size();
//
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> input;
//		switch (input)
//		{
//		case 'L':
//			if(cursor!=0)
//				cursor--;
//			break;
//		case 'D':
//			if(cursor<ar.size())
//				cursor++;
//			break;
//		case 'B':
//			if (cursor != 0)
//			{
//				ar.erase(ar.begin()+cursor-1);
//				cursor--;
//			}
//			break;
//		case 'P':
//			char inputChar;
//			cin >> inputChar;
//			ar.insert(ar.begin() + cursor, inputChar);
//			cursor++;
//			break;
//		}
//		
//	}
//	cout << ar;
//}