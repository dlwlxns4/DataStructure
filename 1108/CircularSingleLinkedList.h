#include <iostream>
#include <utility>

using namespace std;

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
    CircularSingleLinkedList()
    {
        _before_head->Next = nullptr;
        _before_tail = _before_head;
    }
    // 복사 생성자
    CircularSingleLinkedList(const CircularSingleLinkedList& other)
        : CircularSingleLinkedList()
    {
        const Node* tmp = other.head();
        do
        {
            push_back(tmp->Data);
            tmp = tmp->Next;

        } while (tmp != other.head());

    }

    // 할당 연산자
    CircularSingleLinkedList& operator=(const CircularSingleLinkedList& rhs)
    {
        if (this != &rhs)
        {
            CircularSingleLinkedList temp(rhs);
            std::swap(_before_head, temp._before_head);
            std::swap(_before_tail, temp._before_tail);
            std::swap(_size, temp._size);

        }
    }

    // 소멸자
    ~CircularSingleLinkedList()
    {
        delete _before_head;
        _before_head = nullptr;

        _size = 0;
    }

    // 첫 번째 요소를 반환한다.
    int& front()
    {
        return _before_head->Next->Data;
    }
    const int& front() const
    {
        return _before_head->Next->Data;
    }
    void PrintOnce()
    {
        if (_size == 0)
        {
            cout << "텅 빔" << endl;
            return;
        }


        Node* tmp = head();
        cout << "Index : ";
        do
        {
            cout << tmp->Data << ", ";
            tmp = tmp->Next;
        } while (tmp != tail()->Next);
        cout << "첫 요소 ! : " << tmp->Data<<endl;
        cout << endl;
    }


    // 마지막 요소를 반환한다.
    int& back()
    {
        return _before_tail->Next->Data;
    }
    const int& back() const
    {
        return _before_tail->Data;
    }

    // 시작 전 요소를 가리키는 반복자를 반환한다.
    Node* before_head()
    {
        return _before_head;
    }
    const Node* before_head() const
    {
        return _before_head;
    }

    // 끝 전 요소를 가리키는 반복자를 반환한다.
    Node* before_tail()
    {
        return _before_tail;
    }
    const Node* before_tail() const
    {
        return _before_tail;
    }

    // 시작 요소를 가리키는 반복자를 반환한다.
    Node* head()
    {
        return _before_head->Next;
    }
    const Node* head() const
    {
        return _before_head->Next;
    }

    // 끝 요소를 가리키는 반복자를 반환한다.
    Node* tail()
    {
        return _before_tail->Next;
    }
    const Node* tail() const
    {
        return _before_tail->Next;
    }

    // pos 다음에 value를 삽입한다.
    // 삽입된 요소를 가리키는 반복자를 반환한다.
    Node* insert_after(Node* pos, int value)
    {
        Node* newNode = new Node(value);
        Node* where = pos;
    
        //첫 사이즈가 0일 때 
        if (_size == 0)
        {
            _before_head->Next = newNode;
            _before_tail->Next = newNode;
            newNode->Next = newNode;
            _size++;
            cout << "head : " << head()->Data << endl;
            cout << "tail : " << tail()->Data << endl;

            cout << "before_head : " << before_head()->Data << endl;
            cout << "before_tail : " << before_tail()->Data << endl;
            cout << endl;
            return newNode;
        }

        newNode->Next = where->Next;
        where->Next = newNode;
        //if (pos == _before_head)
        //{
        //    tail()->Next = head();
        //}

        //before_tail 갱신
        if (pos == before_tail())
        {
            _before_tail = newNode;
        }
        if (pos == tail())
        {
            _before_tail =_before_tail->Next;
        }


        //tail->Next가 head()에 오도록 갱신
        if (tail()->Next != head())
        {
            tail()->Next = head();
        }


        _size++;
        cout << "head : " << head()->Data << endl;
        cout << "tail : " << tail()->Data << endl;

        cout << "before_head : " << before_head()->Data << endl;
        cout << "before_tail : " << before_tail()->Data << endl;
        cout << endl;
        return newNode;
    }

    // pos 다음 요소를 삭제한다.
    // 삭제된 요소를 가리키는 반복자를 반환한다.
    Node* erase_after(Node* pos)
    {
        Node* where = pos;
        Node* removeNode = where->Next;
        if (empty())
        {

            cout << "텅빔!" << endl;

            cout << "before_head : " << before_head()->Data << endl;
            cout << "before_tail : " << before_tail()->Data << endl;

            return tail();
        }

        if (_size == 1)
        {
            _before_head->Next = nullptr;
            _before_tail->Next = nullptr;
            removeNode->Next = nullptr;
            _size--;

            cout << "텅빔!" << endl;

            cout << "before_head : " << before_head()->Data << endl;
            cout << "before_tail : " << before_tail()->Data << endl;

            return _before_head;
        }


        where->Next = removeNode->Next;
        if (removeNode == head())
        {
            _before_head->Next = removeNode->Next;
        }
        removeNode->Next = nullptr;

        if (where == _before_head)
        {
            tail()->Next = where->Next;
        }
    
        


        

        /*if (tail()->Next == head())
        {
            _before_tail = head();
        }*/
        if (where == before_tail() )
        {
            Node* tmp = before_head();
            while (tmp->Next != where)
            {
                tmp = tmp->Next;
            }
            _before_tail = tmp;

        }
        if (removeNode == before_tail())
        {
            _before_tail = pos;
        }



        _size--;
        cout << "head : " << head()->Data << endl;
        cout << "tail : " << tail()->Data << endl;

        cout << "before_head : " << before_head()->Data << endl;
        cout << "before_tail : " << before_tail()->Data << endl;

        return where->Next;
    }

    // 시작 요소에 value를 삽입한다.
    void      push_front(int value)
    {
        insert_after(before_head(), value);
    }

    // 마지막 요소에 value를 삽입한다.
    void      push_back(int value)
    {
        insert_after(tail(), value);
    }

    // 시작 요소를 제거한다.
    void      pop_front()
    {
        erase_after(before_head());
    }

    // 마지막 요소를 제거한다.
    void      pop_back()
    {
        erase_after(before_tail());
    }

    // 컨테이너가 비었는지 판단한다.
    bool      empty() const
    {
        if (_size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // 컨테이너를 비워버린다.
    void      clear()
    {
        while (empty() == false)
        {
            pop_front();
        }
    }

    // 컨테이너에 value가 있는지 확인한다.
    bool      contains(int value) const
    {
        const Node* tmp = head();
        for (int i = 0; i < _size; ++i)
        {
            if (tmp->Data == value)
                return true;
        }
        return false;
    }

    void printContainer()
    {
        Node* tmp = head();
        int index = 0;
        while (index != 2)
        {
            cout << tmp->Data << " ";
            tmp = tmp->Next;
            if (tmp == tail())
            {
                index++;

            }
        }
        cout << tmp->Data << " ";

        cout << endl;
    }
private:
    // 어떤 멤버가 필요할까?
    Node* _before_head = new Node;
    Node* _before_tail = nullptr;
    int _size = 0;
};
