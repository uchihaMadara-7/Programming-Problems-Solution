/*
	--- Question Statemenet ---

Given a string consisting of opening and closing parenthesis, find length of the longest valid 
parenthesis substring.

Examples:

Input : ((()
Output : 2
Explanation : ()

Input: )()())
Output : 4
Explanation: ()()

Input:  ()(()))))
Output: 6
Explanation:  ()(())

Input:
First line contains the test cases T.  1<=T<=500
Each test case have one line string S of character'(' and ')' of length  N.  1<=N<=10000

Example:
Input:
2
((()
)()())

Output:
2
4

*/

#include<iostream>
#include<stack>
using namespace std;

int longestBalanced(string str)
{
    stack<int> balanced;
    balanced.push(-1);
    int maxim = 0;
    
    for(int i=0;str[i];i++)
    {
        if(str[i] == '(')
            balanced.push(i);
        else
        {
            balanced.pop();
            if(!balanced.empty())
                maxim = max(maxim, i-balanced.top());
            else
                balanced.push(i);
        }
    }
    
    return maxim;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        string str;
        cin >> str;
        
        cout << longestBalanced(str) << endl;
    }
    
	return 0;
}