#!/usr/bin/zsh
#For 1D 
g++ -o ee_Top_half.o $(root-config --cflags) ee_Top_half.cpp  $(root-config --glibs)



Top_list_1=($(find /home/kuanyu/Documents/root_file/BgEstimation/top/ -mindepth 1 -maxdepth 1 -name "top_*_1.root"))
Top_list_2=($(find /home/kuanyu/Documents/root_file/BgEstimation/top/ -mindepth 1 -maxdepth 1 -name "top_*_2.root"))

for file in ${Top_list_1[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $Topoutputfile
    ./ee_Top_half.o "$file" "./output/${Topoutputfile}_output.root" 
 
done

