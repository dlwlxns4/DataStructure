//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int N, M;
//
//
//
////반환값 단지내 집의 개수
////매개변수 : 위치
////단지를 찾는 것
//void bfs(queue<pair<int, int>>& q, vector<vector<int>>& map, vector<vector<bool>>& isVisited)
//{
//
//	int dr[] = { -1,1,0,0 };
//	int dc[] = { 0,0,-1,1 };
//
//
//	while (!q.empty())
//	{
//		int r = q.front().first;
//		int c = q.front().second;
//
//		isVisited[r][c] = true;
//		q.pop();
//
//		for (int i = 0; i < 4; ++i)
//		{
//			int nr = dr[i] + r;
//			int nc = dc[i] + c;
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
//			if (map[nr][nc] != 0)
//				continue;
//
//			map[nr][nc] = map[r][c] + 1;
//
//			q.push({ nr, nc });
//		}
//	}
//
//}
//
//int main()
//{
//
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	queue<pair<int, int>> q;
//
//	cin >> M;
//	cin >> N;
//
//	vector<vector<int>> map(N, vector<int>(M));
//	vector<vector<bool>> isVisited(N, vector<bool>(M));
//
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < M; ++j)
//		{
//			cin >> map[i][j];
//			if (map[i][j] == 1)
//				q.push({ i,j });
//		}
//	}
//
//
//
//	bfs(q, map, isVisited);
//
//
//	int max = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		if (count(map[i].begin(), map[i].end(), 0))
//		{
//			cout << -1;
//			return 0;
//		}
//		max = (*max_element(map[i].begin(), map[i].end())) > max ? (*max_element(map[i].begin(), map[i].end())) : max;
//
//	}
//	cout << max - 1;
//
//}