#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
private:
	int x;
	int y;

public:
	// Constructors
	vect2(int x = 0, int y = 0);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);
	~vect2();
	
	// Access operators
	int& operator[](int index);
	const int& operator[](int index) const;
	
	// Arithmetic operators
	vect2 operator+(const vect2& other) const;
	vect2 operator-(const vect2& other) const;
	vect2 operator*(int scalar) const;
	vect2 operator-() const;
	
	// Compound assignment operators
	vect2& operator+=(const vect2& other);
	vect2& operator-=(const vect2& other);
	vect2& operator*=(int scalar);
	
	// Increment/Decrement operators
	vect2& operator++();      // ++v (pre)
	vect2 operator++(int);    // v++ (post)
	vect2& operator--();      // --v (pre)
	vect2 operator--(int);    // v-- (post)
	
	// Comparison operators
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;
	
	// Output operator
	friend std::ostream& operator<<(std::ostream& os, const vect2& v);
	friend vect2 operator*(int scalar, const vect2& v);
};

#endif