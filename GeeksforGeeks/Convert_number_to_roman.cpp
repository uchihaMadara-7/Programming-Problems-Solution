/*
	--- Question Statement ---

Given an integer n your task is to complete the function convertToRoman which prints 
the corresponding roman number of n .

Input:
The first line of each test case contains the no of test cases T. Then T test cases 
follow. Each test case contains a single integer n.

Output:
For each test case in a new line output will be the roman number representation of n. 

Constraints:
1<=T<=100
1<=n<4000

Example:
Input
2
5
3
Output
V
III 

*/

#include<iostream>
using namespace std;

string romanReturn(int a)
{
    switch(a)
    {
        case 1   : return "I";
        case 4   : return "IV";
		case 5   : return "V";
		case 9   : return "IX";
		case 10  : return "X";
		case 40  : return "XL";
		case 50  : return "L";
		case 90  : return "XC";
		case 100 : return "C";
		case 400 : return "CD";
		case 500 : return "D";
		case 900 : return "CM";
        case 1000: return "M";
    }
}

void convertToRoman(int n) 
{
    int roman[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    int index = 0;
    
    while(n > 0)
    {
        if(n >= roman[index])
        {
            int q = n/roman[index];
            
            for(int i=0;i<q;i++)
                cout << romanReturn(roman[index]);
                
            n = n % roman[index];
        }
        
        index ++;
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

		cout << convertToRoman(n) << endl;
	}

	return 0;
}