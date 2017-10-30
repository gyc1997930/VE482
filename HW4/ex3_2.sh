#!/bin/bash

random=$(( (RANDOM % 10) ))

if [ ! -f "int.txt" ]; then
    echo $random > int.txt
fi

for ((i=0;i<20;++i)); do
    (
        flock 3
        n=$(tail -1 int.txt)
        let n++
        echo $n >> int.txt
    )3<>int.txt
done