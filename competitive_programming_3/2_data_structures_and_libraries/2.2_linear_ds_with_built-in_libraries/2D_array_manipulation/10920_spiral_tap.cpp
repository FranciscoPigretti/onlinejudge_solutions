#include <iostream>  // cin, cout
#include <cstdio>    // scanf, printf
#include <cmath>     // sqrt(x), ceil(x)
#include <algorithm> // erase, all_of
using namespace std;

int main()
{  
    long SZ, P;         

    while ( scanf("%ld %ld", &SZ, &P), (SZ || P) ) {
        long x = 0, y = 0;

        // Inits:
        x = floor((double)SZ / 2) + 1;
        y = x;
       
        long raiz = floor(sqrt((double)P));
        // si es par, menos 1. raiz_impar
        long raiz_impar;
        if ( raiz % 2 == 0) {
            raiz_impar = raiz - 1;
        } else {
            raiz_impar = raiz;
        }
        long proximo_borde = raiz_impar + 1;
                     

        // Centro + 1 por cada "alejamiento":
        long raiz_sobre_2_floor = floor((double)raiz_impar/2);
        x = x + raiz_sobre_2_floor;
        y = y + raiz_sobre_2_floor;
         
        long spiral_edge = raiz_impar*raiz_impar;

        // 4 veces como maximo:       
        long resto = P - (raiz_impar*raiz_impar); 
        if ( resto == 0) {
            std::cout << "Line = " << y << ", column = " << x << "." << endl;
            continue;
        }
        // 1 arriba
        y++;
        resto--;
        if ( resto == 0) {
            std::cout << "Line = " << y << ", column = " << x << "." << endl;
            continue;
        }
        // left
        if (resto > proximo_borde-1) {
            resto = resto - proximo_borde + 1;
            x = x - proximo_borde + 1;
        } else {
            x = x - resto;
            std::cout << "Line = " << y << ", column = " << x << "." << endl;
            continue;
        }        
        // down
        if (resto > proximo_borde) {
            resto = resto - proximo_borde;
            y = y - proximo_borde;
        } else {
            y = y - resto;
            std::cout << "Line = " << y << ", column = " << x << "." << endl;
            continue;
        }
        // right
        if (resto > proximo_borde) {
            resto = resto - proximo_borde;
            x = x + proximo_borde;
        } else {
            x = x + resto;
            std::cout << "Line = " << y << ", column = " << x << "." << endl;
            continue;
        }
        // up
        if (resto > proximo_borde) {
            // no debería pasar
            resto = resto - proximo_borde;
            y = y + proximo_borde;
        } else {
            y = y + resto;
            std::cout << "Line = " << y << ", column = " << x << "." << endl;
            continue;
        }
        
    }   
}