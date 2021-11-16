//#include <iostream>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//// 
//vector<int> graph2[1001];
//
//int N, M;
//int answer;
//
//
//
//void bfs2(int node)
//{
//	static bool isVisited[1001] = { false };
//	queue<int> q;
//
//	q.push(node);
//
//	while (!q.empty())
//	{
//		int vertex = q.front();
//		q.pop();
//
//		if (isVisited[vertex])
//			continue;
//
//		isVisited[vertex] = true;
//
//		answer++;
//
//		for (int e: graph2[vertex])
//		{
//			//방문하지 않았고, 실제로 연결된 친구들을 방문
//			if (isVisited[e] == false)
//			{
//				// 방문할 노드를 스택에 추가한다.
//				q.push(e);
//			}
//		}
//
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
//	cin >> M;
//	for (int i = 0; i < M; ++i)
//	{
//		int s, e;
//		cin >> s;
//		cin >> e;
//
//
//		graph2[s].push_back(e);
//		graph2[e].push_back(s);
//	}
//
//	bfs2(1);
//	cout << answer - 1;
//}