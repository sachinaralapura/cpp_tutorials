#include "fileOperation.h"
char header[] = "* * *P I Z Z A P R O N T O * * *\n\n ";
struct Pizza
{
    char name[50];
    float price;
};

Pizza pizzaMenu[10] = {
    {"Pepperoni", 9.90F},
    {"White Pizza", 15.90F},
    {"Ham Pizza", 12.50F},
    {"Calzone", 14.90F}};
int main(int argc, char const *argv[])
{
    cout << header << endl;
    ofstream outFile;
    if (argc > 1)
    {
        outFile.open(argv[1], ios::out | ios::binary);
        if (outFile.fail())
            fileOpenError(argv[1]);
        else
        {
            for (int i = 0; i < 4; i++)
            {
                outFile << "Name : " << pizzaMenu[i].name
                        << "  price : " << pizzaMenu[i].price << endl;
                // outFile.write((char*)&pizzaMenu[i], sizeof(Pizza));
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        cout << (char *)&pizzaMenu[i] << endl;
    }

    return 0;
}
