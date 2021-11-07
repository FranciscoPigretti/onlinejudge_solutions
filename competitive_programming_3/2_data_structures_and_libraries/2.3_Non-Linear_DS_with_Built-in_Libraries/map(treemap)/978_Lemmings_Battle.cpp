#include <iostream> // cin, cout
#include <set>
#include <iterator>

using namespace std;


int main() {
    
    int test_cases;
    scanf("%d", &test_cases);

    int B, SG, SB, current;
    multiset <int, greater <int> > greens, blues;

    multiset <int, greater <int> > temp_greens, temp_blues;       
    
    multiset <int, greater <int> >::iterator g_it, b_it;


    while(test_cases--) {        
        int number_of_snowflakes;
        scanf("%d %d %d", &B, &SG, &SB);

        greens.clear();
        blues.clear();
        

        while(SG--) {
            scanf("%d", &current);
            greens.insert(current);
        }
        while(SB--) {
            scanf("%d", &current);
            blues.insert(current);
        }

        while(true) {
            for (int i = 0; i < B; i++) {
                // saco de cada uno si hay en ambos
                if (greens.size() > 0 && blues.size() > 0) {
                    g_it = greens.begin();
                    b_it = blues.begin();
                    int g = *g_it;
                    int b = *b_it;
                    greens.erase(g_it);
                    blues.erase(b_it);
                    int res = g - b;
                    if (res > 0) {
                        temp_greens.insert(res);
                    } else if (res < 0) {
                        temp_blues.insert(-res);
                    } else {
                        // empate
                    }
                } else {
                    break;
                }                
            }
            // vuelvo a insertar los ganadores
            for (auto x : temp_greens) {
                greens.insert(x);
            }
            for (auto x : temp_blues) {
                blues.insert(x);
            }
            temp_greens.clear();
            temp_blues.clear();
            // si hay en ambos sigo, sino devuelvo el ganador o empate
            if (greens.size() == 0 && blues.size() == 0) {
                cout << "green and blue died" << endl << endl;
                break;
            } else if (greens.size() == 0) {
                cout << "blue wins" << endl;
                for (auto x : blues) {
                    cout << x << endl;
                }
                if (test_cases != 0) {
                    cout << endl;
                }                
                break;
            } else if (blues.size() == 0) {
                cout << "green wins" << endl;
                for (auto x : greens) {
                    cout << x << endl;
                }
                if (test_cases != 0) {
                    cout << endl;
                }
                break;
            }
        }


    }

}