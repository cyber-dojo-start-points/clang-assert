#include "hiker.h"
#include <stddef.h>

/* Neither table has been filled in yet, so both are still NULL and reading
   from either one crashes the test program. Declaring the pointers volatile
   is what makes the reads happen at all: the makefile compiles with -O,
   where a read the optimiser is free to fold away leaves nothing to
   crash. */

int answer(void)
{
    int *volatile answers = NULL;
    return answers[0];
}

int checksum(void)
{
    int *volatile checksums = NULL;
    return checksums[0];
}
