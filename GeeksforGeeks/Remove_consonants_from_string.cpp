/*
	--- Question Statement ---

Given a string s, remove all consonants and prints the string s that contains vowels only.

Input: The first line of input contains integer T denoting the number of test cases. 
For each test case, we input a string.

Output: For each test case, we get a string containing only vowels. If the string doesn't contain 
any vowels, then print "No Vowel"

Constraints:

1<=T<=100
The string should consist of only alphabets.

EXamples:

Input: geEks
Output: eE

Input: what are you doing
Output: a ae ou oi

*/

#include<iostream>
using namespace std;

bool isVowels(char c)
{
    switch(c)
    {
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case ' ':
        case 'u': return true;
    }
    
    return false;
}

string removeConso(string str)
{
    string ans = "";
    
    for(int i=0;str[i];i++)
    {
        if(isVowels(str[i]))
            ans += str[i];    
    }
    
    if(ans == "")
        return "No Vowel";
    return ans;
}

int main()
{
    int t;
    cin >> t;
    
    string str;
    getline(cin, str);
    
    while(t--)
    {
        getline(cin, str);
        cout << removeConso(str) << endl;
    }
    
	return 0;
}