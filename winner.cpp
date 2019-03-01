#include <iostream>
#include <cstring>
#include <stdio.h>
#include <map>
#include <set>

using namespace std;

struct player
{
    char name[100];
    int score;
};

typedef struct player player;

int main()
{
    int n;

    cin >> n;
    player p[n];
    for(int i = 0; i < n; i++)
    {
        strcpy(p[i].name, "");
        p[i].score = 0;
    }

    map<string, int> p2s;
    set<string> winner;
        for(int i = 0; i < n; i++)
        {
            cin >> p[i].name >> p[i].score;
            p2s[p[i].name] += p[i].score;
        }
        int ws = -100000;
        for(map<string, int> :: iterator it = p2s.begin(); it != p2s.end(); ++it)
        {
            if(it->second > ws)
            {
                winner.clear();
                winner.insert(it->first);
                ws = it->second;
            }
            else if(it->second == ws)
            {
                winner.insert(it->first);
            }
        }
        if(winner.size() > 1)
        {
            p2s.clear();
            for(int i = 0; i < n; i++)
            {
                p2s[p[i].name] += p[i].score;
                if(p2s[p[i].name] >= ws && winner.count(p[i].name) == 1)
                {
                    winner.clear();
                    winner.insert(p[i].name);
                }
            }
        }
    cout << *winner.begin();

    return 0;
}
