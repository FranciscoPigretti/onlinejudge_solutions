/*
$ compilar y correr:
$ PROBLEM=11172_relational_operator
$ g++ -o ${PROBLEM}.out -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE ${PROBLEM}.cpp && ./${PROBLEM}.out < ${PROBLEM}.txt 
*/

#include <iostream> // cin, cout
#include <cstdio> // scanf, printf
using namespace std;

int main()
{
    int TC, a, b;
    scanf("%d", &TC); // number of test cases
    while (TC--) { // shortcut to repeat until 0 | 5 7
        scanf("%d %d", &a, &b); // compute answer | 6 3

        if (a > b) {
            printf(">\n");
        } else if (a < b) {
            printf("<\n");
        } else {
            printf("=\n");
        }
    }
}