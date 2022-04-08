#!/bin/bash
################# main grading code ###################
echo "Start fucking Grading"
for i in *.cc; do
name=$i
echo "                "$name
output=${name/.cc/}
g++ $name -o $output
#./$output
#read id
done

########################### deleting exec files #############33
#for i in *.cc;do name=$i;output=${name/.cc/};rm -rf $output;done
