/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.


Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int lengthOfS = s.length();
        int lengthOfP = p.length();

        vector< vector<bool> > matches(lengthOfS + 1, vector<bool>(lengthOfP +1, false));

        matches[0][0] = true;

        for (int j = 1; j <= lengthOfP; j++)
        {
            if (p[j - 1] == '*')
            {
                matches[0][j] = matches[0][j - 1];
            }
        }

        for (int i = 1; i <= lengthOfS; i++)
        {
            for (int j = 1; j <= lengthOfP; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    matches[i][j] = matches[i - 1][j - 1];
                } else if (p[j - 1] == '*')
                {
                    matches[i][j] = matches[i][j - 1] || matches[i - 1][j];
                }
            }
        }

        return matches[lengthOfS][lengthOfP];
    }
};

    int main()
    {
        Solution solution;

        string s = "aa";
        string p = "*";

        bool result = solution.isMatch(s, p);

        cout << result << endl; // Output: true

        return 0;
    }