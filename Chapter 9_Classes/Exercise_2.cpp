/*
Chapter 9_Exercise 2
Design and implement a Name_pairs class holding (name,age) pairs where name is a string
and age is a double. Represent that as a vector<string> (called name) and a vector<double>
(called age) member. Provide an input operation read_names() that reads a series of names.
Provide a read_ages() operation that prompts the user for an age for each name. Provide
a print() operation that prints out the (name[i],age[i]) pairs (one per line) in the order 
determined by the name vector. Provide a sort() operation that sorts the name vector in 
alphabetical order and reorganizes the age vector to match. Implement all “operations” as 
member functions. Test the class (of course: test early and often).
*/

#include "..\std_lib_facilities.h"

class Name_pairs{
	vector<string> name;
	string a_name;
	vector<double> age;
	double a_number;
	public:
		void read_names();
		void read_ages();
		void print();
		void sort();
};

void Name_pairs::read_names()
{
	//Read a series of names
	cout << "Enter space separated names. Add a space and a semi colon at the end to end input:\n";
	while(cin >> a_name){
		if(a_name == ";") break;
		name.push_back(a_name);
	}
}

void Name_pairs::read_ages()
{
	//Prompt the user for an age for each name
	cout << "Enter the age of each person.\n";
	for(const string& person:name){
		cout << person << "'s age: ";
		cin >> a_number;
		age.push_back(a_number);
	}
}

void Name_pairs::print()
{
	//Print out the (name[i], age[i]) pairs (one per line) in the order determined by name vector
	cout << "\nPairs of names and ages as entered.\n";
	for(int i = 0; i < name.size(); i++){
		cout << "(" << name[i] << ", " << age[i] << ")\n";
	}
}

void Name_pairs::sort()
{
	//Sort the name vector in alphabetical order and reorganize the age vector to match
	const int length = name.size();
	string sorted_name[length];
	double sorted_age[length];
	int index = 0; //To keep track of the positions that have been changed in name
	int pos = 0; //Where the selected element should be moved

	for(const string& outer_name:name){
		int inferior_count = 0;
		//Now how many strings are greater than the current outer_name?
		for(const string& inner_name:name){
			if(outer_name<=inner_name) inferior_count += 1;
		}
		pos = length - inferior_count;
		sorted_name[pos] = outer_name;
		sorted_age[pos] = age[index];
		index += 1;
	}

	//Vector = {pointer to 1st element of array, pointer to last element of array}
	name = {sorted_name, sorted_name + length};
	age = {sorted_age, sorted_age + length};

}

int main()
{
	Name_pairs sample;
	sample.read_names();
	sample.read_ages();
	sample.sort();
	sample.print();
	return 0;
}
