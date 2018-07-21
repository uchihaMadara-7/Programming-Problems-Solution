/*
	--- Question Statement ---
*/

#include<iostream>
#include<stack>

using namespace std;

void insert(stack<int> &s, int element)
{
	if(s.empty() || s.top() < element)
	{
		s.push(element);
		return;
	}

	int copy = s.top();
	s.pop();

	insert(s, element);
	s.push(copy);
}

void sort_stack(stack<int> &s)
{
	if(s.empty())
		return;

	int copy = s.top();
	s.pop();

	sort_stack(s);
	insert(s, copy);
}

void print(stack<int> s)
{
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		stack<int> s;
		int size;

		cin >> size;

		for(int i=0;i<size;i++)
		{
			int a;
			cin >> a;

			s.push(a);
		}

		sort_stack(s);
		print(s);

	}

	return 0;
}