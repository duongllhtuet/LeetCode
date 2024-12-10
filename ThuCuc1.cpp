#include <iostream>
using namespace std;

double P(int n)
{
    if (n <= 0)
        return 1;
    if (n > 10)
        return 1;

    double p = 1;

    for (int i = 1; i <= n; i++)
    {
        p = p * i;
    }
    
    return p;
}
int main()
{
    int n;
    cin >> n;
    cout << P(n);
}