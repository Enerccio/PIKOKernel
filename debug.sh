#!/bin/bash

export PATH=$(realpath toolchain/usr/bin):/usr/local/bin:$PATH
sudo -u enerccio make clean 
sudo -u enerccio make all

pushd disk
./update_image.sh
popd

sudo -u enerccio qemu-system-x86_64 -hdc disk.img -m 128 -s -cpu Haswell,+pdpe1gb -d cpu_reset -machine q35 #-device ivshmem,shm=ivshmem,size=1
#sudo -u enerccio qemu-system-x86_64 -hdc disk.img -m 128 -serial file:com1 -s -smp cores=2,threads=2,sockets=3 -cpu Haswell,+pdpe1gb,+nx -d int,cpu_reset
#sudo -u enerccio qemu-system-x86_64 -hdc disk.img -m 128 -serial file:com1 -s -smp cores=2 -cpu Haswell,+pdpe1gb,+nx -d int,cpu_reset
#sudo -u enerccio qemu-system-x86_64 -hdc disk.img -m 128 -s -smp cores=2,threads=2,sockets=3 -cpu Haswell,+pdpe1gb,+nx
