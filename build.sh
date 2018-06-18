#!/bin/bash

build_type=$1
export build_type

project[0]=dbase
project[1]=dadt
project[2]=dtest
project[3]=test_dadt

for prj in ${project[*]}
do
    echo "current project is \"$prj\""
    # copy build shell to each project
    cp ./single_build.sh ./$prj/make/build_$prj.sh
    # build each project
    cd ./$prj/make
    ./build_$prj.sh
    # remove build shell to keep it unique
    rm ./build_$prj.sh
    cd ../../
done

echo "build finished."

if [[ ${build_type} == "run" ]]; then
    cd ./test_dadt/make/output/exe/
    valgrind --leak-check=full --track-origins=yes --show-reachable=yes -v ./test_dadt
fi

