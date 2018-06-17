#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int three_n_plus_1(int n, int count)
{
        if(n == 1)
                return count;
        if(n % 2 == 0)
                return three_n_plus_1(n/2, count + 1);
        return three_n_plus_1(3*n+1, count + 1);
}

int main()
{
	int n;
	cin >> n;
	cout << three_n_plus_1(n, 0);
	return 0;
}
