#!/bin/bash

Name=fidolio

function help() {
cat <<EOH
This script is auto-generated. Its purpose is to automate the 
autotools process for building Gtk projects. Autotools can be 
complicated taking many rigid steps to accomplish. 
Hopefully this script will be useful for programmers who are
not familiar with the gnu tools for building projects.

USAGE:
  NOTE: Use only one (1) option at a time.

  autotools.sh [options]

OPTIONS:
  -a			# Run all scripts
  -b			# Builds the project
  -c			# Configure the project
  -d			# A conveyance option that builds with the clean flag
  -h			# This help menu
  -i			# Installs the linux project to the system. Must use 'sudo' for permissions
  -k			# Clean all autotool files
  -s			# Scans and auto-generates the Makefile.am file

EXAMPLES:
  autotools.sh -a	# Runs all the scripts to build the project
  autotools.sh -b	# Builds the project
  autotools.sh -d	# Clean and build the project
  autotools.sh -k	# Cleans the project of all auto-generated files

EOH

}

function cleanbuild() {

	if [[ -d "./build" ]]; then
		cd ./build
		make clean
		make -j4

		# MOVE EXECUTABLE TO BIN FOLDER
		if [[ -f "./$Name" ]]; then
			cp -f ./$Name ../bin/$Name
			echo "$Name successfully copied to bin directory"
		fi

		cd ..
	fi
}

function build() {
	clean=0

	if [ "$1" == "clean" ]; then
		clean=1
	fi

	if [[ -d "./build" ]]; then
		cd ./build

		# CLEAN IF REQUESTED
		if [ $clean == 1 ]; then
			make clean
		fi
		
		make -j4

		# MOVE EXECUTABLE TO BIN FOLDER
		if [[ -f "./$Name" ]]; then
			cp -f ./$Name ../bin/$Name
			echo "$Name successfully copied to bin directory"
		fi

		cd ..
	fi
}

function configure() {
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
}

function install() {
	rm -rf /usr/local/share/${Name}
	mkdir /usr/local/share/${Name}
	cp bin/${Name} /usr/local/share/${Name}/${Name}
	cp rsc/${Name}.png rsc/${Name}.svg /usr/local/share/${Name}/
	cp -f rsc/${Name}.desktop /usr/share/applications/${Name}.desktop
}

function scan() {
	mv -f ./Makefile.am ./Makefile.am~

	lastfile=$(ls "./include/" | tail -1)

	# Rebuild the Makefile.am file
	cat > ./Makefile.am <<EOL
#Regenerated Makefile.am from scan.sh

AUTOMAKE_OPTIONS = subdir-objects

bin_PROGRAMS = $Name

${Name}_CPPFLAGS = @GTK4_CFLAGS@ -I../include/ -std=c++20 

${Name}_LDADD = @GTK4_LIBS@

${Name}_SOURCES = \\
EOL

	for file in ./src/*; do
		# process each file
		types=(*.cpp *.c++ *.cc)
		for type in "${types[@]}"; do
			if [ "${type##*.}" = "cpp" ]; then
				echo -e "\tsrc/${file##*/} \\" >> ./Makefile.am
			fi
		done
	done

	for file in ./include/*; do
		# process each file
		types=(*.h *.hpp *.hh *.xpm *.ui)
		
		for type in "${types[@]}"; do
			if [ "${type##*.}" = "hpp" ]; then
				if [[ "${file##*/}" == "$lastfile" ]]; then
					echo -e "\tinclude/${file##*/}" >> ./Makefile.am
				else
					echo -e "\tinclude/${file##*/} \\" >> ./Makefile.am
				fi
			fi
		done
	done

	echo "Makefile.am has been regenerated"
}

function clean() {
	if [[ -d "./build" ]]; then
		cd ./build

		if [[ -f "./Makefile" ]]; then
			make clean
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

	echo 'Project has been cleaned of all autotools files'
}

function all() {
	scan
	clean
	configure
	build
}

while getopts "abcdhiks" opt; do
	case $opt in
		a) all ;;
		c) configure ;;
		b) build ;;
		d) cleanbuild ;;
		h) help ;;
		i) install ;;
		k) clean ;;
		s) scan ;;
		\?) help ;;
	esac
done