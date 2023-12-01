#pragma once
class Fraction
{
private:
	int num, den;
	static int GCD(int a,int b);
	static int LCM(int a, int b);


public:
	Fraction(int num=0,int den=0);
	void InIt(int num,int den);
	void Print();
	int getnum();
	int getden();

	Fraction Reduced();
	Fraction operator+(Fraction F);
	Fraction operator-(Fraction F);
	Fraction operator*(Fraction F);
	Fraction operator/(Fraction F);
	Fraction operator!();
	Fraction operator&();
};

