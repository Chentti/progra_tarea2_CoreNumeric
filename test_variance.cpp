#include <iostream>
#include <vector>
#include "core_numeric.h"

using namespace std;

int main(){

    vector<int> a{1,2,3};
    vector<double> b{1,2,3};

    cout << core_numeric::variance(a) << endl;
    cout << core_numeric::variance(b) << endl;

    // vector<string> s{"a","b"};
    // core_numeric::variance(s);
    // ERROR: string no cumple Subtractable
}