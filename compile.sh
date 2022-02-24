#!/bin/bash
echo "Compiling..."
if [ "$1" = "-r" ];
  then
    gcc main.c -o apspota && ./apspota
  else
    gcc main.c -o apspota
fi
echo "DONE"
