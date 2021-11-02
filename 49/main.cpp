#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    ostream out(cout.rdbuf());

    out.setstate(ios::failbit);

    for (size_t idx = 0, end = stoul(argv[1]); idx < end; ++idx)
        if (out.good())
            out << "Nr. of command line arguments " << argc << '\n';

}