#!/usr/bin/bash
set -eu -o pipefail

FileMainLocation=/home/kuanyu/Documents/CMS/Background_Estimate/fake_rate/dy

#For produce fake rate
g++ -o $FileMainLocation/ee_DY_all.o $(root-config --cflags) ee_DY_all.cpp  $(root-config --glibs)

./ee_DY_all.o  "./output/DY_all_output.root"

root -l -q ee_DY_all_fk_produce.cpp


root -l draw_fakerate.cpp

