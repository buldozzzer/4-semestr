#3. Для заданного в качестве параметра текстового файла создать файлы:
# digits - содержит цифры из исходного файла;
# alpha - содержит буквенные символы из исходного файла;
# other - содержит все остальные символы из исходного файла.

touch alpha.txt
touch digits.txt
touch other.txt
touch tmp.txt
cat "$1" > "tmp.txt"
grep -o  "[[:alpha:]]" "$1" > alpha.txt
grep -o  "[[:digit:]]" "$1" > digits.txt
grep -o  "[^A-Za-z0-9]" "$1" > other.txt
