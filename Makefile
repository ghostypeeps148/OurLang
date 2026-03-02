# build file to compile to output

OURLANG_ROOT      :=  $(shell pwd)

SRCDIR            :=  $(OURLANG_ROOT)/src
INCDIR            :=  $(OURLANG_ROOT)/include
OBJDIR            :=  $(OURLANG_ROOT)/obj
BINDIR            :=  $(OURLANG_ROOT)/bin
TESTDIR           :=  $(OURLANG_ROOT)/tests

TARGET            :=  lang

USE_GCC           := yes


ifeq ($(USE_GCC),)

# use llvm toolchain
CC                :=  clang
LD                :=  lld -flavor ld

else

# use GCC toolchain
CC                :=  gcc
LD                :=  ld

endif

CFLAGS            := -Wall -Werror -O1
LDFLAGS           := -lc

CC_SRCS           :=  $(wildcard $(SRCDIR)/*)
CC_OUTS           :=  $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(CC_SRCS))

MAKE              :=  make

all: $(CC_OUTS) Link
# Run tests
  $(MAKE) -f $(TESTDIR)/Makefile


$(OBJDIR)/%.o: $(SRCDIR)/%.c
  @echo
  $(CC) $(CFLAGS) -c $< -o $@
  @echo


Link:
  $(LD) $(LDFLAGS) $(CC_OUTS) -o $(BINDIR)/$(TARGET)
