#include <iostream>
using namespace std;

void printArrow(int n, bool left)
{
    if (left)
    {
        int spaces = n - 1;
        int stars = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < spaces; j++)
                cout << " ";
            for (int j = 0; j < stars; j++)
                cout << "*";
            cout << endl;
            spaces--;
            stars--;
        }

        spaces += 2;
        stars += 2;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < spaces; j++)
                cout << " ";
            for (int j = 0; j < stars; j++)
                cout << "*";
            cout << endl;
            spaces++;
            stars++;
        }
    }
    else
    {
        int spaces = 0;
        int stars = n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < spaces; j++)
                cout << " ";
            for (int j = 0; j < stars; j++)
                cout << "*";
            cout << endl;
            spaces += 2;
            stars--;
        }

        spaces -= 4;
        stars += 2;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < spaces; j++)
                cout << " ";
            for (int j = 0; j < stars; j++)
                cout << "*";
            cout << endl;
            spaces -= 2;
            stars++;
        }
    }
}

int main()
{
    int n;
    bool left;
    cin >> n >> left; 

    printArrow(n, left);
    return 0;
}
