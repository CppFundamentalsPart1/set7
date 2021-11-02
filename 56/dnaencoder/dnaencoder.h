#ifndef _DNA_ENCODER_H_
#define _DNA_ENCODER_H_

#include <iosfwd>

class DnaEncoder
{
    static char const s_magicHeader = 109;
public:
    bool convToBinary(std::ifstream &in, std::ofstream &out) const;
    bool convToText(std::ifstream &in, std::ofstream &out) const;

private:
    void copyFile(std::ifstream &in, std::ofstream &out) const;

    void getChars(char val, char ret[4]) const;
    bool getBinary(char bases[4], char *dest) const;
};

#endif  // _DNA_ENCODER_H_