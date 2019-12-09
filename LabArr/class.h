#pragma once
class Array
{	

public:
	int* data;
	Array();
	explicit Array(size_t _size);
	Array(const Array& c);
	Array& operator=(const Array& c);
	int& operator[](size_t index);
	const int& operator[](size_t index) const;
	void SetAt(size_t index, int value);
	void RemoveAll();
	//~Array();???
	class ErrorIndex
	{
	public:
		size_t index;
		ErrorIndex(size_t index1) :index(index1)
		{
		}
	};
	size_t GetSize();
	bool IsEmpty();
	Array SetSize(size_t size, int grow = 5);
	void Add(int x);
	void GetAt(int index);
	int GetUpperBound();
	void RemoveAt(size_t index);
	void FreeExtra();
	const Array Append(const Array& oper2) const;

private:

	size_t size;
};
