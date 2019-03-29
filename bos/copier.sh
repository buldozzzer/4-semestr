#!/bin/bash

if [[ $# -le 2 ]]
then
if [[ $# -lt  2 ]]
then
echo "You sould specify at least two arguments!"
exit
fi
if [[ !(-e "$1") ]]
then
echo "File $1 doesn't exists"
exit
fi
if [[ (-d "$1") ]]
then
echo "File $1 is a directory"
exit
fi
if [[ (-e "$2") ]]
then
echo "File $2 already exists, skipping"
exit
fi
if [[ !(-f "$1") ]]
then
echo "File $1 is not file"
exit
fi
cp "$1" "$2"
echo "Copied $1 to $2!"
exit
fi
if [[ $# -eq 3 ]]
then
mv "$1" "$3"
echo "Moved $1 to $3!"
exit
fi
