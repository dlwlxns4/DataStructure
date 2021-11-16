//#include <iostream>
//#include <queue>
//
//
//using namespace std;
//
//struct Pos
//{
//	int pos;
//	int count;
//};
//
//int N, K;
//
//bool visitied[100'001];
//int answer = 100'000;
//queue<Pos> q;
//
//void bfs()
//{
//	while (!q.empty())
//	{
//		Pos currPos = q.front();
//		int currPosX = currPos.pos;
//		int currCount = currPos.count;
//
//		q.pop();
//		
//		visitied[currPosX] = true;
//		if (currPosX == K)
//		{
//			answer = currCount;
//			return;
//		}
//
//		if ( (currPosX-1>=0 &&currPosX-1<=100000) && visitied[currPosX-1]==false )
//		{
//			q.push({ currPosX - 1, currCount + 1 });
//		}
//		if ((currPosX+1 >= 0 && currPosX+1 <= 100000) && visitied[currPosX + 1] == false)
//		{
//			q.push({ currPosX + 1, currCount + 1 });
//		}
//		if ((currPosX*2 >= 0 && currPosX*2 <= 100000) && visitied[currPosX * 2] == false)
//		{
//			q.push({ currPosX *2, currCount + 1 });
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//
//	cin >> N;
//	cin >> K;
//	q.push({ N,0 });
//	visitied[N] = true;
//
//	bfs();
//	cout << answer;
//}