#!/usr/bin/env bash

# Add every specific linkages with libs inside this case
linkingLibs="";

linking_lib() {
    case "$1" in
        pthreads.c)
            linkingLibs="-pthread"
            ;;
        *)
            linkingLibs=""
            ;;
        #TODO: make cases for every file
    esac
}

# destination should be source-files folder
if [ $# -eq 0 ]; then
    filenames=$(ls -l | grep -o [A-Za-z0-9_-]+.c);
	for name in "$filenames"; do
        linking_lib ${name};
	    echo "Compiling \033[0;33m$name\033[0m ..."
        gcc ${linkingLibs} ${name} -o ./source-files/"${name%.*}" && echo "\033[1;92m$name\033[0m done."
	done
else
    for name in "$@"; do
        linking_lib ${name};
        case "$name" in
            *.c)
                gcc -o ${linkingLibs} $(basename "$name") "${name%.*}"
                ;;
            *.cc)
                g++ -o ${linkingLibs} $(basename "$name") "${name%.*}"
                ;;
            *)
                echo "Ignoring $name, since it is not one of my files!"
                ;;
        esac
    done
fi