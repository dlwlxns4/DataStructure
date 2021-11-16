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

		if ((currPosX - 1 >= 0 && currPosY - 2 >= 0) && visited[currPosX - 1][currPosY - 2] == false)
		{
			q.push({ currPosX - 1, currPosY - 2, currCount + 1 });
			visited[currPosX - 1][currPosY - 2] = true;
		}
		if ((currPosX + 1 < size && currPosY - 2 >= 0) && visited[currPosX + 1][currPosY - 2] == false)
		{
			q.push({ currPosX + 1, currPosY - 2, currCount + 1 });
			visited[currPosX + 1][currPosY - 2] = true;
		}
		if ((currPosX - 1 >= 0 && currPosY + 2 < size) && visited[currPosX - 1][currPosY + 2] == false)
		{
			q.push({ currPosX - 1, currPosY + 2, currCount + 1 });
			visited[currPosX - 1][currPosY + 2] = true;
		}
		if ((currPosX + 1 < size && currPosY + 2 < size) && visited[currPosX + 1][currPosY + 2] == false)
		{
			q.push({ currPosX + 1, currPosY + 2, currCount + 1 });
			visited[currPosX + 1][currPosY + 2] = true;
		}

		if ((currPosX - 2 >= 0 && currPosY - 1 >= 0) && visited[currPosX - 2][currPosY - 1] == false)
		{
			q.push({ currPosX - 2, currPosY - 1, currCount + 1 });
			visited[currPosX - 2][currPosY - 1] = true;
		}
		if ((currPosX + 2 < size && currPosY - 1 >= 0) && visited[currPosX + 2][currPosY - 1] == false)
		{
			q.push({ currPosX + 2, currPosY - 1, currCount + 1 });
			visited[currPosX + 2][currPosY - 1] = true;
		}
		if ((currPosX - 2 >= 0 && currPosY + 1 < size) && visited[currPosX - 2][currPosY + 1] == false)
		{
			q.push({ currPosX - 2, currPosY + 1, currCount + 1 });
			visited[currPosX - 2][currPosY + 1] = true;
		}
		if ((currPosX + 2 < size && currPosY + 1 < size) && visited[currPosX + 2][currPosY + 1] == false)
		{
			q.push({ currPosX + 2, currPosY + 1, currCount + 1 });
			visited[currPosX + 2][currPosY + 1] = true;
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