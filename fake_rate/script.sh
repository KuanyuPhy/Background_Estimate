#!/usr/bin/env zsh
g++ -o ./top/ee_Top_split.o $(root-config --cflags) ./top/ee_Top_split.C $(root-config --glibs)

HT_list=("/home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ee_DYincli.root" $(find /home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/DY/ -mindepth 1 -maxdepth 1 -name "ee_ht*.root")) 
Top_list=( $(find /home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/ -mindepth 1 -maxdepth 1 -name "ee_top_*.root"))
Top_emu_list=( $(find /home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/ -mindepth 1 -maxdepth 1 -name "eu_top_*.root"))
Diboson_list=($(find /home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/diboson/ -mindepth 1 -maxdepth 1 -name "diboson_*.root"))
SECONDS=0
for file in ${HT_list[*]}; do
    outputfile="$(basename -s ".root" "$file")"
    #echo $file
    #./top/ee_Top_half.o "$file" "/home/kuanyu/Documents/root_file/BgEstimation/dy/${outputfile}_1.root" "/home/kuanyu/Documents/root_file/BgEstimation/dy/${outputfile}_2.root" &
    #echo ./$outputfile;
done
#echo $Top_list
for file in ${Top_list[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $Topoutputfile
    ./top/ee_Top_split.o "$file" "/home/kuanyu/Documents/root_file/BgEstimation/top/${Topoutputfile}_1.root" "/home/kuanyu/Documents/root_file/BgEstimation/top/${Topoutputfile}_2.root" 
    echo ./$Topoutputfile;
done
for file in ${Diboson_list[*]}; do
    Dibosonoutputfile="$(basename -s ".root" "$file")"
    #echo $Dibosonoutputfile
    #./ee_Diboson_half "$file" "/home/kuanyu/Documents/root_file/BgEstimation/${Dibosonoutputfile}_1.root" "/home/kuanyu/Documents/root_file/BgEstimation/${Dibosonoutputfile}_2.root" 
    #echo ./$outputfile;
done
wait
for file in ${Top_emu_list[*]}; do
    outputfile="$(basename -s ".root" "$file")"
    #echo $outputfile
    #./top/ee_Top_split.o "$file" "/home/kuanyu/Documents/root_file/BgEstimation/top_emu/${outputfile}_1.root" "/home/kuanyu/Documents/root_file/BgEstimation/top_emu/${outputfile}_2.root" 
    #echo ./$outputfile;
done
echo $SECONDS