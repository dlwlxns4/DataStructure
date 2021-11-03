//-------------------------------------------------------------------------------------------------
// 벡터란? (http://www.cplusplus.com/reference/vector/vector/)
//
// Vectors are sequence containers representing arrays that can change in size.
// Just like arrays, vectors use contiguous storage locations for their elements,
// which means that their elements can also be accessed using offsets on regular pointers
// to its elements, and just as efficiently as in arrays. But unlike arrays,
// their size can change dynamically, with their storage being handled automatically
// by the container.
//
// Internally, vectors use a dynamically allocated array to store their elements.
// This array may need to be reallocated in order to grow in size when new elements are inserted,
// which implies allocating a new array and moving all elements to it.
// This is a relatively expensive task in terms of processing time, and thus,
// vectors do not reallocate each time an element is added to the container.
//
// Instead, vector containers may allocate some extra storage to accommodate for possible growth,
// and thus the container may have an actual capacity greater than the storage strictly needed to
// contain its elements (i.e., its size). Libraries can implement different strategies for growth
// to balance between memory usage and reallocations, but in any case,
// reallocations should only happen at logarithmically growing intervals of size
// so that the insertion of individual elements at the end of the vector can be provided with
// amortized constant time complexity.
//-------------------------------------------------------------------------------------------------

#include <string>

//-------------------------------------------------------------------------------------------------
// MyVector 가 관리하는 오브젝트
//-------------------------------------------------------------------------------------------------
struct MyObject
{
    int _id;
};

//-------------------------------------------------------------------------------------------------
// MyVector 클래스.
//-------------------------------------------------------------------------------------------------
class AssignVector
{
private: // 구현에 필요한 멤버 추가 함수/변수들을 자유롭게 아래에 정의 합니다.

    MyObject* myObject = nullptr;
    int _size =0;
    int _capacity =0;

    // 예.1) 사이즈를 저장하는 멤버변수를 아래처럼 추가하면 됩니다.
    // int _vectorSize;

    // 예.2) 저장공간을 늘리는 함수를 아래처럼 추가하면 됩니다.
    // void Grow();

public: // 생성자, 복사생성자, 할당연산자, 소멸자를 .cpp 파일에 구현합니다.

    AssignVector() = default; /**/

    // Constructor.
    AssignVector(int capacity); /**/

    // Copy constructor.
    AssignVector(const AssignVector& other); /**/

    // Assignment operator.
    AssignVector& operator=(const AssignVector& other);/**/

    // Destructor.
    ~AssignVector();

public: // 아래 기능 함수들을 .cpp 파일에 구현합니다.

    // Returns current capacity of this vector.
    int GetCapacity() const;/**/

    // Returns current size of this vector.
    int GetSize() const;/**/

    // Creates a new MyObject instance with the given ID, and appends it to the end of this vector.
    void Add(int id);/**/

    // Returns the first occurrence of MyObject instance with the given ID.
    // Returns nullptr if not found.
    MyObject* FindById(int MyObjectId) const;/**/

    // Trims the capacity of this vector to current size.
    void TrimToSize();/**/

    // Returns the MyObject instance at the specified index.
    MyObject& operator[](size_t index);/**/

    // Returns string representation of the vector.
    std::string ToString() const;/**/

    // Remove all MyObject instances with the given ID in this vector.
    void RemoveAll(int MyObjectId);/**/

    MyObject* begin();/**/

    const MyObject* begin() const;/**/

    MyObject* end();/**/

    const MyObject* end() const;/**/

    void reserve(size_t newCapacity);/**/

    // Returns a newly allocated array of MyVector objects,
    // each of whose elements have the same "_id" value of the MyObject struct.
    // The 'numGroups' is an out parameter, and its value should be set to
    // the size of the MyVector array to be returned.
    AssignVector* GroupById(int* numGroups);/**/
};

