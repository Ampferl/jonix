# Jonix
Jonix is a simple kernel written in C++.

# How to build and run the kernel with qemu
Install requirements:
```shell
sudo apt install build-essential qemu-system-i386 qemu-utils
```
Build and run:
```shell
git clone https://github.com/Ampferl/jonix.git
cd jonix/gnu-efi
make bootloader
cd ../kernel
make kernel
make buildimg
make run
```

## Contact
- Website: [jonas.ampferl.com](https://jonas.ampferl.com/)
- Email: [contact@chaepy.net](mailto:contact@chaepy.net)
