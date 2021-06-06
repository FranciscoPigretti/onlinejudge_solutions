/*
$ compilar y correr:
$ PROBLEM=11498_division_of_nlogonia
$ g++ -o ${PROBLEM}.out -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE ${PROBLEM}.cpp && ./${PROBLEM}.out < ${PROBLEM}.txt 
*/

#include <iostream> // cin, cout
#include <cstdio> // scanf, printf
#include <string>

using namespace std;

int main()
{
    int numberOfQueries, a, b, divPointX, divPointY, residenceX, residenceY;

    while(scanf("%d", &numberOfQueries), numberOfQueries) { // escaneo y chequeo que no sea 0
		scanf("%d %d", &divPointX, &divPointY); // division point
		
		while (numberOfQueries--) {
			scanf("%d %d", &residenceX, &residenceY); // division point

			string result = "";	

			if (residenceY > divPointY) {
				result = "N";
			} else if (residenceY < divPointY)
			 	result = "S";
			else { 
				printf("divisa\n");
				continue;	
			}


			if (residenceX > divPointX) {
				result = result.append("E");	
 			} else if (residenceX < divPointX) {
				result = result.append("O");
			} else {
				printf("divisa\n");
				continue;	
			}
			printf("%s\n", result.c_str());  // ojo con esto del c_str. Sino usar cout
		}
	}
}
 
