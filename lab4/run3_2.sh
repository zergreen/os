#!/bin/bash
echo "" > text3_2.txt
echo "File : $0" > text3_2.txt

for i in {1..10..2}
do
    echo "$i" >> text3_2.txt 
    ./3_2 >> text3_2.txt
done


