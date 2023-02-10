#include <iostream>
#include <vector>

using std::cout;
using std::vector;

vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int>& vect)
{
	int s = vect.size();
	vector<int> lv;
	cout << "\nPrinting the elements from vector: \n";
	for(int i = 0; i < s; ++i){
		lv.push_back(vect[i]);
		cout << lv[i] << " ";}

	vector<int> lv2{vect};
	cout << "\nPrinting the elements from vector copy: \n";
	for(int j=0; j < s; ++j){
		cout << lv2[j] << " ";
	}
}

int main()
{
	f(gv);

	vector<int> vv = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	f(vv);
	return 0;
}