#pragma once

#include <iostream>
#include <queue>
#include <utility>
#include <stack>

using namespace std;

class Set
{
	struct Node
	{
		Node(int data = 0, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr)
			: Data{ data }, Parent{ parent }, Left{ left }, Right{ right }{}
		Node(const Node&) = delete;
		Node* operator=(const Node&) = delete;
		~Node() { Parent = Left = Right = nullptr; }

		int		Data = 0;
		Node* Parent = nullptr;
		Node* Left = nullptr;
		Node* Right = nullptr;
	};


public:

	//트리의 높이를 구한다.
	int height() const
	{
		if (empty())
		{
			return -1;
		}

		queue<Node*> q;
		q.push(_root);
		int h = -1;
		while (false == q.empty())
		{
			size_t sz = q.size();
			for (size_t i = 0; i < sz; ++i)
			{
				Node* node = q.front();
				q.pop();
				if (node->Left)
				{
					q.push(node->Left);
				}
				if (node->Right)
				{
					q.push(node->Right);
				}
			}
			h++;

		}

		return h;
	}

	int heightHelper(const Node* node) const
	{
		if (node == nullptr)
			return -1;

		int left = heightHelper(node->Left) + 1;
		int right = heightHelper(node->Right) + 1;

		return max(left, right);
	}


	// 트리가 비었는지 확인한다.
	bool empty() const
	{
		return _size == 0 || _root == nullptr;
	}

	//트리의 크기를 반환한다.
	size_t size() const
	{
		return _size;
	}

	// 트리를 비운다
	void clear()
	{
		while (false == empty())
		{
			erase(_root);
		}
	}

	// 트리에 값을 삽입한다.
	pair<Node*, bool> insert(int value)
	{
		if (empty())
		{
			_root = new Node(value);
			++_size;

			return make_pair(_root, true);
		}


		Node* curr = _root;
		Node* parent = nullptr;

		while (curr)
		{
			parent = curr;

			if (curr->Data == value)
			{
				return make_pair(curr, false);
			}
			else if (curr->Data < value)
			{
				curr = curr->Right;
			}
			else
			{
				curr = curr->Left;
			}
		}

		curr = new Node(value, parent);

		if (parent->Data > value)
		{
			parent->Left = curr;
		}
		else
		{
			parent->Right = curr;
		}

		++_size;
		return make_pair(curr, true);
	}


	// 트리에서 값을 삭제한다.
	void erase(Node* pos)
	{
		if (empty())
		{
			return;
		}

		if (pos->Parent == nullptr)
		{
			if (pos->Left == nullptr && pos->Right == nullptr)
			{
				_root == nullptr;

				delete pos;
				pos = nullptr;

				--_size;

				return;
			}

			//자식 1개

			if (pos->Left == nullptr)
			{
				_root = pos->Right;
				delete pos;
				pos = nullptr;

				--_size;

				return;
			}
			else if (pos->Right == nullptr)
			{
				_root = pos->Right;
				delete pos;
				pos = nullptr;

				--_size;

				return;
			}

			//자식 2개

			Node* successor = pos->Left;
			while (successor->Right)
			{
				successor = successor->Right;
			}

			swap(pos->Data, successor->Data);
			erase(successor);

			return;
		}


		// 자식이 없을 때 -> 단말 노드일 때
		if (pos->Left == nullptr && pos->Right == nullptr)
		{
			if (pos->Parent->Left == pos)
			{
				pos->Parent->Left == nullptr;
			}
			else
			{
				pos->Parent->Right == nullptr;
			}

			delete pos;
			pos = nullptr;

			--_size;
			return;
		}

		// 자식이 하나일 때
		if (pos->Left == nullptr)
		{
			if (pos->Parent->Left == pos)
			{
				pos->Parent->Left = pos->Right;
			}
			else
			{
				pos->Parent->Right = pos->Right;
			}

			pos->Right->Parent = pos->Parent;
			delete pos;
			pos = nullptr;

			--_size;
			return;
		}
		else if (pos->Right == nullptr)
		{
			if (pos->Parent->Left == pos)
			{
				pos->Parent->Left = pos->Left;
			}
			else
			{
				pos->Parent->Right = pos->Left;
			}

			pos->Left->Parent = pos->Parent;

			delete pos;
			pos = nullptr;

			--_size;
			return;
		}

		Node* successor = pos->Left;
		while (successor->Right)
		{
			successor = successor->Right;
		}

		swap(pos->Data, successor->Data);

		erase(successor);
	}
	size_t erase(int value)
	{
		Node* removed = find(value);
		if (removed == nullptr)
		{
			return 0;
		}
		else
		{
			erase(removed);

			return 1;
		}
	}

	// 트리에서 특정 값을 찾는다.
	Node* find(int value)
	{
		return const_cast<Node*>(static_cast<const Set&>(*this).find(value));
	}

	const Node* find(int value) const
	{
		const Node* result = _root;

		while (result)
		{
			if (result->Data == value)
			{
				return result;
			}
			else if (result->Data < value)
			{
				result = result->Right;
			}
			else
			{
				result = result->Left;
			}
		}

		return nullptr;
	}

	// 순회
	void traverseByPreorder()
	{
		Node* node = _root;
		PreorderHelper(node);
	}
	void PreorderHelper(Node* root)
	{
		if (root != nullptr)
			return;

		cout << root->Data << " ";
		PreorderHelper(root->Left);
		PreorderHelper(root->Right);
	}



	void traverseByInorder()
	{
		Node* node = _root;
		InorderHelper(node);
	}
	void InorderHelper(Node* root)
	{
		if (root != nullptr)
			return;

		InorderHelper(root->Left);
		cout << root->Data << " ";
		InorderHelper(root->Right);
	}



	void traverseByPostorder()
	{
		Node* node = _root;
		PostorderHelper(node);
	}
	void PostorderHelper(Node* root)
	{
		if (root != nullptr)
			return;

		PostorderHelper(root->Left);
		PostorderHelper(root->Right);
		cout << root->Data << " ";
	}



	void traverseByLevelorder()
	{
		if (empty())
		{
			return;
		}

		queue<Node*> q;
		q.push(_root);

		size_t h = 0;

		while (q.empty() != false)
		{
			cout << "Levl " << h << " : ";
			size_t sz = q.size();
			for (size_t i = 0; i < sz; ++i)
			{
				Node* node = q.front();
				q.pop();
				cout << node->Data << " ";
				if (node->Left)
				{
					q.push(node->Left);
				}
				if (node->Right)
				{
					q.push(node->Right);
				}
			}
			h++;
		}
	}

private:
	Node* _root = nullptr;
	size_t		_size = 0;

};

