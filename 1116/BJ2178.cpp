//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int N;
//int M;
//vector<vector<char>> vec;
//
//struct Pos
//{
//	int row;
//	int col;
//	int distance;
//};
//
//int dr[] = { -1,1,0,0 };
//int dc[] = { 0,0,-1,1 };
//
//
//int bfs()
//{
//	queue<Pos> q;
//	vector<vector<bool>> isVisited(N, vector<bool>(M));
//
//	isVisited[0][0] = true;
//
//	q.push({ 0,0,1 });
//
//
//	while (!q.empty())
//	{
//
//		Pos nowPos = q.front();
//		
//
//		q.pop();
//
//		if (nowPos.row == N - 1 && nowPos.col == M - 1)
//		{
//			return nowPos.distance;
//		}
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int nr = dr[i] + nowPos.row;
//			int nc = dc[i] + nowPos.col;
//
//			//해당위치가 유효한지 판단
//			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
//				continue;
//
//			//방문한 곳인지 판단
//			if (isVisited[nr][nc])
//				continue;
//
//			//1인지 판단
//			if (vec[nr][nc] != '1')
//				continue;
//
//			isVisited[nr][nc] = true;
//
//			q.push({ nr, nc, nowPos.distance + 1 });
//		}
//
//	}
//
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
//	cin >> M;
//	for (int i = 0; i < N; ++i)
//	{
//		vector<char> tmp;
//		for (int j = 0; j < M; ++j)
//		{
//			char input;
//			cin >> input;
//			tmp.push_back(input);
//		}
//		vec.push_back(tmp);
//	}
//
//
//	
//	cout << bfs();
//}