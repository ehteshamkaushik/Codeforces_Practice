#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int d;
    cin >> d;
    for(int i = 0; i < d; i++)
    {
        int m , n;
        cin >> m;
        cin >> n;
        vector<int> v[m];
        int x,y,w,s;

        for(int j = 0; j < n; j++)
        {
            cin >> x >> y >> w;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cin >> s;

        int mark[m];
        for(int i = 0; i < m; i++)
            mark[i] = 0;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            for(int i = 0; i < v[u].size(); i++)
            {
                if(mark[v[u][i]] == 0)
                {
                    int a = v[u][i];
                    cout << "a is " << a << "\n";
                    mark[a] = 1;
                    Q.push(a);
                }
            }
        }
        int flag = 0;
        for(int i = 0; i < m; i++)
        {
            if(mark[i] == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            cout << "This district needs no new road\n";
        else
            cout << "This district needs new road(s)\n";
    }
}
