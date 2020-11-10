MITGCM AQUAPLANET WITH TWO CONTINENTS

This is the "noridge" model configuration used in Rheinlænder et al. (2020) https://doi.org/10.1175/JCLI-D-19-0726.1.

The atmosphere, ocean, and sea ice components are configured on the same cubed-sphere grid at a low-horizontal resolution C32 (32 × 32 points per face)

Ocean: 3km deep, flat-bottom, 30 levels

Atm: five-level primitive equation model of intermediate complexity based on the simplified parameterizations primitive equation dynamics (SPEEDY) scheme (Molteni 2003).

Sea Ice: 2.5-layer thermodynamic model based on Winton (2000)

Solar constant is 1366 W/m2


########################################################

NB! This version has useLAYERS =.TRUE. (see rank1/data.pkg) to output uvel and vvel on SIGMA layers. The layers are defined in data.layers (note that number of layers must match NLAYERS in LAYERS_SIZE.h when compiled) 

## Inputs coupler (rank_0)

        - boomerang_noRidge_cs32_runOff1302.bin    #runoff

this is set in "/rank_0/data"

## Inputs ocean model (rank_1)

	- boomerang_noRidge_cs32_Bathy_flat.bin    #bathymetry file, flat-bottomed ocean
	- boomerang_noRidge_cs32_Sinit.bin         #initial salinity field 
	- boomerang_noRidge_cs32_Tinit.bin         #initial temperature field

input files are specified in "rank_1/data"


## Inputs atm model (rank_13)

	- boomerang_noRidge_cs32_albedo10pc.bin    #albedo
	- boomerang_noRidge_cs32_landFrc.bin       #land fraction
	- boomerang_noRidge_cs32_vegFrc75pc.bin    #vegetation

input files are specified in "rank_13/data.aimphys"

## Preparing rank_ dirs
To prepare the rank_ directories run the script "prepRank"

########################################################

## Setting the time-step and coupling freq

For the current version the coupling freq of the atmospheric model is 5 times the ocean timestep (dtO=3600, dtA=720). 

Also set the coupling freq in 'data.cpl' (rank_13), ocean_deltaT=3600 in 'data.ice' (rank_13), deltaT=720 in 'data' (rank_13) and deltaT=3600 in 'data' (rank_1)



