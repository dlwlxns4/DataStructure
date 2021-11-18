#include <iostream>
#include <queue>


using namespace std;

struct PosCount
{
	int posX;
	int posY;
	int count;
};


int answer;
void bfs(queue<PosCount>& q, int desX, int desY, int size)
{
	bool visited[301][301] = { false };
	int dx[8] = { -1, -1, 1, 1, -2, -2 ,2, 2 };
	int dy[8] = { 2, -2, 2, -2, 1, -1, 1, -1 };


	while (!q.empty())
	{
		int currPosX = q.front().posX;
		int currPosY = q.front().posY;
		int currCount = q.front().count;

		q.pop();
		visited[currPosX][currPosY] = true;

		if (currPosX == desX && currPosY == desY)
		{
			answer = currCount;
			return;
		}

		for (int i = 0; i < 8; ++i)
		{
			if (currPosX + dx[i] >= 0 && currPosX + dx[i] < size && currPosY + dy[i] >= 0 && currPosY + dy[i] < size)
			{
				if(visited[currPosX + dx[i]][currPosY + dy[i]]==false)
				q.push({ currPosX + dx[i], currPosY + dy[i], currCount + 1 });
				visited[currPosX + dx[i]][currPosY + dy[i]] = true;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> N;
		queue<PosCount> q;
		int	x, y, desX, desY;
		cin >> x;
		cin >> y;
		cin >> desX;
		cin >> desY;
		q.push({ x,y,0 });

		bfs(q, desX, desY, N);
		cout << answer << endl;
	}
}