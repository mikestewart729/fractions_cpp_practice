#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
public:
    Fraction(int numerator, int denominator);

    void print() const;
    int getNumerator() const { return m_numerator; }
    int getDenominator() const { return m_denominator; }

    // friend functions for operator overloads
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, int value);
    friend Fraction operator*(int value, const Fraction& f1);

private:
    int m_numerator {};
    int m_denominator {1};

    void reduce();
};

#endif