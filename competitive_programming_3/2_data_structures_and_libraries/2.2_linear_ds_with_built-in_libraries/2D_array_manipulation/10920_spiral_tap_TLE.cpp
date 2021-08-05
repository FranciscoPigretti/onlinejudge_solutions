#include <iostream>  // cin, cout
#include <cstdio>    // scanf, printf
#include <cmath>     // sqrt(x), ceil(x)
#include <algorithm> // erase, all_of
using namespace std;
bool DEBUG = true;


int x = 0, y = 0;

std::string directions[4] = { "up", "left", "down", "right" };
int direction_index = 0;

int twice = 0;

int main()
{  
    int SZ, P;       
    

    while ( scanf("%d %d", &SZ, &P), (SZ || P) ) {
        // Inits:
        x = floor((float)SZ / 2);
        y = x;
        direction_index = 0;
        int step = 1;
        int step_counter = 0;
        int twice = 0;

         

        for (int i = 0; i < P; i++) {
            
            // move
            if (directions[direction_index] == "up") {
                y++;
            }
            if (directions[direction_index] == "left") {
                x--;
            }
            if (directions[direction_index] == "down") {
                y--;
            }
            if (directions[direction_index] == "right") {
                x++;
            }

            // 
            step_counter++;
            if (step_counter == step) {
                // cambio de dirección
                direction_index = (direction_index + 1) % 4;
                step_counter = 0;
                twice++;
                if (twice == 2) {
                    step++;
                    twice = 0;
                }
            }
            

        }


       cout << "Line = " << y + 1 << ", column = " << x + 1  << "." << endl;
    }   
}