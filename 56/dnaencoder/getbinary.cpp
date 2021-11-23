#include "dnaencoder.ih"

bool DnaEncoder::getBinary(char const bases[4], char *dest)
{
    *dest = 0;  // reset value to 0

    for (size_t idx = 4, shift = 0; idx--; shift += 2)
        switch (bases[idx])
        {
            case 'A':  // shifting in 0 would be useless
            break;
            case 'T':
                *dest |= 1 << shift;
            break;
            case 'G':
                *dest |= 2 << shift;
            break;
            case 'C':
                *dest |= 3 << shift;
            break;
            default:
            return false;
        }

    return true;
}
