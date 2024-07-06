/****SAMPLE PROGRAM HEADER*******************************************************
Name: Aaron P. Mills	        FAU-ID: Z-23547104
Due Date: 2 June 2021			Total Points:  10
Course: C0P3014
Assignment: Assignment 1		Program Name: nursery_inv
Professor: Dr. Lofton Bullard

Description: In this program, we utilize some user inputs (plant name, county name, plant cost, and quantity) to
compute and display purchase information. This includes tax on purchase, cost of purchase, discount on purchase and
total cost of purchase.

*************************************************************/
#include <iostream>		//library for input/output
#include <iomanip>		//library for input/output manipulation
#include <string>		//library for string
#include <math.h>		//library for math functions (needed for rounding) 

using namespace std;	//allows ommition of "std::" for syntax 

int main()
{

	//*********"*MAGIC FORMULA"**************************
	cout.setf(ios::fixed);				//specify fixed decimal notation
	cout.setf(ios::showpoint);			//decimal points shall always be shown 
	cout.precision(2);					//two decimal places shall always be shown
	//***************************************************************

	string user_response = "y";			//variable for user's decision (later use)

	//variable declaration/initalization 
	string pname;				//string holds plant name
	string cname;				//string holds county name
	double plant_cost;			//double holds cost of a plant;
	int quantity;				//int holds number of plants purchased;
	double purchase_tax = 0;	//double holds tax on purchase
	double net_cost = 0;		//double holds net cost of purchase
	double discount = 0;		//double holds discount on purchase
	double total_cost = 0;		//double holds total cost of purchase
	double tax_rate = 0;		//double holds tax rate based off county

	//loop for user decision and interaction 
	while (user_response == "y" || user_response == "Y")
	{
		//input Statements
		cout << "Enter the Plant Name: ";
		cin >> pname;
		cout << "Enter the County Name: ";
		cin >> cname;
		cout << "Enter the Plant Cost: ";
		cin >> plant_cost;
		cout << "Enter the Quantity: ";
		cin >> quantity;

		//Exercise #2)
		//Calculations
		net_cost = quantity * plant_cost;

		//Exercise #3)
		//Conditional Statements
		if (quantity <= 0)
			discount = .00 * net_cost;
		else if (quantity >= 1 && quantity <= 5)
			discount = .01 * net_cost;
		else if (quantity >= 6 && quantity <= 11)
			discount = .03 * net_cost;
		else if (quantity >= 12 && quantity <= 20)
			discount = .05 * net_cost;
		else if (quantity >= 21 && quantity <= 50)
			discount = .08 * net_cost;
		else if (quantity > 50)
			discount = .12 * net_cost;

		//Exercise #1)
		if (cname == "dade")
			tax_rate = .065;
		else if (cname == "broward")
			tax_rate = .06;
		else if (cname == "palm")
			tax_rate = .07;

		//Exercise #4) & #5)
		//Calculations
		purchase_tax = net_cost * tax_rate;
		total_cost = net_cost + purchase_tax - discount;
		total_cost = floor(total_cost * 100 + 0.5) / 100;	//round to nearest hundredth 


		//Output Statement to display results
		cout << endl << endl;
		cout << "Plant Name\t\t" << "= " << pname << endl;
		cout << "County Name\t\t" << "= " << cname << endl;
		cout << "Plant Cost\t\t" << "= " << plant_cost << endl;
		cout << "Quantity of Plants\t" << "= " << quantity << endl;
		cout << "Net Cost of Purchase\t" << "= " << net_cost << endl;
		cout << "Purchase Tax\t\t" << "= " << purchase_tax << endl;
		cout << "Discount on Purchase\t" << "= " << discount << endl;
		cout << "Total Cost of Purchase\t" << "= " << total_cost << endl;


		cout << "\nWould you like to make another calculation? (Y or N): " << endl;
		cin >> user_response;
		cout << endl;
	}

	return  0;
}