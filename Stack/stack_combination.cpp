#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> combi;
bool marked[10] = {false};

void printStack(stack<int> stk)
{
	while(!stk.empty())
	{
		cout << stk.top() << " ";
		stk.pop();
	}
}

void printVector(vector<int> combina)
{
	for(int i=0;i<combina.size();i++)
		cout << combina[i] << " ";
}

void combination(int n, int limit,stack<int> &stk)
{
	//cout << n <<" "<< combi.size() << " stk " << stk.size() << endl;
	if(n > limit+1)
	{
		return;
	}

	//cout << "combi: " << combi.size() << " stk: " << stk.size() << endl;
	//cout << combi.size() + stk.size() << endl;
	if(combi.size() + stk.size() == limit)
	{
		printVector(combi);
		printStack(stk);
		cout << endl;
		return;
	}

	/*if(combi.size() == limit)
	{
		printVector(combi);
		return;
	}

	if(stk.size() == limit)
	{
		printStack(stk);
		return ;
	}*/

	stk.push(n);
	combination(n+1, limit, stk);
	stk.pop();

	if(!stk.empty())
	{
		combi.push_back(stk.top());
		stk.pop();
		combination(n, limit, stk);
		stk.push(combi.back());
		combi.pop_back();
	}
}

int main()
{
	int n;
	cin >> n;

	stack<int> stk;
	combination(1, n, stk);
	return 0;
}
