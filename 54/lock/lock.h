#ifndef _LOCK_H_
#define _LOCK_H_

#include <string>

class Lock
{
    int d_fileDescriptor = -1;  // file descriptor, negative indicates error

public:
    Lock(std::string const &path);  // lock file in current directory (lock1)

    // lock fine named path in directory lockDir (lock2)
    Lock(std::string const &path, std::string const &lockDir);
    ~Lock();  // releases the lock on the lockfile (lock3)

    bool valid() const;  // is the file descriptor valid

private:
    static int open(std::string const &lockPath);  // open and lock the file

    static std::string lockPath(std::string const &path,      // create path
                                std::string const &lockDir);  // for lockfile

    // get the requested part of path by passing dirname or basename as fun
    // use copy because fun is allowed to modify its argument
    static std::string stringName(std::string path,
                                  char *(*fun)(char *));
};

#endif /* _LOCK_H_ */