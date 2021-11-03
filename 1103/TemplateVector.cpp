//#include <stdexcept>
//#include "TemplateVector.h"
//
//TemplateVector::TemplateVector(size_t count)
//    : _container{ new int[count] }, _size{ count }, _capacity{ count }
//{
//
//}
//
//TemplateVector::TemplateVector(const TemplateVector& other)
//    : _container{ new int[other._capacity] },
//    _size{ other._size },
//    _capacity{ other._capacity }
//{
//    for (size_t i = 0; i < other.size(); ++i)
//    {
//        _container[i] = other[i];
//    }
//}
//
//
//TemplateVector& TemplateVector::operator=(const TemplateVector& rhs)
//{
//    if (this != &rhs)
//    {
//        TemplateVector temp(rhs);
//        std::swap(_container, temp._container);
//        std::swap(_size, temp._size);
//        std::swap(_capacity, temp._capacity);
//
//    }
//    return *this;
//    // TODO: 여기에 return 문을 삽입합니다.
//}
//
//TemplateVector::TemplateVector(TemplateVector&& other)
//    : _container{ other._container },
//    _size{ other._size },
//    _capacity{ other._capacity }
//{
//    other._container = nullptr;
//    other._size = 0;
//    other._capacity = 0;
//
//}
//
//TemplateVector& TemplateVector::operator=(TemplateVector&& other)
//{
//    if (this != &other)
//    {
//        TemplateVector temp(std::move(other));
//        std::swap(_container, temp._container);
//        std::swap(_size, temp._size);
//        std::swap(_capacity, temp._capacity);
//    }
//    return *this;
//    // TODO: 여기에 return 문을 삽입합니다.
//}
//
//TemplateVector::~TemplateVector()
//{
//    clear();
////}
//
//int* TemplateVector::begin()
//{
//    return _container;
//}
//
//const int* TemplateVector::begin() const
//{
//    return _container;
//}
//
//int* TemplateVector::end()
//{
//    return _container + _size;
//}
//
//const int* TemplateVector::end() const
//{
//    return _container + _size;
//}
//
//bool TemplateVector::empty() const
//{
//    if (_size == 0)
//        return true;
//    else
//        return false;
//}
//
//size_t TemplateVector::size() const
//{
//    return _size;
//}
//
//size_t TemplateVector::capacity() const
//{
//    return _capacity;
//}
//
//int& TemplateVector::at(size_t pos)
//{
//    // TODO: 여기에 return 문을 삽입합니다.
//    if (pos >= _size)
//    {
//        throw std::out_of_range("Out of range");
//    }
//
//    return _container[pos];
//}
//
//const int& TemplateVector::at(size_t pos) const
//{
//    // TODO: 여기에 return 문을 삽입합니다.
//    if (pos >= _size)
//    {
//        throw std::out_of_range("Out of range");
//    }
//
//    return _container[pos];
//}
//
//int& TemplateVector::operator[](size_t pos)
//{
//    // TODO: 여기에 return 문을 삽입합니다.
//    return _container[pos];
//}
//
//const int& TemplateVector::operator[](size_t pos) const
//{
//    // TODO: 여기에 return 문을 삽입합니다.
//    return _container[pos];
//}
//
//int& TemplateVector::front()
//{
//    // TODO: 여기에 return 문을 삽입합니다.
//    return _container[0];
//}
//
//const int& TemplateVector::front() const
//{
//    // TODO: 여기에 return 문을 삽입합니다.
//    return _container[0];
//}
//
//int& TemplateVector::back()
//{
//    // TODO: 여기에 return 문을 삽입합니다.
//    return _container[_size - 1];
//}
//
//const int& TemplateVector::back() const
//{
//    // TODO: 여기에 return 문을 삽입합니다.
//    return _container[_size - 1];
//}
//
//void TemplateVector::clear()
//{
//    delete[] _container;
//    _container = nullptr;
//
//    _size = 0;
//    _capacity = 0;
//}
//
//int* TemplateVector::insert(int* pos, int value)
//{
//    int dist = pos - begin();
//
//    if (_size == 0)
//    {
//        reserve(1);
//
//        pos = begin() + dist;
//    }
//    else if (_size == _capacity)
//    {
//        reserve(_capacity * 2);
//
//        pos = begin() + dist;
//    }
//
//    for (int* iter = end(); iter != pos; --iter)
//    {
//        *iter = *(iter - 1);
//    }
//    *pos = value;
//
//    ++_size;
//
//    return pos;
//}
//
//int* TemplateVector::erase(int* pos)
//{
//    // 컨테이너가 비었다면?
//    if (empty())
//    {
//        return end();
//    }
//
//    int* last = end() - 1;
//    if (pos == last)
//    {
//        --_size;
//        return end();
//    }
//
//    for (int* iter = pos; iter != last; ++iter)
//    {
//        *iter = *(iter + 1);
//    }
//    --_size;
//
//    return pos;
//}
//
//void TemplateVector::push_back(int value)
//{
//    insert(end(), value);
//}
//
//void TemplateVector::pop_back()
//{
//    erase(end() - 1);
//}
//
//bool TemplateVector::contains(int value)
//{
//    for (int* iter = begin(); iter != end(); ++iter)
//    {
//        if (*iter == value)
//            return true;
//    }
//
//    return false;
//}
//
//void TemplateVector::reserve(size_t newCapacity)
//{
//    if (newCapacity <= _capacity)
//        return;
//
//    int* newContainer = new int[newCapacity];
//
//    for (size_t i = 0; i < _size; ++i)
//    {
//        newContainer[i] = _container[i];
//    }
//
//    delete[] _container;
//    _container = newContainer;
//    _capacity = newCapacity;
//}
