#!/bin/bash
g++ -o ee_DY_punzi.o $(root-config --cflags) ee_HT_alpha.C $(root-config --glibs)
#g++ -o ee_Top_punzi.o $(root-config --cflags) ee_Top_alpha.C $(root-config --glibs)
#g++ -o ee_Diboson_punzi.o $(root-config --cflags) ee_Diboson_alpha.C $(root-config --glibs)
#g++ -o ee_Triboson_punzi.o $(root-config --cflags) ee_Triboson_alpha.C $(root-config --glibs)
init_value=0.05
#---------------------
#  Run background
#---------------------
DYoutputfile="./output/DY_output"
for ((j=1;j<=20;j++))
do  
    echo $init_value*$j
    ./ee_DY_punzi.o "$j" "${DYoutputfile}_$j.root"
done
wait