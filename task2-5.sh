#!/bin/bash
#5. Найти в файловой системе все файлы, размером больше 1Кб и меньше 1 Мб. В файл записать имена таких файлов, 
#расположенных в каталоге /etc.
touch f1.txt
touch f2.txt
touch f3.txt
echo "более 1кб"
find ~/Desktop -size +1k -print
find ~/Desktop -size +1k >> f1.txt
echo "До  1Mб"
find ~/Desktop -size -1024k -print 
find ~/Desktop -size -1024k -print >> f2.txt
diff -sr f1.txt f2.txt >> f3.txt
rm f1.txt
rm f2.txt
