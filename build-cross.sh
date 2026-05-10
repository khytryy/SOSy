#!/bin/bash

export PREFIX="/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

mkdir ~/crosstmp

wget https://ftp.gnu.org/gnu/binutils/binutils-2.43.1.tar.xz
wget https://ftp.gnu.org/gnu/gcc/gcc-15.2.0/gcc-15.2.0.tar.xz

tar -xf binutils-2.43.1.tar.gz
tar -xf gcc-15.2.0.tar.gz

# Build binutils
cd binutils-2.43.1
mkdir build

../configure \
  --target=$TARGET \
  --prefix=$PREFIX \
  --with-sysroot \
  --disable-nls \
  --disable-werror

make
make install

cd ../..

# Build GCC
cd gcc-15.2.0
mkdir build

../configure \
  --target=$TARGET \
  --prefix=$PREFIX \
  --disable-nls \
  --enable-languages=c,c++ \
  --without-headers

make all-gcc
make all-target-libgcc
make install-gcc
make install-target-libgcc

echo 'export PATH="$PATH:/opt/cross/bin"' >> ~/.bashrc
source ~/.bashrc

i686-elf-gcc --version
i686-elf-ld --version