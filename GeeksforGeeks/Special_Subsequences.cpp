/*
    --- Question Statement --- 

Given a string S, print all ‘Special Subsequences’ of S. A special 
subsequence is a subsequence of given string with capital letters allowed.   
A Subsequence is a sequence that can be derived from given string by 
removing zero or more elements, without changing the order of the remaining 
elements. For example subsequences of abc are {a, b, c, ab, ac, bc, abc}. 
To generate Special Subsequences, we need to consider both the upper and 
lowercases and their combination. For Instance, “ab” has the following 
Special-Subsequences-: { “A”, “AB”, “Ab”, “B”, “a”, “aB”, “ab”, “b” }.

NOTE : Consider only the non-empty Special Subsequences of S, as shown above.

input: ab
output: 8
        A AB Ab B a aB ab b

input: abc
output: 26
        A AB ABC ABc AC Ab AbC Abc Ac B BC Bc C a aB aBC aBc aC ab abC 
        abc ac b bC bc c 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void generate(string str, int size, int current, vector<string> &result, bool flag, vector<bool> &binary);

void store(string str, int size, vector<string> &result, vector<bool> binary, bool flag)
{
    string temp = "";
    for(int i=0;i<size && flag;i++)
    {
        if(binary[i] && flag)
        {
            temp += str[i];
        }
    }
    
    for(int i=0;i<size && !flag;i++)
    {
        if(binary[i])
            temp += char(str[i]-'a'+'A');
        else
            temp += str[i];
    }
    
    if(temp != "" && flag)
    {
        //result.push_back(temp);
        vector<bool> binarys;
        generate(temp, temp.size(), 0, result, false, binarys);
    }
    else if(temp != "")
        result.push_back(temp);
}

void generate(string str, int size, int current, vector<string> &result, bool flag, vector<bool> &binary)
{
    if(current == size)
    {
        store(str, size, result, binary, flag);
        return;
    }
    
    binary.push_back(false);
    generate(str, size, current+1, result, flag, binary);
    binary.pop_back();
    
    binary.push_back(true);
    generate(str, size, current+1, result, flag, binary);
    binary.pop_back();
    
}

int main()
{
    int t;
    cin >> t;
    
    string str;
    while(t--)
    {
        cin >> str;
        int size = str.size();
        
        vector<string> result;
        vector<bool> binary;
        
        generate(str, size, 0, result, true, binary);
        
        size = result.size();
        cout << size << endl;
        
        sort(result.begin(), result.end());
        for(int i=0;i<size;i++)
            cout << result[i] << " ";
        cout << endl;
        
    }
    
	return 0;
}

//AC Ab AbC Abc A AB ABC ABc C bc c a aB aBC Ac B BC Bc abc ac b bC aBc aC ab abC