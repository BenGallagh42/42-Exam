#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint {
private:
    std::string digits; // Store number as string (reversed: "123" = 321)

public:
    // Constructors
    bigint(unsigned long long n = 0);
    
    // Operators
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);
    bigint& operator++();      // ++a
    bigint operator++(int);    // a++
    
    bigint operator<<(const bigint& shift) const;  // digit shift left
    bigint operator>>(const bigint& shift) const;  // digit shift right
    bigint& operator<<=(const bigint& shift);
    bigint& operator>>=(const bigint& shift);
    
    bool operator<(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator>=(const bigint& other) const;
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    
    friend std::ostream& operator<<(std::ostream& os, const bigint& b);
};

#endif