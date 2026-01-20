#include "vect2.hpp"

// Constructor with default values
vect2::vect2(int x, int y) : x(x), y(y)
{
}

// Copy constructor
vect2::vect2(const vect2& other) : x(other.x), y(other.y)
{
}

// Assignment operator
vect2& vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return (*this);
}

// Destructor
vect2::~vect2()
{
}

// Access operator [] (non-const version)
int& vect2::operator[](int index)
{
	if (index == 0)
		return (x);
	return (y);
}

// Access operator [] (const version)
const int& vect2::operator[](int index) const
{
	if (index == 0)
		return (x);
	return (y);
}

// Addition
vect2 vect2::operator+(const vect2& other) const
{
	return (vect2(x + other.x, y + other.y));
}

// Subtraction
vect2 vect2::operator-(const vect2& other) const
{
	return (vect2(x - other.x, y - other.y));
}

// Multiplication by scalar (v * scalar)
vect2 vect2::operator*(int scalar) const
{
	return (vect2(x * scalar, y * scalar));
}

// Unary minus (negation)
vect2 vect2::operator-() const
{
	return (vect2(-x, -y));
}

// Compound addition
vect2& vect2::operator+=(const vect2& other)
{
	x += other.x;
	y += other.y;
	return (*this);
}

// Compound subtraction
vect2& vect2::operator-=(const vect2& other)
{
	x -= other.x;
	y -= other.y;
	return (*this);
}

// Compound multiplication
vect2& vect2::operator*=(int scalar)
{
	x *= scalar;
	y *= scalar;
	return (*this);
}

// Pre-increment (++v)
vect2& vect2::operator++()
{
	x++;
	y++;
	return (*this);
}

// Post-increment (v++)
vect2 vect2::operator++(int)
{
	vect2 temp(*this);
	++(*this);
	return (temp);
}

// Pre-decrement (--v)
vect2& vect2::operator--()
{
	x--;
	y--;
	return (*this);
}

// Post-decrement (v--)
vect2 vect2::operator--(int)
{
	vect2 temp(*this);
	--(*this);
	return (temp);
}

// Equality
bool vect2::operator==(const vect2& other) const
{
	return (x == other.x && y == other.y);
}

// Inequality
bool vect2::operator!=(const vect2& other) const
{
	return (!(*this == other));
}

// Output operator
std::ostream& operator<<(std::ostream& os, const vect2& v)
{
	os << "{" << v.x << ", " << v.y << "}";
	return (os);
}

// Multiplication by scalar (scalar * v)
vect2 operator*(int scalar, const vect2& v)
{
	return (vect2(v.x * scalar, v.y * scalar));
}