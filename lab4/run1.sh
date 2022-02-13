#!/bin/bash
echo "" > text1.txt
echo " File : $0 " > text1.txt

for i in {1..10..2}
do
    echo "$i" >> text1.txt 
    ./1 >> text1.txt
done
