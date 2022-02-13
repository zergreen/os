#!/bin/bash
echo "" > text5.txt 
echo "File : $0" > text5.txt

for i in {1..10..2}
do
    echo "$i" >> text5.txt 
    ./5 >> text5.txt
done


