#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

double dist(double speed, double time, int a)
{
    return ((speed * time)+(.5*a*time*time));
}

double travelTime(double distance, double speed, int a, int v)
{
    double tAll = (-speed+sqrt(speed*speed+4*.5*a*distance))/(a);
    double tMax = (v - speed)/a;
    if(tMax >= tAll)
        return tAll;
    else return (tMax + (distance - dist(speed, tMax, a))/v);
}

int main()
{
    int a, v, l, d, w;
    double ans;
    cin >> a >> v >> l >> d >> w;
    if(v <= w){
        ans = travelTime(l, 0, a, v);
        printf("%.5lf", ans);
        return 0;
    }
    else
    {
        double tw = w/a;
        double dw = dist(0, tw, a);
        if(dw >= d)
        {
            ans = travelTime(l, 0, a, v);
            printf("%.5lf", ans);
            return 0;
        }
        else
        {
            ans = tw + 2*travelTime(.5*(d-dw), w, a, v) + travelTime((l-d), w, a, v);
            printf("%.5lf", ans);
            return 0;
        }
    }

    return 0;
}
