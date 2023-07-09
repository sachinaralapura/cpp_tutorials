#include "telList.h"
int main(int argc, char const *argv[])
{   
    TelList mainTelList;
    
    Element person;
    person.name = "sachin";
    person.telNo = "9897843798";

    mainTelList.append(person);
    mainTelList.print(0);
    return 0;
}
