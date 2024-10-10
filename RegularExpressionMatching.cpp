#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return matchHelper(s, p, 0, 0);
    }

private:
    bool matchHelper(const string& s, const string& p, int i, int j) {
        if (j == p.length()) {
            return i == s.length();
        }

        bool first_match = (i < s.length() && (p[j] == s[i] || p[j] == '.'));

        if (j + 1 < p.length() && p[j + 1] == '*') {
            return (matchHelper(s, p, i, j + 2) || (first_match && matchHelper(s, p, i + 1, j)));
        } else {
            return first_match && matchHelper(s, p, i + 1, j + 1);
        }
    }
};

int main() {
    Solution solution;
    string s = "aa";
    string p = ".*";  

    cout << solution.isMatch(s, p) << endl; 

    return 0;
}
