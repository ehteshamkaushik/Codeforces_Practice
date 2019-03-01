#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

class player
{
public:
    string name;
    int score;
};

int main()
{
    int n, tp = 0, f = 1;;
    string wname, cname;
    int wscore, cscore;
    cin >> n;
    player arr[n];
    while(n > 0)
    {
        cin >> cname >> cscore;
        if(tp == 0)
        {
            wname = cname;
            wscore = cscore;
            player c;
            c.name = cname;
            c.score = cscore;
            arr[tp++] = c;
        }
        else
        {
            player c;
            c.name = cname;
            c.score = cscore;
            for(int i = 0; i < tp; i++)
            {
                if(arr[i].name == cname)
                {
                    arr[i].score = arr[i].score + cscore;
                    f = 0;
                    break;
                }
//                else
//                    arr[tp++] = c;
            }
            if(f)
                arr[tp++] = c;
            if(cname == wname)
            wscore = wscore+cscore;
        }

        for(int i = 0; i < tp; i++)
            {
                if(arr[i].score > wscore)
                {
                    wname = arr[i].name;
                    wscore = arr[i].score;
                }
            }
            cout << "Round : " << n << endl;
        for(int i = 0; i < tp; i++)
        {
            cout << arr[i].name << " " << arr[i].score << endl;
        }
        cout << "Round " << n << " : winner : "<< wname << " " << wscore;
        f = 1;
        n--;
    }
    //cout << wname;
    return 0;
}
