/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/ 

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> tokens;

        for (int i = 0; i < s.size(); i++) {
            char current = s[i];
            switch (current) {
                case ')':
                    if (!tokens.empty() && tokens.top() == '(') {
                        tokens.pop();
                    } else {
                        return false;
                    }
                    break;
                case ']':
                    if (!tokens.empty() && tokens.top() == '[') {
                        tokens.pop();
                    } else {
                        return false;
                    }
                    break;
                case '}':
                    if (!tokens.empty() && tokens.top() == '{') {
                        tokens.pop();
                    } else {
                        return false;
                    }
                    break;
                default:
                    tokens.push(current);
                    break;
            }
        }

        return tokens.empty();
    }
};

int main()
{
    Solution solution;
    string s1 = "({)";

    if (solution.isValid(s1))
    {
        cout << "Input string is valid." << endl;
    } else 
    {
        cout << "Input string is not valid." << endl;
    }

    return 0;
}