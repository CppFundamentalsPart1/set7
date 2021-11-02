#include "dnaencoder.ih"

void DnaEncoder::getChars(char val, char ret[4]) const
{
    for (size_t idx = 4; idx--; val >>= 2)
        switch (val & 0b11)
        {
            case 0:
                ret[idx] = 'A';
            break;
            case 1:
                ret[idx] = 'T';
            break;
            case 2:
                ret[idx] = 'G';
            break;
            case 3:
                ret[idx] = 'C';
            break;
        }
}
