#include "hiker.h"
#include <stddef.h>

int answer(void)
{
    return 6 * 9;
}

int checksum(void)
{
    /* The learner has not filled the table in yet, so it is still NULL and
       reading from it crashes the test program. Declaring the pointer
       volatile is what makes the read happen at all: the makefile compiles
       with -O, where a read the optimiser is free to fold away leaves
       nothing to crash. */
    int *volatile checksums = NULL;
    return checksums[0];
}
