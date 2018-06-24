#include <iostream>

using namespace std;

bool isPallindrome(int n)
{
	int high = sizeof(int)*2-1;
	int low = 0;

	while(low < high)
	{
		if(!((n & 1 << low && n & 1 << high) 
			   || (!(n & 1 << low) && !(n & 1 << high))))
			return false;
        low ++;
        high --;
	}

	return true;
}

int main()
{
	int n;
	cin >> n;

	if(isPallindrome(n))
		cout << "It is a Pallindrome" << endl;
	else
		cout << "It is not a Pallindrome" << endl;
	
	return 0;
}
