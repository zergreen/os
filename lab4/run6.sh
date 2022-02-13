#!/bin/bash
echo "" > text6.txt
echo "File : $0" > text6.txt

for i in {1..10..2}
do
    echo "$i" >> text6.txt 
    ./6 >> text6.txt
done


