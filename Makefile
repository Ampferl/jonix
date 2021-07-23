setup: build-toolchain build-libraries build-bootloader build-kernel

build-toolchain:
	@ cd toolchain && ./build.sh

build-bootloader:
	@ cd kernel/bin/gnu-efi && make bootloader

build-kernel:
	@ cd kernel && make kernel
	@ cd kernel && make buildimg

build-libraries:
	@ cd libraries && make build

run:
	@ cd kernel && make run

clean:
	@ rm sysroot -rf
	@ rm libraries/build -rf
	@ rm build -rf
	@ rm libraries/build -rf