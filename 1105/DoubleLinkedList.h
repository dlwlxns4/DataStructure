#pragma once
#include <cstddef>
#include <utility>


class DoubleLinkedList
{
public:
    struct Node
    {
        Node(int data = 0, Node* prev = nullptr, Node* next = nullptr)
            : Data{ data }, Prev{ prev }, Next{ next } { }
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
        ~Node()
        {
            Next = nullptr;
            Prev = nullptr;
        }
        int     Data;
        Node* Next;
        Node* Prev;
    };
public:
    class const_iterator
    {
    public:
        const_iterator(Node* p = nullptr)
            : _p{ p } { }
        ~const_iterator() { _p = nullptr; }
        const int& operator*() const { return _p->Data; }
        const int* operator->() const { return &_p->Data; }
        const_iterator& operator++()
        {
            _p = _p->Next;
            return *this;
        }
        const_iterator operator++(int)
        {
            auto temp = *this;
            _p = _p->Next;
            return temp;
        }
        const_iterator& operator--()
        {
            _p = _p->Prev;
            return *this;
        }
        const_iterator operator--(int)
        {
            auto temp = *this;
            _p = _p->Prev;
            return temp;
        }
        bool operator==(const const_iterator& rhs) const
        {
            return _p == rhs._p;
        }
        bool operator!=(const const_iterator& rhs) const
        {
            return _p != rhs._p;
        }
        bool operator==(nullptr_t p) const
        {
            return _p == nullptr;
        }
        bool operator!=(nullptr_t p) const
        {
            return _p != nullptr;
        }

        Node* _p = nullptr;
    };
    class iterator : public const_iterator
    {
    public:
        using const_iterator::const_iterator;
        int& operator*() const
        {
            return const_cast<int&>(const_iterator::operator*());
        }
        int* operator->() const
        {
            return const_cast<int*>(const_iterator::operator->());
        }
        iterator& operator++()
        {
            const_iterator::operator++();
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            const_iterator::operator++();
            return temp;
        }
        iterator& operator--()
        {
            const_iterator::operator--();
            return *this;
        }
        iterator operator--(int)
        {
            iterator temp = *this;
            const_iterator::operator--();
            return temp;
        }
    };
    // 기본 생성자
    DoubleLinkedList() = default;
    // count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
    explicit DoubleLinkedList(size_t count)
        : DoubleLinkedList()
    {
        for (size_t i = 0; i < count; ++i)
        {
            push_front(0);
        }
    }
    // 복사 생성자.
    DoubleLinkedList(const DoubleLinkedList& other)
        : DoubleLinkedList()
    {
        for (auto iter = other.begin(); iter != other.end(); ++iter)
        {
            push_back(*iter);
        }
    }
    // 할당 연산자
    DoubleLinkedList& operator=(const DoubleLinkedList& rhs)
    {
        if (this != &rhs)
        {
            DoubleLinkedList temp(rhs);
            std::swap(_end, temp._end);
            std::swap(_head, temp._head);
            std::swap(_size, temp._size);
        }

        return *this;
    }
    // 소멸자
    ~DoubleLinkedList()
    {
        clear();
        delete _end;
        _end = nullptr;
        _head = nullptr;
        _size = 0;
    }

    // 첫 번째 요소를 반환한다.
    int& front() { return *begin(); }
    const int& front() const { return *begin(); }
    // 마지막 요소를 반환한다.
    int& back() { return *(--end()); }
    const int& back() const { return *(--end()); }
    // 시작 요소를 가리키는 반복자를 반환한다.
    // 리스트가 비어있다면 end()와 같다.
    iterator begin() { return _head; }
    const_iterator begin() const { return _head; }
    // 끝 다음 요소를 가리키는 반복자를 반환한다.
    iterator end() { return _end; }
    const_iterator end() const { return _end; }
    // pos 이전에 value를 삽입한다.
    // 삽입된 요소를 가리키는 반복자를 반환한다.
    iterator insert(iterator pos, int value)
    {
        Node* newNode = new Node(value);
        Node* prevNode = pos._p->Prev;
        //    [N]
        // [] <-> [] <-> []
        //        pos
        pos._p->Prev = newNode;
        if (prevNode != nullptr)
        {
            prevNode->Next = newNode;
        }
        newNode->Prev = prevNode;
        newNode->Next = pos._p;
        // [prev] <-> [N] <-> [pos]
        if (pos._p == _head)
        {
            _head = newNode;
        }
        ++_size;
        return newNode;
    }
    // pos 요소를 삭제한다.
    // 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
    // 아무 요소도 없으면 end()를 반환한다.
    iterator erase(iterator pos)
    {
        if (empty())
        {
            return end();
        }
        Node* prevNode = pos._p->Prev;
        Node* nextNode = pos._p->Next;
        if (prevNode != nullptr)
        {
            prevNode->Next = nextNode;
        }
        if (nextNode != nullptr)
        {
            nextNode->Prev = prevNode;
        }
        if (pos._p == _head)
        {
            _head = nextNode;
        }
        delete pos._p;
        pos._p = nullptr;
        --_size;
        return nextNode;
    }
    // 시작에 value를 삽입한다.
    void            push_front(int value) { insert(begin(), value); }
    // 끝에 value를 삽입한다.
    void            push_back(int value) { insert(end(), value); }
    // 시작 요소를 제거한다.
    void            pop_front() { erase(begin()); }
    // 끝 요소를 제거한다.
    void            pop_back() { erase(--end()); }
    // 컨테이너가 비었는지 판단한다.
    bool            empty() const { return _size == 0; }
    // 리스트 안에 있는 요소의 개수를 반환한다.
    size_t          size() const { return _size; }
    // 컨테이너를 비워버린다.
    void            clear()
    {
        while (false == empty())
        {
            pop_front();
        }
    }
    // 해당 value가 있는지 체크한다.
    bool            contains(int value) const
    {
        for (auto iter = begin(); iter != end(); ++iter)
        {
            if (*iter == value)
            {
                return true;
            }
        }
        return false;
    }
private:
    Node* _end = new Node();
    Node* _head = _end;
    size_t          _size = 0;
};