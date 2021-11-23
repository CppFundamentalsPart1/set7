#include "lock.ih"

string Lock::stringName(string path, char *(*fun)(char *))
{
    return (*fun)(path.data());
}