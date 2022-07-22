#!/usr/bin/zsh

#For produce fake rate
g++ -o ee_DY_half_inclu.o $(root-config --cflags) ee_DY_half_inclu.cpp  $(root-config --glibs)
g++ -o ee_DY_half.o $(root-config --cflags) ee_DY_half.cpp  $(root-config --glibs)

#For Ratio apply
g++ -o Ratio_DY_inclu_apply.o $(root-config --cflags) Ratio_DY_inclu_apply.cpp  $(root-config --glibs)
g++ -o Ratio_DY_apply.o $(root-config --cflags) Ratio_DY_apply.cpp  $(root-config --glibs)

HT_inclusive_1="/home/kuanyu/Documents/root_file/BgEstimation/ee_DYincli_1.root"
HT_list_1=($(find /home/kuanyu/Documents/root_file/BgEstimation/ -mindepth 1 -maxdepth 1 -name "ee_ht*_1.root")) 
HT_inclusive_2="/home/kuanyu/Documents/root_file/BgEstimation/ee_DYincli_2.root"
HT_list_2=($(find /home/kuanyu/Documents/root_file/BgEstimation/ -mindepth 1 -maxdepth 1 -name "ee_ht*_2.root")) 

for file in ${HT_inclusive_1[*]}; do
    DY_outputfile="$(basename -s ".root" "$file")"
    echo $file
    ./ee_DY_half_inclu.o "$file" "./output/${DY_outputfile}_output.root" 
    #echo ./$outputfile;
done
wait
for file in ${HT_list_1[*]}; do
    DY_outputfile="$(basename -s ".root" "$file")"
    echo $file
    ./ee_DY_half.o "$file" "./output/${DY_outputfile}_output.root" 
    #echo ./$outputfile;
done
rm DY_all.root
hadd DY_all.root ./output/*.root
rm ./output/*.root
wait
root -q ee_DY_half_fk_produce.cpp
wait
for file in ${HT_inclusive_1[*]}; do
    DY_outputfile="$(basename -s ".root" "$file")"
    echo $DY_outputfile
    ./Ratio_DY_inclu_apply.o "$file" "./output/${DY_outputfile}_output.root" 
    #echo ./$outputfile;
done
wait
for file in ${HT_list_1[*]}; do
    DY_outputfile="$(basename -s ".root" "$file")"
    echo $DY_outputfile
    ./Ratio_DY_apply.o "$file" "./output/${DY_outputfile}_output.root" 
    #echo ./$outputfile;
done
rm Ratio_DY_apply.root
hadd Ratio_DY_apply.root ./output/*.root
rm ./output/*.root
root -l quick_draw.cpp

