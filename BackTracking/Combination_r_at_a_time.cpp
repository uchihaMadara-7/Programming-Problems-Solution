#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> array)
{
	int size = array.size();

	for(int i=0;i<size;i++)
		cout << array[i] << " ";
	cout << endl;
}

void combination(vector<int> array, int n, int size, int r)
{
	static vector<int> combi;

	if(combi.size() == r)
	{
		print(combi);
		return;
	}

	for(;n<size;n++)
	{
		combi.push_back(array[n]);
		combination(array, n+1, size, r);
		combi.pop_back();
	}
}

int main()
{
	int n, r;
	cin >> n >> r;
	vector<int> array(n);

	for(int i=0;i<n;i++)
		cin >> array[i];

	combination(array, 0, n, r);
	return 0;
}