#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream in;
	in.open("data.txt");

	string s;
	getline(in, s);
	cout << s << endl;

	for (int i = 0; i < s.length(); i++)
	{
		cout << static_cast<char>(tolower(s[i]));
	}
	cout << endl;

	for (int i = 0; i < s.length(); i++)
	{
		cout << tolower(s[i])<<' ';
	}

	cout << endl;

	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i] << "  " << tolower(s[i]) << endl;
	}

	cout << endl;

	int lower_letter_count = 0;
	int upper_letter_count = 0;
	int space_count = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			lower_letter_count++;
		else if (s[i] >= 'A' && s[i] <= 'Z')
			upper_letter_count++;
		else if (s[i] == ' ')
			space_count++;
	}

	cout << "lower_letter_count = "<<lower_letter_count << endl;
	cout << "upper_letter_count = " << upper_letter_count << endl;
	cout << "space_count = " << space_count << endl;

	for (int i = 1; i < 27; i++)
	{
		cout << static_cast<char>(96 + i) << endl;
	}

	in.close();

	return 0;
}

