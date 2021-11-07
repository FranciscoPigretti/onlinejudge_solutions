
#include <iostream>  // cin, cout
#include <vector>

using namespace std;

class UnionFind { // OOP style
    private: 
        vector<int> parent_of, rank_of; // remember: vi is vector<int>
    
    public:
    
    UnionFind(int N) { 
        rank_of.assign(N, 0);
        parent_of.assign(N, 0); for (int i = 0; i < N; i++) parent_of[i] = i; 
    }

    int findSet(int i) { 
        if (parent_of[i] == i) {
            return i;
        } else {
            int res = findSet(parent_of[i]);
            parent_of[i] = res;
            return res;
        }
    }        

    
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
    
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) { // if from different set
            int x = findSet(i), y = findSet(j);
            if (rank_of[x] > rank_of[y]) {
                parent_of[y] = x; // rank keeps the tree short
            } else { 
                parent_of[x] = y;
                if (rank_of[x] == rank_of[y]) rank_of[y]++; 
            }
        } 
    }
};
   


int main() {
    int test_cases;
    scanf("%d\n", &test_cases);
  
    int number_of_computers;


    while(test_cases--) {        
        scanf("%d\n", &number_of_computers);
        UnionFind my_network(number_of_computers);

        char command;
        int c1, c2;

        int successful  = 0, unsuccessful = 0;       

        char s[256];
        while (gets(s) && sscanf(s, "%c %d %d", &command, &c1, &c2) == 3) {       
            if (command == 'c') {
                my_network.unionSet(c1-1, c2-1);
            } else if (command == 'q') {
                if (my_network.isSameSet(c1-1, c2-1)) {
                    successful++;
                } else {
                    unsuccessful++;
                }
            } else {
                //space
            }
        }

        cout << successful << "," << unsuccessful << endl;   
        if (test_cases > 0) {
            cout << endl; 
        } else {
            int pepe = 1;
        }

        
    }
} 