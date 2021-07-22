INCLUDEDIR := include
OBJDIR := ../build/libc
INCLUDEDEST := $(OBJDIR)/include

CC = ../../toolchain/local/x86_64/bin/x86_64-jonix-elf-gcc
AR = ../../toolchain/local/x86_64/bin/x86_64-jonix-elf-ar
LOGGING = -Wall -Wextra -Wpedantic -Werror
CFLAGS = -O2 -g -shared -fPIC -ffreestanding -fshort-wchar -mno-red-zone -fno-exceptions -I$(INCLUDEDEST) $(LOGGING)

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,.,./*.c)
OBJS = $(patsubst ./%.c, $(OBJDIR)/%.o, $(SRC))

libc: headers libc.a

libc.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
	@ mv libc.a $(OBJDIR)/libc.a

$(OBJDIR)/%.o: ./%.c
	@ echo !==== COMPILING $^
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@
	
headers:
	mkdir -p $(INCLUDEDEST)
	cp -R --preserve=timestamps $(INCLUDEDIR)/. $(INCLUDEDEST)/.

setup:
	@ mkdir -p $(OBJDIR)
