/*
	--- Question Statement ---

A n digit number has n*(n+1)/2 sub-numbers.  For example, all possible sub-numbers of 975 
are 9 7 5 97 75 975. A number is called Lucky if all sub-numbers have different digit product.  
Digit product of a number is product of its digits.  

For example, the number 23 is Lucky.  Subsequences of it are 2, 3 and 23 and digit products are 
2, 3 and 6 respectively (All digit products are different). 975 is also lucky.

Input:

The first line contains an integer T, depicting total number of test cases. 
Then following T lines contains an integer N .
Output:

Print 1 if number is lucky else print 0.

Constraints:

1<=T<=100

1<=N<=1010
Example:

Input:

2
324
323

Output:

1
0

*/

#include<iostream>
#include<map>
using namespace std;

int product_substring(string str, int low, int high)
{
    int pro = 1;
    
    while(low <= high)
    {
        pro *= (str[low]-'0');
        low ++;
    }
    
    return pro;
}

bool lucky_number(string str)
{
    map<int, int> hash;
    
    int size = str.size();
    for(int i=0;i<size;i++)
    {
        for(int j=i;j<size;j++)
        {
            int product = product_substring(str, i, j);
            hash[product] += 1;
        }
    }
    
    for(map<int,int>::iterator i = hash.begin();i!=hash.end();i++)
        if(i->second > 1)
            return false;
            
    return true;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        string str;
        cin >> str;
        
        cout << lucky_number(str) << endl;
    }
    
	return 0;
}