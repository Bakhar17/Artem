#pragma once
class Array
{
public:
	Array();
	explicit Array(size_t _size);
	Array(const Array& c);
	Array& operator=(const Array& c);
	int& operator[](size_t index);
	const int& operator[](size_t index) const;
	void At(size_t index, int value);

	~Array();
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
	void RemoveAll();
private:
	int* data;
	size_t size;
};
