/*
Seven different symbols represent Roman numerals with the following values:

Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:

If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.
Given an integer, convert it to a Roman numeral.



Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places
Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII
Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV


Constraints:

1 <= num <= 3999
*/

#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string roman = "";
        int countOfNumbersInNum = 0;

        while (num % 10 != 0)
        {
            int endOfTheNumber = num % 10;
            num /= 10;

            switch (endOfTheNumber)
            {
            case 4:
                roman.insert(0, convertIfNumberIs4(endOfTheNumber, countOfNumbersInNum));
                countOfNumbersInNum++;
                break;
            case 9:
                roman.insert(0, convertIfNumberIs9(endOfTheNumber, countOfNumbersInNum));
                countOfNumbersInNum++;
                break;
            default:
                roman.insert(0, convertNumberToRoman(endOfTheNumber * pow(10, countOfNumbersInNum)));
                countOfNumbersInNum++;
                break;
            }
        }

        return roman;
    }

private:
    string intConvertRoman(int value)
    {
        switch (value)
        {
        case 1:
            return "I";
        case 4:
            return "IV";
        case 5:
            return "V";
        case 9:
            return "IX";
        case 10:
            return "X";
        case 40:
            return "XL";
        case 50:
            return "L";
        case 90:
            return "XC";
        case 100:
            return "C";
        case 400:
            return "CD";
        case 500:
            return "D";
        case 900:
            return "CM";
        case 1000:
            return "M";
        default:
            return "";
        };
    };
    string convertIfNumberIs4(int value, int indexOfNumbersInNumer)
    {
        return intConvertRoman(5 * pow(10, indexOfNumbersInNumer) - value * pow(10, indexOfNumbersInNumer)) + intConvertRoman(5 * pow(10, indexOfNumbersInNumer));
    };
    string convertIfNumberIs9(int value, int indexOfNumbersInNumer)
    {
        return intConvertRoman(10 * pow(10, indexOfNumbersInNumer) - value * pow(10, indexOfNumbersInNumer)) + intConvertRoman(10 * pow(10, indexOfNumbersInNumer));
    };
    string convertNumberToRoman(int value)
    {
        std::string result = "";

        while (value >= 1000)
        {
            result += "M";
            value -= 1000;
        }
        while (value >= 500)
        {
            result += "D";
            value -= 500;
        }
        while (value >= 100)
        {
            result += "C";
            value -= 100;
        }
        while (value >= 50)
        {
            result += "L";
            value -= 50;
        }
        while (value >= 10)
        {
            result += "X";
            value -= 10;
        }
        while (value >= 5)
        {
            result += "V";
            value -= 5;
        }
        while (value >= 1)
        {
            result += "I";
            value -= 1;
        }

        return result;
    };
};

int main()
{
    Solution test;
    cout << test.intToRoman(1987);

    return 0;
}