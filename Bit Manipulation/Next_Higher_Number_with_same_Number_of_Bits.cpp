#include <iostream>

using namespace std;

int nextGreater(int n)
{
	int next = 0;
	int bits = 8;

	int i = 0;

	int last = 0, count = 0;
	for(i=0;i<bits;i++)
	{
		if((n & 1 << i) && !(n & 1 << (i+1)))
		{
			last = i;
			break;
		}
	}

	next = next | 1 << (last+1);
	if(last != 0 && n & 1 << (last-1))
	{
		int index = 0;
        for(int i=0;i<last;i++)
        {
        	if(n & 1 << i)
        	{
        		next = next | 1 << index;
        		index ++;
        	}
        }
	}
		
	for(int i=last+2;i<bits;i++)
    {
       	if(n & 1 << i)
        next = next | 1 << i;
    }

	return next;
}

int main()
{
	int n;
	cin >> n;

	cout << nextGreater(n) << endl;
	return 0;
}
