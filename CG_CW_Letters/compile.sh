#!/bin/bash

clear

echo "compile time"

gcc ./drawD.cpp ./drawT.cpp ./drawM.cpp ./drawMM.cpp ./drawF.cpp ./drawC.cpp ./cube.cpp ./driverFish.cpp  -o Fish -lGLU -lglut -lGL -lm

echo "complete"

