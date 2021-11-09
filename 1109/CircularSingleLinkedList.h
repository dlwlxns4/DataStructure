#include <utility>

#pragma once
class CircularSingleLinkedList
{
public:
	struct Node
	{
		Node(int data = 0, Node* next = nullptr)
			: Data{ data }, Next{ next } { }
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node() = default;

		int   Data = 0;
		Node* Next = nullptr;
	};

public:
	// 기본 생성자
	CircularSingleLinkedList() = default;

	// 복사 생성자
	CircularSingleLinkedList(const CircularSingleLinkedList& other)
		:CircularSingleLinkedList()
	{
		if (other.empty())
		{
			return;
		}

		auto iter = other.tail();
		do
		{
			push_back(iter->Data);
			iter = iter->Next;
		} while (iter != other.head());
	}

	// 할당 연산자
	CircularSingleLinkedList& operator=(const CircularSingleLinkedList& rhs)
	{
		if (this != &rhs)
		{
			CircularSingleLinkedList temp(rhs);
			std::swap(_beforeHead, temp._beforeHead);
			std::swap(_beforeTail, temp._beforeTail);
		}
		return *this;
	}

	// 소멸자
	~CircularSingleLinkedList()
	{
		clear();
		delete _beforeHead;
		_beforeHead = nullptr;
		_beforeTail = nullptr;
	}

	// 첫 번째 요소를 반환한다.
	int& front() { return head()->Data; }
	const int& front() const { return head()->Data; }

	// 마지막 요소를 반환한다.
	int& back() { return tail()->Data; }
	const int& back() const { return tail()->Data; }

	// 시작 전 요소를 가리키는 반복자를 반환한다.
	Node* before_head() { return _beforeHead; }
	const Node* before_head() const { return _beforeHead; }

	// 끝 전 요소를 가리키는 반복자를 반환한다.
	Node* before_tail() { return _beforeTail; }
	const Node* before_tail() const { return _beforeTail; }

	// 시작 요소를 가리키는 반복자를 반환한다.
	Node* head() { return _beforeHead->Next; }
	const Node* head() const { return _beforeHead->Next; }

	// 끝 요소를 가리키는 반복자를 반환한다.
	Node* tail() { return before_tail()->Next; }
	const Node* tail() const { return before_tail()->Next; }

	// pos 다음에 value를 삽입한다.
	// 삽입된 요소를 가리키는 반복자를 반환한다.
	Node* insert_after(Node* pos, int value)
	{
		Node* newNode = new Node(value);
		newNode->Next = pos->Next;
		pos->Next = newNode;
		// 첫 번째 원소가 삽입될 때
		if (head()->Next == nullptr)
		{
			head()->Next = head();
		}
		// 두 번째 원소가 삽입될 때
		else if (before_head() == before_tail())
		{
			_beforeTail = head();
			tail()->Next = head();
		}
		// before_tail / tail에 삽입할 때
		else if (pos == before_tail() || pos == tail())
		{
			_beforeTail = _beforeTail->Next;
		}
		// before_head()에 삽입할 때
		else if (pos == before_head())
		{
			tail()->Next = head();
		}
		return newNode;

	}
	// pos 다음 요소를 삭제한다.
	// 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
// pos 다음 요소를 삭제한다.
	// 삭제된 요소를 가리키는 반복자를 반환한다.
	Node* erase_after(Node* pos)
	{
		if (empty())
		{
			return tail();
		}
		Node* removed = pos->Next;
		// 원소가 하나일 때
		if (head()->Next == head())
		{
			before_head()->Next = nullptr;
		}
		// 원소가 두 개일 때
		else if (before_tail() == head())
		{
			before_head()->Next = removed->Next;
			_beforeTail = before_head();
			tail()->Next = head();
		}
		// tail을 제거하려고 할 때
		else if (pos == before_tail())
		{
			before_tail()->Next = removed->Next;
			while (tail()->Next != head())
			{
				_beforeTail = _beforeTail->Next;
			}
		}
		// before_tail이 제거될 때
		else if (removed == before_tail())
		{
			pos->Next = removed->Next;
			_beforeTail = pos;
		}
		// 첫 부분이 제거될 때
		else if (removed == head())
		{
			before_head()->Next = removed->Next;
			tail()->Next = head();
		}
		else
		{
			pos->Next = removed->Next;
		}
		removed->Next = nullptr;
		return removed;
	}


	// 시작 요소에 value를 삽입한다.
	void      push_front(int value) { insert_after(before_head(), value); }

	// 마지막 요소에 value를 삽입한다.
	void      push_back(int value)
	{
		if (empty())
		{
			insert_after(before_head(), value);
		}
		else
		{
			insert_after(tail(), value);
		}
	}

	// 시작 요소를 제거한다.
	void      pop_front() { Node* erased = erase_after(before_head()); delete erased; }

	// 마지막 요소를 제거한다.
	void      pop_back() { Node* erased = erase_after(before_tail()); delete erased; }

	// 컨테이너가 비었는지 판단한다.
	bool      empty() const { return head() == nullptr; }

	// 컨테이너를 비워버린다.
	void      clear()
	{
		while (false == empty())
		{
			pop_front();
		}
	}

	// 컨테이너에 value가 있는지 확인한다.
	bool      contains(int value) const
	{
		if (empty())
			return false;

		auto iter = head();
		do
		{
			if (iter->Data == value)
				return true;
			iter = iter->Next;
		} while (iter != head());

		return false;
	}
private:
	Node* _beforeHead = new Node();
	Node* _beforeTail = _beforeHead;
	// 어떤 멤버가 필요할까?
};
