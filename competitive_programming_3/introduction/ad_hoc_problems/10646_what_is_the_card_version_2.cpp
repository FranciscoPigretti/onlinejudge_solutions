/*
(10-X1+1) + (10-X2+1) + (10-X3+1) + x1 + x2 + x3 = 33
*/

#include <iostream> // cin, cout
#include <cstdio>   // scanf, printf

using namespace std;

int main()
{
    string line;

    int numCase = 1;
    int testCases;
    scanf("%d\n", &testCases);

    while (testCases--)
    {
        int respuesta = 33;

        char face;
        char suite;

        while (respuesta--)
            scanf("%c%c ", &face, &suite);

        cout << "Case " << numCase << ": " << face << suite << endl;
        numCase++;

        getline(cin, line);
    }
}