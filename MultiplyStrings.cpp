/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.



Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"


Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.


*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        int lengthOfNum1 = num1.length();
        int lengthOfNum2 = num2.length();
        
        if (num1 == "0" || num2 == "0")
            return "0";
        
        vector<int> result(lengthOfNum1 + lengthOfNum2, 0);
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        for (int i = 0; i < lengthOfNum2; i++)
        {
            int digit2 = num2[i] - '0';
            for (int j = 0; j < lengthOfNum1; j++)
            {
                int digit1 = num1[j] - '0';
                int product = digit1 * digit2;
                int sum = product + result[i + j];
                
                result[i + j] = sum % 10;           
                result[i + j + 1] += sum / 10;      
            }
        }
        
        int index = result.size() - 1;
        while (index >= 0 && result[index] == 0)
            index--;
        
        string finalResult = "";
        while (index >= 0)
            finalResult += result[index--] + '0';  

        return finalResult;
    }
};

int main()
{
    Solution s;

    string num1 = "123";
    string num2 = "456";

    string result = s.multiply(num1, num2);

    cout << "Product: " << result << endl;  // Output should be "56088"

    return 0;
}