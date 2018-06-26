/*
	--- Question Statement ---
	
	Given two coordinates [a,b] and [c,d]. Find the distance between them.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a,b,c,d;
	cin >> a >> b;
	cin >> c >> d;
	cout << sqrt(pow(a-c,2)+pow(b-d,2));
	return 0;
}
