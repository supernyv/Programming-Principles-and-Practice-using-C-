/*
Exercise 3
Replace Name_pair::print() with a (global) operator << and define ==
and != for Name_pairs.
*/

#include "..\std_lib_facilities.h"

class Name_pairs{
	string a_name;
	double a_number;
	public:
		vector<string> name;
		vector<double> age;
		void read_names();
		void read_ages();
		void sort();
		string operator==(const Name_pairs&);
		string operator!=(const Name_pairs&);
};

void Name_pairs::read_names()
{
	//Read a series of names
	cout << "\nEnter space separated names. Add a space and a semi colon at the end to end input:\n";
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

ostream& operator<< (ostream& os, const Name_pairs& pairs)
{
	//Print out the (name[i], age[i]) pairs (one per line) in the order determined by name vector
	for(int i = 0; i < (pairs.name).size(); i++){
		os << "(" << pairs.name[i] << ", " << pairs.age[i] << ")\n";
	}
	return os;
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

string Name_pairs::operator==(const Name_pairs& right_pairs)
{
	if(name.size() != (right_pairs.name).size()){return "false";}
	for(int i = 0; i<name.size(); i++){
		if(name[i] != (right_pairs.name)[i] || age[i]!=(right_pairs.age)[i]) return "false";
	}
	return "true";
}

string Name_pairs::operator!=(const Name_pairs& right_pairs)
{
	if(name.size() != (right_pairs.name).size()){return "true";}
	for(int i = 0; i<name.size(); i++){
		if(name[i] != (right_pairs.name)[i] || age[i]!=(right_pairs.age)[i]) return "true";
	}
	return "false";
}

int main()
{
	Name_pairs first, second;
	first.read_names();
	first.read_ages();
	first.sort();
	cout << "\nFirst Pairs of names and ages.\n";
	cout << first;

	second.read_names();
	second.read_ages();
	second.sort();
	cout << "\nSecond Pairs of names and ages:\n";
	cout << second;

	cout << "\nAre they equal?: ";
	cout << (first == second);
	cout << "\nAre they not equal?: ";
	cout << (first != second);
	return 0;
}
