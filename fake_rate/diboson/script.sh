#!/usr/bin/zsh

#For produce fake rate
g++ -o ee_Diboson_half.o $(root-config --cflags) ee_Diboson_half.cpp  $(root-config --glibs)
#For Ratio apply
g++ -o Ratio_dib_apply.o $(root-config --cflags) Ratio_dib_apply.cpp  $(root-config --glibs)


Diboson_list_1=($(find /home/kuanyu/Documents/root_file/BgEstimation/ -mindepth 1 -maxdepth 1 -name "diboson_*_1.root"))
Diboson_list_2=($(find /home/kuanyu/Documents/root_file/BgEstimation/ -mindepth 1 -maxdepth 1 -name "diboson_*_2.root"))

for file in ${Diboson_list_1[*]}; do
    dibo_outputfile="$(basename -s ".root" "$file")"
    echo $dibo_outputfile
    ./ee_Diboson_half.o "$file" "./output/${dibo_outputfile}_output.root" 
    #echo ./$outputfile;
done
wait
rm dib_all.root
hadd dib_all.root ./output/*.root
rm ./output/*.root
wait
root -q ee_diboson_half_fk_produce.cpp
wait
for file in ${Diboson_list_2[*]}; do
    dibo_outputfile="$(basename -s ".root" "$file")"
    echo $dibo_outputfile
    ./Ratio_dib_apply.o "$file" "./output/${dibo_outputfile}_output.root" 
    #echo ./$outputfile;
done
wait
rm Ratio_dibo_apply.root
hadd Ratio_dibo_apply.root ./output/*.root
rm ./output/*.root
root -l quick_draw.cpp

