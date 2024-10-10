/*
Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses
substring
.



Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0


Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) 
    {
        stack<int> tokens;

        int maxLength = 0;
        int lastInvalid = -1;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                tokens.push(i);  
            }
            else
            {
                if (!tokens.empty())
                {
                    tokens.pop(); 
                    if (!tokens.empty())
                    {
                        maxLength = max(maxLength, i - tokens.top());
                    }
                    else
                    {
                        maxLength = max(maxLength, i - lastInvalid);
                    }
                }
                else
                {
                    lastInvalid = i;
                }
            }
        }

        return maxLength;
    }
};


int main()
{
    Solution s;

    string input = "()(()";
    int result = s.longestValidParentheses(input);

    cout << result;

    return 0;
}