#include <iostream>
#include <string>

using std::cout;
using std::string;

string cat_dot(const string& s1, const string& s2, const char& sep)
{
	string concat{};
	concat = s1 + sep + s2;
	return concat;
}

int main()
{
	string str1{"First"};
	string str2{"Second"};
	char sep{'_'};
	string str3 = cat_dot(str1, str2, sep);
	cout << str3;
	return 0;
}