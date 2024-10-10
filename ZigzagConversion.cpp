#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        string result = "";
        int lengthString = s.size();

        vector<bool> checkCharacterFilled(lengthString, false);

        for (int i = 0; i < numRows; i++)
        {
            int index = i;

            while (index <= lengthString || ((index - 2 * i) < lengthString && (index - 2 * i) >= 0))
            {
                if (index - 2 * i >= 0 && index - 2 * i < lengthString && checkCharacterFilled[index - 2 * i] == false)
                {
                    result.push_back(s[index - 2 * i]);
                    checkCharacterFilled[index - 2 * i] = true;
                }

                if (index >= 0 && index < lengthString && checkCharacterFilled[index] == false)
                {
                    result.push_back(s[index]);
                    checkCharacterFilled[index] = true;
                }

                index += 2 * (numRows - 1);
            }
        }

        return result;
    }
};

int main()
{
    Solution MySolution;

    string s;
    getline(cin, s);

    int numRows;
    cin >> numRows;

    cout << MySolution.convert(s, numRows);

    return 0;
}