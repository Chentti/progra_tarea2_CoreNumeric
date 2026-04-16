#include <iostream>
#include <vector>
#include "core_numeric.h"

using namespace std;

int main(){

    vector<int> a{1,2,3};
    vector<double> b{1,2,3};

    cout << core_numeric::mean(a) << endl;
    cout << core_numeric::mean(b) << endl;


    // vector<string> s{"a","b"};
    // core_numeric::mean(s);
    // ERROR: string no cumple Divisible
    // vector<char> c{'a','b','c'};
    // core_numeric::mean(c);
    // ERROR: char no cumple Divisible (char/char retorna int)
}