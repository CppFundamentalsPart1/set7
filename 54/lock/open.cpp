#include "lock.ih"

int Lock::open(string const &lockPath)
{
    return ::open(lockPath.c_str(), O_CREAT | O_RDWR, 0600);
}