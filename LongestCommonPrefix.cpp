/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

#include <iostream>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int lengthOfStr = strs.size();
        if (lengthOfStr == 0)
            return "";
        if (lengthOfStr == 1)
            return strs[0];

        sort(strs.begin(), strs.end(), cmp);

        string currentLongestCommonPrefix = findLongestPrefixBetweenTwoStrings(strs[0], strs[1]);

        for (int i = 2; i < lengthOfStr; i++)
        {
            if (currentLongestCommonPrefix.empty())
            {
                break;
            }

            currentLongestCommonPrefix = findLongestPrefixBetweenTwoStrings(currentLongestCommonPrefix, strs[i].substr(0, currentLongestCommonPrefix.length()));
        }

        return currentLongestCommonPrefix;
    }

private:
    static bool cmp(const string &a, const string &b)
    {
        return a < b;
    };
    string findLongestPrefixBetweenTwoStrings(const string &a, const string &b)
    {
        int minLength = a.size();
        for (int i = 0; i < minLength; i++)
        {
            if (a[i] != b[i])
            {
                return a.substr(0, i);
            }
        }
        return a.substr(0, minLength);
    };
};

int main()
{
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << solution.longestCommonPrefix(strs) << endl; // Output: "fl"

    strs = {"dog", "racecar", "car"};
    cout << solution.longestCommonPrefix(strs) << endl; // Output: ""

    return 0;
}