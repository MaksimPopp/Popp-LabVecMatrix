#include <iostream>
using namespace std;
class Vec
{
public:
	double* arr;
	int size;
	Vec(int len)
	{
		size = len;
		arr = new double[len];
	}
	friend std::ostream& operator<<(std::ostream& out, Vec& a)
	{
		for (int i = 0; i < a.size; i++)
			out << a.arr[i] << "  ";
		out << "\n";
		return out;
	}
	Vec& operator=(const Vec& a)
	{
		if (this->arr != nullptr)
		{
			delete[] this->arr;
		}
		this->size = a.size;
		this->arr = new double[a.size];
		for (int i = 0; i < a.size; i++)
			this->arr[i] = a.arr[i];
		return *this;
	}

};
