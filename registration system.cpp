#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, int> id;
    string name;
    cin >> name;
    id[name] = 1;
    cout << "OK\n";
    for(int i = 0; i < n-1; i++)
    {
        cin >> name;
        map<string, int> :: iterator it;
        it = id.find(name);
        if(it == id.end())
        {
            cout << "OK\n";
            id[name] = 1;
        }
        else
        {
            int occ = id[name];
            string num;
            ostringstream convert;
            convert << occ;
            num = convert.str();
            occ++;
            id[name] = occ;
            name += num;
            cout << name;
            id[name] = 1;
        }
    }
    return 0;
}
