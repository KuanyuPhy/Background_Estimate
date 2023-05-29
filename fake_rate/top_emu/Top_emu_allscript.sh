#!/usr/bin/bash
set -eu -o pipefail

FileMainLocation=/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top_emu

#-----------------------
#    For 1D fake rate  
#-----------------------
g++ -o $FileMainLocation/ee_Top_emu.o $(root-config --cflags) $FileMainLocation/ee_Top_emu.cpp  $(root-config --glibs)
g++ -o $FileMainLocation/ee_Top_emu_all_fakerate.o $(root-config --cflags) $FileMainLocation/ee_Top_emu_all_fakerate.cpp  $(root-config --glibs)

Top_emu_list=($(find /home/kuanyu/Documents/root_file/Ztoemu/2016BKGMC/top/ -mindepth 1 -maxdepth 1 -name "*.root"))

#------------------------
#  Clear old files
#------------------------

test -e "$FileMainLocation/top_all.root" && { echo "Delete old top_all.root"; rm $FileMainLocation/top_all.root ;}

for file in ${Top_emu_list[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $file
    ./ee_Top_emu.o "$file" "./output/${Topoutputfile}_output.root" 
    #echo ./$outputfile;
done

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
#test -e "$FileMainLocation/top_emu_fakerate.root" && { echo "Delete old top_emu_fakerate.root"; rm $FileMainLocation/top_emu_fakerate.root ;}
#
./ee_Top_emu_all_fakerate.o "./top_all.root" "./top_emu_all_fakerate.root"
#


#-------------------------------
# Clear process files
#-------------------------------
test -e "$FileMainLocation/ee_Top_emu.o" && { echo "Delete ee_Top_emu.o"; rm $FileMainLocation/ee_Top_emu.o ;}
#test -e "$FileMainLocation/ee_Top_emu_half_fakerate.o" && { echo "Delete ee_Top_emu_half_fakerate.o"; rm $FileMainLocation/ee_Top_emu_half_fakerate.o ;}
#test -e "$FileMainLocation/Ratio_Topee_apply.o" && { echo "Delete Ratio_Topee_apply.o"; rm $FileMainLocation/Ratio_Topee_apply.o ;}
#test -e "$FileMainLocation/Ratio_Top_apply.o" && { echo "Delete Ratio_Top_apply.o"; rm $FileMainLocation/Ratio_Top_apply.o ;}
