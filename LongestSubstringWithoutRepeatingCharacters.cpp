#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSubstringWithoutRepeat = 1;
        int lengthString = s.size();

        if (lengthString == 0) {
            return 0;
        } else {
            vector<int> lengthSubstringWithoutRepeat(lengthString, 0);
            lengthSubstringWithoutRepeat[0] = 1;

            for (int i = 1; i < lengthString; i++) {
                for (int j = 1; j <= lengthSubstringWithoutRepeat[i - 1]; j++) {
                    if (s[i] == s[i - j]) {
                        lengthSubstringWithoutRepeat[i] = 1;
                        maxSubstringWithoutRepeat =
                            max(maxSubstringWithoutRepeat,
                                lengthSubstringWithoutRepeat[i]);
                        break;
                    }
                }

                if (lengthSubstringWithoutRepeat[i] == 0) {

                    lengthSubstringWithoutRepeat[i] =
                        lengthSubstringWithoutRepeat[i - 1] + 1;

                    maxSubstringWithoutRepeat =
                        max(maxSubstringWithoutRepeat,
                            lengthSubstringWithoutRepeat[i]);
                }
            }

            for (int i = 0; i < lengthString; i++)
            {
                cout << lengthSubstringWithoutRepeat[i] << " ";
            }

            return maxSubstringWithoutRepeat;
        }
    }
};

int main()
{
    Solution mySolution;

    string s;
    getline(cin, s);
    mySolution.lengthOfLongestSubstring(s);
}
