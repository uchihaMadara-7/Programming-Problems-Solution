/*
	--- Question Statement ---

Given a array of n strings, find the longest common prefix among all strings present 
in the array.

Input:
The first line of the input contains an integer T which denotes the number of test 
cases to follow. Each test case contains an integer n. Next line has space separated 
n strings. 

Output:
Print the longest common prefix as a string in the given array. If no such prefix 
exists print "-1"(without quotes).

Constraints:
1<=T<=200
1<=n<=100
1<=|S|<=100

Example:
Input:
2
4
geeksforgeeks geeks geek geezer
3
apple ape april

Output:
gee
ap

*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

string longPrefix(vector<string> str, int n)
{
    string ans = "";
    int length = INT_MAX;
    
    for(int i=0;i<n;i++)
    {
        int size = str[i].size();
        length = min(length, size);
    }
    
    for(int i=0;i<length;i++)
    {
        char c = str[0][i];
        for(int j=0;j<n;j++)
        {
            if(str[j][i] != c)
                return ans==""?"-1":ans;
        }
        
        ans += c;
    }
    
    return ans;
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
	    int n;
	    cin >> n;
	    
	    vector<string> str(n);
	    for(int i=0;i<n;i++)
	        cin >> str[i];
	        
	    cout << longPrefix(str, n) << endl;
	}
	
	return 0;
}