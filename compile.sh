#!/bin/bash
echo "Compiling..."
if [ "$1" = "-r" ];
  then
    gcc arrays.c sort.c main.c -o apspota && ./apspota
  else
    gcc arrays.c sort.c main.c -o apspota
fi
echo "DONE"
