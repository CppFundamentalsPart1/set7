#include "dnaencoder/dnaencoder.h"

#include <fstream>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
    bool writeBinary = getopt(argc, argv, "b") == 'b';
    if (argc < 3 + writeBinary)
        return -1;


    ifstream in(argv[argc - 2]);
    ofstream out(argv[argc - 1]);

    DnaEncoder encoder;
    if (writeBinary)
        encoder.convToBinary(in, out);
    else
        encoder.convToText(in, out);

    in.close();
    out.close();
}