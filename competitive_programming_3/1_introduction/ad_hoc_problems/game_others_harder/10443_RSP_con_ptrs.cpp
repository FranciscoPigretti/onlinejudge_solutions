#include <iostream> // cin, cout
#include <cstdio>   // scanf, printf
#include <cmath>    // ceil(x)

using namespace std;

bool DEBUG = false;

char** init_board(int r, int c) {
    char** array { new char*[r] }; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < r; ++count)
        array[count] = new char[c]; // these are our columns
    return array;
}

void print_board(char** ptrptr, int r, int c) {
    if (DEBUG) cout << "-------------------" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << ptrptr[i][j]; 
        }
        cout << endl;
    }
}

void scan_board(char** ptrptr, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%c", &ptrptr[i][j]);
        }
        scanf("\n");
    }
}

void play_one_step(char** board_pre, char** board_post, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            board_post[i][j] = board_pre[i][j];          
            if (board_pre[i][j] == 'R' ) {                    
                if (i > 0 &&  board_pre[i-1][j] == 'P' ) {
                    board_post[i][j] = 'P';
                }
                if (j > 0 && board_pre[i][j-1] == 'P') {
                    board_post[i][j] = 'P';
                }
                if ((i < r-1) && board_pre[i+1][j] == 'P') {
                    board_post[i][j] = 'P';
                }
                if ((j < c-1) && board_pre[i][j+1] == 'P') {
                    board_post[i][j] = 'P';
                }
            }
            if (board_pre[i][j] == 'S') {
                if (i > 0 &&  board_pre[i-1][j] == 'R' ) {
                    board_post[i][j] = 'R';
                }
                if (j > 0 && board_pre[i][j-1] == 'R') {
                    board_post[i][j] = 'R';
                }
                if ((i < r-1) && board_pre[i+1][j] == 'R') {
                    board_post[i][j] = 'R';
                }
                if ((j < c-1) && board_pre[i][j+1] == 'R') {
                    board_post[i][j] = 'R';
                }
            }
            if (board_pre[i][j] == 'P') {
                if ( i > 0 &&  board_pre[i-1][j] == 'S' ) {
                    board_post[i][j] = 'S';
                }
                if (j > 0 && board_pre[i][j-1] == 'S') {
                    board_post[i][j] = 'S';
                }
                if ((i < r-1) && board_pre[i+1][j] == 'S') {
                    board_post[i][j] = 'S';
                }
                if ((j < c-1) && board_pre[i][j+1] == 'S') {
                    board_post[i][j] = 'S';
                }
            }              
        }
    }
}

int main()
{
    int testCases;
    scanf("%d\n", &testCases);
    
    int r, c, n;

    while (testCases--)
    {
        scanf("%d %d %d\n", &r, &c, &n);
        char** board_pre = init_board(r,c);
        char** board_post = init_board(r,c);
         
        scan_board(board_pre, r, c);  
        if (DEBUG) print_board(board_pre, r, c);

        while(n--) {
            play_one_step(board_pre, board_post, r, c);
            if (DEBUG) print_board(board_post, r, c);
            std::swap(board_pre, board_post);
        }      

        print_board(board_pre, r, c); // printeo el pre pues los swapie        
        cout << endl;

    }
}