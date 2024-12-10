/*
Given an array nums of distinct integers, return all the possible
permutations
. You can return the answer in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]


Constraints:

1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, res);
        return res;
    }

private:
    void backtrack(vector<int> &nums, int start, vector<vector<int>> &res)
    {
        if (start == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            // avoid duplicates
            if (i!= start && nums[i] == nums[start])
                continue;

            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            swap(nums[start], nums[i]); // backtrack
        }
    }
};

int main()
{
    Solution s;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = s.permute(nums);

    for (auto &v : res)
    {
        for (auto &num : v)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}