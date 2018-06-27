/*
	--- Question Statement ---

	given a string containing only digits, restore it by returning all
	possible valid ip address combinations. 8bits.8bits.8bits.8bits
	The numbers cannot be prefixed unless they are 0.
	Example : 25525511135
	output: [255.255.11.135], [255.255.111.35]
	Make sure the answer is sorted.
	25252525
	output:
	25.25.25.25, 25.25.252.5, 25.252.5.25, 25.252.52.5
	252.5.25.25, 252.5.252.5, 252.52.5.25, 252.52.52.5
*/

#include <iostream>

using namespace std;

void allPossibleIP(string str, int pos, int dots, int size)
{
	if(dots == 3)
	{
	    if(size-pos > 0 && stoul(str.substr(pos, size-pos)) <= 255)
            cout << str << endl;
		return;
	}

	for(int i=pos;i<size;i++)
	{

        if(str[i-1] != '.')
        {
            if(i-pos > 0 && stoul(str.substr(pos, i-pos)) <= 255)
            {
                allPossibleIP(str.substr(0,i)+'.'+str.substr(i,str.size()-i), i+1, dots+1, size+1);
            }
        }
	}
}

int main()
{
	string str;
	cin >> str;

	allPossibleIP(str, 0, 0, str.size());
	return 0;
}
