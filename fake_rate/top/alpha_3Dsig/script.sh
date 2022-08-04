#!/usr/bin/zsh
#g++ -o ee_Top_half_fakerate.o $(root-config --cflags) ee_Top_half_fakerate.cpp  $(root-config --glibs)
#g++ -o ee_Top_2dhalf.o $(root-config --cflags) ee_Top_2dhalf.cpp  $(root-config --glibs)
#g++ -o Ratio_Top_apply_JetPt.o $(root-config --cflags) Ratio_Top_apply_JetPt.cpp  $(root-config --glibs)
#g++ -o ee_Top_2dhalf_fakerate.o $(root-config --cflags) ee_Top_2dhalf_fakerate.cpp  $(root-config --glibs)

#For 1D 
g++ -o ee_Top_half.o $(root-config --cflags) ee_Top_half.cpp  $(root-config --glibs)
g++ -o ee_Top_half_fakerate.o $(root-config --cflags) ee_Top_half_fakerate.cpp  $(root-config --glibs)
g++ -o Ratio_Top_apply.o $(root-config --cflags) Ratio_Top_apply.cpp  $(root-config --glibs)


Top_list_1=($(find /home/kuanyu/Documents/root_file/BgEstimation/top/ -mindepth 1 -maxdepth 1 -name "top_*_1.root"))
Top_list_2=($(find /home/kuanyu/Documents/root_file/BgEstimation/top/ -mindepth 1 -maxdepth 1 -name "top_*_2.root"))

for file in ${Top_list_1[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $Topoutputfile
    ./ee_Top_half.o "$file" "./output/${Topoutputfile}_output.root" 
    #echo ./$outputfile;
done
wait
rm top_all.root
hadd top_all.root ./output/*.root
rm ./output/*
wait
./ee_Top_half_fakerate.o "./top_all.root" "./top_fakerate.root"
wait
for file in ${Top_list_2[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $Topoutputfile
    ./Ratio_Top_apply.o "$file" "./output/${Topoutputfile}_output.root" 
    #echo ./$outputfile;
done
rm Ratio_apply.root
hadd Ratio_apply.root ./output/*.root
rm ./output/*.root
root -l quick_draw.cpp
#./ee_Top_half_fakerate.o "./top_all.root" "./top_fakerate.root"
