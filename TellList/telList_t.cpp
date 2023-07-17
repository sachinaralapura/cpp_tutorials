#include "telList.h"
TelList mainTelList;
string name, telNo;
inline void drawLine()
{
    cout << "------------------------------------\n";
}
void getName()
{
    cout << "Enter name\n";
    cin >> name;
}
void getNum()
{
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
    // mainTelList.append("sachin", "4563456");
    // mainTelList.append("vinag", "45456456");
    // mainTelList.append("Rakshith", "5456345");

    char ch;
    cout << "enter choice\n";

    do
    {
        cout << "D = Display all entries\n"
                "F = Find a telephone number\n"
                "A = Append an entry\n"
                "E = Erase an entry\n"
                "Q = Quit the program\n"
                "O = Open a file\n"
                "W = Save\n"
                "U = Save as... \n"
             << endl;
        cin >> ch;
        switch (toupper(ch))
        {
        case 'D':
            mainTelList.print();
            break;

        case 'A':
            getName();
            getNum();
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

        case 'F':
            getName();
            drawLine();
            cout << name << " number is : " << mainTelList.getNumber(name) << endl;
            drawLine();
            break;

        case 'O':
            drawLine();
            if (mainTelList.isDirty())
                mainTelList.save();
            if (mainTelList.load())
                cout << "Telephone list read from file "
                     << mainTelList.getFileName() << "!"
                     << endl;
            drawLine();
            break;

        case 'W':
            drawLine();
            if (mainTelList.save())
                cout << "Telephone list has been saved in "
                     << "the file "
                     << mainTelList.getFileName() << endl;
            else
                cerr << "Telephone list not saved!"
                     << endl;
            drawLine();
            break;

        case 'U':
            drawLine();
            if (mainTelList.saveAs())
                cout << "Telephone list has been saved in file: "
                     << mainTelList.getFileName() << " !" << endl;
            else
                cerr << "Telephone list not saved!" << endl;
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
