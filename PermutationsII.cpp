/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.



Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>  

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        backtrack(nums, 0, res);

        return res;
    }
private:
    void backtrack(std::vector<int> &nums, int start, std::vector<std::vector<int>> &res)
    {
        if (start == nums.size())
        {
            res.push_back(nums);
            return;
        }

        std::unordered_set<int> swapped;
        for (int i = start; i < nums.size(); i++)
        {
            if (swapped.find(nums[i]) != swapped.end()) 
                continue;

            swapped.insert(nums[i]); 

            swap(nums[start], nums[i]);
            backtrack(nums, start + 1, res);
            swap(nums[start], nums[i]); 
        }
    }
};

int main()
{
    Solution solution;

    vector<int> nums = {1, 1, 2};
    vector<vector<int>> result = solution.permuteUnique(nums);


    for (const auto &v : result)
    {
        for (const auto &num : v)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}