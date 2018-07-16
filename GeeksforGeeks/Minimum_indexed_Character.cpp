/*
	--- Question Statement ---

Given a string str and another string patt. Find the character in patt that is present at the 
minimum index in str. If no character of patt is present in str then print ‘No character present’.

Input:
The first line of input contains an integer T denoting the number of test cases. Then the 
description of T test cases follow. Each test case contains two strings str and patt respectively.

Output:
Print the character in patt that is present at the minimum index in str.
Print "No character present" (without quotes) if no character of patt is present in str.

Constraints:
1<=T<=10^5
1<=length of string<=10^5

Example:
Input:
2
geeksforgeeks
set
adcffaet
onkl

Output:
e
No character present

*/

#include<iostream>
using namespace std;

void minIndex(string str, string pattern)
{
    bool hash[26] = {false};
    
    for(int i=0;pattern[i];i++)
        hash[pattern[i]-'a'] = true;
        
    for(int i=0;str[i];i++)
        if(hash[str[i]-'a'])
        {
            cout << str[i] << endl;
            return;
        }
    
    cout << "No character present" << endl;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        string str, pattern;
        cin >> str;
        cin >> pattern;
        
        minIndex(str, pattern);
    }
    
	return 0;
}