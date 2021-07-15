#include <iostream> // cin, cout
#include <cstdio>   // scanf, printf
#include <cmath>    // ceil(x)
#include <ctype.h> // isdigit(x), isalpha(x)
#include <algorithm> // fill


#define toDigit(c) (c-'0')


using namespace std;



char board[8][8];

void initBoard() {
    for (int y = 0; y <= 7; y++) 
        for (int x = 0; x <= 7; x++) 
            board[x][y] = '_';
}

void printBoard() {
    for (int y = 0; y <= 7; y++) {
        for (int x = 0; x <= 7; x++) cout << board[x][y];
        cout << endl;
    }
}

void attack(int x, int y)
{
    if (x >= 0 && x <= 7 && y >= 0 && y <= 7) {
        if (board[x][y] == '_') {
            board[x][y] = 'x';
        }
    }
}


bool isOccupied(int x, int y) {
    return isalpha(board[x][y]);
}

void rookAttack(int x, int y) {
    int i = x;
    int j = y;    
    // North
    for(int i = y -1; i>= 0; i--) {
        if (isOccupied(x,i)) {
            break;
        } else {
            board[x][i] = '*';
        }
    }
}

void calculateAttacks() {
    for (int y = 0; y <= 7; y++) {
        for (int x = 0; x <= 7; x++) {
            if (board[x][y] == 'r' || board[x][y] == 'R') rookAttack(x,y);
        }        
    }
}




int main()
{
    char scaned;

    initBoard();
    int x = 0, y = 0;

    while(scanf("%c", &scaned) != EOF) {
        if (scaned == '\n') {
            cout << "Calculando board... imprimir y reiniciar." << endl;
            printBoard();
            cout << "Calculando board... imprimir y reiniciar." << endl;
            calculateAttacks();
            printBoard();
            initBoard();
            x = 0;
            y = 0;
        } else {
            // cout << "Armando board..." << endl;
            if (isdigit(scaned)) {
                x = x + toDigit(scaned);
            } else if (isalpha(scaned)) {
                board[x][y] = scaned;
                x = x + 1;
            } else { // es '/'
                x = 0;
                y = y + 1;
            }
        }
    };



    cout << "Armando último board..." << endl;
    printBoard();
    




}