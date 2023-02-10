#include <iostream>
/*
A string a is lexicographically smaller than string b (of the same length) if in the first position 
where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding 
letter in b. For example, “abc” is lexicographically smaller than “bac” because ‘a’ comes before ‘b’ in 
dictionary order.
*/

using std::cout;

int strcmp(const char* s1, const char* s2)
{
	//Duplicate the c-stryle strings
	const char* s1_cp = s1;
	const char* s2_cp = s2;

	//Check which string comes first
	while(*s1_cp && *s2_cp){ //Dereference, evaluate, execute statement body, then increment. Repeat
		if(*s1_cp < *s2_cp) return -1;
		else if(*s1_cp > *s2_cp) return 1;
		++s1_cp;
		++s2_cp;
	}

	//Check if one string is shorter
	if(*s1_cp) return 1;	//Then s2_cp is shorter
	if(*s2_cp) return -1;	//Then s1_cp is shorter
	//If no letter is greater still, then all are equal
	return 0;
}

int main()
{
	char str1[] = "Example";
	char str2[] = "Example";

	cout << strcmp(str1, str2);
	return 0;
}