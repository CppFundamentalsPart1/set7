#ifndef _LOCK_H_
#define _LOCK_H_

#include <string>

class Lock
{
    int d_fd = -2;

public:
    Lock(std::string const &path);
    Lock(std::string const &path, std::string const &lockDir);
    ~Lock();

    bool valid() const;

private:
    int open(std::string lockPath) const;

    static std::string lockPath(std::string const &path,
                                std::string const &lockDir);

    static std::string stringName(std::string const &path,
                                  char *(*fun)(char *));
};

#endif /* _LOCK_H_ */