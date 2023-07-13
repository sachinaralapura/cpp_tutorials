#include "telList.h"
TelList mainTelList;
string name, telNo;
inline void drawLine(){
    cout << "------------------------------------\n";
}
void getName(){
    cout << "Enter name\n";
    cin >> name;
}
void getNum(){
    cout << "enter Number\n";
    cin >> telNo;
}
int main(int argc, char const *argv[])
{

    // Element person;
    // person.name = "sachin";
    // person.telNo = "9897843798";

    // mainTelList.append(person);
    // mainTelList.print(12);
    mainTelList.append("sachin","4563456");
    mainTelList.append("vinag","45456456");
    mainTelList.append("Rakshith","5456345");

    char ch;
    cout << "enter choice\n";

    do
    {
        cout << "D = Display all entries\n"
                "F = Find a telephone number\n"
                "A = Append an entry\n"
                "E = Erase an entry\n"
                "Q = Quit the program\n"
             << endl;
        cin >> ch;
        switch (toupper(ch))
        {
        case 'D':
            mainTelList.print();
            break;
        case 'A':
            getName();getNum();
            drawLine();
            if (mainTelList.append(name, telNo))
            {
                cout << "appended " << name << endl;
            }
            else
            {
                cout << "name already exists" << endl;
            }
            drawLine();
            break;
        case 'E':
            getName();
            mainTelList.erase(name);
            break;
        case 'F':getName();
                drawLine();
                cout << name << " number is : " << mainTelList.getNumber(name) << endl;
                drawLine();
                break;
        case 'Q':
            exit(0);
        default:
            cout << "enter valid choice\n";
            break;
        }
    } while (true);

    return 0;
}
