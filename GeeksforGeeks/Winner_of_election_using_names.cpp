/*
	--- Question Statement ---

Given an array of names of candidates in an election. A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes. If there is tie, print lexicographically smaller name.

Input:
The first line of the input contains a single integer T, denoting the number of test cases. Then T test case follows. Each testcase contains two lines:-
The number of votes cast N
The name of the candidates separated by a space. Each name represents one vote casted to that candidate.

Output:
For each testcase, print the name of the candidate with the maximum votes, and also print the votes casted for the candidate. The name and votes are separated by a space.

Constraints:
1<=T<=105
1<=N<=1000

Example:

Input:
2
13
john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john
3
andy blake clark

Output:
john 4
andy 1

*/

#include<iostream>
#include<map>
#include<climits>

using namespace std;

void winner(map<string, int> hash)
{
    map<string, int>::iterator i = hash.begin();
    
    int maxim = INT_MIN;
    string result = "";
    for(;i!=hash.end();i++)
    {
        if(i->second > maxim)
        {
            maxim = i->second;
            result = i->first;
        }
        else if(i->second == maxim)
        {
            if(i->first < result)
                result = i->first;
        }
    }
    
    cout << result << " " << maxim << endl;
        
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
        map<string, int> hash;
        
        for(int i=0;i<n;i++)
        {
            cin >> str;
            hash[str] += 1;
        }
        
        winner(hash);
    }
    
	return 0;
}