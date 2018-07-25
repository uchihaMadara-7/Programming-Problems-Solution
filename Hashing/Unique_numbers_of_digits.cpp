/*
	--- Question Statement ---

In given range, print all numbers having unique digits. e.g. In range 1 to 20 should 
print all numbers except 11.

Input:
First line consists of T test cases.
The only line of every test case consists of two integers m and n separated by a space.

Output:
For each test case print all unique numbers separated by space.

Constraints:
1<=T<=100
1<=m,n<1000

Example:
Input:
1
10 20
Output:
10 12 13 14 15 16 17 18 19 20

*/

#include<iostream>
using namespace std;

bool isDistinct(int n)
{
    int hash[10] = {0};
    while(n > 0)
    {
        int remain = n % 10;
        if(hash[remain])
            return false;
        
        hash[remain] = 1;
        n/=10;
    }
    
    return true;
}

void allBetween(int l, int r)
{
    for(int i=l;i<=r;i++)
    {
        if(isDistinct(i))
            cout << i << " ";
    }
    
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int l, r;
        
        cin >> l >> r;
        allBetween(l, r);
    }
    
	return 0;
}