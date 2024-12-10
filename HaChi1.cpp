#include <iostream>
#include <vector>
#include <string>

using namespace std;

int blackjackScore(const vector<string> &cards)
{
    int result = 0;
    int ace = 0;

    for (const string &card : cards)
    {
        if (card == "A")
        {
            ace++;
        }
        else if (card == "J" || card == "Q" || card == "K" || card == "10")
        {
            result += 10;
        }
        else
        {
            result += stoi(card);
        }
    }

    for (int i = 0; i < ace; i++)
    {
        if (result + 11 < 21)
        {
            result += 11;
        }
        else
        {
            result += 11;
        }
    }

    return result;
}

int main()
{
    vector<string> cards = {"A", "3"};
    cout << blackjackScore(cards) << endl;
    return 0;
}
