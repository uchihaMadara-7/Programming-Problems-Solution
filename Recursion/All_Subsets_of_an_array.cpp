/*
    --- Question Statement ---
    
    Given a set of distinct integers, nums, return all possible subsets (the power set).The solution set must 
    not contain duplicate subsets.
    
    Example : [1, 2, 3]
    output:   [3],
              [1],
              [2],
              [1,2,3],
              [1,3],
              [2,3],
              [1,2],
              []
*/

#include <iostream>
#include <vector>

using namespace std;

void all(string str, int n, vector<vector<int>> &subset, vector<int> nums)
{
    if(n == -1)
    {
        int size = str.size();
        vector<int> result;
        for(int i=0;i<size;i++)
        {
            if(str[i] == '1')
                result.push_back(nums[i]);
        }
        
        subset.push_back(result);
        return;
    }
    
    str.push_back('0');
    all(str, n-1, subset, nums);
    str.pop_back();
    
    str.push_back('1');
    all(str, n-1, subset, nums);
    str.pop_back();    
    
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> subset;
    string str;
    all(str, nums.size()-1, subset, nums);
    
    return subset;
}

int main()
{
	int n, a;
	cin >> n;

	vector<int> array;
	for(int i=0;i<n;i++)
	{
		cin >> a;
		array.push_back(a);
	}

	vector<vector<int>> result = subsets(array);

	int size = result.size();
	for(int i=0;i<size;i++)
	{
    cout << "[ ";
		for(int j=0;j<result[i].size();j++)
			cout << result[i][j] <<" ";
		cout << " ]" << endl;
	}

	return 0;
}
