#!/bin/bash
echo "" > text3_1.txt
echo "File : $0" > text3_1.txt

for i in {1..10..2}
do
    echo "$i" >> text3_1.txt 
    ./3_1 >> text3_1.txt
done

