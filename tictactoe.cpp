#include <iostream>
using namespace std;

int winner(char board[3][3], char mark)
{
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3; j++)
//    {
//        cout<< board[i][j];
//    }
//    cout << endl;
//    }

    if((board[0][0] == mark) && (board[0][1] == mark) && (board[0][2] == mark))
    {
       // cout << "returning\n";
        return 1;
    }
    if((board[1][0] == mark) && (board[1][1] == mark) && (board[1][2] == mark))
        return 1;
    if((board[2][0] == mark) && (board[2][1] == mark) && (board[2][2] == mark))
        return 1;
    if((board[0][0] == mark) && (board[1][0] == mark) && (board[2][0] == mark))
        return 1;
    if((board[0][1] == mark) && (board[1][1] == mark) && (board[2][1] == mark))
        return 1;
    if((board[0][2] == mark) && (board[1][2] == mark) && (board[2][2] == mark))
        return 1;
    if((board[0][0] == mark) && (board[1][1] == mark) && (board[2][2] == mark))
        return 1;
    if((board[2][0] == mark) && (board[1][1] == mark) && (board[0][2] == mark))
        return 1;
    return 0;
}

int main()
{
    char board[3][3];
    int cross,naught,dot;
    cross = naught = dot = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            char b;
            cin >> b;
            board[i][j] = b;
            if(b == 'X')
                cross++;
            else if(b == '0')
                naught++;
            else
                dot++;
        }
    }
//    cout << "Cross : " << cross << " naught : " << naught << " DOT : " << dot << endl;
    if(cross - naught > 1 || cross < naught)
        cout << "illegal\n";
    else if(winner(board, 'X') == 1 && (cross - naught) != 1)
        cout << "illegal\n";
    else if(winner(board, '0') == 1 && (cross != naught))
        cout << "illegal\n";
    else if(winner(board, 'X'))
        cout << "the first player won\n";
    else if(winner(board, '0'))
        cout << "the second player won\n";
    else if(dot == 0)
        cout << "draw\n";
    else if(cross-naught == 1)
        cout << "second";
    else
        cout << "first";
    return 0;
}
