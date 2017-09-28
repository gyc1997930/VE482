#!/bin/bash
useradd pomelo
ps -e
top
echo 123 | grep 2 > 1.txt
echo helloworld | grep low > 2.txt
cat 1.txt 2.txt > 3.txt
hexdump 3.txt
find /usr/src -name 'semaphore' | xargs grep -l 'ddekit_sem_down'