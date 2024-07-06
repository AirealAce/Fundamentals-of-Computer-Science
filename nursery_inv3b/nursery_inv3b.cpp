/************************************************************************************************************************
Name: Aaron P. Mills			Z#: Z-23547104
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 07/08/2021			Total Points: 20
Assignment #: Assignment#5		Program Name: nursery_inv3b.cpp

Description: This projects has us computing nursery inventory & purchases! But there's a catch; this time we will
be using arrays. I will create four functions. I will additionally calculate the average of the "total order cost".

*************************************************************************************************************************/
//libraries
#include <iostream>
#include <string>
#include <fstream>	//you must include this library if you wish to do file i/o
#include <iomanip>
using namespace std;

/*********************************************************/
//class declaration
const int CAPACITY = 100;
class order_record
{
public:
	string pname = "0";
	string cname = "0";
	double plant_cost = 0;
	double quantity = 0;
	double purchase_tax = 0;
	double net_cost = 0;
	double tax_rate = 0;
	double discount = 0;
	double discount_rate = 0;
	double total_cost = 0;
};

//***************************************************************************************************************************//
//function prototypes
void input(order_record STR[], int& count);
void process(order_record STR[], const int count);
void output(order_record STR[], const int count);
double count_inventory(order_record STR[], const int count);

//*************************************************************************************************************************//
//function Implementations/definitions
//*************************************************************************************
//Name:  input
//Precondition: Before this function is called, "nursery_inv.txt" file will be opened. 
//Postcondition: After this function is called, the input data will be stored in an array. 
//Description:	This function opnes & reads from a file, then stores the info in an array.
void input(order_record STR[100], int& count) {
	ifstream in;
	in.open("nursery_stock.txt");
	while(!in.eof()) {
		in >> STR[count].pname;
		in >> STR[count].cname;
		in >> STR[count].plant_cost;
		in >> STR[count].quantity;
		++count;
	}	
	in.close(); 
}

//*************************************************************************************
//Name:  process
//Precondition: Before this function is called, the input data from the file has been stored in an array.
//Postcondition: After this function is called, numerous attributes of each element of the array will be computed.
//Description:	This function performs calculations based off the nursery stock information, then saves it in the array elements' attributes
void process(order_record STR[], const int count) {
	for (int x = 0; x < count; ++x) {
		if (STR[x].cname == "dade")
			STR[x].tax_rate = 6.5;
		else if (STR[x].cname == "broward")
			STR[x].tax_rate = 6;
		else if (STR[x].cname == "palm")
			STR[x].tax_rate = 7;

		STR[x].tax_rate /= 100;
		STR[x].net_cost = STR[x].quantity * STR[x].plant_cost;

		if (STR[x].quantity == 0)
			STR[x].discount_rate = 0;
		else if (STR[x].quantity >= 1 && STR[x].quantity <= 5)
			STR[x].discount_rate = .01;
		else if (STR[x].quantity >= 6 && STR[x].quantity <= 11)
			STR[x].discount_rate = .03;
		else if (STR[x].quantity >= 12 && STR[x].quantity <= 20)
			STR[x].discount_rate = .05;
		else if (STR[x].quantity >= 21 && STR[x].quantity <= 50)
			STR[x].discount_rate = .08;
		else if (STR[x].quantity >= 50)
			STR[x].discount_rate = .12;

		STR[x].discount = STR[x].discount_rate * STR[x].net_cost;

		STR[x].purchase_tax = STR[x].net_cost * STR[x].tax_rate;

		STR[x].total_cost = STR[x].net_cost + STR[x].purchase_tax - STR[x].discount;
	}
}

//*************************************************************************************
//Name:  output
//Precondition: Before this function is called, many computations have been completed & stored.
//Postcondition: After this function executes, the calculations will be printed to screen & file. 
//Description: This function displays the calculations of the "process" to the screen & file.
void output(order_record STR[], const int count) {	
	ofstream out;
	out.open("nursery_run_results.txt");

	/*Magic Formula*/
	//Format for FILE
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);
	//Format for CONSOLE (screen)
	//cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);

	for (int x = 0; x < count; ++x) {
		//Print to FILE
		out << left << setw(15) << STR[x].pname << left << setw(10) << STR[x].cname << left;
		out << setw(9) << STR[x].plant_cost << left << setw(11) << STR[x].quantity << left;
		out << setw(11) << STR[x].net_cost << left << setw(14); out.precision(3);
		out << STR[x].tax_rate << left; out.precision(2);
		out << setw(9) << STR[x].purchase_tax << left << setw(10) << STR[x].discount << left;
		out << setw(10) << STR[x].total_cost << endl;
		//Print to CONSOLE (screen)
		cout << left << setw(15) << STR[x].pname << left << setw(10) << STR[x].cname << left;
		cout << setw(9) << STR[x].plant_cost << left << setw(11) << STR[x].quantity << left;
		cout << setw(11) << STR[x].net_cost << left << setw(14); cout.precision(3);
		cout << STR[x].tax_rate << left; cout.precision(2); 
		cout << setw(9) << STR[x].purchase_tax << left << setw(10) << STR[x].discount << left;
		cout << setw(10) << STR[x].total_cost << endl;
	}
	out << "Average Total Order Cost = " << count_inventory(STR, count) << endl;

	out.close();
}
///*************************************************************************************
//Name: count_inventory
//Precondition: Before this function is called, many calculations have been displayed to screen.
//Postcondition: After this function is called, the average total order cost shall be computed. 
//Description: This function calculates the average total cost of the purchases.
double count_inventory(order_record STR[], const int count) {
	double sum = 0, average_cost = 0;
	for (int x = 0; x < count; ++x) {
		sum += STR[x].total_cost;
	}
	
	average_cost = sum / count;
	return average_cost;
}

//*************************************************************************************
//test driver
int main()
{
	/* MAGIC FORMULA */
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	
	order_record STR[CAPACITY];
	int count = 0;

	ifstream in;
	in.open("nursery_stock.txt");
	if (in.fail())

	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		input(STR, count);
		process(STR, count);
		output(STR, count);
		count_inventory(STR, count);
	}
	cout << "Average Total Order Cost = " << count_inventory(STR, count) << endl;
	
	in.close();
	return 0;
}
