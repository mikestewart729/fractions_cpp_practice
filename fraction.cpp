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