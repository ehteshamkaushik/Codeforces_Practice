#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = max(a,b);
    c = 6-c+1;
    if(c == 1)
        cout << "1/6";
    else if(c == 2)
        cout << "1/3";
    else if (c == 3)
        cout << "1/2";
    else if (c == 4)
        cout << "2/3";
    else if(c == 5)
        cout << "5/6";
    else
        cout << "1/1";
    return 0;
}
