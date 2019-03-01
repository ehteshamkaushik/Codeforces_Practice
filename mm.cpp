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
                if(block[i] != 0)
                {
                    continue;
                }
                else
                {
                    int st = i;
                    int c = 0;
                    for(int j = st; j < n+st; j++)
                    {
                        if(block[j] != 0)
                        {
                            break;
                        }
                        c++;
                        i++;
                    }
                    if(c >= n)
                    {
                        count++;
                        for(int j = st; j < n+st; j++)
                        {
                            block[j] = count;
                        }
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
        }
        else if(cmnd[0] == 'e')
        {
            int n;
            cin >> n;
            if(n < 1)
            {
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
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
                    cout << "ILLEGAL_ERASE_ARGUMENT";
                }


            }
        }
        else
        {
            int index = 0;
            int temp[m];
            for(int i = 0; i < m; i++)
                temp[i] = 0;

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
        }
    }

    return 0;
}
