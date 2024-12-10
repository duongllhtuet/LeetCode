/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.



Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"


Constraints:

1 <= n <= 9
1 <= k <= n!
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> factorial(n + 1, 1);
        vector<int> nums(n);

        for (int i = 1; i <= n; i++)
        {
            factorial[i] = factorial[i - 1] * i;
            nums[i - 1] = i;
        }

        string result = "";
        k--;

        for (int i = n; i >= 1; i--)
        {
            int index = k / factorial[i - 1];
            k %= factorial[i - 1];

            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
        }

        return result;
    }
};

int main()
{
    Solution solution;

    int n = 3;
    int k = 3;
    string result = solution.getPermutation(n, k);

    cout << "Result: " << result << endl;

    return 0;
}