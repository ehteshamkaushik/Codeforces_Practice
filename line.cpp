#include <iostream>

using namespace std;

long long int ext_gcd(long long int a, long long int b, long long int *x, long long int *y)
{
    if(a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    long long int x1, y1;
    long long int gcd = ext_gcd(b%a, a, &x1, &y1);
    *x = y1-(b/a)*x1;
    *y = x1;
    return gcd;
}

int main()
{
    long long int a,b,c, x, y;
    cin >> a >> b >> c;
    long long int g = ext_gcd(a, b, &x, &y);
    c = -c;
    if(c%g != 0)
    {
        cout << "-1\n";
    }
    else
    {
        long long int l = c/g;
        cout << x*l << " " << y*l;
    }

    return 0;
}
