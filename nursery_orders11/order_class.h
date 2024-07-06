	#pragma once
//order_class.h
//libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//preprocessor directives
#ifndef order_class_h
#define order_class_h
class order_record
{
public:
	string pname = "";
	string cname = "";
	double plant_cost = 0;
	int quantity = 0;
	double net_cost = 0;
	double tax_rate = 0;
	double purchase_tax = 0;
	double discount = 0;
	double total_cost = 0;
	double discount_rate = 0;
};



class order_class
{
public:
	order_class();	//default constructor
	order_class(const order_class& org); //copy constructor
	~order_class(); //destructor: de-allocates all memory allocate to STR by operator new.
	bool is_Empty(); //inline implementation
	bool is_Full();//inline implementation
	int search(const string key);//returns location of key if in STR; otherwise return -1
	void add(); //adds a order record to STR
	order_class& operator-(const string key); //removes all items in STR with a plant name that matches key.
	void double_size();
	void process();
	friend ostream& operator<<(ostream& out, order_class& ORG); //prints all the elements in ORG's STR to the screen
private:
	int count;
	int size;
	order_record* STR;
};




#endif
