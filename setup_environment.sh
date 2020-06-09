#!/bin/bash
if [ -d "gbdk-2020/" ] 
then
	echo "updating the environment"
	git submodule update
	cd gbdk-2020
	make
	cd ..
else
	sudo apt install sdcc gcc
	# git clone https://github.com/Zal0/gbdk-2020.git
	git submodule init
	cd gbdk-2020
	make
	cd ..
fi

git pull


	
