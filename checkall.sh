#!/bin/bash


echo "Start fucking Grading"
#g++ -o filename filename.cpp
#./filename
for i in /Users/noise/Documents/TA/cal_basic_kim_2021_1/2_hw/home*.cc ; do
#name=$i
#output=${name/.cc/.out}
#g++ -o output $i
output=${name:52}
echo $output
timeout 30  root -q $i+
echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
done


#for i in /home/seungjun/cal_HW1/test*.cc ; do
#
#name=$i
#rm -rf ${name:1:-3}
#done



