#include "fraction.h"
#include <iostream>
#include <numeric>

void Fraction::reduce() 
{
    int g { std::gcd(m_numerator, m_denominator) };
    m_numerator /= g;
    m_denominator /= g;
    // Choose to conventionally make the denominator positive
    if (m_denominator < 0)
    {
        m_numerator *= -1;
        m_denominator *= -1;
    }
}

Fraction::Fraction(int numerator, int denominator)
    : m_numerator { numerator }
    , m_denominator { denominator }
{
    if (denominator == 0)
    {
        // Should maybe throw an exception? But we haven't learned exception handling
        // on learncpp.com at this point yet.
        std::cout << "Attempted to initialize a fraction with zero denominator!\n";
        std::cout << "Resetting the denominator to 1.\n";
        m_denominator = 1;
    }
    reduce();
}

void Fraction::print() const 
{
    std::cout << m_numerator << '/' << m_denominator << '\n';
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    // By returning a fraction using the constructor, we get reduce automatically
    int numerator { f1.m_numerator * f2.m_numerator};
    int denominator { f1.m_denominator * f2.m_denominator };

    return Fraction { numerator, denominator };
}

Fraction operator*(const Fraction& f1, int value)
{
    // Same considerations apply here about the reduce operation
    int numerator { f1.m_numerator * value };

    return Fraction { numerator, f1.m_denominator };
}

Fraction operator*(int value, const Fraction& f1)
{
    // Call the other Fraction * int operator with swapped arguments
    return f1 * value;
}