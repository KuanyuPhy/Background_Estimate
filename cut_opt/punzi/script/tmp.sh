#!/bin/bash

FileMainLocation=/home/kuanyu/Documents/CMS/Background_Estimate/cut_opt/punzi/alpha

test -e "$FileMainLocation/bg_alpha1.root" && { echo "Delete bg_alpha root";}

echo "$FileMainLocation/bg*.root"