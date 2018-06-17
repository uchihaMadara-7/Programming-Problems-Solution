#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int *permutation = new int[n];

	for(int i=0;i<n;i++)
		cin >> permutation[i];

	stack<int> stk;

	int j = 0;
	for(int i=1;i<=n;i++)
	{
		if(permutation[j] != i)
		{
			stk.push(i);
		}
		else
		{
			j++;
			while(!stk.empty() && stk.top() == permutation[j])
			{
				stk.pop();
				j++;
			}
		}
	}

	if(stk.empty())
		cout << "Permutation possible" << endl;
	else
		cout << "Permutation not possible" << endl;

	return 0;
}
