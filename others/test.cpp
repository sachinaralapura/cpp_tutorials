// #include <stdio.h>
// #include <iostream>
// using namespace std;
// int main()
// {
// 	int a = 10;
// 	int  &ref = a;
// 	int *ptra ;
// 	ptra = &a;
// 	ref++;
// 	(*ptra)++;
// 	cout << "a " << a << endl;
// 	cout << "reference " << ref << endl;
// 	cout << "'pointer " << *ptra << endl; 
// 	cout << "a " << a << endl;
// }
#include <GL/glut.h>
#include <vector>
#include <iostream>
using namespace std;

vector<int> oddNumbers(int l, int r) {
    vector<int> arr;
    for(int i = l ; i<=r; i++)
        {
            if((i%2)!=0){
                arr.push_back(i);
            }
        }
    return arr;
}
int main(){
    vector<int> arr1 = oddNumbers(2, 10);
    for(int i = 0 ; i < arr1.size(); i++)
        cout << arr1[i] << endl;
}