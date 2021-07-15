/*
$ compilar y correr:
$ g++ -o 00272_tex_quotes.out -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE 00272_tex_quotes.cpp && ./00272_tex_quotes.out < 00272_tex_quotes.txt 
*/


#include <iostream> // cin, cout
#include <cstdio> // scanf, printf
#include "bits/stdc++.h"  // acos

//using namespace std;

int N; 

int main()
{

    //char line[80];
    std::string line;
    
    //https://www.cplusplus.com/reference/cstdio/scanf/
    //scanf("%[^\n]", line);

    //https://www.cplusplus.com/reference/cstdio/fgets/
    //fgets(line, 80, stdin);

    //printf("El texto es: %s", line);

    bool first_found = false;

    while(std::getline(std::cin, line)) {
        // std::cout << line << std::endl;

        for (char const &c: line) {
            if (c == '"') {
                if (first_found) {
                    std::cout << "''";
                    first_found = false;
                }
                else {
                    std::cout << "``";
                    first_found = true;
                }
            }
            else {
                std::cout << c; 
            }            
        }

        std::cout << std::endl;
    }

}