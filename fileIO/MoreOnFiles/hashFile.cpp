#include "hashFile.h"

// ----------------- methods of HashEntry----------------------

fstream &HashEntry::write(fstream &f)
{
    f.write((char *)&nr, sizeof(nr));
    f.write(name, sizeof(name));
    return f;
}

fstream &HashEntry::read(fstream &f)
{
    f.read((char *)&nr, sizeof(nr));
    f.read(name, sizeof(name));
    return f;
}

fstream &HashEntry::write_at(fstream &f, unsigned long pos)
{
    f.seekp(pos);
    f.write((char *)&nr, sizeof(nr));
    f.write(name, sizeof(name));
    return f;
}

fstream &HashEntry::read_at(fstream &f, unsigned long pos)
{
    f.seekp(pos);
    f.read((char *)&nr, sizeof(nr));
    f.read(name, sizeof(name));
    return f;
}

//----------------------- methods of HashFile -------------------------------

HashFile::HashFile(const string file, unsigned long n) throw(OpenError)
{
    ios::openmode mode = ios::in | ios::out | ios::binary;
    f.open(file.c_str(), mode);
    if (!f)
    {
        f.clear();
        mode |= ios::trunc;
        f.open(file.c_str(), mode);
        if (!f)
            throw OpenError(name);
    }

    name = file;
    b = n;
    HashEntry rec(0L, "");
    f.seekp(0L);
    for (unsigned long i = 0; i < b; i++)
    {
        rec.write(f);
        if (!f)
            throw WriteError(name);
    }
}

void HashFile::insert(HashEntry &rec) throw(ReadError, WriteError)
{
    HashEntry temp;
    int size = temp.getSize();
    unsigned long pos = hash_func(temp.getNr()); //   here pos the nth entry
    // Checking if the position at pos*size is empty or not  using "temp"
    temp.read_at(f, pos * size);
    if (!f)
        throw ReadError(name);
    else
    {
        if (temp.getNr() == 0L)          // if Nr is still 0L after reading the position pos*size
            rec.write_at(f, pos * size); // ie the pos*size position is empty , hence we can write_at this position
        else
        {
            bool found = false;
            unsigned long p = (pos * size + size) % (b * size); // here  b is total blocks and (b*size) is maximum size and (pos * size + size) is next block
            while (!found && p != (pos * size))
            {
                temp.read_at(f, p);
                if (!f)
                    throw ReadError(name);
                else
                {
                    if (temp.getNr() == 0L) // free block
                        found = true;
                    else
                        p = (p + size) % (b * size);
                }
            }

            if (p == pos * size)
                throw WriteError(name);
            if (found == true)
                rec.write_at(f, p);
        }

        if (!f)
            throw WriteError(name);
    }
}

HashEntry &HashFile::retrieve(unsigned long key) throw(ReadError)
{
    static HashEntry temp;
    int size = temp.getSize();
    unsigned long pos = hash_func(key); // Hash value.

    temp.read_at(f, pos * size);

    if (!f)
        throw ReadError(name);
    if (temp.getNr() == key)
    {
        return temp;
    }
    else
    {
        unsigned long p = (pos * size + size) % (b * size);
        while (p != pos * size)
        {
            temp.read_at(f, p);
            if (!f)
                throw ReadError(name);
            else
            {
                if (temp.getNr() == key)
                    return temp;
                else
                    p = (p + size) % (b * size);
            }
        }

        temp.setNr(0L);
        temp.setName("");
        return temp;
    }
}

void HashFile::display()
{
    HashEntry temp;
    f.seekg(0L);
    for (unsigned int i = 0; i < b; i++)
    {
        temp.read(f);
        if (!f)
            throw ReadError(name);
        temp.display();
    }
    f.clear();
}