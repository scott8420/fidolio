#!/bin/bash
source ./clean_configure.sh

if [[ -d "./build" ]]; then
	cd ./build
	make -j4
	if [[ -f "./fidolio" ]]; then
		cp -f ./fidolio ../bin/fidolio
		echo "fidolio successfully copied to bin directory"
	fi
fi