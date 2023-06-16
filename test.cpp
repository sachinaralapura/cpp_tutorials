#include <iostream>
void add(int *x){
    std::cout << *x << std::endl;
}
int main(){
    int *p ;
    int **pp;
    int x(5);
    add(&x);
    p = &x;
    pp = &p;

    std:: cout << "the address of a is : "  << &x << std::endl;
    std::cout << "The address of the pointer p : " << p << std::endl;
    std::cout << "the value of *pp " << *pp << std::endl;
    std::cout << "The address of the pointer pp : " << pp << std::endl;
    std::cout <<"the value of  *p : "<< *p << std::endl;
    std::cout <<"the value of  *p + 5 : "<< (*p+5) << std::endl;
    std::cout << "the value of **pp : " << **pp << std::endl; 
    return 1;
}