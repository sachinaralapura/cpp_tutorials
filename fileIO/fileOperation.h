#include <iostream>
#include <fstream>
using namespace std;
inline void fileOpenError(const char *fileName){
    std::cout << "error in opening file " << fileName << std::endl;
    exit(1);
}

void copyFile(istream &source , ostream &destination){
    char c;
    while(source.get(c)){
        // destination.put(c); or 
        destination << c;
    }
}

