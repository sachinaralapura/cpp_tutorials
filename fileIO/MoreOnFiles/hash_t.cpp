#include <iostream>
#include <string>
#include "hashFile.h"
using namespace std;
int main()
{
    try
    {
        HashFile hash("Client.fle", 7);
        cout << "\nInsert: " << endl;
        HashEntry kde(0L, "Vivi");
        hash.insert(kde);

        kde.setNr(1L);
        kde.setName("Peter");
        hash.insert(kde);

        kde.setNr(2L);
        kde.setName("Alexa");
        hash.insert(kde);
        
        kde.setNr(3L);
        kde.setName("Peter");
        hash.insert(kde);
        
        kde.setNr(4L);
        kde.setName("Jeany");
        hash.insert(kde);
        
        cout << "\nInsertion complete: " << endl;
        hash.display();
        unsigned long key;
        cout << "Key? ";
        cin >> key;
        HashEntry temp = hash.retrieve(key);
        if (temp.getNr() != 0L)
            temp.display();
        else
            cout << "Key " << key
                 << " not found" << endl;
    }
    catch (OpenError &err)
    {
        cerr << "Error in opening the file:"
             << err.getName() << endl;
        return(1);
    }
    catch (WriteError &err)
    {
        cerr << "Error writing to file: "
             << err.getName() << endl;
        return(1);
    }
    catch (ReadError &err)
    {
        cerr << "Error reading from file: "
             << err.getName() << endl;
        return(1);
    }
    return 0;
}