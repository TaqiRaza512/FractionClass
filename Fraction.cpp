#include "Fraction.h"
#include<iostream>
#include<fstream>
using namespace std;

Fraction::Fraction(int numerator, int denominator)
{
	InIt(numerator,denominator);
}
int Fraction::getnum()
{
	return num;
}
int Fraction::getden()
{
	return den;
}
void Fraction::InIt(int numerator,int denominator)
{

	num = numerator;
	den = denominator;

}
void Fraction::Print()
{
	cout << "\t"  << this->num << "/" << den;

}
int Fraction::GCD(int a, int b)
{
	for (int ri = b; ri >= 1; ri--)
	{
		if (a % ri == 0 && b % ri == 0)
		{
			return ri;
		}
	}
}
int Fraction::LCM(int a, int b)
{
	return (a * b / GCD(a, b));	
}
Fraction Fraction::Reduced()
{
	int gcd = GCD(this->num, this->den);
	Fraction Res(this->num / gcd, this->den / gcd);
	return Res;
}
Fraction Fraction::operator+(Fraction F)
{
	Fraction Res;
	int lcm=LCM(this->den, F.den);
	Res.den = lcm;	
	Res.num=this->num*( lcm/ this->den)+ F.num * (lcm / F.den);
	Res=Res.Reduced();
	return Res;
}
Fraction Fraction::operator-(Fraction F)
{
	Fraction Res;
	int lcm = LCM(this->den, F.den);
	Res.den = lcm;
	Res.num = this->num * (lcm / this->den) - F.num * (lcm / F.den);
	Res=Res.Reduced();

	return Res;
}
Fraction Fraction::operator*(Fraction F)
{
	Fraction Res;
	Res.den = this->den * F.den;
	Res.num = this->num * F.num;
	Res=Res.Reduced();
	return Res;
}
Fraction Fraction::operator/(Fraction F)
{
	Fraction Res = (*this)*(!F);
	Res=Res.Reduced();
	return Res;
}
Fraction Fraction::operator!()
{
	Fraction Res;
	Res.den =this->num ;
	Res.num = this->den;
	return Res;
}
Fraction Fraction::operator&()
{
	Fraction Res;
	Res.num = -this->num;
	Res.den = this->den;
	return Res;

}
