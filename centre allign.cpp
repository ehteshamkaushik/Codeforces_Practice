#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> lines;
    int i = 0;
    int maxlen = 0;
    string l;
    while(getline(cin, l))
    {
        lines.push_back(l);
        if(maxlen <= lines[i].size())
        {
            maxlen = lines[i].size();
        }
        i++;
    }
    for(int j = 0; j < maxlen+2; j++)
        cout << "*";
    cout << endl;
    maxlen+=2;
    int f = 0;
    for(int j = 0; j < i; j++)
    {
        int len = lines[j].size();
        len+= 2;
        if(len%2 == maxlen%2)
        {
            int spc = (maxlen - len)/2;
            cout << "*";
            for(int k = 0; k < spc; k++)
                cout << " ";
            cout << lines[j];
            for(int k = 0; k < spc; k++)
                cout << " ";
            cout << "*" << endl;
        }
        else
        {
            int l,r;
            if(f == 0)
            {
                l = (maxlen -len)/2;
                r = maxlen - len - l;
                f = 1;
            }
            else
            {
                r = (maxlen -len)/2;
                l = maxlen - len - r;
                f = 0;
            }

            cout << "*";
            for(int k = 0; k < l; k++)
                cout << " ";
            cout << lines[j];
            for(int k = 0; k < r; k++)
                cout << " ";
            cout << "*" << endl;
        }
    }
    for(int j = 0; j < maxlen; j++)
        cout << "*";
    cout << endl;
    return 0;
}
