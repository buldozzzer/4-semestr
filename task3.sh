#!/bin/bash

function files_creator ()  # dir_name file_name 
{
  full_name="$1/$2"
  # не забываем про структурное программирование 
  # добавляем табуляцию для очередного уровня вложенности
  if [[ ! -e "$1" ]]; then
     echo "Directory does not exist, creating $1"
     mkdir "$1"
  elif [[ ! -d "$1" ]]; then
     echo "$1 is not a directory, exiting"
     exit 1
  fi
  touch "$1/$2"
}

  read -p "Enter dir and file names: " dir_name file_name
  files_creator "$dir_name" "$file_name"
  if [[ -f "$full_name" ]];
  then 
    echo "Created $full_name";
   fi

  echo "Do you want repeat? yes/no"

  read  flag
  while [ "$flag" = "yes" ]
  do
    if [ "$flag" = "no" ]
    then
    exit
    fi
    read -p "Enter dir and file names: " dir_name file_name
    files_creator "$dir_name" "$file_name"
    if [[ -f "$full_name" ]];
    then
      echo "Created $full_name";
    fi
    echo "Do you want repeat? yes/no"
    read flag
  done
