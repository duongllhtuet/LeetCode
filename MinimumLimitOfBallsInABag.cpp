/*
You are given an integer array nums where the ith bag contains nums[i] balls. You are also given an integer maxOperations.

You can perform the following operation at most maxOperations times:

Take any bag of balls and divide it into two new bags with a positive number of balls.
For example, a bag of 5 balls can become two new bags of 1 and 4 balls, or two new bags of 2 and 3 balls.
Your penalty is the maximum number of balls in a bag. You want to minimize your penalty after the operations.

Return the minimum possible penalty after performing the operations.



Example 1:

Input: nums = [9], maxOperations = 2
Output: 3
Explanation:
- Divide the bag with 9 balls into two bags of sizes 6 and 3. [9] -> [6,3].
- Divide the bag with 6 balls into two bags of sizes 3 and 3. [6,3] -> [3,3,3].
The bag with the most number of balls has 3 balls, so your penalty is 3 and you should return 3.
Example 2:

Input: nums = [2,4,8,2], maxOperations = 4
Output: 2
Explanation:
- Divide the bag with 8 balls into two bags of sizes 4 and 4. [2,4,8,2] -> [2,4,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,4,4,4,2] -> [2,2,2,4,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,4,4,2] -> [2,2,2,2,2,4,2].
- Divide the bag with 4 balls into two bags of sizes 2 and 2. [2,2,2,2,2,4,2] -> [2,2,2,2,2,2,2,2].
The bag with the most number of balls has 2 balls, so your penalty is 2, and you should return 2.


Constraints:

1 <= nums.length <= 105
1 <= maxOperations, nums[i] <= 109
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // Đặt khoảng penalty ban đầu
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        // Binary search để tìm penalty nhỏ nhất
        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Kiểm tra nếu penalty là mid có khả thi không
            if (canReduce(nums, maxOperations, mid)) {
                result = mid; // Cập nhật kết quả
                right = mid - 1; // Thử penalty nhỏ hơn
            } else {
                left = mid + 1; // Thử penalty lớn hơn
            }
        }

        return result;
    }

private:
    bool canReduce(const vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;
        for (int num : nums) {
            // Tính số lần cần chia túi để đảm bảo các túi có số bóng <= penalty
            operations += (num + penalty - 1) / penalty - 1; // Làm tròn lên
            if (operations > maxOperations) {
                return false; // Không đủ số lần chia
            }
        }
        return true;
    }
};

int main()
{
    Solution solution;

    vector<int> nums1 = {9};
    cout << solution.minimumSize(nums1, 2) << endl; // Output: 3

    vector<int> nums2 = {2,4,8,2};
    cout << solution.minimumSize(nums2, 4) << endl; // Output: 2
    

    return 0;
}