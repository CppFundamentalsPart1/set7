#include "main.ih"

#include <unistd.h>

extern int optind; // contains the index of the first non-option in argv

int main(int argc, char *argv[])
{
    bool printAll = getopt(argc, argv, "a") == 'a'; // check if option a is set

    while (getopt(argc, argv, "a") != -1); // let getopt read through all args


    if (optind == argc) // if no further arguments provided read default file
    {
        ifstream in("/var/log/account/pacct");
        readProcesses(in, printAll);
        in.close();
    }
    else  // else read through each argument and print the process info
    {
        for (size_t idx = optind, end = argc; idx < end; ++idx)
        {
            ifstream in(argv[idx]);
            readProcesses(in, printAll);
            in.close();
        }
    }

}