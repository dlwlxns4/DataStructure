//#include <iostream>
//#include <vector>
//#include <stdio.h>
//
//using namespace std;
//
//struct Node
//{
//
//	int left = -1;
//	int right = -1;
//};
//
//
//void Postorder(const vector<int>& tree, int index)
//{
//	if (tree[index] == 0)
//		return;
//
//	Postorder(tree, index * 2);
//	Postorder(tree, index * 2 + 1);
//	cout << tree[index]<<endl;
//}
//
//int main()
//{
//	int node;
//	int root = 1;
//	
//	while (scanf("%d", &node) != EOF)
//	{
//		while (graph[root] != 0)
//		{
//			if (graph[root] < node)
//				root = root * 2 + 1;
//			else
//				root = root * 2;
//		}
//		graph[root] = node;
//		root = 1;
//	}
//
//	Postorder(graph, 1);
//}