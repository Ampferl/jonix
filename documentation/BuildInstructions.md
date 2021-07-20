# Jonix build instructions
## Prerequisites
### Debian/Ubuntu
```shell
sudo apt install build-essential bison flex libgmp3-dev libmpc-dev libmpfr-dev texinfo qemu-system-i386 qemu-utils
```

## Clone repository
```shell
git clone https://github.com/Ampferl/jonix.git
cd jonix
```

## Build toolchain
```shell
cd toolchain
./build.sh
``` 

## Build bootloader
```shell
cd jonix/kernel/bin/gnu-efi
make bootloader
cd ../../..
```

## Build and run the kernel
```
make kernel
make buildimg
make run
```