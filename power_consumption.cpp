#include <iostream>

using namespace std;

int main()
{
    int n, p1, p2, p3, t1, t2, l, r, ans = 0;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    cin >> l >> r;
    ans += (r-l)*p1;
    for(int i = 0; i < n-1; i++)
    {
        int l1, r1;
        cin >> l1 >> r1;
        ans += (r1-l1)*p1;
        int rem = l1-r;
        if(rem >= t1)
        {
            ans += t1*p1;
            rem -= t1;
        }
        else{
            ans+= rem*p1;
            l = l1;
            r = r1;
            continue;
        }
        if(rem >= t2)
        {
            ans += t2*p2;
            rem -= t2;
        }else{
            ans+= rem*p2;
            l = l1;
            r = r1;
            continue;
        }
        if(rem > 0)
        {
            ans += rem*p3;
        }
        l = l1;
        r = r1;
    }
    cout << ans << endl;
    return 0;
}
