#!/bin/bash

echo "Start fucking Grading"
for i in *.cc; do
name=$i
echo "                "$name
output=${name/.cc/}
g++ $name -o $output
./$output
read id
done

###########################
#for i in *.cc;do name=$i;output=${name/.cc/};rm -rf $output;done
