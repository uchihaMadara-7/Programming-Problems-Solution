/*
	--- Question Statement ---

	Given a string and poistive integer d. Some characters may be repeated in
	the string. Rearrange characters such tha same characters are d distance
	away from each other. Example : abb d=2 output: bab

*/

#include <iostream>
#include <utility>
#include <algorithm>
#include <string.h>

using namespace std;

bool sort_compare(pair<int,int> a, pair<int,int> b)
{
		return a.second > b.second;
}

string reArrange(string str, int d)
{
	pair<int,int> hash[26];

	for(int i=0;str[i];i++)
	{
		hash[str[i]-'a'].second ++;
		hash[str[i]-'a'].first = str[i] - 'a';
	}

	sort(hash, hash+26, sort_compare);

	int size = str.size();
	char *newstr = new char[size];
	for(int i=0;i<size;i++)
        newstr[i] = '0';

    int index = 0, lastempty = 0;
    for(int i=0;i<26;i++)
    {
    	if(hash[i].second > 1)
    	{
    		index = lastempty;
    		while(hash[i].second--)
    		{
    			if(index >= size)
    				return "-1";

    			newstr[index] = hash[i].first + 'a';
    			index += d;
    		}

    		lastempty ++;
    		while(newstr[lastempty] != '0')
    			lastempty ++;
    	}
    }

    for(int i=0;i<26;i++)
    {
    	if(hash[i].second == 1)
    	{
            newstr[lastempty] = hash[i].first + 'a';
            while(newstr[lastempty] != '0')
                lastempty ++;
    	}
    }

    string result = "";
    for(int i=0;i<size;i++)
        result += newstr[i];

	return result;
}

int main()
{
	string str;
	cin >> str;

	int d;
	cin >> d;

    cout << reArrange(str, d) << endl;
    return 0;
}
