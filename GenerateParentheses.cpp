/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // std::sort, std::unique
#include <unordered_set>  // std::unordered_set
#include <unordered_map>  // std::unordered_map
#include <queue>  // std::queue

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateHelper(n, n, "", result);

        return result;
    };
private:
    void generateHelper(int left, int right, string current, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }
        
        if (left > 0) {
            generateHelper(left - 1, right, current + "(", result);
        }
        
        if (right > left) {
            generateHelper(left, right - 1, current + ")", result);
        }
    };
};


int main()
{
    Solution solution;

    int n = 3;
    vector<string> result = solution.generateParenthesis(n);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}