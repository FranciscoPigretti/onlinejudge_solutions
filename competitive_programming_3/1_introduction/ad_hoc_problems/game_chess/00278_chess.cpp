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
    int a = ceil((float)n / 2);
    int b = floor((float)n / 2);
    int c = ceil((float)m / 2);
    int d = floor((float)m/2);

    return (a*c)+(b*d);   
}

int Kings(int n, int m)
{
    int a = ceil((float)n / 2);
    int b = ceil((float)m / 2);
    return a * b;
}

int Queens(int n, int m)
{
    return  (n < m) ? n : m;    
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
            // cout << "Case " << n << " " << m << ":" ;
            int res = Queens(n, m);
            cout << res << endl;
        }
        if (chesspiece == 'K')
        {
            cout << Kings(n, m) << endl;
        }
    }
}