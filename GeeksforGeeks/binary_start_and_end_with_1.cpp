/*
    --- Question Statment ---

Given a binary string, count number of substrings that start and end with 1. For example, if the 
input string is “00100101”, then there are three substrings “1001”, “100101” and “101”. 

Constraints:

1 ≤ T ≤ 40
1 ≤ |s| ≤ 1000


Example:

Input:
1
4
1111
Output:
6

*/

#include<iostream>
using namespace std;

int allsubstring(string str, int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
        if(str[i] == '1')
            count ++;
            
    return (count*(count-1))/2;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        string str;
        cin >> str;
        
        cout << allsubstring(str, n) << endl;
    }
    
	return 0;
}