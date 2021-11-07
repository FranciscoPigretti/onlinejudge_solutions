
#include <iostream> // cin, cout
#include <cstdio> // scanf, printf

#include <bitset> 

using namespace std;

int returnVal(char x)
{
    return (int) x - 65;
}

int main() {
    
    int test_cases;
    scanf("%d\n", &test_cases);
  
    while(test_cases--) {        

        int v = 0;
        int e = 0;
        bitset<26> bitset1;
        char a;
        char b;
        string line;

        while(scanf("(%c,%c)\n", &a, &b)) {
            bitset1.set(returnVal(a));
            bitset1.set(returnVal(b));
            e++;
            //  cout << a << b << endl;
        };
            
        getline(cin, line); // ***
        
        while(scanf("%c", &a) >= 0) {
            if (a == '\n') {
                break;
            } else if (a == ',') {
                // nada
            } else {
                v++;
                // cout << "something" << a << endl;
            }
        };

        int components =  v - e;
        int acorns = v - bitset1.count();
        int trees = components - acorns;

        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s)." << endl;


    }



}