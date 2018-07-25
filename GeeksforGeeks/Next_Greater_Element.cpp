/*
    --- Question Statement ---

Given an array A [ ] having distinct elements, the task is to find the next greater element for each 
element of the array in order of their appearance in the array. If no such element exists, output -1 

Input:
The first line of input contains a single integer T denoting the number of test cases.Then T test 
cases follow. Each test case consists of two lines. The first line contains an integer N denoting the 
size of the array. The Second line of each test case contains N space separated positive integers 
denoting the values/elements in the array A[ ].
 
Output:
For each test case, print in a new line, the next greater element for each array element separated 
by space in order.

Constraints:
1<=T<=200
1<=N<=1000
1<=A[i]<=1000

Example:
Input
1
4
1 3 2 4 

Output
3 4 4 -1

Explanation
In the array, the next larger element to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? since it doesn't exist 
hence -1.

*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void NextGreater(int *array, int n)
{
    stack<int> greater;
    vector<int> ans(n);
    greater.push(0);
    
    for(int i=1;i<n;i++)
    {
        while(!greater.empty() && array[i] > array[greater.top()])
        {
            ans[greater.top()] = array[i];
            greater.pop();
        }
        
        greater.push(i);
    }
    
    for(int i=0;i<n;i++)
    {
        if(ans[i] == 0)
            cout << -1 << " ";
        else
            cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        int *array = new int[n];
        for(int i=0;i<n;i++)
            cin >> array[i];
            
        NextGreater(array, n);
    }
    
	return 0;
}