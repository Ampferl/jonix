INCLUDEDIR := include
OBJDIR := ../build/libGUI
SYSROOT := ../../sysroot
INCLUDEDEST := $(SYSROOT)/usr/include/gui
LIBDEST := $(SYSROOT)/usr/lib

CC = ../../toolchain/local/x86_64/bin/x86_64-jonix-elf-gcc
AR = ../../toolchain/local/x86_64/bin/x86_64-jonix-elf-ar
LOGGING = -Wall -Wextra -Wpedantic -Werror
CFLAGS = --sysroot=$(SYSROOT) -O2 -g -shared -fPIC -ffreestanding -fshort-wchar -mno-red-zone -fno-exceptions -I$(INCLUDEDEST) $(LOGGING)

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

SRC = $(call rwildcard,.,./*.c)
OBJS = $(patsubst ./%.c, $(OBJDIR)/%.o, $(SRC))

libGUI: dirs headers libGUI.a sysroot-install

libGUI.a: $(OBJS)
	$(AR) rcs $@ $(OBJS)
	@ mv libGUI.a $(OBJDIR)/libGUI.a

$(OBJDIR)/%.o: ./%.c
	@ echo !==== COMPILING $^
	@ mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

dirs:
	mkdir -p $(OBJDIR)
	mkdir -p ../../sysroot/usr/include
	mkdir -p $(INCLUDEDEST)
	mkdir -p ../../sysroot/usr/lib

headers:
	cp -R --preserve=timestamps $(INCLUDEDIR)/. $(INCLUDEDEST)

sysroot-install:
	cp -R --preserve=timestamps $(OBJDIR)/libGUI.a $(LIBDEST)

setup:
	@ mkdir -p $(OBJDIR)
