#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
public:
    Fraction(int numerator, int denominator);

    void print() const;

private:
    int m_numerator {};
    int m_denominator {1};

    void reduce();
};

#endif