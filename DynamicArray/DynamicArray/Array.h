#pragma once
#pragma once
class Array
{
public:
	Array();
	explicit Array(size_t _size);
	Array(const Array& c);
	Array& operator=(const Array& c);
	int& operator[](int index);
	void SetAt(size_t index, int value);
	const int GetSize();
	const void FreeExtra(size_t newsize);
	const void SetSize(size_t size, size_t grow = 1);
	const bool IsEmpty();
	const int GetUpperBound();
	const void RemoveAll();
	const void Add(size_t indexpos, int value);
	const void InsertAt(size_t index, int value);
	const void RemoveAt(size_t index);
	friend const Array Append(Array& A, Array& B);
	~Array();
	class ErrorIndex
	{
	public:
		size_t index;
		ErrorIndex(size_t index1) :index(index1) {
		}
	};


private:
	int* data;
	size_t size;
	int elements;
	int grow;
};
