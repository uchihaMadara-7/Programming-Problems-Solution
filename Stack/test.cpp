#include <iostream>
#include <stack>

using namespace std;

void callfunction(stack<int> stk)
{
	while(!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
}

int main()
{
	stack<int> stk;
	stk.push(1);
	stk.push(2);
	stk.push(3);
	callfunction(stk);

	while(!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
}
