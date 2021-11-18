//#include <iostream>
//#include <vector>
//#include <queue>
//
//#define INF 987654321
//
//using namespace std;
//
//
//// 1. distance / distnace [i] : 시작 정점 -> i로가는 최단 경로. distance[start] = 0 / INF;
//// 2. 발견되었고, 방문하지 않은 정점 중 최단 경로의 정점을 찾는다. 
//// 3. 해당 정점(v)을 경유해서 갔을 때, 최단 경로가 있는지 탐색한다. distance [i] = min(distance[i], distance[v] + graph[v][i]);
//// 4. 모든 정점에 대해서 최단 경로를 찾을 때까지 2번부터 반복한다.
////start : 시작 정점
//
//
//
//
//int N, M, startNode;
//
//std::vector<int> GetShortestPath2(const vector<vector<pair<int, int>>>& map)
//{
//	// distance 배열 만들기
//	// 발견되지 않은 정점은 모두 INF다.
//	vector<int> dist(N, INF);
//	// 시작 정점은 거리가 0이다.
//	dist[startNode - 1] = 0;
//
//	// 우선순위 큐를 이용한다.
//	priority_queue<pair<int, int>> pq;
//
//	// 시작 정점을 넣어준다.
//	pq.emplace(0, startNode - 1);
//
//	// dist의 모든 값을 찾을 때까지
//	while (false == pq.empty())
//	{
//		// dist 중에서 가장 최소값을 가지는 정점을 뽑아낸다.
//		int w = -pq.top().first;
//		int v = pq.top().second;
//		pq.pop();
//
//		// 해당 정점을 이용했을 때, 최단 거리를 찾을 수 있는지 체크한다.
//		//for (int node = 0; node < N; ++node)
//		//{
//		//	if (dist[node] > dist[v] + graph[v][node])
//		//	{
//		//		dist[node] = dist[v] + graph[v][node];
//
//		//		pq.emplace(-dist[node], node);
//		//	}
//		//}
//
//		//인접리스트
//		for (pair<int, int> i : map[v])
//		{
//			if (dist[i.first] > dist[v] + i.second)
//			{
//				dist[i.first] = dist[v] + i.second;
//
//				pq.emplace(-dist[i.first], i.first);
//			}
//		}
//
//	}
//
//	return dist;
//}
//
//
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> N;
//	cin >> M;
//	cin >> startNode;
//
//	vector<vector<pair<int, int>>> map2(N);
//	for (int i = 0; i < M; ++i)
//	{
//		int start = 0, end = 0, weight = 0;
//		cin >> start;
//		cin >> end;
//		cin >> weight;
//
//		map2[start - 1].push_back({ end - 1, weight });
//	}
//
//
//	auto path = GetShortestPath2(map2);
//	for (int i : path)
//	{
//		if (i == INF)
//			cout << "INF" << endl;
//		else
//			cout << i << endl;
//	}
//}
//
