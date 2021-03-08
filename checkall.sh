#!/bin/bash


echo "Start fucking Grading"

#g++ -o filename filename.cpp
#./filename
for i in /home/seungjun/cal_HW1/test*.cc ; do
name=$i
output=${name/.cc/.out}
g++ -o output $i
echo $output
./output
echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
done


for i in /home/seungjun/cal_HW1/test*.cc ; do

name=$i
rm -rf ${name:1:-3}
done



