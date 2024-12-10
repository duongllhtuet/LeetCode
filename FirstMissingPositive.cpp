/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:

Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.


Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/

#include <iostream>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int lengthOfNums = nums.size();
        int result = 0;

        for (int i = 0; i < lengthOfNums; i++)
        {
            if (nums[i] <= 0)
            {
                continue;
            }

            if (nums[i] - result == 0)
            {
                continue;
            }

            if (nums[i] - result == 1)
            {
                result = nums[i];
                continue;
            }

            if (nums[i] - result > 2)
            {
                return result;
            }

            if (nums[i] - result == 2)
            {
                ++result;
            }
        }

        return ++result;
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {1, 2, 0};

    cout << solution.firstMissingPositive(nums1) << endl; // Output: 3

    vector<int> nums2 = {3, 4, -1, 1};

    cout << solution.firstMissingPositive(nums2) << endl; // Output: 2

    vector<int> nums3 = {7, 8, 9, 11, 12};

    cout << solution.firstMissingPositive(nums3) << endl; // Output: 1

    return 0;
}