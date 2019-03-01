#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    char str[6];
    cin >> str;
    char ch;
    int i = 0, res = 0;
    int len = strlen(str) - 1;

    while(len >= 0)
    {
        cout <<"len : " <<  len<< endl;
        ch = str[len];
        cout << ch << endl;
        int a = ch-64;
        cout << "val : " << a << endl;
        cout << "i : " << i << endl;
        cout << (a*pow(26,i)) << endl;
        res = res+(a*pow(26,i));
        cout << "res : " << res << endl;
        i++;
        len--;
    }

    return 0;
}
