#!/bin/bash
echo "" > text7.txt
echo "File : $0" > text7.txt

for i in {1..10..2}
do
    echo "$i" >> text7.txt 
    ./7 >> text7.txt
done


