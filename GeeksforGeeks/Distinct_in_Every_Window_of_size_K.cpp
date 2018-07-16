/*
    --- Question Statment ---

Given an array A[] of size n and an integer k, your task is to complete 
the function countDistinct which prints the count of distinct numbers in 
all windows of size k in the array A[].

Input:  A[] = {1, 2, 1, 3, 4, 2, 3};
            k = 4
Output:
3 4 4 3
Explanation:
First window is {1, 2, 1, 3}, count of distinct numbers is 3
Second window is {2, 1, 3, 4} count of distinct numbers is 4
Third window is {1, 3, 4, 2} count of distinct numbers is 4
Fourth window is {3, 4, 2, 3} count of distinct numbers is 3

Constraints:
1<=T<=100
1<=n,k<=100
1<=A[]<=100

*/

#include<iostream>

using namespace std;

void countDistinct(int *array, int k, int n)
{
    int hash[101] = {0};

    int distinct = 0;
    for(int i=0;i<k;i++)
    {
        if(hash[array[i]] == 0)
        {
            distinct ++;
        }
        
        hash[array[i]] ++;
    }
    cout << distinct << " ";
    
    for(int i=1;i<=n-k;i++)
    {
        hash[array[i-1]] --;
        if(hash[array[i-1]] == 0)
            distinct --;
        
        hash[array[i+k-1]] ++;
        if(hash[array[i+k-1]] == 1)
            distinct ++;
            
        cout << distinct << " ";
    }
}

int main()
{
    int n, k;
    cin >> n >> k;

    int *array = new int[n];
    for(int i=0;i<n;i++)
        cin >> array[i];

    countDistinct(array, k, n);
}