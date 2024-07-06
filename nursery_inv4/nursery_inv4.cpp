/************************************************************************************************************************
Name: Aaron P. Mills			Z#: Z-23547104
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 06/29/2021			Total Points: 10
Assignment #: Assignment#5		Program Name: nursery_inv4.cpp

Description: This projects has us computing nursery inventory & purchases! But there's a catch; this time we will
be reading/writing from files. I will be using input & output streams.  

*************************************************************************************************************************/
//Include libraries
#include <iostream>				//input/ouput
#include <string>				//strings
#include <fstream>				//file input/output
#include <iomanip>				//input/output manipulation
using namespace std;			//allows ommition of "std::", because it is now implied. 

/*******************************************************************************************************************/
//Class Declaration 
class order_record
{//Definition
public:						//Access Specifier/Key
	string pname = "";			//Object Declarations 
	string cname = "";
	double plant_cost = 0;
	int quantity = 0;
	double tax_rate = 0;
	double net_cost = 0;
	double discount_rate = 0;
	double discount = 0;
	double purchase_tax = 0;
	double total_cost = 0;
	double total_sales = 0;
};

//**********************************************************************************************************
//Function Prototypes/Declarations
void input(ifstream&, order_record&);
void process(order_record&);
void output(ofstream&, const order_record);

//**************************************************************************************************************************************************************************
//Name: input
//Precondition: Before this function is called, the "nursery_stock" file has been opened. 
//Discription: This function gathers input from file & stores in variables
//Postcondition: Each variable holds data from the file, ready for proccessing. 
void input(ifstream& in, order_record& customer_order)
{
	in >> customer_order.pname;
	in >> customer_order.cname;
	in >> customer_order.plant_cost;
	in >> customer_order.quantity;
}

///*************************************************************************************
//Name: process
//Precondition: Before this function is called, the input data has been stored in variables.
//Discription: This function performs calculations using the input data.
//Postcondition: The computations have been performed & each variable holds its respective calculation.
void process(order_record& customer_order)
{
	if (customer_order.cname == "dade")
		customer_order.tax_rate = 5.5;
	else if (customer_order.cname == "broward")
		customer_order.tax_rate = 5;
	else if (customer_order.cname == "palm")
		customer_order.tax_rate = 6;

	customer_order.net_cost = customer_order.quantity * customer_order.plant_cost;

	if (customer_order.quantity == 0)
		customer_order.discount_rate = 0;
	else if (customer_order.quantity >= 1 && customer_order.quantity <= 6)
		customer_order.discount_rate = .02;
	else if (customer_order.quantity >= 7 && customer_order.quantity <= 13)
		customer_order.discount_rate = .04;
	else if (customer_order.quantity >= 14 && customer_order.quantity <= 25)
		customer_order.discount_rate = .07;
	else if (customer_order.quantity >= 26 && customer_order.quantity <= 60)
		customer_order.discount_rate = .09;
	else if (customer_order.quantity >= 60)
		customer_order.discount_rate = .14;

	customer_order.discount = customer_order.discount_rate * customer_order.net_cost;

	customer_order.purchase_tax = customer_order.net_cost * customer_order.tax_rate / 100;

	customer_order.total_cost = customer_order.net_cost + customer_order.purchase_tax - customer_order.discount;

	customer_order.total_sales += customer_order.total_cost;
}


///**********************************************************************************************************************
//Name: output
//Precondition: Before this function is called, the calculations of the plant purchase has been performed and the output file is
// opened. (sells_results)  
//Discription: This function prints the data processed earlier onto a file/console
//Postcondition: The processed data has been displayed to the screen & saved in the file. 
void output(ofstream& out, const order_record customer_order)
{
	/*Magic Formula*/
	//Format for FILE
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);
	//Format for CONSOLE (screen)
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	//Print to FILE
	out << left << setw(15) << customer_order.pname << left << setw(10) << customer_order.cname << left;
	out << setw(9) << customer_order.plant_cost << left << setw(7) << customer_order.quantity << left;
	out << setw(8) << customer_order.tax_rate << left << setw(11) << customer_order.net_cost << left;
	out << setw(9) << customer_order.discount_rate * 100 << left << setw(10) << customer_order.discount << left;
	out << setw(10) << customer_order.purchase_tax << left << setw(10) << customer_order.total_cost << endl;
	//Print to CONSOLE (screen)
	cout << left << setw(15) << customer_order.pname << left << setw(10) << customer_order.cname << left;
	cout << setw(9) << customer_order.plant_cost << left << setw(7) << customer_order.quantity << left;
	cout << setw(8) << customer_order.tax_rate << left << setw(11) << customer_order.net_cost << left;
	cout << setw(9) << customer_order.discount_rate * 100 << left << setw(10) << customer_order.discount << left;
	cout << setw(10) << customer_order.purchase_tax << left << setw(10) << customer_order.total_cost << endl;
}

//*************************************************************************************************************************
//This is where I will call each function & open/close files.
int main()
{
	order_record purchase_record;

	ifstream in;    //declaring an input file stream
	in.open("nursery_stock.txt"); //opening the input file stream 
	ofstream out;
	out.open("sells_results.txt");

	if (in.fail())
		cout << "Input file did not open correctly" << endl;
	else
	{   //the following while loop processes one order record at a time
		while (!in.eof())
		{
			input(in, purchase_record);
			process(purchase_record);
			output(out, purchase_record);
		}
		cout << "Total Sales = $" << purchase_record.total_sales << endl;
		out << "Total Sales = $" << purchase_record.total_sales << endl;
	}

	in.close();		//always close opened files.
	out.close();
	return 0;
}



