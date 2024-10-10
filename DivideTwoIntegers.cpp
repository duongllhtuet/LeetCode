/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.



Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.


Constraints:

-231 <= dividend, divisor <= 231 - 1
divisor != 0
*/

#include <iostream>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
        {
            return INT_MAX;
        }

        bool negative = (dividend < 0) ^ (divisor < 0);

        long long absDividend = labs(dividend);
        long long absDivisor = labs(divisor);

        int quotient = 0;
        int currentBitShift = 0;

        long long tempDivisor = absDivisor;
        while ((tempDivisor << 1) <= absDividend)
        {
            tempDivisor <<= 1;
            currentBitShift++;
        }

        while (currentBitShift >= 0)
        {
            if (absDividend >= tempDivisor)
            {
                absDividend -= tempDivisor;
                quotient += (1 << currentBitShift);
            }
            tempDivisor >>= 1;
            currentBitShift--;
        }

        return negative ? -quotient : quotient;
    }
};

int main()
{
    Solution solution;

    int result = solution.divide(-2147483648, 1);

    cout << result;

    return 0;
}