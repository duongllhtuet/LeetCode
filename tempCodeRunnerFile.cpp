#include <iostream>
using namespace std;

int main()
{
    double a;
    cin >> a;

    cout << a;
    if (a >= 3.6)
    {
        cout << "Xuat sac" << endl;
    }
    else if (a >= 3.2)
    {
        cout << "Gioi" << endl;
    }
    else if (a >= 2.5)
    {
        cout << "Kha" << endl;
    }
    else if (a >= 2)
    {
        cout << "Trung binh" << endl;
    }
    else
    {
        cout << "Khong ra duoc truong" << endl;
    };
    return 0;
}