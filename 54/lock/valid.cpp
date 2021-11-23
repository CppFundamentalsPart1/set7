#include "lock.ih"

bool Lock::valid() const
{
    return d_fileDescriptor >= 0;
}