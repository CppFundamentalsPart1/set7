#include "main.ih"

#include <unistd.h>

int main(int argc, char *argv[])
{
    bool printAll = getopt(argc, argv, "a") == 'a';

    if (argc < 3)
    {
        ifstream in("/var/log/account/pacct");
        readProcess(in, printAll);
        in.close();
    }
    else
    {
        for (size_t idx = 2, end = argc; idx < end; ++idx)
        {
            ifstream in(argv[idx]);
            readProcess(in, printAll);
            in.close();
        }
    }

}