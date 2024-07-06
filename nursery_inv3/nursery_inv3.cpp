/************************************************************************************************************************
Name: Aaron P. Mills			Z#: Z-23547104
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 06/15/2021			Total Points: 20
Assignment #:Assignment#3		Program Name: nursery_inv3.cpp

Description: This projects has us computing nursery inventory & purchases! But there's a catch; this time we will
be using a class. We will be using multiple objects of that class to gather input, proccess data, & display output. 

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
	double purchase_tax=0;	
	double total_cost=0;
};

//**********************************************************************************************************
//Function Prototypes/Declarations
void input(ifstream&, order_record&);
void output(ofstream&, const order_record&);
void process(order_record&);

//**************************************************************************************************************************************************************************
//Name: input
//Precondition: Before this function is called, the "nursery_stock" file has been opened. 
//Discription: This function gathers input from file & stores in variables
//Postcondition: Each variable holds data from the file, ready for proccessing. 
void input(ifstream& in, order_record& plant_record) // example using the call by 
{
	in >> plant_record.pname;
	in >> plant_record.cname;
	in >> plant_record.plant_cost;
	in >> plant_record.quantity; 
}

///*************************************************************************************
//Name: process
//Precondition: Before this function is called, the input data has been stored in variables.
//Discription: This function performs calculations using the input data.
//Postcondition: The computations have been performed & each variable holds its respective calculation.
void process(order_record& plant_record)
{
	if (plant_record.cname == "dade")
		plant_record.tax_rate = 5.5;
	else if (plant_record.cname == "broward")
		plant_record.tax_rate = 5;
	else if (plant_record.cname == "palm")
		plant_record.tax_rate = 6;

	plant_record.net_cost = plant_record.quantity * plant_record.plant_cost;

	if (plant_record.quantity == 0)
		plant_record.discount_rate = 0;
	else if (plant_record.quantity >= 1 && plant_record.quantity <= 6)
		plant_record.discount_rate = .02; 
	else if (plant_record.quantity >= 7 && plant_record.quantity <= 13)
		plant_record.discount_rate = .04;
	else if (plant_record.quantity >= 14 && plant_record.quantity <= 25)
		plant_record.discount_rate = .07;
	else if (plant_record.quantity >= 26 && plant_record.quantity <= 60)
		plant_record.discount_rate = .09;
	else if (plant_record.quantity >= 60)
		plant_record.discount_rate = .14;

	plant_record.discount = plant_record.discount_rate * plant_record.net_cost;

	plant_record.purchase_tax = plant_record.net_cost * plant_record.tax_rate / 100;

	plant_record.total_cost = plant_record.net_cost + plant_record.purchase_tax - plant_record.discount;
}


///**********************************************************************************************************************
//Name: output
//Precondition: Before this function is called, the calculations of the plant purchase has been performed.  
//Discription: This function prints the data processed earlier onto a file/console
//Postcondition: The processed data has been displayed to the screen & saved in a file. 
void output(ofstream& out, const order_record& plant_record)
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
	out << left << setw(15) << plant_record.pname << left << setw(10) << plant_record.cname << left;
	out << setw(9) << plant_record.plant_cost << left << setw(7) << plant_record.quantity << left;
	out << setw(8) << plant_record.tax_rate << left << setw(11) << plant_record.net_cost << left;
	out << setw(9) << plant_record.discount_rate * 100 << left << setw(10) << plant_record.discount << left;
	out << setw(10) << plant_record.purchase_tax << left << setw(10) << plant_record.total_cost << endl;
	//Print to CONSOLE (screen)
	cout << left << setw(15) << plant_record.pname << left << setw(10) << plant_record.cname << left;
	cout << setw(9) << plant_record.plant_cost << left << setw(7) << plant_record.quantity << left;
	cout << setw(8) << plant_record.tax_rate << left << setw(11) << plant_record.net_cost << left;
	cout << setw(9) << plant_record.discount_rate*100 << left << setw(10) << plant_record.discount << left;
	cout << setw(10) << plant_record.purchase_tax << left << setw(10) << plant_record.total_cost << endl;
}

//*************************************************************************************************************************
//This is where I will call each function & open/close files.
int main()
{
	order_record purchase_record;

	ifstream in;    //declaring an input file stream
	in.open("nursery_stock.txt"); //opening the input file stream 
	ofstream out;
	out.open("sample_calculations.txt");

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
	}

	in.close();		//always close opened files.
	out.close();
	return 0;
}


