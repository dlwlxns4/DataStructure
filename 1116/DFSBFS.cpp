//#include <iostream>
//#include <vector>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
////인접 행렬;
//bool graph[1001][1001];
//
//// 
//vector<int> graph2[1001];
//
//int N, M, V;
//
//
//// 인접행렬에서의 dfs
////node : 시작 정점
//void dfs(int node)
//{
//	//visited 행렬
//	static bool isVisited[1001] = { false };
//
//	stack<int> stk;
//	stk.push(node);
//
//	while (stk.empty() == false)
//	{
//		// 스택에서 다음에 방문할 정점을 가져온다.
//		int vertex = stk.top();
//		stk.pop();
//
//		if (isVisited[vertex])
//			continue;
//
//		cout << vertex << " ";
//		//방문한 정점을 표기한다.
//		isVisited[vertex] = true;
//
//		//연견될 노드를 모두 방문한다.
//		for (int i = N; i >= 1; --i)
//		{
//			//방문하지 않았고, 실제로 연결된 친구들을 방문
//			if (isVisited[i] == false && graph[vertex][i] == true)
//			{
//				// 방문할 노드를 스택에 추가한다.
//				stk.push(i);
//			}
//		}
//
//	}
//}
//
//// 인접리스트에서의 dfs
//// node : 시작 정점
//void dfs2(int node)
//{
//	//1. 방문할 정점을 표기할 자료구조
//	static bool isVisited[1001] = { false };
//
//	//2. 스택 구성
//	stack<int> stk;
//	stk.push(node);
//
//	//3. 모든 정점 방문할 때까지 순회
//	while (!stk.empty())
//	{
//		//4. 스택에서 다음에 방문할 정점을 가져온다.
//		int vertex = stk.top();
//		stk.pop();
//
//		//5. 이미 방문할 노드라면 건너뛴다.
//		if (isVisited[vertex])
//			continue;
//
//		cout << vertex << " ";
//
//		//6. 정점을 방문한다.
//		isVisited[vertex] = true;
//
//		//7. 연결된 정점 중 방문하지 않은 정점을 스택에 추가한다.
//		for (int e : graph2[vertex])
//		{
//			if (isVisited[e] == false)
//			{
//				stk.push(e);
//			}
//		}
//	}
//}
//
//// 재귀로 구현한 dfs / 인접 행렬 사용
//void dfsR(int node)
//{
//	// 1. 방문한 정점을 표기할 Set을 정의
//	static bool isVisited[1001] = { false };
//
//
//	isVisited[node] = true;
//	cout << node << " ";
//
//	for (int i = 1; i <= N; ++i)
//	{
//		if (isVisited[i] == false && graph[node][i] == true)
//			dfsR(i);
//	}
//}
//
//// 재귀로 구현한 dfs / 인접 행렬 사용
//void dfs2R(int node)
//{
//	// 1. 방문한 정점을 표기할 Set을 정의
//	static bool isVisited[1001] = { false };
//
//
//	isVisited[node] = true;
//	cout << node << " ";
//
//	for (int e : graph2[node])
//	{
//		if (isVisited[e]== false)
//			dfs2R(e);
//	}
//}
//
//
//void bfs(int node)
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
//		cout << vertex << " ";
//
//		for (int i = 1; i <= N; ++i)
//		{
//			//방문하지 않았고, 실제로 연결된 친구들을 방문
//			if (isVisited[i] == false && graph[vertex][i] == true)
//			{
//				// 방문할 노드를 스택에 추가한다.
//				q.push(i);
//			}
//		}
//
//	}
//}
//
////void dpss(int node)
////{
////	static bool isVisited[1001] = { false };
////
////	isVisited[node] = false;
////	cout << node << " ";
////
////	for (int e : graph2[node])
////	{
////		if (isVisited[e] == false)
////		{
////			dpss(e);
////		}
////	}
////}
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
//		cout << vertex << " ";
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
//	cin >> V;
//	for (int i = 0; i < M; ++i)
//	{
//		int s, e;
//		cin >> s;
//		cin >> e;
//
//		graph[s][e] = graph[e][s] = true;
//
//		graph2[s].push_back(e);
//		graph2[e].push_back(s);
//	}
//
//	//dfs
//	dfs(V);
//	cout << endl;
//	dfs2(V);
//	cout << endl;
//	dfsR(V);
//	cout << endl;
//	dfs2R(V);
//	cout << endl;
//
//	//bfs
//	bfs(V);
//	cout << endl;
//	bfs2(V);
//}