#!/bin/bash 
 
# 显示帮助信息 
show_help() { 
   echo "Usage:" 
   echo "First time:"
   echo "./_build_dual_1_config_and_compile.sh  XXX   YYY"
   echo "Then:"   
   echo "./_build_dual_2_compile.sh  XXX   YYY"
   echo ""
   echo " XXX = project name(such as m57/m20/d600...)"
   echo " YYY = image name(bootimage/pl/lk/dtboimage/...) or none(just for source & lunch cmd)"
   echo "Example:" 
   echo "step 1:        ./_build_dual_1_config_and_compile.sh    M57   bootimage" 
   echo "step 2 :      ./_build_dual_2_compile.sh   M57   bootimage" 
   echo "step 3 :      ......." 
   echo "step n :      ./_build_dual_2_compile.sh   M57   bootimage" 
} 
 
# 检查是否提供了参数 
if [ $# -eq 0 ]; then 
   show_help 
   exit 1 
fi 

source build/envsetup.sh

#convert paramter to low case
proj_name=$(echo "$1" | tr 'A-Z' 'a-z') 
image_name=$(echo "$2" | tr 'A-Z' 'a-z') 

# check input parameters
if [[ $proj_name != d600 ]] &&[[ $proj_name != p20 ]] &&[[ $proj_name != m57 ]] ;then
echo "unknown project name:"
echo $1
exit 1
fi

if [[ $image_name != dtboimage ]] &&[[ $image_name != bootimage ]] &&[[ $image_name != lk ]] &&[[ $image_name != pl ]] &&[[ $image_name != none ]] ;then
echo "unknown image type:"
echo $2
exit 1
fi

export OUT_DIR=_out_$proj_name

if [[ $proj_name == m57 ]];then
lunch vnd_spm8675p1_64_raite-userdebug
if [[ $image_name == dtboimage ]]; then
rm -rf $OUT_DIR/target/product/spm8675p1_64_raite/obj/PACKAGING/dtb/
rm -rf $OUT_DIR/target/product/spm8675p1_64_raite/obj/KERNEL_OBJ/arch/arm64/boot/dts/
fi
fi

if [[ $proj_name == p20 ]]; then
lunch vnd_spm8675p1_64_wifi_raite-userdebug
if [[ $image_name == dtboimage ]]; then
rm -rf $OUT_DIR/target/product/spm8675p1_64_wifi_raite/obj/PACKAGING/dtb/
rm -rf $OUT_DIR/target/product/spm8675p1_64_wifi_raite/obj/KERNEL_OBJ/arch/arm64/boot/dts/
fi
fi

if [[ $proj_name == d600 ]]; then
lunch vnd_spm8675p1_64_wifi_raite-userdebug
if [[ $image_name == dtboimage ]]; then
rm -rf $OUT_DIR/target/product/spm8675p1_64_wifi_raite/obj/PACKAGING/dtb/
rm -rf $OUT_DIR/target/product/spm8675p1_64_wifi_raite/obj/KERNEL_OBJ/arch/arm64/boot/dts/
fi
fi


cd kernel-4.14
make mrproper
cd -
cp -rf ~/Desktop/_make_mrproper/* ./kernel-4.14/scripts/kconfig/

if [[ $proj_name != none ]]; then
make $image_name  2>&1 | tee _build_dual-$proj_name-$image_name.log
fi

