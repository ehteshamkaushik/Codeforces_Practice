#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main()
{
    int i = 0, res = 0;
    char str[6];
    int asci;
    cin >> str;
    int l = strlen(str) - 1;
    while(l >= 0)
    {
        asci = str[i] - 64;
        res += (asci*pow(26,i));
        i++;
        l--;
        cout << res << endl;
    }
    return 0;
}

