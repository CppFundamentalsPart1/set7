#include "lock/lock.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
    if (argc == 1)
        {
            cout << "Usage: " << argv[0] << " filename\n"
                    "to append a line to `filename'\n";
            return 0;
        }

        string file{ argv[1] };

        ofstream out{ file, ios::app };     // prepare for appending
        if (not out.good())
            return 1;                       // couldn't append

        Lock lock{ file, "/tmp" };          // lock access

        if (not lock.valid())
        {
            cout << "Can't lock " << file << '\n';
            return 1;
        }

        cout << "? ";                       // show prompt, then read a line
        string line;                        // fm. cin
        getline(cin, line);

        out << line << '\n';                // append the line
}