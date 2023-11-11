#include <iostream>

class Vector
{
public:
	Vector();
	Vector(int len);
	Vector(const Vector& v);
	Vector& operator=(const Vector& v);
	Vector(Vector&& vector);
	Vector& operator=(Vector&&);

	~Vector();
	int getLength();
	int getCapacity();
	void print();
	void changeLength(int newLength);
	double& operator[](int a);

private:
	double* vec;
	int length;
	int capacity;
};