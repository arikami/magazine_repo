#!/bin/bash

# install package dependencies
sudo apt install gcc sdcc sdcc-ucsim

# setup gbdk-2020 submodule
git submodule init
git submodule update

# build everything
export SDCCDIR="/usr"
export SDCCLIB="/usr"
# export PATH = "$PATH:$(pwd)/gdbk-2020/bin"
cd gbdk-2020
make
cd ..

	# git clone https://github.com/Zal0/gbdk-2020.git



	
