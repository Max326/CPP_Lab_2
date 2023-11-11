#include "vector.h"

Vector::Vector() {
	std::cout << "Default constructor ran." << std::endl;
	vec = nullptr;
	length = 1;
	capacity = 1;
}

Vector::Vector(int len) : length(len),
						  capacity(len) {
	std::cout << "Vector created." << std::endl;

	vec = new double[len];

	for(int i = 0; i < len; i++) {
		vec[i] = 0.0;
	}
}

Vector::Vector(const Vector &v) : length(v.length),
								  capacity(v.capacity) {
	std::cout << "Vector copied." << std::endl;

	vec = new double[capacity];	 // Allocate new memory
	for(int i = 0; i < length; i++) {
		vec[i] = v.vec[i];	// Copy elements
	}
}

Vector &Vector::operator=(const Vector &v) {
	std::cout << "Vector copied by assignment operator." << std::endl;

	if(this != &v) {
		delete[] vec;

		length = v.length;
		capacity = v.capacity;

		vec = new double[capacity];
		for(int i = 0; i < length; i++) {
			vec[i] = v.vec[i];
		}
	}
	return *this;
}

Vector::Vector(Vector &&vector) : vec(vector.vec),
								  length(vector.length),
								  capacity(vector.capacity) {
	std::cout << "Moving constructor ran." << std::endl;

	vector.vec = nullptr;
	vector.length = 0;
	vector.capacity = 0;
}

Vector &Vector::operator=(Vector &&vector) {
	std::cout << "Moving assignment operator ran." << std::endl;
	if(this != &vector) {
        delete [] vec;

        vec = vector.vec;
        length = vector.length;
        capacity = vector.capacity;

		vector.vec = nullptr;
		vector.length = 0;
		vector.capacity = 0;
	}
	return *this;
}

Vector::~Vector() {
	delete[] vec;
	std::cout << "Vector destroyed." << std::endl;
}

int Vector::getLength() {
	return length;
}

int Vector::getCapacity() {
	return capacity;
}

void Vector::print() {
	for(int i = 0; i < length; i++) {
		std::cout << "Element " << i << " of vector is: " << vec[i] << std::endl;
	}
}

void Vector::changeLength(int newLength) {
	if(newLength <= capacity && newLength <= length) {
		length = newLength;
	} else if(newLength <= capacity && newLength > length) {
		for(int i = length; i < newLength; i++) {  // Initialize new elements to 0.0
			vec[i] = 0.0;
		}
		length = newLength;	 // Update the length after initializing
	} else if(newLength >= capacity) {
		double *newVec = new double[newLength];

		for(int i = 0; i < length; i++) {
			newVec[i] = vec[i];
		}

		for(int i = length; i < newLength; i++) {
			newVec[i] = 0.0;
		}

		delete[] vec;
		vec = newVec;
		length = newLength;
		capacity = newLength;

	} else {
		std::cout << "Unexpected case." << std::endl;
	}

	std::cout << "Vector length: " << length << std::endl;
	std::cout << "Vector capacity: " << capacity << std::endl;
}

double &Vector::operator[](int a) {
	if(a >= length) {
		changeLength(a);
	}
	return vec[a];
}