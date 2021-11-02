#include "AssignVector.h"

#include <iostream>
using namespace std;

AssignVector::AssignVector(int capacity)
	:myObject{ nullptr }, _size{ 0 }, _capacity{ capacity }
{
	reserve(capacity);
}


// 복사 생성자. 깊은 복사(deep copy)가 이뤄져야 한다.
AssignVector::AssignVector(const AssignVector& other)
	: myObject{ new MyObject[other._capacity] }, _size{ other._size }, _capacity{ other._capacity }
{
	for (int i = 0; i < other._size; i++)
	{
		myObject[i]._id = other.myObject[i]._id;
	}
}

// 할당 연산자. 깊은 복사(deep copy)가 이뤄져야 한다.
AssignVector& AssignVector::operator=(const AssignVector& other)
{
	if (this != &other)
	{
		AssignVector temp(other);
		std::swap(myObject, temp.myObject);
		std::swap(_size, temp._size);
		std::swap(_capacity, temp._capacity);

	}
	return *this;
}

AssignVector::~AssignVector()
{
	delete[] myObject;
	_capacity = 0;
	_size = 0;
}

int AssignVector::GetCapacity() const
{
	return _capacity;
}

int AssignVector::GetSize() const
{
	return _size;
}

void AssignVector::Add(int id)
{
	MyObject* newMyObject = new MyObject;
	newMyObject->_id = id;

	if (_size == 0)
	{
		reserve(1);
	}
	else if (_size == _capacity)
	{
		reserve(_capacity * 2);

	}

	cout << "추가 완료 : " << newMyObject->_id << " " << _size <<  endl;

	myObject[_size] = *newMyObject;
	++_size;
}

MyObject* AssignVector::FindById(int MyObjectId) const
{
	int index = 0;
	for (int i = 0; i < _size; ++i)
	{
		if (myObject[i]._id == MyObjectId)
			return &myObject[i];
	}

	return nullptr;
}

void AssignVector::TrimToSize()
{
	if (_size == _capacity)
		return;

	MyObject* newObject = new MyObject[_size];

	for (size_t i = 0; i < _size; ++i)
	{
		newObject[i] = myObject[i];
	}

	delete[] myObject;
	myObject = newObject;
	_capacity = _size;
}

MyObject& AssignVector::operator[](size_t index)
{
	// TODO: 여기에 return 문을 삽입합니다.
	return myObject[index];
}

//MyObject& AssignVector::operator[](size_t index)
//{
//	// TODO: 여기에 return 문을 삽입합니다.
//	return *this;
//}

std::string AssignVector::ToString() const
{
	string str;

	for (int i = 0; i < _size; i++)
		str.push_back(myObject[i]._id);

	return str;
}

void AssignVector::RemoveAll(int MyObjectId)
{
	cout << "제거 전 Vector데이터 : " << endl;
	for (MyObject* myObj = begin(); myObj != end(); ++myObj)
	{
		cout << (*myObj)._id << " ";
	}

	for (MyObject* myObj = begin(); myObj != end()-1; ++myObj)
	{
		if ((*myObj)._id == MyObjectId)
		{
			for (MyObject* tmp = myObj; tmp != end() - 1; ++tmp)
			{
				(*tmp)._id = (*(tmp + 1))._id;

			}
			_size--;
			myObj--;
		}
	}
	
	cout << "제거 전 Vector데이터 : " << endl;
	for (MyObject* myObj = begin(); myObj != end() ; ++myObj)
	{
		cout << (*myObj)._id << " ";
	}
	

}

MyObject* AssignVector::begin()
{
	return myObject;
}

const MyObject* AssignVector::begin() const
{
	// TODO: 여기에 return 문을 삽입합니다.
	return myObject;
}

MyObject* AssignVector::end()
{
	// TODO: 여기에 return 문을 삽입합니다.

	return myObject + _size;
}

const MyObject* AssignVector::end() const
{
	// TODO: 여기에 return 문을 삽입합니다.
	return myObject + _size;
}

void AssignVector::reserve(size_t newCapacity)
{
	if (newCapacity <= _capacity)
		return;

	MyObject* newObject = new MyObject[newCapacity];

	for (size_t i = 0; i < _size; ++i)
	{
		newObject[i] = myObject[i];
	}

	delete[] myObject;
	myObject = newObject;
	_capacity = newCapacity;
}


AssignVector* AssignVector::GroupById(int* numGroups)
{
	AssignVector* newAssignVector = new AssignVector;
	cout << endl;
	for (int i = 0; i < *numGroups; i++)
	{
		cout << "Group : ";
		newAssignVector->Add(0);
	}

	return newAssignVector;
}
