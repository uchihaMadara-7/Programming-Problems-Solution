#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int three_n_plus_1(int n, int count, vector<int> &counts, int low, int high, int origin)
{
	cout << n << "..";

	if(n >= low && n <= high)
	{
		if(counts[n-low] > 0)
		{
			cout << " know this ";
			return count + counts[n-low];
		}

		if(n != origin)
		{
			counts[n-low] = -1;
			cout << "(might need: "<< n << ")";
		}
	}

	if(n == 1)
		return count;
	if(n % 2 == 0)
		return three_n_plus_1(n/2, count + 1, counts, low, high, origin);
	return three_n_plus_1(3*n+1, count + 1, counts, low, high, origin);
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> counts(m-n+1);

	int max_no, max_steps = INT_MIN;
	for(int i=n;i<=m;i++)
	{
		if(counts[i-n] != -1)
		{
			counts[i-n] = three_n_plus_1(i, 0, counts, n, m, i);
			cout << endl;
			if(counts[i-n] > max_steps)
			{
				max_no = i;
				max_steps = counts[i-n];
			}
			//cout << i <<" "<< three_n_plus_1(i, 0, counts, n, m) << endl;
		}
	}

	for(int i=n;i<=m;i++)
	{
		cout << i << " -> " << counts[i-n] << endl;
	}

	cout << max_no << " " << max_steps << endl;
	return 0;
}
