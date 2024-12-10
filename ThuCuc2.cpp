#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string pigLatin(string word)
{
    if (word.empty()) return word;

    // Kiểm tra nếu từ không phải là chữ cái
    for (char c : word)
    {
        if (!isalpha(c))
        {
            return "Invalid input: contains non-alphabetical characters.";
        }
    }

    // Giữ nguyên chữ hoa/thường của ký tự đầu tiên
    bool isUpper = isupper(word[0]);
    word[0] = tolower(word[0]);

    char firstChar = word[0];
    string result;

    if (firstChar == 'a' || firstChar == 'e' || firstChar == 'i' || firstChar == 'o' || firstChar == 'u')
    {
        result = word + "way";
    }
    else
    {
        result = word.substr(1) + firstChar + "ay";
    }

    if (isUpper)
    {
        result[0] = toupper(result[0]);
    }

    return result;
}

int main()
{
    string word;
    cout << "Enter a word: ";
    cin >> word;
    cout << pigLatin(word) << endl;
    return 0;
}
