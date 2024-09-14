#!/bin/bash
if [[ -d "./build" ]]; then
	cd ./build

	if [[ -f "./Makefile" ]]; then
		make maintainer-clean
	fi
	
	cd ..
fi

if [[ -f "./aclocal.m4" ]]; then
	rm -f ./aclocal.m4
fi

if [[ -f "./autom4te.cache" ]]; then
	rm -rf ./autom4t3.cache
fi

if [[ -f "./config.h.in" ]]; then
	rm -f ./config.h.in
fi

if [[ -f "./configure" ]]; then
	rm -f ./configure
fi

if [[ -f "./configure~" ]]; then
	rm -f ./configure~
fi

if [[ -f "./depcomp" ]]; then
	rm -f ./depcomp
fi

if [[ -f "./Makefile.in" ]]; then
	rm -f ./Makefile.in
fi

if [[ -f "./missing" ]]; then
	rm -f ./missing
fi

if [[ -f "./COPYING" ]]; then
	rm -f ./COPYING
fi

if [[ -f "./INSTALL" ]]; then
	rm -f ./INSTALL
fi

if [[ -f "./install-sh" ]]; then
	rm -f ./install-sh
fi

aclocal

sleep 3

automake --add-missing

sleep 3

autoreconf

if [[ -d "./build" ]]; then
	cd ./build
	../configure;
	make -j4
	if [[ -f "./fidolio" ]]; then
		cp -f ./fidolio ../bin/fidolio
		echo "fidolio successfully copied to bin directory"
	fi
fi