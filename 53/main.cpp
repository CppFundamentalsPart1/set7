#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    double value = 12.04;

    cout << "std display:      '" << setw(15) << value << "'\n"
         << "left aligned:     '" << setw(15) << left << value << "'\n"
         << "right aligned:    '" << setw(15) << right << value << "'\n"
         << "3 digits:         '" << setw(15) << setprecision(3) << showpoint
            << value << noshowpoint << "'\n"
         << "4-digit fraction: '" << setw(15) << fixed << setprecision(4)
            << value << "'\n"
         << "std display:      '" << setw(15) << resetiosflags(ios::fixed)
            << value << "'\n";
}