#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int T;
int N, M, K;


//반환값 단지내 집의 개수
//매개변수 : 위치
//단지를 찾는 것
int dfs(int r, int c, vector<vector<int>>& map, vector<vector<bool>>& isVisited)
{
	isVisited[r][c] = true;

	int result = 1;

	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };

	for (int i = 0; i < 4; ++i)
	{
		int nr = dr[i] + r;
		int nc = dc[i] + c;



		//해당위치가 유효한지 판단
		if (nr < 0 || nr >= N || nc < 0 || nc >= M)
			continue;

		//방문한 곳인지 판단
		if (isVisited[nr][nc])
			continue;

		if (map[nr][nc] == '0')
		{
			map[nr][nc] = '1';
		}
		
		//1인지 판단
		if (map[nr][nc] != '1')
			continue;

		result += dfs(nr, nc, map, isVisited);
	}

	return ++result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int result = 0;
	cin >> M;
	cin >> N;

	vector<vector<char>> map(N, vector<char>(M));
	vector<vector<bool>> isVisited(N, vector<bool>(M));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
		}
	}



	////지도를 전부 순회
	//for (int i = 0; i < N; ++i)
	//{
	//	for (int j = 0; j < M; ++j)
	//	{
	//		//방문하지 않은 단지를 돌아야 함
	//		if (isVisited[i][j] == false && map[i][j] == 1)
	//		{
	//			result = dfs(i, j, map, isVisited))
	//		}
	//	}
	//}
	cout << result << endl;

}