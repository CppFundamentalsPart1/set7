#include <csignal>
#include <fstream>
#include <iostream>
#include <linux/acct.h>
using namespace std;

int main()
{
    acct_v3 data;

    ifstream acctFile("/var/log/account/pacct");

    while (true)
    {
        acctFile.read(reinterpret_cast<char *>(&data), sizeof(data));

        if (!acctFile)
            break;


        if (data.ac_exitcode != 0)
        {
            cout << "program: ";

            for (auto it = data.ac_comm; *it != 0; ++it)
                cout << *it;

            cout << " code: " << data.ac_exitcode << '\n';
        }
    }

    acctFile.close();
}