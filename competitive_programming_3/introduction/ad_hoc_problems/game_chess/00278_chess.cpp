/*
knights
        
|k|x|k|            |k|k|4
|x|k|x|            |k|k|         |k|k|k|3   |k|k|2       |k|1
|k|x|k| 5

|k| |k| |          |k|k|
| |k| |k|          |k|K| 
|k| |k| |6         | | |      


|k| |k| |
| |k| |k|
|k| |k| |
| |k| |k|
_______________
|k| | | | | | |
| |k| | | | | |
|k| |k| | | | |
| |k| |k| | | |
|k| |k| |k| | |
| |k| |k| |k| |
|k| |k| |k| |k|
| |k| |k| |k| |

menor + k(n -2) + k(m-2)

__________
|k|x| |x| | | | |
|x|k|x| |x| | | |
| |x|k|x| |x| | |
|x| |x|k|x| |x| |
| |x| |x|k|x| |x|
| | |x| |x|k|x| |
| | | |x| |x|k|x|
| | | | |x| |x|k|

3*8 da 12

3*2

diag + 2*(diag-2)       // 7+ 10 + 6 + 2 = 25   
                                

Lo completo y después le saco?


__________
|k|k|k|k|k|
|x|x|x|x|x|
|x|x|x|x|x|
| | | | | |

__________
|k|x|x| | |
|k|x|x| | |
|k|x|x| | |
|k|x|x| | |

Del más grande, le saco 3.
Si alguno es menor a 3, devuelvo el más grande.
-------------------------------------------
_________
|Q|x|x|x|
|x|x| | |
|x| |x| |
|x| | |x|

5x4 -> 3x3 (del mayor se sacan 2)
___________
|Q|x|x|x|x|
|x|x|Q|x|x|     | | | |
|x|x|x|x| |     | | | |
|x| |x|x|x|     | | | |
| | | | | |
| | | | | |

___________
|K|x|K| |K|
|x|x| | | |
|K| |K| | | 
| | | | | |

n/2 celing * m/2 ceiling?


*/

#include <iostream> // cin, cout
#include <cstdio>   // scanf, printf
#include <cmath>    // ceil(x)

using namespace std;

int knights(int n, int m)
{
    int menor = (n < m) ? n : m;

    int count = menor;

    for (int i = n - 2; i >= 1; i = i - 2)
    {
        count += i;
    }

    for (int i = m - 2; i >= 1; i = i - 2)
    {
        count += i;
    }

    return count;
}

int Kings(int n, int m)
{
    int a = ceil(n / 2);
    int b = ceil(m / 2);
    return a * b;
}

int Queens(int &n, int &m)
{
    int menor = (n < m) ? n : m;
    int mayor = (m > n) ? m : n;

    if (mayor == 5)
    {
        return 5;
    }
    else if (menor == 1)
    {
        return 1;
    }
    else
    {
        if ((mayor == menor) || (mayor == menor + 1))
        {
            return mayor - 1;
        }
        else
        {
            return menor;
        }
    }
}

int main()
{
    int testCases;
    scanf("%d\n", &testCases);

    char chesspiece;
    int n, m;

    while (testCases--)
    {
        scanf("%c %d %d\n", &chesspiece, &n, &m);

        if (chesspiece == 'r')
        {
            cout << ((n < m) ? n : m) << endl;
        }
        if (chesspiece == 'k')
        {
            cout << knights(n, m) << endl;
        }
        if (chesspiece == 'Q')
        {
            cout << "Case " << n << " " << m << ":" ;
            int res = Queens(n, m);
            cout << res << endl;
        }
        if (chesspiece == 'K')
        {
            cout << Kings(n, m) << endl;
        }
    }
}