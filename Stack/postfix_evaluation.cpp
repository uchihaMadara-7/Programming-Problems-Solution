#include <iostream>
#include <stack>

using namespace std;

bool isOperator(char c)
{
	switch(c)
	{
		case '+' :
		case '-' :
		case '*' :
		case '/' :	return true;
	}
	return false;
}

int postfixEvaluation(string expression)
{
	stack<char> evalStack;

	int result;
	int size = expression.size();
	for(int i=0;i<size;i++)
	{
		if(!isOperator(expression[i]))
		{
			evalStack.push(expression[i]);
			//cout << "Push: " << evalStack.top() << endl;
		}
		else
		{
			int operand2 = evalStack.top() - '0';
			evalStack.pop();
			int operand1 = evalStack.top() - '0';
			evalStack.pop();

			//cout << operand1 << expression[i] << operand2 << endl;

			switch(expression[i])
			{
				case '+' : result = operand1 + operand2;
					   break;
				case '-' : result = operand1 - operand2;
					   break;
				case '*' : result = operand1 * operand2;
					   break;
				case '/' : result = operand1 / operand2;
			}

			evalStack.push(result+'0');
		}
	}

	return evalStack.top() - '0';
}

int main()
{
	string expression;
	cin >> expression;

	cout << "Result after evaluation: " << postfixEvaluation(expression) << endl;

}
