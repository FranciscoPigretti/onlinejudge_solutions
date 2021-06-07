#include <iostream> // cin, cout
#include <cstdio>   // scanf, printf
#include <deque>

using namespace std;

struct Card
{
    char face;
    char suite;
    Card(char a_face, char a_suite) : face(a_face), suite(a_suite) {}
};

int main()
{
    int Y;
    int X;

    string line;

    int throwAway;
    int numCase = 1;

    int testCases;
    scanf("%d\n", &testCases);

    int rounds;

    while (testCases--)
    {

        deque<Card> pila;
        int pila_inicial = 27;
        int num_mano = 25;

        // Lleno la pila con las primeras 27 cartas:
        while (pila_inicial--)
        {

            char face;
            char suite;

            scanf("%c%c ", &face, &suite);

            pila.push_front(Card(face, suite));
        }

        // Juego 3 rondas:
        Y = 0;
        rounds = 3;
        while (rounds--)
        {
            Card &carta = pila.front();

            if (carta.face == 'A' || carta.face == 'T' || carta.face == 'J' || carta.face == 'Q' || carta.face == 'K')
                X = 10;
            else
                X = carta.face - '0'; // Hack para castear a int.

            Y += X;
            throwAway = 10 - X + 1;

            while (throwAway--)
                pila.pop_front();
        }

        // Agregar el resto de las cartas:
        while (num_mano--)
        {
            char face;
            char suite;

            scanf("%c%c ", &face, &suite);

            pila.push_front(Card(face, suite));
        }

        // Busco la Y desde abajo:
        Y--;
        while (Y--)
        {
            pila.pop_back();
        }

        cout << "Case " << numCase << ": " << pila.back().face << pila.back().suite << endl;
        numCase++;
    }
}