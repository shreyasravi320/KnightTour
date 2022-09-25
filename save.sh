#!/bin/bash

i=6
while [ $i -le 256 ]
do
    echo $i
    ./knight $i
    i=$((i + 2))
done
