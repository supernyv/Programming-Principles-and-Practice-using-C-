#include <iostream>

using std::cout;

int ga[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(const int arr[], const int s)
{
	int la[s];
	cout << "\nPrinting the elements from array: \n";
	for(int i = 0; i < s; ++i){
		la[i] = arr[i];
		cout << la[i] << " ";}

	int* p = new int[s];
	cout << "\nPrinting the elements from free store: \n";
	for(int j=0; j < s; ++j){
		p[j] = arr[j];  //Points to and dereferences the jth element
		cout << p[j] << " ";
	}
	delete[] p;
}

int main()
{
	f(ga, 10);

	int aa[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
	f(aa, 10);
	return 0;
}