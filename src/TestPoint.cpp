/*
g++ -c TestPoint.cpp Point.cpp
g++ -o testPoint TestPoint.o Point.o
 */
#include <iostream>
#include "Point.h"

int main(int argc, char const *argv[]) {
    Point p (11,12);
    Point  q (0,4);
    std::cout << "Difference        : " <<  p - q << std::endl;
    std::cout << "Somme             : " << p + q << std::endl;
    std::cout << "Produit Scalaire  : " << p * q << std::endl;
    std::cout << "Produit Vectoriel : " << (p ^ q) << std::endl;
    return 0;
}
