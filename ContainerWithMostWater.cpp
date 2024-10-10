#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/

// class Solution
// {
// public:
//     int maxArea(vector<int> &height)
//     {
//         int lengthOfArray = height.size();
//         vector<int> maximumArea(lengthOfArray, 0);

//         int maximumWater = 0;

//         for (int i = 1; i < lengthOfArray; i++)
//         {
//             for (int j = 0; j < i; j++)
//             {
//                 int minLengthOfTwoPoint = min(height[i], height[j]);

//                 int maxAmountOfWaterAmongTwoPoint = (i - j) * minLengthOfTwoPoint;

//                 maximumArea[j] = max(maxAmountOfWaterAmongTwoPoint, maximumArea[i]);

//                 if (maximumArea[j] > maximumWater)
//                 {
//                     maximumWater = maximumArea[j];
//                 }
//             }
//         }

//         return maximumWater;
//     }
// };

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int lengthOfArray = height.size();
        int right = lengthOfArray - 1;
        int maxWater = 0;

        while (left < right) 
        {
            int minHeight = min(height[left], height[right]);
            maxWater = max(maxWater, minHeight * (right - left));

            if (height[left] < height[right])
            {
                left++;
            } else 
            {
                right--;
            }
        }

        return maxWater;
    }
};

int main()
{
    Solution test;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << test.maxArea(height);

    return 0;
}