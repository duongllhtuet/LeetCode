/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, const int target) 
    {
        int lengthOfNum = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < lengthOfNum - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < lengthOfNum - 2; j++)
            {
                if (j > 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = lengthOfNum - 1;

                while(left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];

                    if(sum == target)
                    {
                        vector<int> quad = {nums[i], nums[j], nums[left], nums[right]};
                        result.push_back(quad);

                        while(left < right && nums[left] == quad[2]) left++;
                        while(left < right && nums[right] == quad[3]) right--;
                    }
                    else if(sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }
            }
        }

        return result; 
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = solution.fourSum(nums, 0);

    for (vector<int > i : result) 
    {
        for (int j : i)
        {
            cout << j << " ";
        }

        cout << endl;
    }


    return 0;
}