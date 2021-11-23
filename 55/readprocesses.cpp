#include "main.ih"

void readProcesses(ifstream &in, bool writeAll)
{
    acct_v3 processData;

    // while we successfully read data from the file
    while (
      in.read(reinterpret_cast<char *>(&processData), sizeof(processData)))
    {
        // print the file if it has nonzero exit code or if we should write all
        if (processData.ac_exitcode != 0 || writeAll)
            printProcess(processData);
    }
}