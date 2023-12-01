#include<iostream>
#include "Fraction.h"
#include<fstream>
using namespace std;

void LoadData(Fraction* &F,int &size)
{
	ifstream rdr("Fraction.txt");
	rdr >> size;
	int d, n;
	F = new Fraction[size];
	for (int ri=0;ri<size;ri++)
	{
		rdr >> d >> n;
		F[ri].InIt(d,n);
	}
}
ostream& operator<<(ostream&,Fraction F)
{
	cout << F.getnum() << "/" << F.getden();
	return cout;

}
void printline(char S,int length)
{
	for (int ri=0;ri<length;ri++)
	{
		cout << S;
	}
	cout << endl;
}
void print(Fraction* F,int size)
{
	printline('=',28);
	cout << "Hence there are " << size << " fractions " << endl;
	printline('_', 28);
	cout << endl;

	for (int ri=0;ri<size;ri++)
	{
		cout << "F" << ri + 1;
		F[ri].Print();
		cout << endl;
	}
	printline('_', 28);
	cout << endl;
	printline('=', 28);

}


void BinaryCal(Fraction* F, int size)
{
	char tocont;
	do
	{
		system("cls");
		print(F,size);
		char d,oprt;
		int ri, ui, li;
		cin >> d >> ri >> d >> d >> ui >> oprt >> d >> li;

		 ri--, ui--, li--;

		 switch (oprt)
		 {
		 case '+':
			 F[ri] = F[ui]+(F[li]);
			 cout << F[ri];
			break;
		 case '-':
			 F[ri] = F[ui]-(F[li]);
			 cout << F[ri];

			 break;
		 case '*':
			 F[ri] = F[ui]*(F[li]);
			 cout << F[ri];

			 break;

		 case '/' :

			 F[ri] = F[ui]/(F[li]);
			 cout << F[ri];

			 break;
		 default:
			 cout << "\nplease enter valid input\n";
		 }

		cout << "\nDo you want to continue .....\n";
		cin >> tocont;

	} while (tocont=='y' or tocont =='Y');



}

void UnaryMenu()
{

	cout << "\nPress -F for additive inverse of the fraction...\n";
	cout << "\nPress !F for Multiplicative inverse of the fraction...\n";


}
void UnaryCal(Fraction* F, int size)
{
	char tocont,oprt,d;
	int index;
	Fraction Res;
	
	do
	{
		system("cls");
		print(F, size);
		UnaryMenu();
		cin >> oprt >> d >> index;
		index--;
		switch (oprt)
		{
		case '-':
			 Res= &F[index];
			cout << "\n\nThe additive inverse of F" << index + 1 << " is ";
			cout << Res;
			break;

		case '!':
			 Res= !F[index];
			cout << "\n\nThe Multiplicative inverse of F" << index + 1 << " is ";
			cout << Res;
			break;
		
			default:
				cout << "\n\nplease enter the valid input\n\n";
				break;
		}
		cout << "\n\nDo you want to continue (Y/N).....\n";
		cin >> tocont;

	} while (tocont == 'Y' or tocont == 'y');

}

void Menu()
{
	cout << "\nPress 1 for the Binary calculator of Fractions..\n";
	cout << "\nPress 2 for the Unary calculator of Fractions..\n";
	
}
void Calculator(Fraction* F, int size)
{
	int opt;
	Menu();
	cin >> opt;
	switch (opt)
	{
	case 1:
		BinaryCal(F,size);

		break;
	case 2:
		UnaryCal(F,size);
		break;
	deafult:
		cout << "\nplease enter valid number....\n";
	}

}
int main()
{
	Fraction* F;
	int size=0;
	LoadData(F,size);
	print(F,size);
	Calculator(F,size);
}