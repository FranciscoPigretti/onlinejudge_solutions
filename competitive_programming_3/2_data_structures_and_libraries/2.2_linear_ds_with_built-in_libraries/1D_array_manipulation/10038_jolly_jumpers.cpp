#include <iostream>  // cin, cout
#include <cstdio>    // scanf, printf
#include <cmath>     // sqrt(x), ceil(x)
#include <algorithm> // erase, all_of
using namespace std;
bool DEBUG = true;

int main()
{  
    int n;     
    string line;

    while (scanf("%d", &n) != EOF) {
        // Caso borde:
        if (n == 1) {
            cout << "Jolly" << endl;
            getline(cin, line);
            continue;
        }
        // Inicializo array de booleanos:
        bool flags[n-1] = { false };
        int previous_digit;
        int current_digit;
        char end_of_line;

        scanf("%d", &previous_digit);
        // Voy escaneando, seteo en true la posición de la diferencia absoluta ( menos 1):
        while (scanf("%d%c", &current_digit, &end_of_line)) {
            int temp = abs(previous_digit - current_digit) - 1;
            flags[temp] = true;

            previous_digit = current_digit;
            if (end_of_line == '\n') break;
        }

        // Si son todos true, jolly!
        if (std::all_of(flags,(flags+n-1), [](bool i) { return i; })) {
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }   
}