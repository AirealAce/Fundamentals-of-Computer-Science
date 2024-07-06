/************************************************************************************************************************
Name: Aaron P. Mills			Z#: Z-23547104
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date: 07/21/2021			Total Points: 10
Assignment #: Assignment#8		Program Name: nursery_dynamic.cpp

Discription: In this project, we will be implmenting many functions, isstreams, arrays, classes, loops,
if-statements, & pointers. We will be performing functions on data from a text file. 

*************************************************************************************************************************/
//libraries
#include <iostream>
#include <string>
#include <fstream>  
#include <iomanip>
using namespace std;

//*************************************************************************************************************************/
class order_record
{
public:
	string pname = "0";
	string cname = "0";
	double plant_cost = 0;
	int quantity = 0;
	double net_cost = 0;
	double tax_rate = 0;
	double purchase_tax = 0;
	double discount = 0;
	double total_cost = 0;
	double discount_rate = 0;
};

//*************************************************************************************************************************/
//function prototypes
void initialize(order_record*& STR, int& count, int& size);
bool is_Empty(int count);
bool is_Full(int count, int size);
int search(order_record* STR, int  count, string key);
void add(order_record*& STR, int& count, int& size);
void remove(order_record* STR, int& count, string key);
void double_size(order_record*& STR, int  count, int& size);
void process(order_record* STR, int count);
void print(const order_record* STR, const int  count);
void destory_STR(order_record* STR, int& count, int& size);

//*************************************************************************************************************************/
//function implementations
//Name: initialize
//Precondition: Variables, class, & array have been declared & the input file is within this same folder.
//^ also, some functions like double_size() have been well defined.
//Postcondition: The data from the file has been stored in the array.
//Decription: Reads the data file of call information (cell number, item_number, quantity, price, and processing_plant) into the dynamic 
//array of call record, STR. If the count because equal to the size the function double_size is called and the memory allocated to STR is doubled.
/***********************************************************************************************************************************************/
void initialize(order_record*& STR, int& count, int& size)
{
	//variable initializations 
	size = 1;		//AKA capacity
	count = 0;		

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
			if (is_Full(size, count)) {
				//double the size
				double_size(STR,count,size);
			}
		}
	}
	in.close();
}

/**********************************************************************************************************************************/
//Name: is_Empty 
//Precondition: Array, count, & size/capacity have been initialized or declared. 
//Postcondition: A value of true or false is returned. 
//Decription: returns true if array is empty
/*********************************************************************************************************************************/
bool is_Empty(int count)
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: Is_full 
//Precondition: Array has been declared, as well as the initalization of count & size.
//Postcondition: True or false is returned
//Decription: returns true if STR is full
/*********************************************************************************************************************************/
bool is_Full(int count, int size)
{
	return count == size;
}

/**********************************************************************************************************************************/
//Name: search
//Precondition: Array, count, & size have been declared. 
//Postcondition: The location of the key in the array has been returned, or -1. 
//Decription: locates key in STR if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int search(order_record* STR, int  count, string key)
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
//Precondition: Array, class, size, & count have been declared. process function well defined.
//Postcondition: A new element of the user's choice shell be added to the array.
//Decription: adds a new record to STR; if STR is full, double_size is called to increase the capacity of STR.
/********************************************************************************************************************************/
void add(order_record*& STR, int& count, int& size)
{
	//array should not be full at this stage based off my code
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
	if (is_Full(size, count)) {
		//double the size
		double_size(STR, count, size);
	}
	
	//info needs to be re-processed now. 
	process(STR,count);
}

/********************************************************************************************************************************/
//Name: Remove
//Precondition: search function has been well defined, as well as the declaration of soeme variables.
//Postcondition: the array potentially loses some elements, & the others are shifted.
//Decription: remove all occurences of key from STR if it is there.
/*******************************************************************************************************************************/
void remove(order_record* STR, int& count, string key)
{
	//while the key item exist in the array 
	while (search(STR, count, key) > -1) {
		int rem = search(STR, count, key); //this is the location of the item to remove;
		//each element must be shifted to account for the loss 
		for (int x = rem; x < count - 1; ++x) {
			STR[x] = STR[x + 1]; 
		}
		--count;	//we lose one element
	}
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: size has been declared
//Postcondition: size is doubled
//Decription: doubles the size (capacity) of STR
/******************************************************************************************************************************/
void double_size(order_record*& STR, int  count, int& size)
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
/*************************
*****************************************************************************************************/
//Name: process
//Precondition: The data from the file has been stored in the array. Variables well defined.
//Postcondition: The array holds the calculated data as objects to each element.
//Decription: calculate the net cost, tax rate, order tax and total cost for every order record in STR.
/*****************************************************************************************************************************/
void process(order_record* STR, int count)
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
			STR[x].discount_rate = .12;

		STR[x].discount = STR[x].discount_rate * STR[x].net_cost;

		STR[x].purchase_tax = STR[x].net_cost * STR[x].tax_rate;

		STR[x].total_cost = STR[x].net_cost + STR[x].purchase_tax - STR[x].discount;
	}
}

/****************************************************************************************************************************/
//Name: print
//Precondition: The data from the file has been processed & stored in the array.
//Postcondition: Data is printed to file (& screen)
//Decription: prints every field of every order_record in STR formatted to the screen.
/***************************************************************************************************************************/
void print(const order_record * STR, const int  count)
{
		ofstream out;
		out.open("nursery_result20.txt", fstream::app);
		static int run = 1;


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

		out << "****************************\n";
		out << "*********end of run " << run << "****" << endl;
		out << "*******************************\n";
		run++;
		out.close();
}



/****************************************************************************************************************************/
//Name: destroy_STR
//Precondition: Array STR has been declared.
//Postcondition: Array STR has no more allocated memory. 
//Decription: de-allocates all memory allocated to STR.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
void destory_STR(order_record* STR, int& count, int& size)
{
	count = 0;
	size = 0;
	delete[] STR;
}

//*********************************************************************************************************
//test driver
int main()
{
	//variable initializations
	int count = 0; 
	int size = 1;
	//dynamic array
	order_record* STR = 0;

	//testings
	cout << "**********************************************************************\n";
	cout << "Test 1: Testing initialize, double_size, process, is_full and print " << endl;
	initialize(STR, count, size);
	process(STR, count);
	print(STR, count);
	cout << "End of Test 1" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 2:
	cout << "Test 2: Testing add, double_size, process, is_full, and print " << endl;
	add(STR, count, size);
	print(STR, count);
	cout << "End of Test 2" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 3:
	cout << "Test 3: Testing remove, is_Empty, search and print " << endl;
	cout << "Removing rose\n";
	remove(STR, count, "rose");
	print(STR, count);
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	cout << "Removing owl\n";
	remove(STR, count, "owl");
	print(STR, count);
	cout << "End of Test 3" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	//Test 4:
	cout << "Test 4: Testing add, double_size, process, is_full, and print " << endl;
	add(STR, count, size);
	print(STR, count);
	cout << "End of Test 4" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	cout << "Test 5: destroy_STR and print " << endl;
	destory_STR(STR, count, size);
	cout << "size = " << size << endl;
	cout << "count = " << count << endl;
	cout << "End of Test 5" << endl;
	cout << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	return 0;
}