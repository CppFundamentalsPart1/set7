#include "lock.ih"

int Lock::open(string lockPath) const
{
    return ::open(lockPath.c_str(), O_CREAT | O_RDWR, 0600);
}