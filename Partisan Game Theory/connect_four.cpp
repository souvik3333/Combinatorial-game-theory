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

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000000;

        // Traverse all cells
        for (int i = 0; i<6; i++)
        {
            for (int j = 0; j<7; j++)
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
        for (int i = 0; i<6; i++)
        {
            for (int j = 0; j<7; j++)
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
    for (int i = 0; i<6; i++)
    {
        for (int j = 0; j<7; j++)
        {
            // Check if celll is empty
            if (board[i][j]=='_')
            {
                // Make the move
                board[i][j] = player;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(board, 0, false);

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
                    { '_', 'o', 'x', 'o', 'x', 'o', 'o' },
                    { '_', 'x', 'o','_', '_', '_','_' },
                    { '_', 'x', 'o','_', '_', 'o','x'  },
                    { '_', 'o', 'x','x', 'o', 'o','o' },
                    { '_', 'x', 'o','x', 'o', 'x','x'  },
                    { '_', 'o', 'o','x', 'o', 'o', 'o' }
            };
    Move bestMove = findBestMove(board);
    printf("ROW: %d COL: %d\n", bestMove.row,
           bestMove.col );
    return 0;
}