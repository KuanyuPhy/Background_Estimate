#!/usr/bin/zsh
g++ -o ee_Top_half_fakerate.o $(root-config --cflags) ee_Top_half_fakerate.cpp  $(root-config --glibs)

Top_list=( $(find /home/kuanyu/Documents/root_file/BgEstimation/ -mindepth 1 -maxdepth 1 -name "top_*_1.root"))

for file in ${Top_list[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $file
    ./ee_Top_half_fakerate.o "$file" "./output/${Topoutputfile}_output.root" 
    #echo ./$outputfile;
done
