#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	int sum = 0;
	for(int i=0;i<n;i++)
		sum += array[i];

	int squareSum = 0;
	for(int i=0;i<n;i++)
		squareSum += pow(array[i], 2);

	int sumDiff = n*(n+1)/2 - sum;
	int squareDiff = n*(n+1)*(2*n+1)/6 - squareSum;

	int x = (squareDiff/sumDiff - sumDiff)/2;
	int y = x + sumDiff;

	cout <<"repeating: " << x << " missing: " << y << endl;

	return 0;
}
