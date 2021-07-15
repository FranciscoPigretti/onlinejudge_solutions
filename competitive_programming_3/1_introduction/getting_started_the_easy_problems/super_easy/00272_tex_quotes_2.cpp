/*
$ compilar:  g++ -o program source.cpp
$ correr: ./program
*/


//g++ -o program.out -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE source.cpp

// my first program in C++
#include <iostream> // cin, cout
#include <cstdio> // scanf, printf
#include "bits/stdc++.h"  // acos

//using namespace std;

int N; 

int main()
{
    std::string line;
    std::ifstream myfile;
    myfile.open("uva_00272_tex_sample_input.txt");

    while(getline(myfile, line)) {

        printf(line);
    }

}