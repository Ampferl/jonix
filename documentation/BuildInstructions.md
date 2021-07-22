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

## Build toolchain
```shell
make setup
``` 
## Run the kernel
```
make run
```