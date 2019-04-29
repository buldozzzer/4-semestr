#!/bin/bash
#10. Найти файл string.h,
# в случае успеха скопировать его в заданный
# в качестве параметра каталог.
i=0
for file in `find / -type f -name "string.h"`
do
  mkdir "$1/string_$i"
  cp "$file" "$1/string_$i"
  let "i=$i+1"
done
