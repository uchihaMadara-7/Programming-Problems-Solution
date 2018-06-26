/*
	--- Question Statement ---

	Write a function to print all the 3 letter code of a phone dialpad. Each key must
	be pressed only once. One of such combination is "adg" when 1,2 and 3 is pressed.
*/

#include <iostream>
#include <vector>

using namespace std;

string str[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<char> three;
bool visited[8] = {false};

int count = 0;

void print()
{
	for(int i=0;i<three.size();i++)
		cout << three[i];
	cout << endl;
}

void letterCode()
{
	if(three.size() == 3)
	{
		count ++;
		print();
		return;
	}

	for(int i=0;i<8;i++)
	{
		if(!visited[i])
		{
			for(int j=0;str[i][j];j++)
			{
				visited[i] = true;
				three.push_back(str[i][j]);
				letterCode();
				visited[i] = false;
				three.pop_back();
			}
		}
	}
}

int main()
{
    letterCode();
    cout << count << endl;
	return 0;
}
