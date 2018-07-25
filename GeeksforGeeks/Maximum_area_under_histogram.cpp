/*
	--- Question Statement ---

Find the largest rectangular area possible in a given histogram where the largest rectangle can be 
made of a number of contiguous bars. For simplicity, assume that all bars have same width and the 
width is 1 unit.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, 
the first line contains an integer 'N' denoting the size of array. The second line contains N 
space-separated integers A1, A2, ..., AN denoting the elements of the array. The elements of the 
array represents the height of the bars.

Output:
In each seperate line the maximum rectangular area possible from the contigous bars.

Constraints:
1<=T<=30
1<=N<=100
1<=A[i]<=1000

Example:
Input: 
1
7
6 2 5 4 5 1 6

Output:
12

*/

#include<iostream>
#include<stack>
using namespace std;

int maxArea(int *array, int n)
{
    stack<int> histogram;
    int maxim = 0;
    
    int i = 0, area;
    
    while(i<n)
    {
        if(histogram.empty() || array[i] >= array[histogram.top()])
        {
            histogram.push(i);
            i ++;
        }
            
        else
        {
            int top = histogram.top();
            histogram.pop();
            
            if(histogram.empty())
                area = array[top] * i;
            else
                area = array[top] * (i-histogram.top()-1);
                
            maxim = max(area, maxim);
        }
    }
    
    while(!histogram.empty())
    {
        int top = histogram.top();
        histogram.pop();
        
        if(histogram.empty())
            area = array[top] * i;
        else
            area = array[top] * (i-histogram.top()-1);
            
        maxim = max(maxim, area);
    }
    
    return maxim;
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
            
        cout << maxArea(array, n) << endl;
    }
    
	return 0;
}