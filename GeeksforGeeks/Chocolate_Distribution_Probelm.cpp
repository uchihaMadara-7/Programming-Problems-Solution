/*
	--- Question Statment ---

Given an array A[] of N integers where each value represents number of 
chocolates in a packet. Each packet can have variable number of chocolates. 
There are m students, the task is to distribute chocolate packets 
such that :

	1. Each student gets one packet.
	2. The difference between the number of chocolates given to the 
	   students in packet with maximum chocolates and packet with minimum 
	   chocolates is minimum.

Examples

Input : A[] = {3, 4, 1, 9, 56, 7, 9, 12} 
        m = 5
Output: Minimum Difference is 6
We may pick 3,4,7,9,9 and the output 
is 9-3 = 6

Input : A[] = {7, 3, 2, 4, 9, 12, 56} 
        m = 3
Output: Minimum difference is 2
We can pick 2, 3 and 4 and get the minimum
difference between maximum and minimum packet
sizes. ie 4-2 = 2

*/

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int Chocolate(int *array, int n, int m)
{
    sort(array, array+n);
    
    int minim = INT_MAX;
    
    for(int i=0;i<=n-m;i++)
    {
        if(array[i+m-1]-array[i] < minim)
            minim = array[i+m-1] - array[i];
    }
    
    return minim;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, m;
        cin >> n;
        int *array = new int[n];
        
        for(int i=0;i<n;i++)
            cin >> array[i];
            
        cin >> m;
        
        cout << Chocolate(array, n, m) << endl;
    }
    
	return 0;
}