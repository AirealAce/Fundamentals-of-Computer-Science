/*********************************************************************************************************************
Name: Aaron P. Mills	Z#:Z-23547104
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 06/08/2021	Total Points: 20
Assignment#:Assignment#2 Program Name: nursery_inv2.cpp
Description: In this assignment, we will create a program that uses functions, call by reference, and files to compute
information on plant orders. Pass by reference is used when we want to change the value of a variable, while pass by 
const is used when we don't. 
//Note: The professor says I can use the Magic Formula instead of rounding to the nearest hundredth. 
********************************************************************************************************************/

#include <iostream>		//i/o library
#include <string>		//string library
#include <fstream>		//file i/o library
#include <iomanip>		//i/o manipulation library
using namespace std;	//allows ommition of "std::"

/*******************************************************************************************************************/

//Function Prototypes 
void input(ifstream&, string&, string&, double&, int&);
void process(const string, const double, const int, double&, double&, double&, double&, double&, double&);
void output(const string, const string, const double, const int, const double&, const double&, const double&, const 
	double&, const double&, const double&);

/************************************************************************************************************/

//Function Implementation/Definitions
//This function records data so it is in usable form
void input(ifstream& in,string& pname,string& cname, double& plant_cost,int& quantity) 
{//^ this is call by reference
	in >> pname;
	in >> cname;
	in >> plant_cost;
	in >> quantity;
}

//This function processes data (performs calculations)
void process(const string cname, const double plant_cost, const int quantity, double& tax_rate, double& net_cost, 
	double& discount_rate, double& discount, double& purchase_tax, double& total_cost)
{
	//2.a) tax_rate is based on county
	if (cname == "dade")
		tax_rate = .055;
	else if (cname == "broward")
		tax_rate = .05;
	else if (cname == "palm")
		tax_rate = .06;

	//2.b) net cost of purchase formula
	net_cost = quantity * plant_cost;


	//2.c) discount is based on the quantity of plants in the purchase
	if (quantity <= 0)
		discount_rate = .00;
	else if (quantity >= 1 && quantity <= 6)
		discount_rate = .02;
	else if (quantity >= 7 && quantity <= 13)
		discount_rate = .04;
	else if (quantity >= 14 && quantity <= 25)
		discount_rate = .07;
	else if (quantity >= 26 && quantity <= 60)
		discount_rate = .09;
	else if (quantity > 60)
		discount_rate = .14;
	discount = discount_rate * net_cost;

	//2.d) tax on purchase formula
	purchase_tax = net_cost * tax_rate;
	

	//2.e) total cost of purchase formula
	total_cost = net_cost + purchase_tax - discount;

}

//This function displays output
void output(const string pname, const string cname, const double plant_cost, const int quantity,double& tax_rate, 
	double& net_cost, double& discount_rate, double& discount, double& purchase_tax, double&total_cost)
{
	/*MAGIC FORMULA*/
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	//Create a neat output
	cout << left << setw(15) << pname << left << setw(10) << cname << left << setw(9) << plant_cost << left << setw(7);
	cout << quantity << left << setw(8) << tax_rate * 100 << left << setw(11) << net_cost << left << setw(9);
	cout << discount_rate *100 << left << setw(10) << discount << left << setw(10) << purchase_tax << left << setw(10);
	cout << total_cost << endl;
}

/********************************************************************************************************************/

int main()
{
	//Variable Declarations/Initializations
	string pname = "";
	string cname = "";
	double plant_cost = 0;
	int quantity = 0;
	double tax_rate = 0;
	double net_cost = 0;
	double discount_rate = 0;
	double discount = 0;
	double purchase_tax = 0;
	double total_cost = 0;
	ifstream in;	//declaring an input file stream

	in.open("nursery_stock.txt"); //opening the input file stream
	if (in.fail())	//if file fails to open
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{ //the following while loop processes one order record at a time
		while (!in.eof())	//while not at the end of the file
			{//Function calls
			 input(in, pname,cname, plant_cost, quantity);
			 process(cname, plant_cost, quantity, tax_rate, net_cost, discount_rate, discount, purchase_tax,total_cost);
			 output(pname, cname, plant_cost, quantity, tax_rate, net_cost, discount_rate, discount, purchase_tax, total_cost);
			}
	}
	
	in.close();				//always close opened files
	cout << endl << endl;	//make the program neat
	return 0;				//always return 0 at end of main
}