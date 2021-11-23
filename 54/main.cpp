#include "lock/lock.h"

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    string file(argv[1]);  // file to append to

    ofstream out(file, ios::app);  // open file in append mode

    if (!out.good())  // if opening or appending failed close the program
        return 1;

    Lock lock(file);  // lock file access

    if (!lock.valid())  // lock failed so print error message and close
    {                   // the program
        cout << "Failed to lock " << file << '\n';
        return 1;
    }

    cout << "? ";  // prompt for the line to append
    string line;
    getline(cin, line);  // read the line

    out << line << '\n';  // append it to the file

    // lock gets released on program exit
}