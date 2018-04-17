#include<bits/stdc++.h>
using namespace std;

struct Move
{
    int row, col;
};

char player = 'x', opponent = 'o';


bool isMovesLeft(char board[6][7])
{
    for (int i = 0; i<6; i++)
        for (int j = 0; j<7; j++)
            if (board[i][j]=='_')
                return true;
    return false;
}
int evaluate(char board[6][7])
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row<6; row++)
    {
        for(int col=0;col<4;col++){
            if(board[row][col]==board[row][col+1] && board[row][col+2]==board[row][col+1] && board[row][col+2]==board[row][col+3]){
                if (board[row][col]==player)
                    return +100000;
                else if (board[row][col]==opponent)
                    return -100000;
            }
        }
    }
    // Checking for columns for X or O victory.
    for (int col = 0; col<7; col++)
    {
        for(int row=0;row<3;row++){
            if(board[row][col]==board[row+1][col] && board[row+1][col]==board[row+2][col] && board[row+2][col]==board[row+3][col]){
                if (board[row][col]==player)
                    return +100000;
                else if (board[row][col]==opponent)
                    return -100000;
            }
        }
    }
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]==board[3][3]){
        if(board[0][0]==player){
            return +100000;
        }
        else if(board[0][0]==opponent){
            return -100000;
        }
    }
    if(board[0][1]==board[1][2]&&board[0][1]==board[2][3]&&board[0][1]==board[3][4]){
        if(board[0][1]==player){
            return +100000;
        }
        else if(board[0][1]==opponent){
            return -100000;
        }
    }
    if(board[0][2]==board[1][3]&&board[0][2]==board[2][4]&&board[0][2]==board[3][5]){
        if(board[0][2]==player){
            return +100000;
        }
        else if(board[0][2]==opponent){
            return -100000;
        }
    }
    if(board[0][3]==board[1][4]&&board[0][3]==board[2][5]&&board[0][3]==board[3][6]){
        if(board[0][3]==player){
            return +100000;
        }
        else if(board[0][3]==opponent){
            return -100000;
        }
    }
    if(board[1][0]==board[2][1]&&board[1][0]==board[3][2]&&board[1][0]==board[4][3]){
        if(board[1][0]==player){
            return +100000;
        }
        else if(board[1][0]==opponent){
            return -100000;
        }
    }
    if(board[1][1]==board[2][2]&&board[1][1]==board[3][3]&&board[1][1]==board[4][4]){
        if(board[1][1]==player){
            return +100000;
        }
        else if(board[1][1]==opponent){
            return -100000;
        }
    }
    if(board[1][2]==board[2][3]&&board[1][2]==board[3][4]&&board[1][2]==board[4][5]){
        if(board[1][2]==player){
            return +100000;
        }
        else if(board[1][2]==opponent){
            return -100000;
        }
    }
    if(board[1][3]==board[2][4]&&board[1][3]==board[3][5]&&board[1][3]==board[4][6]){
        if(board[1][3]==player){
            return +100000;
        }
        else if(board[1][3]==opponent){
            return -100000;
        }
    }
    if(board[2][0]==board[3][1]&&board[2][0]==board[4][2]&&board[2][0]==board[5][3]){
        if(board[2][0]==player){
            return +100000;
        }
        else if(board[2][0]==opponent){
            return -100000;
        }
    }
    if(board[2][1]==board[3][2]&&board[2][1]==board[4][3]&&board[2][1]==board[5][4]){
        if(board[2][1]==player){
            return +100000;
        }
        else if(board[2][1]==opponent){
            return -100000;
        }
    }
    if(board[2][2]==board[3][3]&&board[2][2]==board[4][4]&&board[2][2]==board[5][5]){
        if(board[2][2]==player){
            return +100000;
        }
        else if(board[2][2]==opponent){
            return -100000;
        }
    }
    if(board[2][3]==board[3][4]&&board[2][3]==board[4][5]&&board[2][3]==board[5][6]){
        if(board[2][3]==player){
            return +100000;
        }
        else if(board[2][3]==opponent){
            return -100000;
        }
    }
    if(board[0][3]==board[1][2]&&board[0][3]==board[2][1]&&board[0][3]==board[3][0]){
        if(board[0][3]==player){
            return +100000;
        }
        else if(board[0][3]==opponent){
            return -100000;
        }
    }
    if(board[0][4]==board[1][3]&&board[0][4]==board[2][2]&&board[0][4]==board[3][1]){
        if(board[0][4]==player){
            return +100000;
        }
        else if(board[0][4]==opponent){
            return -100000;
        }
    }
    if(board[0][5]==board[1][4]&&board[0][5]==board[2][3]&&board[0][5]==board[3][2]){
        if(board[0][5]==player){
            return +100000;
        }
        else if(board[0][5]==opponent){
            return -100000;
        }
    }
    if(board[0][6]==board[1][5]&&board[0][6]==board[2][4]&&board[0][6]==board[3][3]){
        if(board[0][6]==player){
            return +100000;
        }
        else if(board[0][6]==opponent){
            return -100000;
        }
    }
    if(board[1][3]==board[2][2]&&board[1][3]==board[3][1]&&board[1][3]==board[4][0]){
        if(board[1][3]==player){
            return +100000;
        }
        else if(board[1][3]==opponent){
            return -100000;
        }
    }
    if(board[1][4]==board[2][3]&&board[1][4]==board[3][2]&&board[1][4]==board[4][1]){
        if(board[1][4]==player){
            return +100000;
        }
        else if(board[1][4]==opponent){
            return -100000;
        }
    }
    if(board[1][5]==board[2][4]&&board[1][5]==board[3][3]&&board[1][5]==board[4][2]){
        if(board[1][5]==player){
            return +100000;
        }
        else if(board[1][5]==opponent){
            return -100000;
        }
    }
    if(board[1][6]==board[2][5]&&board[1][6]==board[3][4]&&board[1][6]==board[4][3]){
        if(board[1][6]==player){
            return +100000;
        }
        else if(board[1][6]==opponent){
            return -100000;
        }
    }
    if(board[2][3]==board[3][2]&&board[2][3]==board[4][1]&&board[2][3]==board[5][0]){
        if(board[2][3]==player){
            return +100000;
        }
        else if(board[2][3]==opponent){
            return -100000;
        }
    }
    if(board[2][4]==board[3][3]&&board[2][4]==board[4][2]&&board[2][4]==board[5][1]){
        if(board[2][4]==player){
            return +100000;
        }
        else if(board[2][4]==opponent){
            return -100000;
        }
    }
    if(board[2][5]==board[3][4]&&board[2][5]==board[4][3]&&board[2][5]==board[5][2]){
        if(board[2][5]==player){
            return +100000;
        }
        else if(board[2][5]==opponent){
            return -100000;
        }
    }
    if(board[2][6]==board[3][5]&&board[2][6]==board[4][4]&&board[2][6]==board[5][3]){
        if(board[2][6]==player){
            return +100000;
        }
        else if(board[2][6]==opponent){
            return -100000;
        }
    }
    return 0;
}
int minimax(char board[6][7], int depth, bool isMax)
{
    int score = evaluate(board);

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 100000)
        return score-depth;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -100000)
        return score+depth;
    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(board)==false)
        return 0;
    if(depth==8){
        return score;
    }
    // If this maximizer's move
    if (isMax)
    {
        int best = -1000000;

        // Traverse all cells
        for (int j = 0; j<7; j++)
        {
            for (int i = 0; i<6; i++)
            {
                // Check if cell is empty
                if (board[i][j]=='_')
                {
                    // Make the move
                    board[i][j] = player;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                                minimax(board, depth+1, !isMax) );

                    // Undo the move
                    board[i][j] = '_';
                    break;
                }
            }
        }
        return best;
    }

        // If this minimizer's move
    else
    {
        int best = 1000000;

        // Traverse all cells
        for (int j = 0; j<7; j++)
        {
            for (int i = 0; i<6; i++)
            {
                // Check if cell is empty
                if (board[i][j]=='_')
                {
                    // Make the move
                    board[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                               minimax(board, depth+1, !isMax));

                    // Undo the move
                    board[i][j] = '_';
                    break;
                }

            }
        }
        return best;
    }
}

Move findBestMove(char board[6][7])
{
    int bestVal = -100000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;

    // Traverse all cells, evalutae minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int j = 0; j<7; j++)
    {
        for (int i = 0; i<6; i++)
        {
            // Check if celll is empty
            if (board[i][j]=='_')
            {
                // Make the move
                board[i][j] = player;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 1, false);

                // Undo the move
                board[i][j] = '_';

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
                break;
            }
        }
    }

    printf("The value of the best Move is : %d\n",
           bestVal);

    return bestMove;
}
int main()
{
    char board[6][7] =
            {
                    { '_', '_', '_', '_', '_', '_', '_' },
                    { '_', '_', '_', '_', '_', '_', '_' },
                    { '_', '_', '_', '_', '_', '_', '_' },
                    { '_', '_', '_', '_', '_', '_', '_' },
                    { '_', '_', '_', '_', '_', '_', '_' },
                    { '_', '_', '_', '_', '_', '_', '_' }
            };
    Move bestMove = findBestMove(board);
    printf("ROW: %d COL: %d\n", bestMove.row,
           bestMove.col );
    return 0;
}