#!/bin/bash
echo "" > text2.txt
echo "File : $0" > text2.txt

for i in {1..10..2}
do
    echo "$i" >> text2.txt 
    ./2 >> text2.txt
done

