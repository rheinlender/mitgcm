C $Header: /u/gcmpack/MITgcm/pkg/atm_ocn_coupler/OCNIDS.h,v 1.5 2015/12/25 16:39:51 jmc Exp $
C $Name:  $

c These lines are here to deliberately cause a compile-time error.
c If you see these lines in your .F files or the compiler shows them
c   as an error then it means you have not placed your coupler
c   configuration files in the appropriate place.
c You need: a) to place you own copy of OCNIDS.h in a directory
c   (e.g.: shared_code) which is both in the include path of the
c   coupler and in include path of the ocean component ;
c and b) to comment out these lines.

C     *==========================================================*
C     | OCNIDS.h Declare symbolic constants holding strings that
C     |          are used to identify this component and the
C     |          fields it exchanges with other components.
C     *==========================================================*
      CHARACTER*(8)  ocnCompName
      PARAMETER( ocnCompName         = 'UV-Ocean'       )

      CHARACTER*(13) ocnCplParamsName
      PARAMETER( ocnCplParamsName    = 'OCN CplParams'  )
      INTEGER    ocnParSize
      PARAMETER( ocnParSize = 6 )

C--   fields sent from OCN to ATM:
      CHARACTER*(10) ocnMxlDName
      PARAMETER( ocnMxlDName         = 'OCN ocMxlD'     )
      CHARACTER*(7)  ocnSSTName
      PARAMETER( ocnSSTName          = 'OCN SST'        )
      CHARACTER*(7)  ocnSSSName
      PARAMETER( ocnSSSName          = 'OCN SSS'        )
      CHARACTER*(9)  ocnSSVsqName
      PARAMETER( ocnSSVsqName        = 'OCN SSVsq'      )
      CHARACTER*(11) ocnCO2FluxName
      PARAMETER( ocnCO2FluxName      = 'OCN CO2Flux'    )

C--   fields sent in both direction:
      CHARACTER*(12) ocnSIceFracName
      PARAMETER( ocnSIceFracName     = 'OCN sIceFrac'   )
      CHARACTER*(13) ocnSIceThickName
      PARAMETER( ocnSIceThickName    = 'OCN sIceThick'  )
      CHARACTER*(13) ocnSIceSnowName
      PARAMETER( ocnSIceSnowName     = 'OCN sIceSnowH'  )
      CHARACTER*(10) ocnSIceQ1Name
      PARAMETER( ocnSIceQ1Name       = 'OCN sIceQ1'     )
      CHARACTER*(10) ocnSIceQ2Name
      PARAMETER( ocnSIceQ2Name       = 'OCN sIceQ2'     )

C--   fields sent from ATM to OCN:
      CHARACTER*(8)  ocnSLPrName
      PARAMETER( ocnSLPrName         = 'OCN SLPr'       )
      CHARACTER*(12) ocnHeatFluxName
      PARAMETER( ocnHeatFluxName     = 'OCN HeatFlux'   )
      CHARACTER*(14) ocnQshortWaveName
      PARAMETER( ocnQshortWaveName   = 'OCN Qshortwave' )
      CHARACTER*(8)  ocnTauXName
      PARAMETER( ocnTauXName         = 'OCN tauX'       )
      CHARACTER*(8)  ocnTauYName
      PARAMETER( ocnTauYName         = 'OCN tauY'       )
      CHARACTER*(10) ocnFWFluxName
      PARAMETER( ocnFWFluxName       = 'OCN FWFlux'     )
      CHARACTER*(10) ocnRunOffName
      PARAMETER( ocnRunOffName       = 'OCN RunOff'     )
      CHARACTER*(12) ocnSaltFxName
      PARAMETER( ocnSaltFxName       = 'OCN SaltFlux'   )
      CHARACTER*(12) ocnSIceMassName
      PARAMETER( ocnSIceMassName     = 'OCN sIceMass'   )
      CHARACTER*(14) ocnSaltPlmFlxName
      PARAMETER( ocnSaltPlmFlxName   = 'OCN SaltPlmFlx' )
      CHARACTER*(10) ocnAirCO2Name
      PARAMETER( ocnAirCO2Name       = 'OCN AirCO2'     )
      CHARACTER*(11) ocnWindSpdName
      PARAMETER( ocnWindSpdName      = 'OCN WindSpd'    )

C---+----1----+----2----+----3----+----4----+----5----+----6----+----7-|--+----|
