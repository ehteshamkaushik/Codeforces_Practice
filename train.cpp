#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool chksq(string dest1, string dest2, string source)
{
    int found = source.find(dest1);
    if(found == std::string::npos)
        return false;
    int found2 = source.find(dest2, found+dest1.size());
    if(found2 != std::string::npos)
        return true;
    return false;
}

int main()
{
    string source;
    string dest1, dest2;
    cin >> source;
    cin >> dest1;
    cin >> dest2;

    bool f = chksq(dest1, dest2, source);
    string revsource(source.rbegin(), source.rend());
    bool r = chksq(dest1, dest2, revsource);
    if(f == true && r == true)
    {
        cout << "both";
        return 0;
    }
    else if(f == true)
    {
        cout << "forward";
        return 0;
    }
    else if(r == true)
    {
        cout << "backward";
        return 0;
    }
    else
    {
        cout << "fantasy";
    }
    return 0;
}
