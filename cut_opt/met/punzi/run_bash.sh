#!/bin/bash
g++ -o ana_DY_punzi.o $(root-config --cflags) ana_DY_punzi.C $(root-config --glibs)
g++ -o ana_Top_punzi.o $(root-config --cflags) ana_Top_punzi.C $(root-config --glibs)
g++ -o ana_Diboson_punzi.o $(root-config --cflags) ana_Diboson_punzi.C $(root-config --glibs)
g++ -o ana_Triboson_punzi.o $(root-config --cflags) ana_Triboson_punzi.C $(root-config --glibs)
#---------------------
#  Run background
#---------------------
DYoutputfile="./output/DY_output"
Topoutputfile="./output/Top_output"
Dibosonoutputfile="./output/Di_output"
Tribosonoutputfile="./output/Tri_output"

for ((j=1;j<=50;j++))
do  
    echo $j
    ./ana_DY_punzi.o "$j" "${DYoutputfile}_$j.root" &
    ./ana_Top_punzi.o "$j" "${Topoutputfile}_$j.root" &
    ./ana_Diboson_punzi.o "$j" "${Dibosonoutputfile}_$j.root" &
    ./ana_Triboson_punzi.o "$j" "${Tribosonoutputfile}_$j.root" &
done
wait
#hadd uu_DY_punzi.root ./output/DY_output*.root
#hadd uu_Top_punzi.root ./output/Top_output*.root
#hadd uu_Diboson_punzi.root ./output/Di_output*.root
hadd uu_Triboson_punzi.root ./output/Tri_output*.root
#wait
#hadd uu_bgall_punzi.root uu_DY_punzi.root uu_Top_punzi.root uu_Diboson_punzi.root uu_Triboson_punzi.root
#wait
#rm ./output/*
#rm ./output/"DY_output*".root
