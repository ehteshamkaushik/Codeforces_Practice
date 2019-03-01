#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;


int main()
{
    vector<int> board[64];
    board[0].push_back(1);
    board[0].push_back(8);
    board[0].push_back(9);
    board[7].push_back(6);
    board[7].push_back(14);
    board[7].push_back(15);
    board[56].push_back(48);
    board[56].push_back(49);
    board[56].push_back(57);
    board[63].push_back(62);
    board[63].push_back(55);
    board[63].push_back(54);
    for(int i = 8; i <= 48; i+=8)
    {
        board[i].push_back(i-8);
        board[i].push_back(i-7);
        board[i].push_back(i+1);
        board[i].push_back(i+8);
        board[i].push_back(i+9);
    }
    for(int i = 15; i <= 55; i+=8)
    {
        board[i].push_back(i-8);
        board[i].push_back(i-9);
        board[i].push_back(i-1);
        board[i].push_back(i+8);
        board[i].push_back(i+7);
    }
    for(int i = 1; i <= 6; i++)
    {
        board[i].push_back(i-1);
        board[i].push_back(i+1);
        board[i].push_back(i+7);
        board[i].push_back(i+8);
        board[i].push_back(i+9);
    }
    for(int i = 57; i <= 62; i++)
    {
        board[i].push_back(i-1);
        board[i].push_back(i+1);
        board[i].push_back(i-7);
        board[i].push_back(i-8);
        board[i].push_back(i-9);
    }
    for(int i = 1; i <= 6; i++)
    {
        for(int j = 1; j <=6; j++)
        {
            board[i*8+j].push_back((i*8+j)+1);
            board[i*8+j].push_back((i*8+j)-1);
            board[i*8+j].push_back((i*8+j)+7);
            board[i*8+j].push_back((i*8+j)+8);
            board[i*8+j].push_back((i*8+j)+9);
            board[i*8+j].push_back((i*8+j)-7);
            board[i*8+j].push_back((i*8+j)-8);
            board[i*8+j].push_back((i*8+j)-9);
        }
    }
    char c;
    int x;
    cin >> c >> x;
    int s = (c-'a')*8+(x-1);
    cin >> c >> x;
    int d = (c-'a')*8+(x-1);


    int parent[64];
    int visited[64];
    for(int i = 0; i < 64; i++)
    {
        parent[i] = -1;
        visited[i] = 0;
    }
    queue<int> q;
    visited[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < board[u].size(); i++)
        {
            int v = board[u][i];
            if(visited[v] == 0)
            {
                visited[v] = 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }


//    for(int i = 0; i < 64; i++)
//    {
//        cout << "parent of " << i << " is " << parent[i] << endl;
//    }
    int t = d;
    int count = 0;
    stack<int> path;
    while(parent[t] != -1)
    {
        count++;
        path.push(t);
        t = parent[t];
    }

    cout << count << endl;
    for(int i = 0; i < count; i++)
    {
        int p = path.top();
        path.pop();
        int dif = s-p;

        switch(dif)
        {
        case 1:
            cout << "D\n";
            break;
        case -1:
            cout << "U\n";
            break;
        case 8:
            cout << "L\n";
            break;
        case -8:
            cout << "R\n";
            break;
        case 7:
            cout << "LU\n";
            break;
        case -7:
            cout << "RD\n";
            break;
        case 9:
            cout << "LD\n";
            break;
        case -9:
            cout << "RU\n";
        }
        s = p;
    }

//for(int i = 0; i < 64; i++)
//{
//    cout << i << " --> ";
//    for(int j = 0; j < board[i].size(); j++)
//    {
//        int v = board[i][j];
//        cout << v << " --> ";
//    }
//    cout << endl;
//}

    return 0;

}
