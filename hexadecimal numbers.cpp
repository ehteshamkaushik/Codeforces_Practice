#include <iostream>

using namespace std;

int n, c = 0;

void func(int num)
{
    if (num <= n){
        c++;
        func(num * 10);
        func(num*10 + 1);
    }
    else return;
}

int main()
{
    cin >> n;
    func(1);
    cout << c;
    return 0;
}
