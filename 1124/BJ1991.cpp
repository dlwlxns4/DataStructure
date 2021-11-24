//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void Preorder(const vector<char>& tree, int index)
//{
//	if (tree[index] == '.')
//		return;
//
//	cout << tree[index] ;
//	Preorder(tree, index * 2);
//	Preorder(tree, index * 2 + 1);
//}
//
//void Inorder(const vector<char>& tree, int index)
//{
//	if (tree[index] == '.')
//		return;
//
//	Inorder(tree, index * 2);
//	cout << tree[index];
//	Inorder(tree, index * 2 + 1);
//}
//
//void Postorder(const vector<char>& tree, int index)
//{
//	if (tree[index] == '.')
//		return;
//
//	Postorder(tree, index * 2);
//	Postorder(tree, index * 2 + 1);
//	cout << tree[index];
//}
//
//int main()
//{
//	int N;
//
//	cin >> N;
//
//	vector<char> tree(500, '.');
//	tree[1] = 'A';
//	
//	
//	int root = 1;
//	for (int i = 0; i < N; ++i)
//	{
//		char startNode;
//		char daughter1, daughter2;
//
//		cin >> startNode >> daughter1 >> daughter2;
//		root = find(tree.begin(), tree.end(), startNode) - tree.begin();
//		tree[root * 2] = daughter1;
//		tree[root * 2 + 1] = daughter2;
//	}
//	Preorder(tree, 1);
//	puts("");
//	Inorder(tree, 1);
//	puts("");
//	Postorder(tree, 1);
//	puts("");
//
//}