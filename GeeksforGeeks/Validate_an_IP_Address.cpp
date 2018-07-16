/*
	--- Question Statement ---

Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses are canonically 
represented in dot-decimal notation, which consists of four decimal numbers, each ranging 
from 0 to 255, separated by dots, e.g., 172.16.254.1 . The generalized form of an IPv4 address is 
(0-255).(0-255).(0-255).(0-255)

Your task is  to complete the function isValid which returns 1 if the ip address is valid else 
returns 0. The function takes a string ip as its only argument .

Input:
The first line of each test case contains an integer T denoting the number of test case . 
Then T test cases follow . Each test case takes a string ip.

Output:
For each test case output will be 1 if the string is a valid ip address else 0.

Constraints:
1<=T<=100
1<=length of string <=50

Example(To be used only for expected output) :
Input
4
222.111.111.111
5555..555
0000.0000.0000.0000
1.2.3.04

Output
1
0
0
0

*/

bool onlyvalid(char *ip, int n)
{
    for(int i=0;i<n;i++)
        if((ip[i]<'0' || ip[i]>'9') && ip[i] != '.')
            return false;
            
    return true;
}

bool validate(char *ip, int first, int last)
{
    if(ip[first] == '0' && last-first+1 > 1)
        return false;
        
    if(last-first+1 > 3 || last-first+1 <= 0)
        return false;
        
    int sum = 0;
    for(int i=first;i<=last;i++)
        sum = sum * 10 + (ip[i]-'0');
        
    if(sum > 255)
        return false;
        
    return true;
}

int isValid(char *ip)
{
    
    if(ip[0] == '.')
        return 0;
    
    int size = strlen(ip);
    
    if(!onlyvalid(ip, size))
        return 0;
    
    int first = 0, sum = 0, dots = 0;
    
    for(int i=0;i<size;i++)
    {
        if(ip[i] == '.')
        {
            dots ++;
            
            if(!validate(ip, first, i-1))
                return 0;
            first = i+1;
        }
    }
    
    if(!validate(ip, first, size-1))
        return 0;
    
    if(dots != 3)
        return 0;
        
    return 1;
}

int main()
{
	char ip[50];
	cin >> ip;

	cout << isValid(ip) << endl;
	return 0;
}