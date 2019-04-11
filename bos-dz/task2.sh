#!/bin/bash

# аргументы командной строки
# First argument -- исходный каталог
# Second argument -- конечный каталог, где нужно удалить все 
# дубликаты для файлов исходного каталога
read d1
read d2
if [[ !( -e $d1) ]]
then
echo "$d1 doesn't exist"
exit
if [[ !( -e $d2) ]]
then
echo "$d2 doesn't exist"
exit
fi
fi

if [[ !( -d $d1) ]]
then
echo "$d1 isn't directory"
exit
if [[ !( -d $d2) ]]
then
echo "$d2 isn't directory"
exit
fi
fi

return_code=0
for file in `ls ./$d1`
do
  echo "Found $file"

  if `rm ./$d2/${file} 2>> $d2/err.txt`
  then
    echo "Backup removed!"
  else
    echo "Can't remove backup!"
    return_code=1
  fi
done

exit $return_code
