//order_class.cpp
#include <iostream>
#include <iomanip>
#include <fstream>
#include "order_class.h"
using namespace std;

//member functions
//Name: default constructor
//Precondition: This function has been declaraed within the class.
//Postcondition: Members have been declared/initialized. 
//Decription: Reads the data file of purchase order information (plant name, county name, plant cost and quantity) into the dynamic array of order records, 
//STR. If the count become equal to the size the function double_size is called and the memory allocated to STR is doubled.
/************************************************************************************************************************************/
order_class::order_class()
{
	cout << "The default constructor has been called\n";
	size = 1;
	count = 0;
	STR = new order_record[size];

	cout << "The default constructor has been called\n";

	//open file
	ifstream in;
	in.open("nursery_stock.txt");
	if (in.fail())
		cout << "Input file did not open correctly" << endl;
	else
	{   //else read into array from file
		//allocate memory for array
		STR = new order_record[size];
		while (!in.eof())
		{
			//read file text into array		
			in >> STR[count].pname;
			in >> STR[count].cname;
			in >> STR[count].plant_cost;
			in >> STR[count].quantity;
			++count;	//number of items in array increases by 1 
			//if the array is full
			if (is_Full()) {
				//double the size
				double_size();
			}
		}
	}
	in.close();

}

/************************************************************************************************************************************/
//Name: copy constructor
//Precondition: another array has been defined
//Postcondition: a new array has been defined, which is a copy of the original
//Description:  The function performs a deep copy of the formal parameter org. 
/************************************************************************************************************************************/
order_class::order_class(const order_class& org)
{
	(*this).STR = new order_record[org.size];	//create new array with org's size

	(*this).count = org.count;					//give new array the count of org
	for (int i = 0; i < (*this).count; i++) {
		//copy old array into new array
		(*this).STR[i] = org.STR[i];
	}
}

/***********************************************************************************************************************************/
//Name: is_Empty
//Precondition: An array & class have been declared.
//Postcondition: A boolean value is returned to tell if the array is empty or not.
//Decription: returns true if STR is empty
/**********************************************************************************************************************************/
bool order_class::is_Empty()
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: is_Full 
//Precondition: An array has been declared & class. 
//Postcondition: A boolean value is returned to tell if the array is full or not.
//Decription: returns true if STR is full
/*********************************************************************************************************************************/
bool order_class::is_Full()
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: A keyword is passed to this function.
//Postcondition: The location of such keyword is revealed. 
//Decription: locates key in STR if it is there; otherwise -1 is returned
//Decription: locates key in STR if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int order_class::search(const string key)
{
	//go through each element of the array
	for (int x = 0; x < count; ++x) {
		//find the plant name that matches the key
		if (STR[x].pname == key) {
			//return that location in the array
			return x;
		}
	}
	//if not in array, return -1
	return -1;
}

/*********************************************************************************************************************************/
//Name: add
//Precondition: An array has been declared.  
//Postcondition: The user's input is added to the order record array. 
//Decription: adds a order_record to STR; if STR is full, double_size is called to increase the size of STR. The user 
//            is prompted to enter the plant name, county name, plant cost and quantity.
/********************************************************************************************************************************/
void order_class::add()
{
	//prompt user for the order record they'd like to add
	cout << "Enter plant name: \t";
	cin >> STR[count].pname;
	cout << "Enter county name: \t";
	cin >> STR[count].cname;
	cout << "Enter plant cost: \t";
	cin >> STR[count].plant_cost;
	cout << "Enter plant quantity: \t";
	cin >> STR[count].quantity;
	++count; //count increases because we just added a new element 

	//if the array is full
	if (is_Full()) {
		//double the size
		double_size();
	}

	//info needs to be re-processed now. 
	process();
}

/********************************************************************************************************************************/
//Name: operator-
//Precondition: A keyword is passed to this function, the word to be removed.
//Postcondition: The array removes all occurrences of the keyword.
//Decription: removes all order records in STR with a plant name field that matches key, if it is there.
/*******************************************************************************************************************************/
order_class& order_class::operator-(const string key)
{
	//while the key item exist in the array 
	if (search(key) > -1) {
		while (search(key) > -1) {
			int rem = search(key); //this is the location of the item to remove;
			//each element must be shifted to account for the loss 
			for (int x = rem; x < count - 1; ++x) {
				STR[x] = STR[x + 1];
			}
			--count;	//we lose one element
		}
	}
	else
		cout << "This data does not contain " << key << endl;
	return *this; //returning the current object
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: An array has been declared, as well as its size.
//Postcondition: The size of the array has been doubled.
//Decription: doubles the size (capacity) of STR
/******************************************************************************************************************************/
void order_class::double_size()
{
	size *= 2;	//double the size
	//allocate memory 
	order_record* temp = new order_record[size];	//create a temporary array with new size
	//copy contents from STR array into temp array 
	for (int i = 0; i < count; ++i) {
		temp[i] = STR[i];
	}
	//delete old memory used for array STR
	delete[] STR;
	//point to the new array memory location, where the size has been doubled 
	STR = temp;
}


/******************************************************************************************************************************/
//Name: process
//Precondition: The array holds the data from the file.
//Postcondition: Calculations are performed to fill out the subsections of the array's variables.
//Decription: calculate the net cost, tax rate, order tax, discount and total cost for every order record in STR. for every call record in STR.
/*****************************************************************************************************************************/
void order_class::process()
{
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
			STR[x].discount_rate = .13;

		STR[x].discount = STR[x].discount_rate * STR[x].net_cost;

		STR[x].purchase_tax = STR[x].net_cost * STR[x].tax_rate;

		STR[x].total_cost = STR[x].net_cost + STR[x].purchase_tax - STR[x].discount;
	}
}


/****************************************************************************************************************************/
//Name: operator<<
//Precondition: Calculations have been performed on the array.
//Postcondition: The array information is displayed to file & screen.
//Decription: prints every field of every call_record in STR formatted to a file and return the stream.
/***************************************************************************************************************************/
ostream& operator<<(ostream& out, order_class& org)
{

	static int run = 1;

	/*Magic Formula*/
	out.setf(ios::showpoint);
	out.precision(2);
	out.setf(ios::fixed);

	for (int x = 0; x < org.count; ++x) {
		//Print to FILE
		out << left << setw(15) << org.STR[x].pname << left << setw(10) << org.STR[x].cname << left;
		out << setw(9) << org.STR[x].plant_cost << left << setw(11) << org.STR[x].quantity << left;
		out << setw(11) << org.STR[x].net_cost << left << setw(14); out.precision(3);
		out << org.STR[x].tax_rate << left; out.precision(2);
		out << setw(9) << org.STR[x].purchase_tax << left << setw(10) << org.STR[x].discount << left;
		out << setw(10) << org.STR[x].total_cost << endl;

	}

	out << "****************************\n";
	out << "*********end of run " << run << "****" << endl;
	out << "*******************************\n";
	run++;


	out << "****************************\n";
	out << "*********end of run " << run << "****" << endl;
	out << "*******************************\n";
	run++;
	return out;//returning object that invoked the function
}

/****************************************************************************************************************************/
//Name: destructor
//Precondition: The array is allocated memory.
//Postcondition: The array is no longer allocated memory. 
//Decription: de-allocates all memory allocated to STR.  This will be the last function to be called (automatically by the compiler)
//before the program is exited.
/***************************************************************************************************************************/
order_class::~order_class()
{
	cout << "The destructor has been called\n";
	count = 0;
	size = 0;
	delete[] STR;
}

