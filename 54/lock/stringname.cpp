#include "lock.ih"

string Lock::stringName(string const &path, char *(*fun)(char *))
{
    char fileName[path.length() + 1];

    fileName[path.copy(fileName, string::npos)] = 0;

    return (*fun)(fileName);
}