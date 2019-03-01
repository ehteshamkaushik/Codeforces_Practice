#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int m,n;
    char C;
    cin >> m >> n>> C;
    char office[m][n];
    vector<int> r;
    vector <int> c;
    int count= 0;
    set<char> color;
    color.insert(C);
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> office[i][j];
            if(office[i][j] == C)
            {
                count++;
                r.push_back(i);
                c.push_back(j);
            }
        }
    }
    for(int i = 0; i < count; i++)
    {
        int row = r[i];
        int col = c[i];
        cout << "Checking cell : " << row << " " << col << " char : " << office[row][col] << endl;
        if(row != 0)
        {
            if(office[row-1][col] != '.')
                color.insert(office[row-1][col]);
        }
        if(col != 0)
        {
            if(office[row][col-1] != '.')
                color.insert(office[row][col-1]);
        }
        if(row != m-1)
        {
            if(office[row+1][col] != '.')
                color.insert(office[row+1][col]);
        }
        if(col!= n-1)
        {
            if(office[row][col+1] != '.')
                color.insert(office[row][col+1]);
        }
    }
    set<char> :: iterator it;
    for(it = color.begin(); it != color.end(); ++it)
        cout << *it << " ";
    cout << endl;
    int ans = color.size()-1;
    cout << ans;
    return 0;
}
