/*
	--- Question Statement ---

Find the first non-repeating element in a given array of integers.

Note: Array consists of only positive and negative integers and not zero.

Input:

The first line of input is an integer T, denoting the number of test cases. Each test case has 
subsequent two lines of input. First line is an integer N, denoting size of integer array A. Second 
line consists of N space separated integers of the array A.

Output:

The only line of output for each test case is the first non-repeating element in the array A. 
If there is no such element, print 0 as the output.

Constraints:

1<=T<=100;
1<=N<=100;
A[i] belongs to [-100,100]-{0}, where i is an integer denoting index of array.

Example:

Input:

4
5
-1 2 -1 3 2
6
9 4 9 6 7 4
3
1 1 1
2
-3 2


Output:

3
6
0
-3

*/

#include<iostream>
#define SIZE 201
using namespace std;

int first_non_repeating(int *array, int n)
{
    int hash[SIZE] = {0};
    
    for(int i=0;i<n;i++)
        hash[array[i]+100] ++;
        
    for(int i=0;i<n;i++)
    {
        if(hash[array[i]+100] == 1)
            return array[i];
    }
    
    return 0;
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
            
        cout << first_non_repeating(array, n) << endl;
    }
    
	return 0;
}