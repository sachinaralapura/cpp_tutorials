#include <stdio.h>
#include <iostream>
using namespace std;
int main(){

	int a  = 10;
	int *ptr;
	ptr = &a;
	*ptr = 23;
	cout << a ;
	printf("Hello world");
	return 0;
}
