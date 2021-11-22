#include "lock.ih"

string Lock::lockPath(string const &path, string const &lockDir)
{
    return lockDir + '/' + stringName(path, &basename) + ".lck";
}