#!/bin/bash
echo "Compiling..."
if [ "$1" = "-r" ];
  then
    gcc src/arrays.c src/sort.c src/main.c -o apspota && ./apspota
  else
    gcc src/arrays.c src/sort.c src/main.c -o apspota
fi
echo "DONE"
