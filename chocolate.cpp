#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int bar[n];
    for(int i = 0; i < n; i++)
    {
        cin >> bar[i];
    }

    int l = 0;
    int r = n-1;
    int a = 0, b = 0, lsum = bar[l], rsum = bar[r];
    while(l <= r)
    {
        if(lsum < rsum)
        {
            a++;
            l++;
            lsum+=bar[l];
        }
        else if(lsum > rsum)
        {
            b++;
            r--;
            rsum+=bar[r];
        }
        else
        {
            if(l == r)
            {
                a++;
                l++;
            }
            else
            {
                a++;
                b++;
                l++;
                r--;
                lsum+= bar[l];
                rsum+= bar[r];
            }
        }
    }
    cout << a << " " << b;
    return 0;
}
