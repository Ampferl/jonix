# Jonix build instructions
## Prerequisites
### Debian/Ubuntu
```shell
sudo apt install build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo qemu-system-i386 qemu-utils grub-pc-bin xorriso mtools nasm
```

## Clone repository
```shell
git clone https://github.com/Ampferl/jonix.git
cd jonix
```

## Build Operating System
```shell
make setup
``` 
With the command `make setup`, jonix will automatically build the toolchain, kernel and libraries and put them together into one running system.
## Run the kernel
```
make run
```