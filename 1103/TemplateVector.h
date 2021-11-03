#pragma once
#include <stdexcept>


template <typename T>
class TemplateVector
{
public:
    // 기본 생성자
    TemplateVector() = default;

    // count만큼 공간이 할당된 생성자
    explicit TemplateVector(size_t count) : _container{ new int[count] }, _size{ count }, _capacity{ count }{};

    // 복사 생성자. 깊은 복사(deep copy)가 이뤄져야 한다.
    TemplateVector(const TemplateVector& other) : _container{ new int[other._capacity] },
        _size{ other._size },
        _capacity{ other._capacity }
    {
        for (size_t i = 0; i < other.size(); ++i)
        {
            _container[i] = other[i];
        }
    };

    // 할당 연산자. 깊은 복사(deep copy)가 이뤄져야 한다.
    TemplateVector& operator=(const TemplateVector& rhs) {
        if (this != &rhs)
        {
            TemplateVector temp(rhs);
            std::swap(_container, temp._container);
            std::swap(_size, temp._size);
            std::swap(_capacity, temp._capacity);

        }
        return *this;
        // TODO: 여기에 return 문을 삽입합니다.
    };

    // 이동 생성자
    TemplateVector(TemplateVector&& other)    : _container{ other._container }, _size{ other._size }, _capacity{ other._capacity }
    {
        other._container = nullptr;
        other._size = 0;
        other._capacity = 0;
    };
        // 이동 할당 생성자
    TemplateVector& operator=(TemplateVector&& other) {
        if (this != &other)
        {
            TemplateVector temp(std::move(other));
            std::swap(_container, temp._container);
            std::swap(_size, temp._size);
            std::swap(_capacity, temp._capacity);
        }
        return *this;
        // TODO: 여기에 return 문을 삽입합니다.
    }
    // 소멸자
    ~TemplateVector() {
        clear();
    };


    // 첫 번째 요소를 가리키는 반복자를 반환한다.
    T* begin() {
        return _container;
    };
    const T* begin() const {
        return _container;
    };

    // 마지막 요소의 다음 번째를 가리키는 반복자를 반환한다.
    T* end() {
        return _container + _size;
    };
    const T* end() const {
        return _container + _size;
    };

    // 컨테이너가 비었는지 검사한다.
    bool                empty() const {
        if (_size == 0)
            return true;
        else
            return false;
    };

    // 원소의 개수를 반환한다.
    size_t              size() const {
        return _size;
    };

    // 현재 할당된 공간의 크기를 반환한다.
    size_t              capacity() const {
        return _capacity;
    };

    // pos에 위치한 원소의 참조를 반환한다. 만약 pos가 범위에서 벗어나면 std::out_of_range 예외가 던져진다.
    T& at(size_t pos) {
        // TODO: 여기에 return 문을 삽입합니다.
        if (pos >= _size)
        {
            throw std::out_of_range("Out of range");
        }

        return _container[pos];
    };
    const T& at(size_t pos) const {
        // TODO: 여기에 return 문을 삽입합니다.
        if (pos >= _size)
        {
            throw std::out_of_range("Out of range");
        }

        return _container[pos];
    }

    // pos에 위치한 원소의 참조를 반환한다.
    T& operator[](size_t pos) {
        // TODO: 여기에 return 문을 삽입합니다.
        return _container[pos];
    }
    ;
    const T& operator[](size_t pos) const {
        // TODO: 여기에 return 문을 삽입합니다.
        return _container[pos];
    }
    ;

    // 컨테이너의 첫 번째 원소의 참조를 반환한다.
    T& front() {
        // TODO: 여기에 return 문을 삽입합니다.
        return _container[0];
    };
    const T& front() const {
        // TODO: 여기에 return 문을 삽입합니다.
        return _container[0];
    };

    // 컨테이너의 마지막 원소의 참조를 반환한다.
    T& back() {
        // TODO: 여기에 return 문을 삽입합니다.
        return _container[_size - 1];
    };
    const T& back() const {
        // TODO: 여기에 return 문을 삽입합니다.
        return _container[_size - 1];
    };

    // 컨테이너를 비운다.
    void                clear() {
        delete[] _container;
        _container = nullptr;

        _size = 0;
        _capacity = 0;
    };

    // pos 이전 위치에 value를 삽입한다.
    // value가 삽입된 곳을 가리키는 포인터를 반환한다.
    T* insert(T* pos, const T& value) {
        int dist = pos - begin();

        if (_size == 0)
        {
            reserve(1);

            pos = begin() + dist;
        }
        else if (_size == _capacity)
        {
            reserve(_capacity * 2);

            pos = begin() + dist;
        }

        for (int* iter = end(); iter != pos; --iter)
        {
            *iter = *(iter - 1);
        }
        *pos = value;

        ++_size;

        return pos;
    };

    // pos에 위치한 원소를 지운다.
    // 삭제된 요소의 다음 포인터를 반환한다.
    T* erase(T* pos) {
        // 컨테이너가 비었다면?
        if (empty())
        {
            return end();
        }

        int* last = end() - 1;
        if (pos == last)
        {
            --_size;
            return end();
        }

        for (int* iter = pos; iter != last; ++iter)
        {
            *iter = *(iter + 1);
        }
        --_size;

        return pos;
    };

    // 컨테이너의 맨 끝에 원소를 추가한다.
    void                push_back(const T& value) {
        insert(end(), value);
    };

    // 컨테이너의 마지막 원소를 삭제한다.
    void                pop_back() {
        erase(end() - 1);
    };
    // value가 존재하는지 검사한다.
    bool                contains(const T& value) {
        for (int* iter = begin(); iter != end(); ++iter)
        {
            if (*iter == value)
                return true;
        }

        return false;
    };

    // 컨테이너의 용량을 newCapacity보다 같거나 크게 늘린다.
    // newCapacity > _capacity라면 새로운 메모리를 할당하고,
    // 그렇지 않다면 아무 동작도 수행하지 않는다.
    void                reserve(size_t newCapacity) {
        if (newCapacity <= _capacity)
            return;

        int* newContainer = new int[newCapacity];

        for (size_t i = 0; i < _size; ++i)
        {
            newContainer[i] = _container[i];
        }

        delete[] _container;
        _container = newContainer;
        _capacity = newCapacity;
    }
    ;
private:

    T*                  _container = nullptr;
    size_t              _size = 0;
    size_t              _capacity = 0;
};
