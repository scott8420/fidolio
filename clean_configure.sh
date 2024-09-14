#!/bin/bash

source ./clean_project.sh

aclocal
sleep 1
automake --add-missing
sleep 1
autoreconf

if [[ -d "./build" ]]; then
	cd ./build
	../configure;
	cd ..
fi

echo 'Configure is complete'