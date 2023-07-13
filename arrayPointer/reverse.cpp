#include <iostream>
#include <string.h>
using namespace std;
#define CNT 80
void reverse(char *strPtr);
int main(){
    //int len;
    char word[CNT];

    cin.width(CNT);
    cin >> word;
    //len = strlen(word);
    // for(ptrWord = word + len; ptrWord>=word ; ptrWord--){
    //     cout << *ptrWord;
    // }
    reverse(word);
    return 0;
}

void reverse(char *strptr){
    int len  = strlen(strptr);
    char *ptr = strptr+len;
    while(ptr>=strptr){
        cout<< *ptr;
        ptr--;
    }
}