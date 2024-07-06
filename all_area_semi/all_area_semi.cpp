/*********************************************************************************************************************
Name: Aaron P. Mills	Z#:Z-23547104
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 06/22/2021	Total Points: 10
Assignment#:Assignment#4 Program Name: all_area_semi.cpp
Description: In this assignment, we will create a program that creates & uses a function to
compute the area of an arbitrary triangle.

********************************************************************************************************************/
//Libraries
#include <iostream>				//input/output
#include <string>				//strings				
#include <iomanip>				//input/output manipulation
#include <math.h>				//mathematical functions
using namespace std;

//***************************************************************************************************
//function prototypes
void Compute(const double, const double, const double, double&, double&);

//****************************************************************************************************
//function definitions
//Name: Compute
//Precondition: Before this function is called, the user provides the triangle side lengths.  
//Discription: Function calculates & displays semiperimeter & area using call by value & reference.
//Postcondition: The result will be displayed, & stored in the respective variables (semiperimeter,area)
void Compute(const double a, const double b, const double c, double& area, double& semiperimeter)
{
	/* Magic Formula *///to round to nearest hundredth 
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	//calculations & display
	semiperimeter = (a + b + c) / 2;
	area = sqrt(semiperimeter * (semiperimeter - a) * (semiperimeter - b) * (semiperimeter - c));
	cout << "Semiperimeter: " << semiperimeter << endl << "Area: " << area << endl;
}

//**********************************************************************************************************
int main()
{
	//variable declaration
	double a, b, c, area, semiperimeter;
	a = 0; b = 0; c = 0; area = 0; semiperimeter = 0;	//initialization 

	cout << "Welcome to Aaron's Traingular Area Calculator!" << endl;

	//while loop - to record triangle information & check validity 
	char x = 'Y';
	while (x == 'Y' || x == 'y') {
		cout << "Enter your traingale information below." << endl << endl;
		cout << "Side a: ";
		cin >> a;
		cout << "Side b: ";
		cin >> b;
		cout << "Side c: ";
		cin >> c;
		cout << endl;

		//validation check
		if (a + b > c && a + c > b && b + c > a) {
			Compute(a, b, c, area, semiperimeter);		//function call
		}
		else {
			cout << "This triangle's lengths are invalid; the triangle is illegal. ";
		}

		//ask user if they would like to continue calculating
		do {
			cout << endl << "Would you like to perform another calculation? (Y/y or N/n): ";
			cin >> x;
			if (x != 'Y' && x != 'y' && x != 'N' && x != 'n')
				cout << endl << "That wasn't an option. ";
			else
				cout << endl << "_______________________________________________________________________________________________________" << endl;
		} while (x != 'Y' && x != 'y' && x != 'N' && x != 'n');
	}

	return 0;
}