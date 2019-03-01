#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
    string name;
    int online = 0;
    int traffic = 0;
    while(getline(cin, name))
    {
        if(name[0] == '+'){

            online++;
        }
        else if(name[0] == '-'){
            online--;
        }
        else
        {
            int l = name.size()-name.find(':') - 1;
            traffic += (online * l);


        }

    }
    cout << traffic << endl;
    return 0;
}
