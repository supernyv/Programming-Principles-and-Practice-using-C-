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

char* copy_move(const char* str)
{
	const int len = cstr_len(str)+2;
	char* itr = new char[len];

	//place a null at the begining of str_itr and move to second position
	*itr = '\0';
	++itr;

	//Copy str into str_itr;
	while(*str){
		*itr = *str;
		++str;
		++itr;}
	//Place another null at the end of str_itr and move backward, before iterating
	*itr = '\0';
	--itr;

	return itr; //itr is already pointing at the last element, the 0 character
}

char* reverse(const char* str)
{
	const int len = cstr_len(str)+1;

	//One string for copying the reverse of str
	char* str_cp = new char[len];

	//One string to return the pointer at the begining of the reverse
	char* str_ptr = new char[len];
	str_ptr = str_cp;

	//Copy str into a new string and move the pointer to the last element of that string
	char* str_itr = copy_move(str);

	//Str_itr is already at the end, iterate backwards
	while(*str_itr){
		*str_cp = *str_itr;
		--str_itr;
		++str_cp;
	}

	//Now Place the null at the end of str_cp
	*str_cp = '\0';

	//Delete str_itr because we no longer need it;
	delete[] str_itr;

	return str_ptr;
}

char comp_str(const char* s1, const char* s2)
{
	while(*s1 && *s2){
		if(*s1 != *s2) return 'N';
		++s1;
		++s2;
	}
	return 'Y';
}

int main()
{
	const char* str1 = "mayhyam";
	const char* str2 = reverse(str1);

	char sol = comp_str(str1, str2);
	cout << "Is the string \"" << str1 << "\" a palindrome? : " << sol << endl;
}
