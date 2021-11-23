#include "lock.ih"

Lock::Lock(string const &path, string const &lockDir)
{
    string lockName = lockPath(path, lockDir);

    if ((d_fileDescriptor = open(lockName)) < 0)  // opening failed
        return;

    if (flock(d_fileDescriptor, LOCK_EX) == -1)  // locking failed
        d_fileDescriptor = -1;
}