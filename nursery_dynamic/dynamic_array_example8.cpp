#include <iostream>
#include <string>
#include <iostream>

using namespace std;

void Initialize(int * & A, int & count, int & size);
void Double_Size(int * & A, int count, int & size);
void Add(int * & A, int & count, int & size, const int key);
int Search(int * & A, const int count, const int key);
int Search(int * & A, const int count, const int key);
void Remove(int * &A, int & count, const int key);

void Initialize(int * & A, int & count, int & size)
{
	for(int i=0; i<20; i++)
	{
		if (count == size)
		{
			Double_Size(A,count,size);
		}
		A[i] = i+100;
		count++;
	}
}


void Double_Size(int * & A, int count, int & size)
{
	size *= 2;

	int * t = new int[size];

	for(int i=0; i<count; i++)
	{
		t[i] = A[i];
	}

	delete [ ] A;

	A = t;
}


void Add(int * & A, int & count, int & size, const int key)
{
	if (count == size)
	{
		Double_Size(A,count,size);
	}

	A[count] = key;
	count++;
}

void Print(int * & A, int & count)
{
	for(int i=0; i<count; i++)
	{
		cout<<"A[ "<<i<<" ] = "<< A[i] <<endl;
	}
}

int Search(int * & A, const int count, const int key)
{
	for(int i=0; i<count; i++)
	{
		if (A[i] == key)
		{
			return i;
		}
	}
	return -1;
}

void Remove(int * &A, int & count, const int key)
{
	int loc = Search(A,count,key);

	if(loc != -1)
	{
		for(int j=loc; j<count-1; j++)
		{
			A[j] = A[j+1];
		}
		count--;
	}
}



int main()
{
	int count = 0, size = 2, *A = new int[size];

	Initialize(A,count,size);
	cout<<endl<<"A before 114 is removed"<<endl;
	Print(A,count);
	Remove(A,count,114);
	cout<<endl<<"A after 114 is removed"<<endl;
	Print(A,count);

	return 0;
}