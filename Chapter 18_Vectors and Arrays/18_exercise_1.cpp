#include <iostream>

using std::cout;

int str_len(const char* s)
{
	int len = 0;
	while(*s){
		len += 1;
		++s; //s is a local variable, changes to it don't affect c_str in strup()
	}
	return len;
}

char* strdup(const char* c_str)
{
	const int len = str_len(c_str) + 1; //c-style string are 0 terminated
	//So we need a space to add the 0 at the end of a copy

	char* copied = new char[len];

	char* cp = copied; //Make a duplicate of copied that you can use to move 

	while(*cp++ = *c_str++); //copy values from c_str to cp untill you meet the null character
	//This while evaluates *s_str firt because it's the r-value of the assignment.
	*copied = '\0';

	return copied; //copied still points to the same adress because cp was used for increment
}

int main()
{
	const char* original = "A string"; //0-terminated string, pointing after g returns the null character
	const char* my_str = strdup(original); //strdup also return a zero-terminated string;
	cout << my_str;

	delete[] my_str;
	return 0;
}