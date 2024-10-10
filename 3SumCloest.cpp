/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int lengthOfNum = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];  // Khởi tạo với giá trị hợp lý.

        for (int i = 0; i < lengthOfNum - 2; i++) 
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1; 
            int right = lengthOfNum - 1;
            while (left < right)
            {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum; 
                }

                if (currentSum == target) {
                    return target;  
                } else if (currentSum > target) {
                    --right;
                } else {
                    ++left;
                }
            }
        }

        return closestSum;
    }
};


int main() 
{
    Solution solution;
    vector<int> nums = {-1, 2, 1, -4};
    cout << solution.threeSumClosest(nums, 1) << endl;

    return 0;
}