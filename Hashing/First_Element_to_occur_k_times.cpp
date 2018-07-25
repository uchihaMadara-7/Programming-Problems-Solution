/*
	--- Question Statement ---

Given an array of n integers. The task is to find the first element that occurs k number 
of times. If no element occurs k times the print -1. The distribution of integer elements 
could be in any range.

Input:
The first line of input contains an integer T denoting the number of test cases. Then 
T test cases follow. The first line of each test case contains an integer N denoting 
the size of an array and the number K. The second line of each test case contains N 
space separated integers denoting elements of the array A[ ].

Output:
For each test case in a new line print the required answer.


Constraints:
1<= T <=100
1<= N,K <=100000
1<= A<=1000000


Example:

Input :
1
7 2
1 7 4 3 4 8 7

Output :
7

Explanation:
Both 7 and 4 occur 2 times. But 7 is the first that occurs 2 times.

*/

#include<iostream>
#include<map>
using namespace std;

void firstElement(int *array, int n, int k)
{
    map<int,pair<int,int>> hash;
    
    for(int i=0;i<n;i++)
    {
        if(hash.find(array[i]) == hash.end())
        {
            hash[array[i]].second = i;
        }
        
        hash[array[i]].first ++;
    }
    
    int index = n;
    for(map<int,pair<int,int>>::iterator i=hash.begin();i!=hash.end();i++)
    {
        if((i->second).first == k && index > (i->second).second)
        {
            index = (i->second).second;
        }
    }
    
    if(index == n)
        cout << "-1" << endl;
    else
        cout << array[index] << endl;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        
        int *array = new int[n];
        for(int i=0;i<n;i++)
            cin >> array[i];
            
        firstElement(array, n, k);    
    }
    
	return 0;
}