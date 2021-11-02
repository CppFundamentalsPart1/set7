#include "main.ih"

void readProcesses(ifstream &in, bool writeAll)
{
    acct_v3 processData;
    while (true)
    {
        in.read(reinterpret_cast<char *>(&processData), sizeof(processData));

        if (!in)
            break;

        if (processData.ac_exitcode != 0 || writeAll)
            printProcess(processData);
    }
}