#include <iostream>
#include <cmath>

using namespace std;

void pari_sum_k(int *array, int n, int key)
{
	int i = 0, j = n-1;
	while(i < j)
	{
		if(array[i] + array[j] == key)
		{
			cout << "Indexes are: " << i << " " << j << endl;
			return;
		}
		if(array[i] + array[j] < key)
			i++;
		else
			j--;
	}
	cout << "Nothing found!! " << endl;
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];

	for(int i=0;i<n;i++)
		cin >> array[i];

	int key;
 	cin >> key;

	pari_sum_k(array, n, key);
	return 0;
}
