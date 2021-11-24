//#include <queue>
//#include <iostream>
//
//
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	int N;
//	priority_queue<int> pq;
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		int input;
//		cin >> input;
//		if (input == 0)
//		{
//			if (pq.empty())
//			{
//				cout << 0 << "\n";
//			}
//			else
//			{
//				cout << pq.top() << "\n";
//				pq.pop();
//			}
//		}
//		else
//		{
//			pq.push(input);
//		}
//	}
//}