#!/bin/bash
#2017-3-19-per

directory_result=~/Desktop
directory_task=C:\\Users\\Ivan\\Downloads\\bos\\bos\\ddz
full_name="2017-3-19"


for ((i=2;i<=5;i++))
do
Group=1
Student_number=19
Task_number=$(tail -n 1 $directory_task/$i.txt | cut -d '.' -f 1)
Task=$((($Student_number+$i*$Group)%$Task_number+1))
Task_text=$(grep "$Task." -m 1 $directory_task/$i.txt)

cd $directory_result

if [[ ! -f task$i-$Task.sh ]]
then
touch "task$i-$Task.sh"
fi
cd ..
done
