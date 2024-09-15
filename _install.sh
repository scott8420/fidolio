#!/bin/bash
Name=fidolio

rm -rf /usr/local/share/${Name}
mkdir /usr/local/share/${Name}
cp bin/${Name} /usr/local/share/${Name}/${Name}
cp rsc/${Name}.png rsc/${Name}.svg /usr/local/share/${Name}/
cp -f rsc/${Name}.desktop /usr/share/applications/${Name}.desktop