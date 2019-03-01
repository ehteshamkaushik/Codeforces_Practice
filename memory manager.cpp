#include <iostream>


using namespace std;

int main()
{
    int t, m;
    cin >> t >> m;
    int block[m];
    for(int i = 0; i < m; i++)
    {
        block[i] = 0;
    }
    int memory[101];
    int start[101];
    for(int i = 1; i < 101; i++)
    {
        memory[i] = 0;
        start[i] = -1;
    }
    int curr = 0;
    int count = 0;
    for(int i = 0; i < t; i++)
    {
        string cmnd;
        cin >> cmnd;
        if(cmnd[0] == 'a')
        {
            int n;
            cin >> n;
            int f = 0;

            for(int i = 0; i < m; i++)
            {
                cout << "checking :::: \n";
                if(block[i] != 0)
                {
                    cout << "got nonzero at : " << i << " continuing\n";
                    continue;
                }
                else
                {
                    cout << "Got 0 at : " << i << " checking further \n";
                    int st = i;
                    int c = 0;
                    cout << "starting from : " << st << endl;
                    for(int j = st; j < n+st; j++)
                    {
                        cout << "checking : " << j << endl;
                        if(block[j] != 0)
                        {
                            cout << "got nonzero at : " << j << " continuing\n";
                            break;
                        }
                        cout << "got: " << n << " \n";
                        c++;
                        i++;
                    }
                    if(c >= n){
                    cout << "found place at : " << st << endl;
                    count++;
                    for(int j = st; j < n+st; j++)
                    {
                        block[j] = count;
                    }
                    memory[count] = n;
                    start[count] = st;
                    f = 1;
                    break;
                    }
                }
            }
            if(f == 0)
            {
                cout << "NULL\n";
            }
            else
            {
                cout << count << endl;
            }
            for(int i = 0; i < m; i++)
            {
                cout << block[i] << " " ;
            }
            for(int i = 1; i <= count; i++)
            {
                cout << "\nmemory : " << i << " size: " << memory[i] << " starting index : " << start[i] << endl;
            }
        }
        else if(cmnd[0] == 'e')
        {
            int n;
            cin >> n;
            if(n < 1)
            {
                cout << "error\n";
            }
            else
            {
                int c = 0;
                for(int i = 0; i < m; i++)
                {
                    if(block[i] == n)
                    {
                        block[i] = 0;
                        c++;
                    }
                }
                if(c == 0)
                {
                    cout << "error";
                }
            }

            cout << endl;
            for(int i = 0; i < m; i++)
            {
                cout << block[i] << " " ;
            }
            for(int i = 1; i <= count; i++)
            {
                cout << "\nmemory : " << i << " size: " << memory[i] << " starting index : " << start[i] << endl;
            }
        }
        else
        {
            int index = 0;
            int temp[m];
            for(int i = 0; i < m; i++)
                temp[i] = 0;

            cout << endl;
            for(int i = 0; i < m; i++)
            {
                if(block[i] != 0)
                {
                    temp[index] = block[i];
                    index++;
                }
            }
            for(int i = 0; i < m; i++)
            {
                block[i] = temp[i];
            }

            cout << endl;
            for(int i = 0; i < m; i++)
            {
                cout << block[i] << " " ;
            }
            for(int i = 1; i <= count; i++)
            {
                cout << "\nmemory : " << i << " size: " << memory[i] << " starting index : " << start[i] << endl;
            }
        }
    }

    return 0;
}
