/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.



Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 20
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right)
        {
            for (int i = left; i <= right; ++i)
            {
                matrix[top][i] = num++;
            }
            top++;

            for (int i = top; i <= bottom; ++i)
            {
                matrix[i][right] = num++;
            }
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; --i)
                {
                    matrix[bottom][i] = num++;
                }
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};

int main()
{
    Solution solution;
    int n; cin >> n;
    vector<vector<int>> result = solution.generateMatrix(n);

    for (const auto &row : result)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}