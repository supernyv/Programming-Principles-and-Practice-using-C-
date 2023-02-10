#include <iostream>

using std::cout;
using std::endl;

int cstr_len(const char* s)
{
	int len = 0;
	while(*s){
		len += 1;
		++s;
	}
	return len;
}

char* cat_dot(const char* s1, const char* s2)
{
	const int len = cstr_len(s1) + cstr_len(s2) + 1;

	char* cp = new char[len];
	char* concat = cp;

	//Copy the first c-string
	while(*s1){
		*concat = *s1;
		++concat;
		++s1;
	}

	//Place the seperator and move to the next address
	*concat = '.';
	++concat;

	//Concatenate the second string to the first
	while(*s2){
		*concat = *s2;
		++concat;
		++s2;
	}

	//Add the 0
	*concat = '\0';

	return cp;
}

int main()
{
	const char* str1 = "One";
	const char* str2 = "Another";
	
	const char* str3 = cat_dot(str1, str2);
	cout << str3 << endl;
	delete[] str3;
	return 0;
}