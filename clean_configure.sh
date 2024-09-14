#!/bin/bash
source ./clean_project.sh

aclocal
sleep 3
automake --add-missing
sleep 3
autoreconf

if [[ -d "./build" ]]; then
	cd ./build
	../configure;
	cd ..
fi

echo 'Configure is complete'