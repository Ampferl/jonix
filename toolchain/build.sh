#!/usr/bin/env bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

echo $DIR


ARCH=x86_64
PREFIX="$DIR/local/$ARCH"
TARGET=$ARCH-jonix-elf
PATH="$PREFIX/bin:$PATH"

BINUTILS_VERSION=2.37
BINUTILS_HASH=e78d9ff2976b745a348f4c1f27c77cb1
GCC_VERSION=11.1.0
GCC_HASH=77f6252be0861ab918042acf42bc10ff

cd $DIR
mkdir build

cd $DIR/build


wget -c https://ftp.gnu.org/gnu/gcc/gcc-$GCC_VERSION/gcc-$GCC_VERSION.tar.xz
if [ "$(md5sum < gcc-$GCC_VERSION.tar.xz)" = "$GCC_HASH  -" ]
then
    echo Valid Hash
else
    echo Wrong Hash
    rm gcc-$GCC_VERSION.tar.xz
    exit
fi
tar -xf gcc-$GCC_VERSION.tar.xz
rm gcc-$GCC_VERSION.tar.xz


wget -c https://ftp.gnu.org/gnu/binutils/binutils-$BINUTILS_VERSION.tar.xz
if [ "$(md5sum < binutils-$BINUTILS_VERSION.tar.xz)" = "$BINUTILS_HASH  -" ]
then
    echo Valid Hash
else
    echo Wrong Hash
    rm binutils-$BINUTILS_VERSION.tar.xz
    exit
fi
tar -xf binutils-$BINUTILS_VERSION.tar.xz
rm binutils-$BINUTILS_VERSION.tar.xz

mkdir build-binutils
cd build-binutils
../binutils-$BINUTILS_VERSION/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot=../sysroot --disable-nls --disable-werror
make
make install

cd $DIR/build 
 
mkdir build-gcc
cd build-gcc
../gcc-$GCC_VERSION/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers --with-sysroot=../sysroot
make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc