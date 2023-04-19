#!/bin/bash

i=6
while [ $i -le 64 ]
do
    echo $i
    ./knight $i
    i=$((i + 2))
done
