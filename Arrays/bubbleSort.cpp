#include <iostream>
using namespace std;
#define MAX 100
long num[MAX];
int count;
void display(){
    for(int i = 0; i <  count;i++ ){
        cout << num[i] << endl;
    }
}

int main(){
    int i;
    for(i = 0 ; i <MAX && cin >> num[i]; ++i)
    ;
    count = i;
    long temp;
    int end = count;
    bool sorted = false;
    while(!sorted){
        sorted = true;
        --end;
        for(i = 0 ; i < end; i++){
            if(num[i]> num[i+1]){
                sorted = false;
                temp = num[i];
                num[i] = num[i+1];
                num[i+1] = temp;
            }
        }
    }

    display();
}