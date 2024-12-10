/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <climits>
#include <cmath>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector< vector<int> > combinations;
        vector<int> combination;
        set<vector<int>> uniqueCombinations;

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, combination, combinations, uniqueCombinations);

        return combinations;
    }
private:
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& combination, vector<vector<int>>& combinations, set<vector<int>>& uniqueCombinations)
    {
        if (target == 0)
        {
            if(uniqueCombinations.find(combination) == uniqueCombinations.end())
            {
                combinations.push_back(combination);
                uniqueCombinations.insert(combination);
            }

            return;
        }

        if (target < 0)
        {
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            combination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, combination, combinations, uniqueCombinations);
            combination.pop_back();
        }
    }
};

int main()
{
    Solution solution;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result = solution.combinationSum2(candidates, target);

    for (const auto& combination : result)
    {
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}