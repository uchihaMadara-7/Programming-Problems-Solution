/*
    --- Question Statement ---

Given a non-empty array of non-negative integers nums, the degree of this array is 
defined as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length of a (contiguous) subarray of nums, 
that has the same degree as nums.

Example 1:

Input: [1, 2, 2, 3, 1]
Output: 2
Explanation: 
The input array has a degree of 2 because both elements 1 and 2 appear twice.
Of the subarrays that have the same degree:
[1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
The shortest length is 2. So return 2.

Example 2:

Input: [1,2,2,3,1,4,2]
Output: 6

Note:
nums.length will be between 1 and 50,000.
nums[i] will be an integer between 0 and 49,999.

*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

int subarray(vector<int> nums)
{
    int size = nums.size(), maxim = -1;
    int length;
    
    map<int,pair<pair<int,int>,int>> hash;
    
    for(int i=0;i<size;i++)
    {
        if(hash.find(nums[i]) == hash.end())
            hash[nums[i]].first.second = i;
        hash[nums[i]].first.first ++;
        hash[nums[i]].second = i;
    }
    
    
    for(map<int,pair<pair<int,int>,int>>::iterator i =hash.begin();i!=hash.end();i++)
    {
        if((i->second).first.first > maxim)
        {
            maxim = (i->second).first.first;
            length = (i->second).second - (i->second).first.second + 1;
        }
        else if((i->second).first.first == maxim && (i->second).second - (i->second).first.second + 1 < length)
        {
            length = (i->second).second - (i->second).first.second + 1;
        }
            
    }
    
    return length;
}

int findShortestSubArray(vector<int>& nums) 
{
        return subarray(nums);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin >> nums[i];

    cout << findShortestSubArray(nums) << endl;

    return 0;
}