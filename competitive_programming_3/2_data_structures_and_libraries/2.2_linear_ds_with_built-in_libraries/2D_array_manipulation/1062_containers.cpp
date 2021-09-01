#include <list>
#include <iostream> // cin, cout
#include <stack>

using namespace std;


int main() {

	std::list<stack<char>> my_stacks = {};

    char char_read;
    bool stacked;
    int caso = 1;

    while (scanf("%c", &char_read) >= 0) {
        stacked = false;
        if (char_read == '\n') {
            // print and reset
            cout << "Case " << caso << ": " << my_stacks.size() << endl;
            caso++;
            my_stacks = {};
        } else if (char_read == 'e') {
            break;
        } else {
            list<stack<char>>::iterator i;
            for (i = my_stacks.begin(); i != my_stacks.end(); ++i) {
                if (char_read <= i->top()) {
                    i->push(char_read);
                    stacked = true;
                    break;
                } 
            }                        
            
            if (!stacked) {
                stack<char> new_stack;
                new_stack.push(char_read);
                my_stacks.emplace_back(new_stack);
            }            
        }     
    }
}