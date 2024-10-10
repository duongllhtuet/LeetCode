#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string expand(int i, int j, string s) {
        int left = i;
        int right = j;

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            
            string odd = expand(i, i, s);
            if (odd.size() > ans.size()) {
                ans = odd;
            }

            string even = expand(i, i + 1, s);
            if (even.size() > ans.size()) {
                ans = even;
            }
        }

        return ans;
    }
};

int main()
{
    Solution mySolution;

    string s;
    getline(cin, s);

    cout << mySolution.longestPalindrome(s);

    return 0;
}