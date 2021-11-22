#include "lock.ih"

Lock::Lock(string const &path, string const &lockDir)
{
    string lockName = lockPath(path, lockDir);

    if ((d_fd = open(lockName)) < 0)
        return;

    if (flock(d_fd, LOCK_EX) == -1)
        d_fd = -2;
}