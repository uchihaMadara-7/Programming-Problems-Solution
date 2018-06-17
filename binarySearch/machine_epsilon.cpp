#include <iostream>

using namespace std;

int main()
{
	// epsilon changes with for double
	float epsilon = 0.5;
	float prevEpsilon;
	while(1 + epsilon != 1)
	{
		prevEpsilon = epsilon;
		epsilon /= 2;
	}

	cout << "Your machine epsilon is: " << prevEpsilon << endl;
	return 0;
}
