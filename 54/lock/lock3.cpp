#include "lock.ih"

Lock::~Lock()
{
    if (d_fd > -1)
        close(d_fd);
}