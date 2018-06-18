#!/bin/bash

LOG_PATH=./output/log
if ! [ -d $LOG_PATH ]; then mkdir -p $LOG_PATH; fi

filename=`basename $0`
filename=${filename%.*}
cur_time=$(date "+%Y-%m-%d_%H:%M:%S")
log_filename=${filename}_${cur_time}.log

echo ${filename} | tr [a-z] [A-Z]
make $build_type 2>&1 | tee $LOG_PATH/$log_filename

exit 0

