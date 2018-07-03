/*
	Given an array of size n, print all the subsets of matrix (a subset is unique i.e
	{1 2 3} is same as {2 1 3}).
	
	Example: n = 8
			 array = [ 3 8 7 6 4 3 2 1 ]
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> unique_element(int *array, int n)
{
	map<int,int> hash;
	vector<int> unique;

	for(int i=0;i<n;i++)
	{
		if(hash.find(array[i]) != hash.end())
			continue;
		hash[array[i]] = 1;
		unique.push_back(array[i]);
	}

	return unique;
}

void print(vector<int> subset, int n)
{
	for(int i=0;i<n;i++)
		cout << subset[i] <<" ";
	cout << endl;
}

void all_subset(vector<int> unique, int i, int n, int k)
{
	static vector<int> subset;

	if(subset.size() == k)
	{
		print(subset, subset.size());
		return;
	}

	for(;i<n;i++)
	{
		subset.push_back(unique[i]);
		all_subset(unique, i+1, n, k);
		subset.pop_back();
	}
}

void all_subset_main(int *array, int n, int k)
{
	vector<int> unique = unique_element(array, n);
	int size = unique.size();

	//print(unique, size);
	all_subset(unique, 0, size, k);
}

int main()
{
	int n;
	cin >> n;

    int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	int k;
	cin >> k;

	all_subset_main(array, n, k);
	return 0;
}
