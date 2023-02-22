#!/usr/bin/bash
set -eu -o pipefail

FileMainLocation=/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu


#-----------------------
#    For 1D fake rate  
#-----------------------
g++ -o $FileMainLocation/ee_Top_emu_half.o $(root-config --cflags) $FileMainLocation/ee_Top_emu_half.cpp  $(root-config --glibs)
g++ -o $FileMainLocation/ee_Top_emu_half_fakerate.o $(root-config --cflags) $FileMainLocation/ee_Top_emu_half_fakerate.cpp  $(root-config --glibs)
g++ -o $FileMainLocation/Ratio_Topee_apply.o $(root-config --cflags) $FileMainLocation/Ratio_Topee_apply.cpp  $(root-config --glibs)
g++ -o $FileMainLocation/Ratio_Top_apply.o $(root-config --cflags) $FileMainLocation/Ratio_Top_apply.cpp  $(root-config --glibs)
g++ -o $FileMainLocation/Ratio_Top_apply_LO.o $(root-config --cflags) $FileMainLocation/predict/Ratio_Top_apply_LO.cpp  $(root-config --glibs)


Top_emu_list_1=($(find /home/kuanyu/Documents/root_file/BgEstimation/top_emu/ -mindepth 1 -maxdepth 1 -name "eu_top_emu_*_1.root"))
Top_emu_list_2=($(find /home/kuanyu/Documents/root_file/BgEstimation/top_emu/ -mindepth 1 -maxdepth 1 -name "eu_top_emu_*_2.root"))


#------------------------
#  Clear old files
#------------------------

test -e "$FileMainLocation/top_all.root" && { echo "Delete old top_all.root"; rm $FileMainLocation/top_all.root ;}

for file in ${Top_emu_list_1[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $Topoutputfile
    ./ee_Top_emu_half.o "$file" "./output/${Topoutputfile}_output.root" 
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
test -e "$FileMainLocation/top_emu_fakerate.root" && { echo "Delete old top_emu_fakerate.root"; rm $FileMainLocation/top_emu_fakerate.root ;}

./ee_Top_emu_half_fakerate.o "./top_all.root" "./top_emu_fakerate.root"


for file in ${Top_emu_list_2[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $Topoutputfile
    ./Ratio_Top_apply_LO.o "$file" "./output/${Topoutputfile}_output.root" 
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

#root -l quick_TopeeFR_draw.cpp
#./ee_Top_half_fakerate.o "./top_all.root" "./top_fakerate.root"

#-------------------------------
# Clear process files
#-------------------------------
test -e "$FileMainLocation/ee_Top_emu_half.o" && { echo "Delete ee_Top_emu_half.o"; rm $FileMainLocation/ee_Top_emu_half.o ;}
test -e "$FileMainLocation/ee_Top_emu_half_fakerate.o" && { echo "Delete ee_Top_emu_half_fakerate.o"; rm $FileMainLocation/ee_Top_emu_half_fakerate.o ;}
test -e "$FileMainLocation/Ratio_Topee_apply.o" && { echo "Delete Ratio_Topee_apply.o"; rm $FileMainLocation/Ratio_Topee_apply.o ;}
test -e "$FileMainLocation/Ratio_Top_apply.o" && { echo "Delete Ratio_Top_apply.o"; rm $FileMainLocation/Ratio_Top_apply.o ;}
