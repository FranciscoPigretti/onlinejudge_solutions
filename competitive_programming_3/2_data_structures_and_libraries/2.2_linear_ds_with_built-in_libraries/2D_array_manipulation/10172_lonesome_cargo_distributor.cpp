#include <list>
#include <iostream> // cin, cout
#include <stack>
#include <queue>

using namespace std;

int main() {

    int sets;
    int countries;
    int carrier_capacity;
    int platforms_B_capacity;

    scanf("%d", &sets);

    while (sets > 0) {
        sets--;
        // Build ring
        scanf("%d %d %d", &countries, &carrier_capacity, &platforms_B_capacity);
        
        std::queue<int> B_platfroms[countries]; 
        stack<int> carrier;
        
        int total_cargoes = 0;

        for (int i = 0; i < countries; i++) {
            int cargos;
            scanf("%d", &cargos);
            std::queue<int> new_queue;

            for (int j = 0; j < cargos; j++) {
                int cargo;
                scanf("%d", &cargo);
                new_queue.push(cargo-1);
                total_cargoes++;
            }
            B_platfroms[i] = new_queue;        
        }

        int i = 0;
        int time = 0;
        int dispatched_cargoes = 0;
        // calculate time
        while (true) {
            // Descargar
            while (carrier.size() > 0) { // si tengo cosas
                if (carrier.top() == i) { // si estoy en el pais, la popeo
                    carrier.pop();
                    time++;
                    dispatched_cargoes++;                  
                }                    
                else 
                    // tengo que descargar en B mientras haya lugar
                    if (B_platfroms[i].size() < platforms_B_capacity) {
                        B_platfroms[i].push( carrier.top());
                        carrier.pop();
                        time++;
                    } else {
                        break; // no hay lugar para descargar. Paso a lo siguiente.
                    }                        
            }
            //check finish
            if (dispatched_cargoes == total_cargoes) {
                cout << time << endl;
                break;              
            }
                
            // Cargar (saco de B mientras haya y/o tenga espacio)
            while (B_platfroms[i].size() > 0 && carrier.size() < carrier_capacity) {
                carrier.push( B_platfroms[i].front() );
                B_platfroms[i].pop();                  
                time++;
            }
            // Go to next station:
            time++;
            time++;
            i++;
            i = i % countries;
        }
    }
}