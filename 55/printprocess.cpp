#include "main.ih"

void printProcess(acct_v3 const &process)
{
    cout << '\'' << process.ac_comm << "' ";  // print process name

    // print name if kill or term, else print exit code
    switch (process.ac_exitcode)
    {
        case SIGKILL:
            cout << "KILL\n";
        break;
        case SIGTERM:
            cout << "TERM\n";
        break;
        default:
            cout << process.ac_exitcode << '\n';
        break;
    }
}