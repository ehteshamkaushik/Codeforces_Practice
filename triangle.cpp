#include <iostream>

using namespace std;

int check_triangle(int a, int b, int c)
{
    if(a+b > c && b+c > a && c+a > b)
        return 2;
    else if(a+b >= c && b + c >= a && c+a >= b)
        return 1;
    return 0;
}

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = 0, curr;
    curr = check_triangle(a, b, c);
    if(curr > ans)
        ans = curr;
    curr = check_triangle(a, b, d);
    if(curr > ans)
        ans = curr;
    curr = check_triangle(a, c, d);
    if(curr > ans)
        ans = curr;
    curr = check_triangle(b, c, d);
    if(curr > ans)
        ans = curr;
    if(ans == 0)
        cout << "IMPOSSIBLE";
    else if(ans == 1)
        cout << "SEGMENT";
    else
        cout << "TRIANGLE";
    return 0;
}
