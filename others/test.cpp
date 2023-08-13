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
// #include <GL/glut.h>
// #include <vector>
// #include <iostream>
// using namespace std;

// vector<int> oddNumbers(int l, int r) {
//     vector<int> arr;
//     for(int i = l ; i<=r; i++)
//         {
//             if((i%2)!=0){
//                 arr.push_back(i);
//             }
//         }
//     return arr;
// }
// int main(){
//     vector<int> arr1 = oddNumbers(2, 10);
//     for(int i = 0 ; i < arr1.size(); i++)
//         cout << arr1[i] << endl;
// }

#include <iostream>
using namespace std;

class Worker
{
private:
    string name;

public:
    Worker(const string &s = " ") : name(s) {}
    virtual ~Worker() {}
    virtual void display() const{};
    virtual void income() const = 0;
};

class Employee : public Worker
{
private:
    long salary;

public:
    Employee(const string &s = " ", long sal = 0) : Worker(s), salary(sal) {}
    void display() const
    {
        cout << "display" << endl;
    }
    void income() const
    {
        cout << salary << endl;
    }
};

int main()
{

    Worker *worker = new Employee("ravi", 12000);
    worker->income();
    return 0;
}