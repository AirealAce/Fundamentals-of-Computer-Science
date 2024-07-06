//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name:  Lofton Bullard        Z#: Z111111111
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  06/05/2050           Due Time: 11:59 PM
Total Points: 2000
Assignment #: xyz.cpp

Description:

*************************************************************************************************************************/

//Include the following

#include <iostream>
#include <string>
#include <fstream>  
#include <iomanip>
using namespace std;


class order_record
{
public:
	string pname;
	string cname;
	double plant_cost;
	int quantity;
	double net_cost;
	double tax_rate;
	double purchase_tax;
	double discount;
	double total_cost;
};


//Prototypes for your functions 

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

//Function Implementations will go here
/*************************************************************************************************************************************************/
//Name: initialize
//Precondition: 
//Postcondition: 
//Decription: Reads the data file of call information (cell number, item_number, quantity, price, and processing_plant) into the dynamic 
//array of call record, STR. If the count because equal to the size the function double_size is called and the memory allocated to STR is doubled.
/***********************************************************************************************************************************************/
void initialize(order_record*& STR, int& count, int& size)
{
	//Put the code here to the dynamic array STR.  Remember to: 1) initialize size to 1 and count to 0;
	//2)open and close the ifstream object; 3) allocate memory for the dynamic array; 4) call double_size if
	//the array becomes full. Hint see program "dynamic_array_example8.cpp"
}

/**********************************************************************************************************************************/
//Name: is_Empty 
//Precondition: 
//Postcondition: 
//Decription: returns true if STR is empty
/*********************************************************************************************************************************/
bool is_Empty(int count)
{
	return count == 0;
}

/**********************************************************************************************************************************/
//Name: Is_full 
//Precondition: 
//Postcondition: 
//Decription: returns true if STR is full
/*********************************************************************************************************************************/
bool is_Full(int count, int size)
{
	return count == size;
}


/**********************************************************************************************************************************/
//Name: search
//Precondition: 
//Postcondition: 
//Decription: locates key in STR if it is there; otherwise -1 is returned
/*********************************************************************************************************************************/
int search(order_record* STR, int  count, string key)
{
	return -1;
}


/*********************************************************************************************************************************/
//Name: add
//Precondition: 
//Postcondition: 
//Decription: adds a new record to STR; if STR is full, double_size is called to increase the capacity of STR.
/********************************************************************************************************************************/
void add(order_record*& STR, int& count, int& size)
{
	
}


/********************************************************************************************************************************/
//Name: Remove
//Precondition: 
//Postcondition: 
//Decription: remove all occurences of key from STR if it is there.
/*******************************************************************************************************************************/
void remove(order_record* STR, int& count, string key)
{
	//Put the code here to remove ALL the records in STR that have a pname equal to key
	//If you find the item(s), you must shift and decrement count. Hint see program "dynamic_array_example8.cpp"
}

/******************************************************************************************************************************/
//Name: double_size
//Precondition: 
//Postcondition: 
//Decription: doubles the size (capacity) of STR
/******************************************************************************************************************************/
void double_size(order_record*& STR, int  count, int& size)
{
	//Put the code here to double the size (amount of memory allocated to the array) of the dynamic array.
	//You must allocate memory using new. Hint see program "dynamic_array_example8.cpp"
}

/******************************************************************************************************************************/
//Name: process
//Precondition: 
//Postcondition: 
//Decription: calculate the net cost, tax rate, order tax and total cost for every order record in STR.
/*****************************************************************************************************************************/
void process(order_record* STR, int count)
{
	//Put the code here for the loop to process the data stored in the array.
}

/****************************************************************************************************************************/
//Name: print
//Precondition: 
//Postcondition: 
//Decription: prints every field of every order_record in STR formatted to the screen.
/***************************************************************************************************************************/
void print(const order_record* STR, const int  count)
{
	ofstream out;
	out.open("nursery_result20.txt", fstream::app);
	static int run = 1;
	
	//put code here for the loop to print the data in the array to the stream out.

	out << "****************************\n";
	out << "*********end of run " << run << "****" << endl;
	out << "*******************************\n";
	run++;
	out.close();
}



/****************************************************************************************************************************/
//Name: destroy_STR
//Precondition: 
//Postcondition: 
//Decription: de-allocates all memory allocated to STR.  This should be the last function to be called before the program
//            is exited.
/***************************************************************************************************************************/
void destory_STR(order_record* STR, int& count, int& size)
{
	//Remember to set count and size to zero, and delete the memory allocated to STR using the new operator.
}

//Here is your driver to test the program
int main()
{
	//int count = 0; //intializating count
	//int size = 1;
	//order_record* STR = 0;//declaring the dynamic array

	//cout << "**********************************************************************\n";
	//cout << "Test 1: Testing initialize, double_size, process, is_full and print " << endl;
	//initialize(STR, count, size);
	//process(STR, count);
	//print(STR, count);
	//cout << "End of Test 1" << endl;
	//cout << "**********************************************************************\n";
	//cout << "**********************************************************************\n";
	////Test 2:
	////void add(order_record * & STR, int & count, int & size);
	//cout << "Test 2: Testing add, double_size, process, is_full, and print " << endl;
	//add(STR, count, size);
	//print(STR, count);
	//cout << "End of Test 2" << endl;
	//cout << "**********************************************************************\n";
	//cout << "**********************************************************************\n";
	////Test 3:
	////void remove(order_record * STR, int & count, string key);
	//cout << "Test 3: Testing remove, is_Empty, search and print " << endl;
	//cout << "Removing rose\n";
	//remove(STR, count, "rose");
	//print(STR, count);
	//cout << "Removing rose\n";
	//remove(STR, count, "owl");
	//print(STR, count);
	//cout << "End of Test 3" << endl;
	//cout << "**********************************************************************\n";
	//cout << "**********************************************************************\n";
	////Test 4:
	////void add(order_record * & STR, int & count, int & size);
	//cout << "Test 4: Testing add, double_size, process, is_full, and print " << endl;
	//add(STR, count, size);
	//print(STR, count);
	//cout << "End of Test 4" << endl;
	//cout << "**********************************************************************\n";
	//cout << "**********************************************************************\n";
	////void destroy_STR(order_record  * STR, int & count, int & size);*/
	//cout << "Test 5: destroy_STR and print " << endl;
	//destory_STR(STR, count, size);
	//cout << "size = " << size << endl;
	//cout << "count = " << count << endl;
	//cout << "End of Test 5" << endl;
	//cout << "**********************************************************************\n";
	//cout << "**********************************************************************\n";
	return 0;
}