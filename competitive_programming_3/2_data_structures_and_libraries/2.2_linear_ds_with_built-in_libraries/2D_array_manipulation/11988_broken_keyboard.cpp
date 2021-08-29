#include <list>
#include <iostream> // cin, cout
using namespace std;

int main() {

	std::list<char> my_list = { };
    std::list<char>::iterator it;

    it = my_list.begin();

    char actual;
    while (scanf("%c", &actual) >= 0) {
        if (actual == '[') {
            it = my_list.begin();
            continue;
        }
        if (actual == ']') {
            it = my_list.end();
            continue;
        }           
        if (actual == '\n') {
            for (auto& x: my_list)
                cout << x;
            cout << endl;
            my_list = {};
            it = my_list.begin();
            continue;
        }
        my_list.insert(it, actual);  
    }
}