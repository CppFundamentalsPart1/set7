#include "lock.ih"

Lock::~Lock()
{
    if (d_fileDescriptor >= 0)
        close(d_fileDescriptor);  // close the file if it was locked
}