/*
	--- Question Statement ---
	
	Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
	Example : n = 16
	output: true
*/

#include <iostream>

using namespace std;

bool isPowerOfFour(int num) 
{
	if(num < 0)
	    return false;

	int bits = sizeof(int) * 8;
	int last = 0;

	int count = 0;
	for(int i=0;i<bits-1;i++)
	{
	    if(num & 1 << i)
	    {
		count ++;
		last = i;
	    }
	}

	int count1 = 0;
	for(int i=0;i<last;i++)
	{
	    if(!(num & 1 << i))
		count1 ++;
	}

	cout << count << " " << count1 << endl;
	if(count == 1 && count1 % 2 == 0)
	    return true;
	return false;
}

int main()
{
	int n;
	cin >> n;

	if(isPowerOf4(n))
		cout << n <<" is a power of 4"<<endl;
	else
		cout << n <<" is not a power of 4"<<endl;
}
