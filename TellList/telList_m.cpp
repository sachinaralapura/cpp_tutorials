#include "telList.h"

bool TelList::append(const string &name, const string &telNo)
{
    int src = search(name);
    if (count < 100 && name != " " && src== -1)
    {
        Element temp;
        temp.name = name;
        temp.telNo = telNo;
        v[count++] = temp;
        return true;
    }
    return false;
}

int TelList::search(const string &name)
{
    for (int i = 0; i < count; i++)
    {
        if ((this->v[i]).name == name)
            return i;
    }
    return -1;
}

bool TelList::erase(const string &name)
{
    int pos = search(name);
    if(pos!= -1){
        int i = pos;
        while(i < count){
            this->v[i] = this->v[i+1];
            i++;
        }
        count--;
        return true;
    }else{
        printf("given name is not in the lists\n");
    }

    return false;
}

string TelList::getNumber(const string& name){
    int pos = search(name);
    return this->v[pos].telNo;
}

void TelList::print(){
    for(int i = 0; i < count; i++){
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