# build file to compile to output but windows (TM) (this took me FAR too long)
# TODO: merge with main makefile using OS detection

# windows oofy goofy error (no root required in path is assumed)

SRCDIR            :=  src
INCDIR            :=  include
TESTDIR           :=  tests
OBJDIR            :=  obj
BINDIR            :=  bin

TARGET            :=  lang

USE_GCC           := yes


ifeq ($(USE_GCC),)

# use llvm toolchain
CC                :=  clang
LD                :=  lld -flavor ld

else

# use GCC toolchain
CC                :=  gcc
# windows oofy goofy moment im too tired to count: ld is not ld but gcc because mingw says so
LD                :=  gcc

endif

CFLAGS            := -Wall -Werror -O1
LDFLAGS           := -o

CC_SRCS           :=  $(wildcard $(SRCDIR)/*)
CC_OUTS           :=  $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CC_SRCS))

MAKE              :=  make

all: init $(CC_OUTS) Link
# Run tests
	$(MAKE) -f $(TESTDIR)/Makefile

init:
# windows oofy goofy error x2 (mkdir does not have -p on Windows)
# and x3 (mkdir errors when folders exist already) (bad solution i know)
# and x4 (why no rm in cmd.exe)
	rmdir /s /q $(OBJDIR) $(BINDIR)
	mkdir $(OBJDIR) $(BINDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo
	$(CC) $(CFLAGS) -c $< -o $@
	@echo


Link:
# chagned this i guess
# i love windows
	$(LD) -o $(BINDIR)/$(TARGET).exe $(CC_OUTS)
