#include "dnaencoder.ih"

void DnaEncoder::copyFile(std::ifstream &in, std::ofstream &out)
{
    //return to the beginning of both streams
    in.seekg(0);
    out.seekp(0);

    out << in.rdbuf();
}
