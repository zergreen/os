#!/bin/bash
echo "" > text4.txt 
echo "File : $0" > text4.txt

for i in {1..10..2}
do
    echo "$i" >> text4.txt
    ./4 >> text4.txt
done


