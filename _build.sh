#!/bin/bash

# SEE IF -c HAS BEEN PASSED TO SCRIPT
while getopts ":c" opt; do
	case $opt in
		c) CLN=1 ;;
		?) echo "Invalid option -$opt"; exit ;;
	esac
done

if [[ -d "./build" ]]; then
	cd ./build

	# CLEAN IF REQUESTED
	if [ $CLN -eq 1 ]; then
		make clean
	fi
	
	make -j4

	# MOVE EXECUTABLE TO BIN FOLDER
	if [[ -f "./fidolio" ]]; then
		cp -f ./fidolio ../bin/fidolio
		echo "fidolio successfully copied to bin directory"
	fi

	cd ..
fi