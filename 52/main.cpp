#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

ostream &now(ostream &out)
{
    time_t seconds = time(0);

    return out << put_time(localtime(&seconds), "%c");
}

int main(int argc, char *argv[])
{
    cout << now << '\n';
}