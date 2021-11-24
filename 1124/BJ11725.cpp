//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int parent[100'001] = { 0 };
//vector<int> graph[100'001];
//int N;
//
//void SetParent(int p, int c)
//{
//	parent[c] = p;
//
//	for (int n : graph[c])
//	{
//		if (parent[n] == 0)
//			SetParent(c, n);
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
//
//	cin >> N;
//
//
//	//vertex, parent
//
//
//	for (int i = 1; i < N; ++i)
//	{
//		int node1, node2;
//
//		cin >> node1 >> node2;
//
//		graph[node1].push_back(node2);
//		graph[node2].push_back(node1);
//	}
//
//	SetParent(1, 1);
//
//	for (int i = 2; i <= N; ++i)
//	{
//		cout << parent[i] << "\n";
//	}
//
//
//}