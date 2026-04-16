#include <iostream>
#include <vector>
#include "core_numeric.h"

using namespace std;

int main(){

    vector<double> v{1,2,3};

    cout << core_numeric::transform_reduce(v,
        [](double x){
            return x*x;
        }) << endl;
}