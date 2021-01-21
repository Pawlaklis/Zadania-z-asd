#include <iostream>
#include "ArrayClass.h"

int main() {
    ArrayClass A(25);

    A.create_random();

    std::cout << "Tablica: \n";
    A.print();
    std::cout << "Sortowanie przez wstawianie: \n";
    A.insertionSort();
    A.print();
    A.permutate();
    std::cout << "Sortowanie przez scalanie: \n";
    A.mergeSort();
    A.print();
    A.permutate();
    std::cout << "Sortowanie przez kopcowanie: \n";
    A.heapSort();
    A.print();





    return 0;
}
