#!/bin/bash
g++ -o ee_HT_metcut.o $(root-config --cflags) ee_HT_metcut.C $(root-config --glibs)

HT_list=("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/uu_DYincli.root" $(find /home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/DY -mindepth 1 -maxdepth 1 -name "uu_ht*.root")) 
Top_list=( $(find /home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top -mindepth 1 -maxdepth 1 -name "ee_top_*.root"))
Topemu_list=( $(find /home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top -mindepth 1 -maxdepth 1 -name "eu_top_*.root"))
Diboson_list=($(find /home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson -mindepth 1 -maxdepth 1 -name "uu_diboson_*.root"))
Triboson_list=($(find /home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/triboson -mindepth 1 -maxdepth 1 -name "uu_triboson*.root"))

for file in ${HT_list[*]}; do
    outputfile="$(basename -s ".root" "$file")"
    #echo $file
    #echo ${outputfile}
    #./ee_HT_metcut.o "$file" "/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/DY/passmetcut/${outputfile}.root"
    #echo ./$outputfile;
done
wait
for file in ${Top_list[*]}; do
    outputfile="$(basename -s ".root" "$file")"
    #echo $file
    #echo ${outputfile}
    #./ee_HT_metcut.o "$file" "/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/passmetcut/${outputfile}.root"
    #echo ./$outputfile;
done
wait
for file in ${Diboson_list[*]}; do
    outputfile="$(basename -s ".root" "$file")"
    #echo $file
    #echo ${outputfile}
    #./ee_HT_metcut.o "$file" "/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/diboson/passmetcut/${outputfile}.root"
    #echo ./$outputfile;
done
wait
for file in ${Triboson_list[*]}; do
    outputfile="$(basename -s ".root" "$file")"
    #echo $file
    #echo ${outputfile}
    #./ee_HT_metcut.o "$file" "/home/kuanyu/Documents/root_file/Ztouu/2016BKGMC/triboson/passmetcut/${outputfile}.root"
    #echo ./$outputfile;
done
wait
for file in ${Topemu_list[*]}; do
    outputfile="$(basename -s ".root" "$file")"
    #echo $file
    echo ${outputfile}
    ./ee_HT_metcut.o "$file" "/home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/passmetcut/${outputfile}.root"
    #echo ./$outputfile;
done

