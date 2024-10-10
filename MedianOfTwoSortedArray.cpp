#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        double result;

        for (int i = 0; i < n; i++) 
        {
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin(), nums1.end());

        if (m + n % 2 == 1)
        {
            result = (double(nums1[(m + n) / 2]) * 10000) / 10000;
            return result;
        }

        result = (((double(nums1[(m + n) / 2]) + double(nums1[(m + n) / 2 - 1])) / 2) * 10000) / 10000;
        return result;
    }
};

int main()
{
    return 0;
}