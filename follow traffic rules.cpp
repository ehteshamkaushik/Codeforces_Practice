#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>

using namespace std;

double dist(int a, int v, int u)
{
    return ((double)(v*v - u*u)/(double)(2*a));
}

int main()
{
    int a, v;
    cin >> a >> v;
    int l, d, w;
    cin >> l >> d >> w;
    double t;
    if(v <= w)
    {
        double reqDist = dist(a, v, 0);
        if(l <= reqDist)
        {
            t = sqrt((double)(2*l)/(double)a);
            printf("%.10f",t);
            return 0;
        }
        else
        {
            t = sqrt((double)(2*reqDist)/(double)a) + ((double)(l-reqDist)/(double)v);
            //cout << setprecision(10) << t;
            printf("%.10f",t);
            return 0;
        }
    }
    else
    {
        double reqDist = dist(a, w, 0);
        if(reqDist > (double)d)
        {
            double reqDist = dist(a, v, 0);
            if((double)l <= reqDist)
            {
                t = sqrt((double)(2*l)/(double)a);
                //cout << setprecision(10) << t;
                printf("%.10f",t);
                return 0;
            }
            else
            {
                t = sqrt((double)(2*reqDist)/(double)a) + ((double)(l-reqDist)/(double)v);
                //cout << setprecision(10) << t;
                printf("%.10f",t);
                return 0;
            }
        }
        else if(reqDist == (double)d)
        {
            double t1 = sqrt(double(2*d)/(double)a);
            double reqDist = dist(a, v, w);
            if((double)(l-d) <= reqDist)
            {
                double v1 = sqrt(w*w + 2*a*(l-d));
                double t2 = (double)(v1-w)/(double)a;
                t = t1+t2;
                //cout << setprecision(10) << t;
                printf("%.10f",t);
                return 0;
            }
            else
            {
                double t2 = ((double)(v-w)/(double)a) + ((double)(l-d-reqDist)/(double)v);
                t = t1+t2;
                //cout << setprecision(10) << t;
                printf("%.10f",t);
                return 0;
            }
        }
        else
        {
            double t1 = (double)w/(double)a + (double)(d - reqDist)/(double)w;
            double reqDist = dist(a, v, w);
            if((double)(l-d) <= reqDist)
            {
                double v1 = sqrt(w*w + 2*a*(l-d));
                double t2 = (double)(v1-w)/(double)a;
                t = t1+t2;
                //cout << setprecision(10) << t;
                printf("%.10f",t);
                return 0;
            }
            else
            {
                double t2 = ((double)(v-w)/(double)a) + ((double)(l-d-reqDist)/(double)v);
                t = t1+t2;
                //cout << setprecision(10) << t;
                printf("%.10f",t);
                return 0;
            }
        }
    }
    return 0;
}
