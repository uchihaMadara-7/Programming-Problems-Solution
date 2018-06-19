#include <iostream>
#include <algorithm>

using namespace std;

class polynomial
{
	pair<int,int> *equation;
	int terms;

	polynomial add_sub(polynomial eq, bool flag);
	public:

	polynomial(int size);

	void input();

	void operator=(polynomial eq);
	polynomial operator+(polynomial eq);
	polynomial operator-(polynomial eq);
	void operator+=(polynomial eq);
	void operator-=(polynomial eq);
	polynomial operator*(polynomial eq);

	void show();
};

void polynomial::show()
{
	for(int i=0;i<terms;i++)
		cout << equation[i].first << "^" << equation[i].second << " ";
	cout << endl;
}

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.second < b.second;
}

void polynomial::input()
{
	for(int i=0;i<terms;i++)
		cin >> equation[i].first >> equation[i].second;
	sort(equation, equation+terms, compare);
}

polynomial polynomial::add_sub(polynomial eq, bool flag)
{
	polynomial result(terms+eq.terms);
	int index = 0;
	int i = 0, j = 0;

	while(i < terms && j < eq.terms)
	{
		if(equation[i].second == eq.equation[j].second)
		{
			if(flag)
				result.equation[index].first = equation[i].first + eq.equation[j].first;
			else
				result.equation[index].first = equation[i].first - eq.equation[j].first;

			result.equation[index].second = equation[i].second;
			index ++;
			i++;
			j++;
		}
		else if(equation[i].second < eq.equation[j].second)
		{
			result.equation[index].first = equation[i].first;
			result.equation[index].second = equation[i].second;
			index++;
			i++;
		}
		else
		{
			if(flag)
				result.equation[index].first = eq.equation[j].first;
			else
				result.equation[index].first = 0-eq.equation[j].first;

			result.equation[index].second = eq.equation[j].second;
			index++;
			j++;
		}
	}

	while(i < terms)
	{
		result.equation[index].first = equation[i].first;
		result.equation[index].second = equation[i].second;
		index++;
		i++;
	}

	while(j < eq.terms)
	{
		if(flag)
			result.equation[index].first = eq.equation[j].first;
		else
			result.equation[index].first = 0-eq.equation[j].first;

		result.equation[index].second = eq.equation[j].second;
		index++;
		j++;
	}

	result.terms = index;
	return result;
}

void polynomial::operator=(polynomial eq)
{
	pair<int,int> *temp = equation;
	free(temp);
	terms = eq.terms;
	equation = new pair<int,int>[terms];

	for(int i=0;i<terms;i++)
	{
		equation[i].first = eq.equation[i].first;
		equation[i].second = eq.equation[i].second;
	}
}

void polynomial::operator+=(polynomial eq)
{
	*this = add_sub(eq, true);
}

void polynomial::operator-=(polynomial eq)
{
	*this = add_sub(eq, false);
}

polynomial polynomial::operator-(polynomial eq)
{
	return add_sub(eq, false);
}

polynomial polynomial::operator+(polynomial eq)
{
	return add_sub(eq, true);
}

polynomial polynomial::operator*(polynomial eq)
{
	
}

polynomial::polynomial(int size)
{
	terms = size;
	equation = new pair<int,int>[terms];
}

/*
37 9
23 11
17 5
1 9
13 3
26 5
25 0
*/

int main()
{
	polynomial eq1(3);
	eq1.input();

	polynomial eq2(4);
	eq2.input();

    eq1 = eq2;
    eq1.show();
    return 0;
}
