#include "core_numeric.h"

int main(){

    core_numeric::add(2,3);
    core_numeric::add(1.5,2.5);

    // core_numeric::add("hola","mundo");
    // ERROR: const char* no cumple Addable

    // core_numeric::count_elements(5);
    // ERROR: int no cumple Iterable
}