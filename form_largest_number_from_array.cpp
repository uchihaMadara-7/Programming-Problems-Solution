#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool compare(int a, int b)
{
	int first = stoi(to_string(a) + to_string(b));
	int second = stoi(to_string(b) + to_string(a));

	if(first > second)
		return true;
    return false;
}

int main()
{
	int n;
	cin >> n;

	int *array = new int[n];
	for(int i=0;i<n;i++)
		cin >> array[i];

	string result = "";

	sort(array, array + n, compare);

	// SELECTION SORT
	/*for(int i=0;i<n;i++)
	{
		int max = i;
		for(int j=i+1;j<n;j++)
		{
			int first = stoi(to_string(array[j]) + to_string(array[max]));
			int second = stoi(to_string(array[max]) + to_string(array[j]));

			if(first > second)
			{
				max = j;
			}
		}

		int temp = array[i];
		array[i] = array[max];
		array[max] = temp;
	}*/

	for(int i=0;i<n;i++)
		result += to_string(array[i]);

	cout << result << endl;
	return 0;
}
