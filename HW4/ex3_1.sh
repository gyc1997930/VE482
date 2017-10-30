#!/bin/bash

random=$(( (RANDOM % 10) ))

if [ ! -f "int.txt" ]; then
    echo $random > int.txt
fi

for ((i=0;i<20;++i)); do
    n=$(tail -1 int.txt)
    let n++
    echo $n >> int.txt
done