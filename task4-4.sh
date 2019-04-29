#!/bin/bash
#2017-3-19
#4. В текущем каталоге для каждого пользователя из файла
#passwd создать файл с именем <имя-пользователя>.path 
#содержащий путь к домашней директории пользователя.

IFS=$'\n'
for entry in $(cat /etc/passwd)
do
user=$(echo "$entry" | cut -d ':' -f 1)
echo "$user"
touch "$user.path"
hd=$(echo "$entry" | cut -d ':' -f 6)
echo "$hd" > "$user.path"
done

