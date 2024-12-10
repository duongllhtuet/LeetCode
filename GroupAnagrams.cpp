/*
Given an array of strings strs, group the
anagrams
 together. You can return the answer in any order.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]



Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> anagramMap;

        for (const auto &word : strs)
        {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            anagramMap[sortedWord].push_back(word);
        }

        vector<vector<string>> result;
        for (const auto &entry : anagramMap)
        {
            result.push_back(entry.second);
        }

        return result;
    }
};

int main()
{
    Solution solution;

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = solution.groupAnagrams(strs);

    for (const auto &group : result)
    {
        for (const auto &word : group)
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}