#!/bin/bash

module purge
#module load comp-intel/11.1.046 mpi/mpt.1.25     netcdf/3.6.0/intel
#module load comp-intel/2011.2 mpi-sgi/mpt.2.04.10789 netcdf/4.0
module load intelcomp/17.0.0
module load mpt/2.14
module load netcdf
module list

dir1=/home/ntnu/rheinlender/MITgcm
dir2=/home/ntnu/rheinlender/MITgcm/JR_runs/aquaplanet_cs32_layers
workdir=/work/rheinlender/MITgcm/JR_runs/aquaplanet_cs32_b2
optfile=linux_amd64_ifort+mpi_vilje_hp

echo '¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤'
echo 'List directories:'
echo $dir1
echo $dir2
echo $optfile
echo '¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤'


echo building cpl
cd build_cpl
$dir1/tools/genmake2 -of $dir1/tools/build_options/$optfile -mpi -rootdir=$dir1 -mods="$dir2/code_cpl $dir2/shared_code" -standarddirs=""
make depend
make -j 2

echo building ocn
cd ../build_ocn
$dir1/tools/genmake2 -of $dir1/tools/build_options/$optfile -mpi -rootdir=$dir1 -mods="$dir2/code_ocn $dir2/shared_code"
make depend
make -j 2

echo building atm
cd ../build_atm
$dir1/tools/genmake2 -of $dir1/tools/build_options/$optfile -mpi -rootdir=$dir1 -mods="$dir2/code_atm $dir2/shared_code"
make depend
make -j 2

echo '¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤'
echo Make dependencies DONE

echo '¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤'$
echo 'Copying executables'

cd ..
cp -p build_cpl/mitgcmuv mitgcmuv.C1
cp -p build_ocn/mitgcmuv mitgcmuv.O12
cp -p build_atm/mitgcmuv mitgcmuv.A12

echo '¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤'$
echo 'Copying' $dir2 '-->' $workdir

#cp -p $dir2/* $workdir 


