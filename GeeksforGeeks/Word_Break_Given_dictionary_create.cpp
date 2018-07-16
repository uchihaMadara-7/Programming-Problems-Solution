/*
	--- Question Statement ---

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where 
each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "snakesandladder",
dict = ["snake", "snakes", "and", "sand", "ladder"].

A solution is ["snakes and ladder",
           "snake sand ladder"].

Input:
The first line contains an integer T, denoting the number of test cases.
Every test case has 3 lines.
The first line contains an integer N, number of words in the dictionary.
The second line contains N strings denoting the words of the dictionary.
The third line contains a string s.

Output:
For each test case, print all possible strings in one line. Each string is enclosed in (). See Example.
If no string possible print "Empty" (without quotes).

Constraints:
1<=T<=100
1<=N<=20
1<=Length of each word in dictionary <=15
1<=Length of s<=1000
 

Note: Make sure the strings are sorted in your result.

Exapmle:
Input:
1
5
lr m lrm hcdar wk
hcdarlrm

Output:
(hcdar lr m)(hcdar lrm)

*/

#include<iostream>
#include<vector>

using namespace std;

void print(vector<string> result)
{
	int size = result.size();
	cout <<"(";
	for(int i=0;i<size-1;i++)
        	cout << result[i] << " ";
    cout << result[size-1] << ")";
}

vector<string> result;

void check_password(vector<string> password, string str, int size, int x)
{
    if(x >= str.size())
	{
		print(result);
	    return;
	}

	for(int i=0;i<size;i++)
	{
	    if(str.size()-x >= password[i].size() &&
			password[i] == str.substr(x, password[i].size()))
		{
			result.push_back(password[i]);
			check_password(password, str, size, x+password[i].size());
			result.pop_back();
		}
	}

}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<string> password(n);
        for(int i=0;i<n;i++)
        	cin >> password[i];
        
        string str;
        cin >> str;
        
        check_password(password, str, n, 0);
        cout << endl;
    }
    
    return 0;
}