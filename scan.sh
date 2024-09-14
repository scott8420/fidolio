#!/bin/bash

for file in ./src/*; do
    # process each file
	types=(*.cpp *.c++ *.cc)
	for type in "${types[@]}"; do
  		if [ "${type##*.}" = "cpp" ]; then
    		echo -e "\tsrc/${file##*/} \\"
  		fi
	done
done

for file in ./include/*; do
    # process each file
	types=(*.h *.hpp *.hh *.xpm *.ui)
	for type in "${types[@]}"; do
  		if [ "${type##*.}" = "hpp" ]; then
    		echo -e "\tinclude/${file##*/} \\"
  		fi
	done
done
