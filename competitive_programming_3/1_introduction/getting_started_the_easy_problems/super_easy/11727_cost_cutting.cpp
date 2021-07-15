/*
$ compilar y correr:
$ PROBLEM=11727_cost_cutting
$ g++ -o ${PROBLEM}.out -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE -Wno-unused-result ${PROBLEM}.cpp && ./${PROBLEM}.out < ${PROBLEM}.txt 
*/
#include <cstdio> // scanf, printf

int main()
{
    int numberOfTestCases, a, b, c, res, ncase;

    scanf("%d", &numberOfTestCases);

    ncase = 1;
    while (numberOfTestCases--) {
    	scanf("%d %d %d", &a, &b, &c);

    	if ((((a > b) &&  (a < c)) || ((a < b) &&  (a > c)))) { 
    		res = a;	
    	}

		if ((((b > a) &&  (b < c)) || ((b < a) &&  (b > c)))) { 
    		res = b;	
    	}    	

    	if ((((c > a) &&  (c < b)) || ((c < a) &&  (c > b)))) { 
    		res = c;	
    	}

    	printf("Case %d: %d\n", ncase, res);
    	ncase++;
    } 
}