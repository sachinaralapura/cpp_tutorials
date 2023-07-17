#include "telList.h"

// --------------------------- append() method ----------------------------

bool TelList::append(const string &name, const string &telNo)
{
    int src = search(name);
    if (count < MAX && name.length() > 1 && src == -1)
    {
        Element temp;
        temp.name = name;
        temp.telNo = telNo;
        v[count++] = temp;
        dirty = true;
        return true;
    }
    return false;
}

// --------------------------- search() method ----------------------------

int TelList::search(const string &name) const
{
    for (int i = 0; i < count; i++)
    {
        if ((this->v[i]).name == name)
            return i;
    }
    return -1;
}

// --------------------------- erase() method ----------------------------

bool TelList::erase(const string &name)
{
    int pos = search(name);
    if (pos != -1)
    {
        int i = pos;
        while (i < count)
        {
            this->v[i] = this->v[i + 1];
            i++;
        }
        count--;
        return true;
    }
    else
    {
        printf("given name is not in the lists\n");
    }

    return false;
}

string TelList::getNumber(const string &name)
{
    int pos = search(name);
    return this->v[pos].telNo;
}

// ------------------------------- print() methods ---------------------

void TelList::print()
{
    for (int i = 0; i < count; i++)
    {
        print(i);
    }
}
void TelList::print(int i)
{
    if (i < this->count)
    {
        cout << "---------------------------------------------------" << endl;
        cout << "          name : " << v[i].name << endl;
        cout << "          telephone number : " << v[i].telNo << endl;
        cout << "---------------------------------------------------" << endl;
    }
    else
        cout << "give valid number" << endl;
}

//----------------------------------- Load() method --------------------------

bool TelList::load()
{
    cout << "\n--- Load the telephone list "
         << "from a file. ---"
         << "\nFile: ";

    string file;
    cin.sync();
    cin.clear();
    cin >> file; // fileName input
    if (file.empty())
    {
        cerr << "File is empty " << endl;
        return false;
    }

    // open the file for reading:
    ifstream infile(file.c_str(), ios::in | ios::binary);
    if (!infile)
    {
        cerr << "File " << file << "could not be opened! " << endl;
        return false;
    }

    int i = 0;
    while (i < MAX)
    {
        getline(infile, v[i].name, '\0');
        getline(infile, v[i].telNo, '\0');

        if (!infile)
            break;
        ++i;
    }

    if (i == MAX)
        cerr << "MAX capacity has been reached" << endl;
    else if (!infile.eof())
    {
        cerr << "Error reading file " << file << endl;
        return false;
    }

    count = i;
    fileName = file;
    dirty = false;
    return true;
}

//------------------------------------ saveAs() method ----------------------

bool TelList::saveAs()
{
    cout << "-- Save the telephone list in a file. --"
         << "\nFile: ";
    string file;
    cin.clear();
    cin.sync();
    cin >> file;
    if (!setFilename(file))
    {
        cerr << "No file name declared!" << endl;
        return false;
    }
    return save();
}

//----------------------------------- save() method -------------------------

bool TelList::save()
{
    // save the telephone list
    if (fileName.empty())
        return saveAs();
    if (!dirty)
        return true;

    ofstream outFile(fileName.c_str(), ios::out | ios::binary);
    if (!outFile)
    {
        cerr << "File " << fileName
             << " could not be opened!" << endl;
        return false;
    }

    int i = 0;
    while (i < count)
    {
        outFile << v[i].name << '\0';
        outFile << v[i].telNo << '\0';
        ++i;
        if (!outFile)
            break;
    }
    if (i < count)
    {
        cerr << "Error writing to file " << fileName << endl;
        return false;
    }
    dirty = false;
    return true;
}