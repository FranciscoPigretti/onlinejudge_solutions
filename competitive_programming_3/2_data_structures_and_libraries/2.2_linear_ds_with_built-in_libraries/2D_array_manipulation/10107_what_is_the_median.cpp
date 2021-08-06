#include <iostream>  // cin, cout
#include <cstdio>    // scanf, printf
#include <cmath>     // sqrt(x), ceil(x)
#include <algorithm> // erase, all_of
#include <climits> // INT_MAX
#include <vector>

using namespace std;

int main()
{  
    vector<int> v;
    int current;

    bool par = false;

    while (scanf("%d", &current) > 0) {
       
       v.push_back(current);

        if (par) {
            auto right = v.begin() + v.size()/2;
            auto left = v.begin() + v.size()/2 - 1;
            std::nth_element(v.begin(), left, v.end()); 
            int left_int = v[v.size()/2 - 1];
            std::nth_element(v.begin(), right, v.end()); 
            int right_int = v[v.size()/2] ;
            cout << (left_int + right_int)/2 << endl;
        } else {
            auto mid = v.begin() + v.size()/2;            
            std::nth_element(v.begin(), mid, v.end()); 
            cout << v[v.size()/2] << endl;        
        }
        par = !par;         
    }   
}