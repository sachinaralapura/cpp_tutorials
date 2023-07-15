#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int a = 10;
	int  &ref = a;
	int *ptra ;
	ptra = &a;
	ref++;
	(*ptra)++;
	cout << "a " << a << endl;
	cout << "reference " << ref << endl;
	cout << "'pointer " << *ptra << endl; 
	cout << "a " << a << endl;
}
