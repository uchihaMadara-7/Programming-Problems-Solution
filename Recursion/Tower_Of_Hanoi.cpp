/*
	--- Question Statement ---

	Write a function to print all the steps in tower of hanoi. 
	Example: n = 2
	output: 1 A to C
			2 A to B
			1 C to B 
			
*/

#include <iostream>
#define dikha(n,a,b) cout<<n<<" "<<a<<" to "<<b<<endl

using namespace std;

void towerHanoi(int n, char from, char to, char aux)
{
	if(n == 1)
	{
		dikha(n, from, to);
		return;
	}

	towerHanoi(n-1, from, aux, to);
	dikha(n, from, to);
	towerHanoi(n-1, aux, to, from);
}

int main()
{
	int n;
	cin >> n;

	towerHanoi(n, 'A', 'B', 'C');
	return 0;
}
