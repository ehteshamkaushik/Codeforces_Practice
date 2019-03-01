#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;


double len(double x1, double y1, double x2, double y2)
{
    double ans;
    ans = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return ans;
}
double ang(double a, double b, double c)
{
    double ans;
    double pi = 2*acos(0.0);
    ans = acos((b*b+c*c-a*a)/(2*b*c));
    return (ans*180/pi);
}

double gcd(double x, double y) {
    double eps = 1e-4;
    while (fabs(x) > eps && fabs(y) > eps) {
        if (x > y)
                x -= floor(x / y) * y;
        else
                y -= floor(y / x) * x;
    }
    return x + y;
}

int main()
{
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    double a, b, c;
    a = len(x1, y1, x2, y2);
    b = len(x2, y2, x3, y3);
    c = len(x3, y3, x1, y1);
    double s;
    s = 0.5*(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
    s = abs(s);
    double R = (a*b*c)/(4*s);
    double A, B, C;
    A = ang(a, b, c);
    B = ang(b, c, a);
    C = ang(c, a, b);
    double g = gcd(A, gcd(B, C));
    double n = 180/g;
    double ans = (n/2)*R*R*sin(3.1416*2/n);
    printf("%.6lf",ans);
    return 0;
}
