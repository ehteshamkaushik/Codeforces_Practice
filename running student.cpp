#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    int n, s, i;
    double reqT = 1e20, t, vb, vs, xu, yu, x[105];
    cin >> n >> vb >> vs;
    for(i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    cin >> xu >> yu;
    for(i = 2; i <= n; i++)
    {
        t = x[i]/vb+sqrt((x[i]-xu)*(x[i]-xu)+yu*yu)/vs;
        if(t <= reqT)
        {
            reqT = t;
            s = i;
        }
    }
    cout << s;
    return 0;
}
