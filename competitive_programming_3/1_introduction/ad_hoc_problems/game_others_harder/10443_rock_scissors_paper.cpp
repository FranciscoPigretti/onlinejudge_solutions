#include <iostream> // cin, cout
#include <cstdio>   // scanf, printf
#include <cmath>    // ceil(x)
#include <utility> // swap


using namespace std;

int main()
{
    int testCases;
    scanf("%d\n", &testCases);

    
    int r, c, n;

    while (testCases--)
    {
        scanf("%d %d %d\n", &r, &c, &n);
        char board_pre[r][c];
        char board_post[r][c];

         

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%c", &board_pre[i][j]);
            }
            scanf("\n");
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board_post[i][j] = board_pre[i][j];          
                if (board_pre[i][j] == 'R' ) {                    
                    if ( i > 0 &&  board_pre[i-1][j] == 'P' ) {
                        board_post[i][j] = 'P';
                    }
                    if (j > 0 && board_pre[i][j-1] == 'P') {
                        board_post[i][j] = 'P';
                    }
                    if ((i < r-2) && board_pre[i+1][j] == 'P') {
                        board_post[i][j] = 'P';
                    }
                    if ((j < c-2) && board_pre[i][j+1] == 'P') {
                        board_post[i][j] = 'P';
                    }
                }
                if (board_pre[i][j] == 'S') {
                    if ( i > 0 &&  board_pre[i-1][j] == 'R' ) {
                        board_post[i][j] = 'R';
                    }
                    if (j > 0 && board_pre[i][j-1] == 'R') {
                        board_post[i][j] = 'R';
                    }
                    if ((i < r-2) && board_pre[i+1][j] == 'R') {
                        board_post[i][j] = 'R';
                    }
                    if ((j < c-2) && board_pre[i][j+1] == 'R') {
                        board_post[i][j] = 'R';
                    }
                }
                if (board_pre[i][j] == 'P') {
                    
                }
                std::swap(board_pre, board_post);

            }
        }


         for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << board_post[i][j]; 
            }
            cout << endl;
        }

    }
}