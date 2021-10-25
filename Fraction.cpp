//Drew Childs
//wacmk9@mail.umkc.edu
//4/9/20
//CS201L Lab 11

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
}

istream& operator >> (istream& in, Fraction& fraction) {
	char divide;
	in >> fraction.numerator;
	in >> divide;
	in >> fraction.denominator;
	return in;
}

 ostream& operator << (ostream& out, const Fraction& fraction) {
	out << fraction.numerator << " / " << fraction.denominator;
	return out;
}

const Fraction Fraction::operator + (Fraction rhs) {
	Fraction simplified;
	int temp = this->denominator * rhs.denominator;
	simplified.numerator = (this->numerator * rhs.denominator) + (rhs.numerator * this->denominator);
	simplified.denominator = temp;
	simplified.reduce();
	return simplified;
}

const Fraction Fraction::operator - (Fraction rhs) {
	Fraction simplified;
	int temp = this->denominator * rhs.denominator;
	simplified.numerator = (this->numerator * rhs.denominator) - (rhs.numerator * this->denominator);
	simplified.denominator = temp;
	simplified.reduce();
	return simplified;
}

const Fraction Fraction::operator * (Fraction rhs) {
	Fraction simplified;
	simplified.numerator = this->numerator * rhs.numerator;
	simplified.denominator = this->denominator * rhs.denominator;
	simplified.reduce();
	return simplified;
}

const Fraction Fraction::operator / (Fraction rhs) {
	Fraction simplified;
	simplified.numerator = this->numerator * rhs.denominator;
	simplified.denominator = this->denominator * rhs.numerator;
	simplified.reduce();
	return simplified;
}

bool Fraction::operator == (Fraction rhs) {
	Fraction left, right = rhs;					//created new objects so I wouldn't modify the existing ones
	left.denominator = this->denominator;
	left.numerator = this->numerator;
	left.reduce();
	right.reduce();
	if (left.numerator == right.numerator && left.denominator == right.denominator) {
		return true;
	}
	else {
		return false;
	}
}