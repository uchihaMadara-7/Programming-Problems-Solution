#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<char> perm)
{
	while(!perm.empty())
	{
		cout << perm.top();
		perm.pop();
	}
	cout << endl;
}

void permutation(string str, stack<char> perm, int n)
{
	static bool *visited = new bool[n];

	if(perm.size() == n)
	{
		printStack(perm);
		return;
	}

	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			visited[i] = true;
			perm.push(str[i]);
			permutation(str, perm, n);
			perm.pop();
			visited[i] = false;
		}
	}
}

int main()
{
	string str;
	cin >> str;

	stack<char> perm;
	permutation(str, perm, str.size());
	return 0;
}
0