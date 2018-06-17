#include <iostream>
#include <stack>

using namespace std;

bool balanceParenthesis(string expression)
{
	stack<char> parenthesis;

	int size = expression.size();
	for(int i=0;i<size;i++)
	{
		if(expression[i] == '(')
		{
			parenthesis.push('(');
		}
		else
		{
			if(parenthesis.empty())
				return false;
			parenthesis.pop();
		}
	}

	return parenthesis.empty();
}

int main()
{
	string expression;
	cin >> expression;

	if(balanceParenthesis(expression))
		cout << "Balanced!!"<<endl;
	else
		cout << "Not Balanced!!"<<endl;
}
