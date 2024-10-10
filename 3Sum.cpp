/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;
// My Solution
// class Solution
// {
// private:
//     set<vector<int>> uSet;

//     void findTriplets(vector<int> &nums, int start, int end)
//     {
//         int defaultSum = nums[start - 1];
//         int currentSum;
//         while (start < end)
//         {
//             currentSum = defaultSum + nums[start] + nums[end];

//             if (currentSum == 0)
//             {
//                 vector<int> triplet = {defaultSum, nums[start], nums[end]};
//                 uSet.insert(triplet);
//                 ++start;
//                 --end;
//             }
//             else if (currentSum > 0)
//             {
//                 --end;
//             }
//             else
//             {
//                 ++start;
//             }
//         }
//     };

// public:
//     vector<vector<int>> threeSum(vector<int> &nums)
//     {
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> result;

//         int lengthOfNum = nums.size();
//         for (int i = 1; i < lengthOfNum; i++)
//         {
//             findTriplets(nums, i, lengthOfNum - 1);
//         }

//         for (const vector<int> &triplet : uSet)
//         {
//             result.push_back(triplet);
//         }

//         return result;
//     }
// };

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int lengthOfNum = nums.size();

        for (int i = 0; i < lengthOfNum - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int start = i + 1, end = lengthOfNum - 1;
            while (start < end)
            {
                int currentSum = nums[i] + nums[start] + nums[end];

                if (currentSum == 0)
                {
                    result.push_back({nums[i], nums[start], nums[end]});

                    while (start < end && nums[start] == nums[start + 1])
                        ++start;
                    while (start < end && nums[end] == nums[end - 1])
                        --end;

                    ++start;
                    --end;
                }
                else if (currentSum > 0)
                {
                    --end;
                }
                else
                {
                    ++start;
                }
            }
        }

        return result;
    }
};


int main()
{
    Solution solution;
    vector<int> nums = {-2, 0, 1, 1, 2};
    vector<vector<int>> result = solution.threeSum(nums);

    for (const auto &triplet : result)
    {
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}