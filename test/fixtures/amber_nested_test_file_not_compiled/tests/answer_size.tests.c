#include "tests/answer_size.tests.h"
#include "hiker.h"
#include <assert.h>

/* The makefile gathers its sources with *.c, which matches this directory
   only, so a test file put in a sub-directory is never compiled. The header
   beside it still declares the test, so main() compiles and the mistake
   surfaces at link time as an undefined reference. */
void the_answer_is_two_digits_long(void)
{
    assert(answer() > 9 && answer() < 100);
}
