#!/bin/bash

clear

echo "compile time"

gcc ./Resources/drawD.cpp ./Resources/drawT.cpp ./Resources/drawM.cpp ./Resources/drawMM.cpp ./Resources/drawF.cpp ./Resources/drawC.cpp ./Resources/cube.cpp ./mainBat.cpp ./Draw_Wing_Pt2.cpp -o tester -lGLU -lglut -lGL -lm

echo "complete"

./tester

fin

