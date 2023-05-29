#!/usr/bin/bash
set -eu -o pipefail

FileMainLocation=/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top

#-----------------------
#  g++ fake rate code 
#-----------------------
g++ -o $FileMainLocation/ee_Top_ee_half.o $(root-config --cflags) $FileMainLocation/ee_Top_ee_half.C  $(root-config --glibs)
g++ -o $FileMainLocation/ee_Top_ee_half_fakerate.o $(root-config --cflags) $FileMainLocation/ee_Top_ee_half_fakerate.cpp  $(root-config --glibs)
g++ -o $FileMainLocation/Ratio_Top_apply.o $(root-config --cflags) $FileMainLocation/Ratio_Top_apply.cpp  $(root-config --glibs)


Top_ee_list_1=($(find /home/kuanyu/Documents/root_file/BgEstimation/top/ -mindepth 1 -maxdepth 1 -name "ee_top_*_1.root"))
Top_ee_list_2=($(find /home/kuanyu/Documents/root_file/BgEstimation/top/ -mindepth 1 -maxdepth 1 -name "ee_top_*_2.root"))


#------------------------
#  Clear old files
#------------------------
test -e "$FileMainLocation/top_all.root" && { echo "Delete old top_all.root"; rm $FileMainLocation/top_all.root ;}

for file in ${Top_ee_list_1[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $Topoutputfile
    ./ee_Top_ee_half.o "$file" "./output/${Topoutputfile}_output.root" 
    #echo ./$outputfile;
done
wait
hadd top_all.root ./output/*.root


if [ "ls -A $FileMainLocation/output/*" = "" ]; then
    echo "$FileMainLocation/output/* is indeed empty"
else
    echo "$FileMainLocation/output/* is not empty"
    echo "Clear output directory" && rm $FileMainLocation/output/*
fi

wait

#----------------------------
# Calculate fake rate
#----------------------------
test -e "$FileMainLocation/top_ee_fakerate.root" && { echo "Delete old top_ee_fakerate.root"; rm $FileMainLocation/top_ee_fakerate.root ;}

./ee_Top_ee_half_fakerate.o "./top_all.root" "./top_ee_fakerate.root"

for file in ${Top_ee_list_2[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $Topoutputfile
    ./Ratio_Top_apply.o "$file" "./output/${Topoutputfile}_output.root" 
    #echo ./$outputfile;
done

test -e "$FileMainLocation/Ratio_apply.root" && { echo "Delete old Ratio_apply.root"; rm $FileMainLocation/Ratio_apply.root ;}

hadd Ratio_apply.root $FileMainLocation/output/*.root

if [ "ls -A $FileMainLocation/output/*" = "" ]; then
    echo "$FileMainLocation/output/* is indeed empty"
else
    echo "$FileMainLocation/output/* is not empty"
    echo "Clear output directory" && rm $FileMainLocation/output/*
fi




