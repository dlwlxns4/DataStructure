#include <vector>
#include <queue>
#include <iostream>

using namespace std;

#define INF 987654321

int N, M, startNode;

vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph)
{

	vector<int> dist(graph.size(), INF);


	dist[startNode-1] = 0;
	
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, startNode-1);


	while (!pq.empty())
	{
		int weight = -pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		Pos path[ny][nx] = pos;
		for (auto i : graph[vertex])
		{
			int newWeight = i.first;
			int newVertex = i.second;

			if (dist[newVertex] > weight + newWeight)
			{
				dist[newVertex] = weight + newWeight;

				pq.emplace(-dist[newVertex], newVertex);

			}
		}
	}

	return dist;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;
	cin >> startNode;

	vector<vector<pair<int, int>>> map2(N);
	for (int i = 0; i < M; ++i)
	{
		int start = 0, end = 0, weight = 0;
		cin >> start;
		cin >> end;
		cin >> weight;

		map2[start - 1].emplace_back( weight, end-1 );
	}


	auto path = dijkstra(map2);
	for (int i : path)
	{
		if (i == INF)
			cout << "INF" << endl;
		else
			cout << i << endl;
	}
}

