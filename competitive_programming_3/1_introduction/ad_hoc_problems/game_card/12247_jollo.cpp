/*
$ compilar y correr:
$ PROBLEM=11172_relational_operator
$ g++ -o ${PROBLEM}.out -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE ${PROBLEM}.cpp && ./${PROBLEM}.out < ${PROBLEM}.txt 

/*
EDIT: al final es más simple, ver el código.

En cada partida hay que mirar el peor caso, es decir, mi mejor carta contra su peor carta, y la X contra la menor que me gana. 

ABCXY  -> no necesito nada, gano siemrpe
ABXCY  -> una gano siempre. Puedo "gastar" Y con A, pero la otra la gano, necesito >B.
AXBCY -> una gano siempre. Puedo "gastar" Y con A, pero luego me gana, necesito >B.
XABCY -> idem anterior.

ABXYC -> Peor caso: le gana a Y con C, y luego gano una de las otras dos, necesito ganar la tercera con >B
AXBYC -> -1 y a partir de acá siempre es -1 porque no puedo asegurar la victoria
AXYBC -> -1 ...

c < y: (una victoria asegurada)
	c < x: segunda asegurada, listo, devuelvo la minima posible
	x < c:   
		b < x: 1 más que b
		x < b: 
			a < x: 1 más que c
			x < a: 1 más que c

b < y < c: 
	b < x: 1 más que b
	a < x < b: -1 
*/

#include <iostream> // cin, cout
#include <cstdio>	// scanf, printf
#include <array>
#include <algorithm> // sort

using namespace std;

array<int, 3> princesa;
array<int, 2> principe;

#define A princesa[0]
#define B princesa[1]
#define C princesa[2]

#define X principe[0]
#define Y principe[1]

int valorMayorPosibleQue(int valor)
{
	for (int i = valor + 1; i <= 52; i++)
	{
		if (i != A && i != B && i != C && i != X && i != Y)
			return i;
	}
	return -1;
}

int main()
{
	int a, b, c, x, y;

	while (scanf("%d %d %d %d %d", &a, &b, &c, &x, &y), (a || b || c || x || y))
	{
		princesa[0] = a;
		princesa[1] = b;
		princesa[2] = c;

		principe[0] = x;
		principe[1] = y;

		sort(princesa.begin(), princesa.end());
		sort(principe.begin(), principe.end());

		if (C < Y)
		{
			if (C < X)
				cout << valorMayorPosibleQue(0) << endl;
			else
			{
				if (B < X)
					cout << valorMayorPosibleQue(B) << endl;
				else
					cout << valorMayorPosibleQue(C) << endl;
			}
		}
		else
		{
			if (B < X) // resumido haxor de (B<X && B<Y)
				cout << valorMayorPosibleQue(B) << endl;
			else
				cout << "-1" << endl;
		}
	}
}

