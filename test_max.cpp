#include <iostream>
#include <vector>
#include "core_numeric.h"
#include "modelos.h"

using namespace std;

int main(){

    vector<int> a{1,8,3};
    vector<double> b{1,2.7,0.3};
    vector<Coordenada> c{
        Coordenada(1),
        Coordenada(9),
        Coordenada(4)
    };

    vector<Vector3D> d{
        Vector3D(2),
        Vector3D(7),
        Vector3D(5)
    };

    vector<Esfera> e{
        Esfera(3),
        Esfera(8),
        Esfera(1)
    };

    cout << core_numeric::max(a) << endl;
    cout << core_numeric::max(b) << endl;
    cout << core_numeric::max(c).x << endl;
    cout << core_numeric::max(d).mag << endl;
    cout << core_numeric::max(e).radio << endl;

    // vector<string> s{"a","b"};
    // core_numeric::max(s);
    // ERROR: string no cumple Comparable
}