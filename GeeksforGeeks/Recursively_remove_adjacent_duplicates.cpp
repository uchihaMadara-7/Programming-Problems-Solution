/*
	--- Question Statement ---

Given a string s, recursively remove adjacent duplicate characters from the string s. The output 
string should not have any adjacent duplicates.
 
Input:
The first line of input contains an integer T, denoting the no of test cases. Then T test cases follow. 
Each test case contains a string str.

Output:
For each test case, print a new line containing the resulting string.

Constraints:
1<=T<=100
1<=Length of string<=50

Example:
Input:
2
geeksforgeek
acaaabbbacdddd

Output:
gksforgk
acac

*/

#include<iostream>
using namespace std;

string removeduplicate(string str, int current, string result ="")
{
    if(current < 0)
    {
        if(result == str)
            return result;
        return removeduplicate(result, result.size()-1);
    }
    
    if(current !=0 && str[current] == str[current-1])
        return removeduplicate(str, current-1, result);
    if(current < str.size()-1 && str[current] == str[current+1])
        return removeduplicate(str, current-1, result);
    return removeduplicate(str, current-1, str[current]+result);
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
	    string str; 
	    cin >> str;
	    
	    cout << removeduplicate(str, str.size()-1) << endl;
	}
	
	return 0;
}