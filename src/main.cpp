#include "vector.h"

int main() {
	std::cout << "Hello world" << std::endl;

	{
		Vector vector(5);

		std::cout << "Vector length: " << vector.getLength() << std::endl;
		std::cout << "Vector capacity: " << vector.getCapacity() << std::endl;

		vector.changeLength(7);

		// vector.print();

		vector[3] = 42;

		Vector bector {vector};	 // copying constructor

		Vector kector;
		kector = bector;  // copying by assignment op

		kector.print();

		vector = vector;

		vector[4] = 2137;

		Vector dector {std::move(vector)};
		dector = std::move(dector);

		dector.print();

	}
}
