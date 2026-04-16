#include <iostream>
#include "core_numeric.h"

using namespace std;

int main(){

    cout << core_numeric::sum_variadic(1,2,33,4) << endl;
    cout << core_numeric::mean_variadic(0.1,2,3,4) << endl;
    cout << core_numeric::variance_variadic(1,2,3,4) << endl;
    cout << core_numeric::max_variadic(1,2.7,3,4) << endl;
}