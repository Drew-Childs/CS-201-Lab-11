#pragma once
//Drew Childs
//4/9/20
//Lab 11

#include <iostream>
using namespace std;

class Fraction
{

	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.

private:
	int getGCD(int num1, int num2);
	int numerator;
	int denominator;

public:
	void reduce();
	Fraction();
	const Fraction operator + (Fraction rhs);
	const Fraction operator - (Fraction rhs);
	const Fraction operator * (Fraction rhs);
	const Fraction operator / (Fraction rhs);
	bool operator == (Fraction rhs);
	friend istream& operator >> (istream& in, Fraction& fraction);
	friend ostream& operator << (ostream& out, const Fraction& fraction);


};

