#include "fraction.h"
#include <iostream>

int main() 
{
    Fraction f1 { 1, 4 };
    f1.print();

    Fraction f2 { 4, 0 };
    f2.print();

    return 0;
}