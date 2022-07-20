#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *emoji = "\xF0\x9F\x8E\x82";
    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");

    int c;
    unsigned int bytes = 0;
    int found = 0;

    while ((c = fgetc(fp)) != EOF)
    {
        unsigned b = (unsigned)c & 0xff;
        printf("%u\n", b);

        if ((b & 0x80) && (~b & 0x40)) // Has leading bytes
        {
            bytes = (bytes << 8) | b;
            continue;
        }

        printf("Bytes: %u\n", bytes);

        if (bytes == 0xf09f8e82)
        {
            found = 1;
            break;
        }

        bytes = b;
    }

    if (bytes == 0xf09f8e82)
    {
        found = 1;
    }

    fclose(fp);

    return found == 1 ? 0 : 1;
}