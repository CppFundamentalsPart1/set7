#include "lock.ih"

bool Lock::valid() const
{
    return d_fd > -1;
}