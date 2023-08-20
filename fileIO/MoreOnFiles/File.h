/*
Random file access gives you the option of reading and writing information directly at a pre-defined position.
To be able to do this, you need to change the current file position explicitly, that is, you need to point
the get/put pointer to the next byte to be manipulated. After pointing the pointer, you can revert to using
the read and write operations that you are already familiar with.

■ Discovering and Changing the Current Position
    The file stream classes comprise methods to discover and change the current position in
a file. The tellp() and tellg() methods return the current position of the put or
get pointers as a long value.

Example: long rpos = myfile.tellg();

 - The current file position can be modified using the seekp() or seekg() method.

■ Positioning Flags
The fstr.seekp(pos, ios::begin); statement  seeks to the position pos in the stringstream fstr.
The ios::begin parameter specifies that the position is relative to the beginning of the stringstream.

    If pos is 10, then the fstr.seekp(pos, ios::begin); 
    statement will seek to the 10th character in the stringstream.

*/