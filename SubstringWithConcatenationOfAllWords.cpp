/*
You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated string is a string that exactly contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated string because it is not the concatenation of any permutation of words.
Return an array of the starting indices of all the concatenated substrings in s. You can return the answer in any order.



Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation:

The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.

Example 2:

Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

Explanation:

There is no concatenated substring.

Example 3:

Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]

Explanation:

The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"].
The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"].
The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"].



Constraints:

1 <= s.length <= 104
1 <= words.length <= 5000
1 <= words[i].length <= 30
s and words[i] consist of lowercase English letters.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int lengthOfWords = words.size();
        int lengthOfElementsInWords = words[0].length();
        int lengthOfString = s.length();

        vector<int> result;

        if (lengthOfWords * lengthOfElementsInWords > lengthOfString)
        {
            return result;
        }

        unordered_map<string, int> wordCount;
        for (int i = 0; i < lengthOfWords; i++)
        {
            string word = words[i];
            if (wordCount.find(word) == wordCount.end())
            {
                wordCount[word] = 1;
            }
            else
            {
                wordCount[word]++;
            }
        }

        int index = 0;
        while ((index + lengthOfWords * lengthOfElementsInWords) <= lengthOfString)
        {
            unordered_map<string, int> currentWordCount = wordCount;
            string wordsInString = s.substr(index, lengthOfWords * lengthOfElementsInWords);
            for (int i = 0; i < wordsInString.length(); i += lengthOfElementsInWords)
            {
                string wordInWordsInString = wordsInString.substr(i, lengthOfElementsInWords);
                if (currentWordCount.find(wordInWordsInString) != currentWordCount.end())
                {
                    if (currentWordCount[wordInWordsInString] != 0)
                    {
                        currentWordCount[wordInWordsInString]--;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            bool checked = true;
            for (auto &currentPairWordCount : currentWordCount)
            {
                if (currentPairWordCount.second != 0)
                {
                    checked = false;
                    break;
                }
            }

            if (checked)
            {
                result.push_back(index);
            }

            index++;
        }

        return result;
    }
};

int main()
{
    Solution solution;

    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"foo", "bar"};

    vector<int> result = solution.findSubstring(s, words);

    for (int index : result)
    {
        cout << index << " ";
    }

    return 0;
}