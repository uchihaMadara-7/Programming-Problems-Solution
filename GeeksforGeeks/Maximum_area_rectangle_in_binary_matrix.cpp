/*
    --- Question Statement ---

Given a binary matrix, Your task is to complete the function maxArea which the maximum size 
rectangle area in a binary-sub-matrix with all 1’s. The function takes 3 arguments the first 
argument is the Matrix M[ ] [ ] and the next two are two  integers n and m which denotes the size 
of the matrix M. Your function should return an integer denoting the area of the maximum rectangle .

Input:
The first line of input is an integer T denoting the no of test cases . Then T test cases follow. 
The first line of each test case are 2 integers n and m denoting the size of the matrix M . 
Then in the next line are n*m space separated values of the matrix M.

Output:
For each test case output will be the area of the maximum rectangle .

Constraints:
1<=T<=50
1<=n,m<=50
0<=M[][]<=1

Example:
Input
1
4 4 
0 1 1 0 1 1 1 1 1 1 1 1 1 1 0 0

Output
8

Explanation
For the above test case the matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8

*/


#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX],int n,int m);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<maxArea(M,n,m)<<endl;
    }
}

int maxHistogram(int mat[MAX][MAX], int n, int index)
{
    stack<int> histogram;
    int area, i=0;
    int maxim = 0;
    
    while(i < n)
    {
        if(histogram.empty() || mat[index][i] >= mat[index][histogram.top()])
        {
            histogram.push(i);
            i ++;
        }
            
        else
        {
            int top = histogram.top();
            histogram.pop();
            
            if(histogram.empty())
                area = mat[index][top] * i;
            else
                area = mat[index][top] * (i-histogram.top()-1);
                
            maxim = max(maxim, area);
        }
    }
    
    while(!histogram.empty())
    {
        int top = histogram.top();
        histogram.pop();
        
        if(histogram.empty())
            area = mat[index][top] * i;
        else
            area = mat[index][top] * (i-histogram.top()-1);
            
        maxim = max(area, maxim);
    }
    
    return  maxim;
}

int maxArea(int mat[MAX][MAX],int n,int m)
{
    int maxim = 0;
    
    maxim = maxHistogram(mat, m, 0);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j])
                mat[i][j] = mat[i-1][j] + 1;
        }
        
        int area = maxHistogram(mat, m, i);
        maxim = max(area, maxim);
    }
    
    return maxim;
}
