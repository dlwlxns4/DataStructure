//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//
//using namespace std;
//
//int N;
//char map[25][25];
//bool isVisited[25][25] = { false };
//
//
//vector<int> house;
////반환값 단지내 집의 개수
////매개변수 : 위치
////단지를 찾는 것
//int dfs(int r, int c)
//{
//	isVisited[r][c] = true;
//
//	int result = 1;
//
//	//if ((r - 1) >= 0 && isVisited[r - 1][c] == false && map[r - 1][c] == '1')
//	//{
//	//	result += dfs(r - 1, c);
//	//}
//	//if ((r + 1) < N && isVisited[r + 1][c] == false && map[r + 1][c] == '1')
//	//{
//	//	result +=dfs(r - 1, c);
//	//}
//	//if ((c - 1) >= 0 && isVisited[r][c-1] == false && map[r][c-1] == '1')
//	//{
//	//	result +=dfs(r, c+1);
//	//}
//	//if ((c + 1) < N && isVisited[r][c+1] == false && map[r][c+1] == '1')
//	//{
//	//	result +=dfs(r, c+1);
//	//}
//
//	int dr[] = { -1,1,0,0 };
//	int dc[] = { 0,0,-1,1 };
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int nr = dr[i] + r;
//		int nc = dc[i] + c;
//
//		//해당위치가 유효한지 판단
//		if (nc < 0 || nr >= N || nc < 0 || nc >= N)
//			continue;
//
//		//방문한 곳인지 판단
//		if (isVisited[nr][nc])
//			continue;
//
//		//1인지 판단
//		if (map[nr][nc] != '1')
//			continue;
//
//		result += dfs(nr, nc);
//	}
//
//	return result;
//}
//
//int main()
//{
//	scanf("%d", &N);
//	for (int i = 0; i < N; ++i)
//	{
//		scanf("%s", map[i]);
//	}
//
//
//
//	//지도를 전부 순회
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			//방문하지 않은 단지를 돌아야 함
//			if (isVisited[i][j] == false && map[i][j] == '1')
//			{
//				house.push_back(dfs(i, j));
//			}
//		}
//	}
//
//
//
//	sort(house.begin(), house.end());
//	cout << house.size() << endl;
//	for (int i : house)
//		cout << i << endl;
//}