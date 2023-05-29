#!/usr/bin/bash
set -eu -o pipefail

FileMainLocation=/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/top

#-----------------------
#    For 1D fake rate  
#-----------------------
g++ -o $FileMainLocation/ee_Top_ee_all.o $(root-config --cflags) $FileMainLocation/ee_Top_ee_all.C  $(root-config --glibs)
g++ -o $FileMainLocation/ee_Top_ee_all_fakerate.o $(root-config --cflags) $FileMainLocation/ee_Top_ee_all_fakerate.cpp  $(root-config --glibs)

Top_ee_list=($(find /home/kuanyu/Documents/root_file/Ztoee/2016BKGMC/top/ -mindepth 1 -maxdepth 1 -name "*.root"))

#------------------------
#  Clear old files
#------------------------

test -e "$FileMainLocation/top_all.root" && { echo "Delete old top_all.root"; rm $FileMainLocation/top_all.root ;}

for file in ${Top_ee_list[*]}; do
    Topoutputfile="$(basename -s ".root" "$file")"
    echo $file
    ./ee_Top_ee_all.o "$file" "./output/${Topoutputfile}_output.root" 
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
./ee_Top_ee_all_fakerate.o "./top_all.root" "./top_ee_all_fakerate.root"
#


#-------------------------------
# Clear process files
#-------------------------------
test -e "$FileMainLocation/ee_Top_ee_all.o" && { echo "Delete ee_Top_ee_all.o"; rm $FileMainLocation/ee_Top_ee_all.o ;}
test -e "$FileMainLocation/ee_Top_ee_all_fakerate.o" && { echo "Delete ee_Top_ee_all_fakerate.o"; rm $FileMainLocation/ee_Top_ee_all_fakerate.o ;}
test -e "$FileMainLocation/top_all.root" && { echo "Delete top_all.o"; rm $FileMainLocation/top_all.root ;}

#test -e "$FileMainLocation/Ratio_Topee_apply.o" && { echo "Delete Ratio_Topee_apply.o"; rm $FileMainLocation/Ratio_Topee_apply.o ;}
#test -e "$FileMainLocation/Ratio_Top_apply.o" && { echo "Delete Ratio_Top_apply.o"; rm $FileMainLocation/Ratio_Top_apply.o ;}
