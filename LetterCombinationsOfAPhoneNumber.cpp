/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.




Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]


Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};  

        vector<string> resultAfterCombinations;
        addLetterToResult(resultAfterCombinations, 0, digits.length(), digits, "");

        return resultAfterCombinations;
    };

private:
    unordered_map<char, vector<string>> numberToStringMap = {
        {'2', {"a", "b", "c"}},
        {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}},
        {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}},
        {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}},
        {'9', {"w", "x", "y", "z"}}
    };

    void addLetterToResult(vector<string>& result, int index, int lengthOfDigits, const string& digits, string currentString)
    {
        if (index == lengthOfDigits) {
            result.push_back(currentString);
            return;
        }

        for (const string& letter : numberToStringMap[digits[index]]) 
        {
            currentString.push_back(letter[0]);
            addLetterToResult(result, index + 1, lengthOfDigits, digits, currentString);
            currentString.pop_back(); 
        }
    };
};


int main()
{
    Solution solution;

    string digits = "233";
    vector<string> result = solution.letterCombinations(digits);

    for (string letter : result)
    {
        cout << letter << " ";
    }

    return 0;
}