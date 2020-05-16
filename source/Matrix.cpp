#include <iostream>
using namespace std;
class Matrix
{
public:
	double** arr;
	int line, collumn;
	Matrix(int i, int j)
	{
		line = i;
		collumn = j;
		arr = new double* [line];
		for (int k = 0; k < i; k++)
			arr[k] = new double[collumn];



	}

	Matrix& operator=(const Matrix& a)
	{
		if (this->collumn > 0)
		{
			for (int i = 0; i < a.line; i++)
				delete[] this->arr[i];

		}
		if (this->line > 0)
		{
			delete[] this->arr;
		}
		this->line = a.line;
		this->collumn = a.collumn;
		this->arr = new double* [a.line];
		for (int i = 0; i < a.line; i++)
			this->arr[i] = new double[a.collumn];
		for (int i = 0; i < a.line; i++)
		{
			for (int j = 0; j < a.collumn; j++)
				this->arr[i][j] = a.arr[i][j];
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, Matrix& a)
	{
		for (int i = 0; i < a.line; i++)
		{
			for (int j = 0; j < a.collumn; j++)
				out << a.arr[i][j] << "  ";
			out << "\n";
		}
		return out;
	}


	Matrix& operator+(const Matrix& a)
	{
			if (a.line != this->line || a.collumn != this->collumn)
			{
				throw exception("Matrices have different sizes");
			}
			for (int i = 0; i < a.line; i++)
				for (int j = 0; j < a.collumn; j++)
					this->arr[i][j]=a.arr[i][j] + this->arr[i][j];
			return *this;
	}

	Matrix& operator-(const Matrix& a)
	{
		if (a.line != this->line || a.collumn != this->collumn)
		{
			throw exception("Matrices have different sizes");
		}
			for (int i = 0; i < a.line; i++)
				for (int j = 0; j < a.collumn; j++)
					this->arr[i][j] =  this->arr[i][j]-a.arr[i][j] ;
			return *this;
	}

	Matrix operator*(const Matrix& a)
	{
		if (this->collumn != a.line)
		{
			throw exception("Matrices are incompatible");
		}
			Matrix c(this->line, a.collumn);
			for (int i = 0; i < c.line; i++)
				for (int j = 0; j < c.collumn; j++)
					c.arr[i][j] = 0;
			for (int i = 0; i < this->line; i++)
				for (int j = 0; j < a.collumn; j++)
					for(int k=0;k< this->collumn;k++)
					c.arr[i][j] += this->arr[i][k] * a.arr[k][j];
			return c;

	}

};
int main()
{
	Matrix a(3, 2);
	Matrix b(2, 3);

	Matrix c(0,0);
	for (int i = 0; i < b.line; i++)
		for (int j = 0; j < b.collumn; j++)
			b.arr[i][j] = i + j;
	for (int i = 0; i < a.line; i++)
		for (int j = 0; j < a.collumn; j++)
			a.arr[i][j] = i + j;
	try 
	{
	c=( a * b);
	cout <<c;
	}
	catch (const  exception& ex)
	{
		cout << ex.what() << endl;
	}

}