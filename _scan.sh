#!/bin/bash
mv -f ./Makefile.am ./Makefile.am~

lastfile=$(ls "./include/" | tail -1)

# Rebuild the Makefile.am file
echo -e "#Regenerated Makefile.am from scan.sh" > ./Makefile.am
echo -e "" >> ./Makefile.am
echo -e "AUTOMAKE_OPTIONS = subdir-objects" >> ./Makefile.am
echo -e "" >> ./Makefile.am
echo -e "bin_PROGRAMS = fidolio" >> ./Makefile.am
echo -e "" >> ./Makefile.am
echo -e "fidolio_CPPFLAGS = @GTK4_CFLAGS@ -I../include/ -std=c++20" >> ./Makefile.am  
echo -e "" >> ./Makefile.am
echo -e "fidolio_LDADD = @GTK4_LIBS@" >> ./Makefile.am
echo -e "" >> ./Makefile.am
echo -e "fidolio_SOURCES = \\" >> ./Makefile.am

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

echo -e "Makefile.am has been regenerated"