CFLAGS += -I.
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -x c
CFLAGS += -std=c18
CFLAGS += -Wshadow
CFLAGS += -Wfloat-equal
CFLAGS += -O
CFLAGS += -Wsequence-point
CFLAGS += -Wmissing-noreturn
CFLAGS += -Wunreachable-code
CFLAGS += -Wmissing-prototypes
CFLAGS += -Wstrict-prototypes

CFLAGS += -fprofile-arcs -ftest-coverage

#CFLAGS += -fsanitize=leak,address
#CFLAGS += -fno-sanitize-recover=undefined
CFLAGS += -fno-omit-frame-pointer

H_FILES = $(wildcard *.h)
COMPILED_H_FILES = $(patsubst %.h,%.compiled_h,$(H_FILES))
C_FILES = $(wildcard *.c)

.PHONY: test.output
test.output: test makefile
	@./$<

test: $(C_FILES) $(COMPILED_H_FILES)
	@$(CC) $(CFLAGS) -O $(C_FILES) -o $@

# This rule ensures header files build in their own right.
# The quality of header files is important because header files
# are #included from other files and thus have a large span
# of influence (unlike .cpp files which are not #included)

%.compiled_h: %.h
	@$(CC) -x c++ $(CFLAGS) -c -o $@ $<
