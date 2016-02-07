#include "__cf_ASM.h"
#include <math.h>
#include "ASM_acc.h"
#include "ASM_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T hpyptyxxuz ;
real_T an24lhwopd ; real_T kto1nx4hut ; real_T mkgxby3oif ; real_T pwshdupdri
; real_T a1werbeobb ; real_T nzhdnbh0x3 ; n3qi1whofz * _rtB ; loikxjbxjg *
_rtP ; ew10rzwqr2 * _rtDW ; _rtDW = ( ( ew10rzwqr2 * ) ssGetRootDWork ( S ) )
; _rtP = ( ( loikxjbxjg * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz
* ) _ssGetBlockIO ( S ) ) ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
ehctirsryt = _rtP -> P_25 ; _rtB -> djsv5je2jp = _rtP -> P_26 * _rtB ->
ehctirsryt ; } hpyptyxxuz = ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) ->
higv254nrc ; pwshdupdri = muDoubleScalarCos ( hpyptyxxuz ) ; an24lhwopd = ( (
f1xhd02yjc * ) ssGetContStates ( S ) ) -> bujmkolqyo ; a1werbeobb =
muDoubleScalarCos ( an24lhwopd ) ; hpyptyxxuz = muDoubleScalarSin (
hpyptyxxuz ) ; an24lhwopd = muDoubleScalarSin ( an24lhwopd ) ; _rtB ->
p5dsurc2ww = pwshdupdri * a1werbeobb - hpyptyxxuz * an24lhwopd ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
bng4gctcqn = ( ssGetTaskTime ( S , 1 ) >= _rtP -> P_29 ) ; _rtDW ->
etbenh3omx = ( ssGetTaskTime ( S , 1 ) >= _rtP -> P_32 ) ; _rtDW ->
fry5fbmgyd = ( ssGetTaskTime ( S , 1 ) >= _rtP -> P_35 ) ; } if ( _rtDW ->
etbenh3omx == 1 ) { nzhdnbh0x3 = _rtP -> P_34 ; } else { nzhdnbh0x3 = _rtP ->
P_33 ; } if ( nzhdnbh0x3 > _rtP -> P_38 ) { if ( _rtDW -> bng4gctcqn == 1 ) {
_rtB -> gnlqvhm4tr = _rtP -> P_31 ; } else { _rtB -> gnlqvhm4tr = _rtP ->
P_30 ; } } else if ( _rtDW -> fry5fbmgyd == 1 ) { _rtB -> gnlqvhm4tr = _rtP
-> P_37 ; } else { _rtB -> gnlqvhm4tr = _rtP -> P_36 ; } } kto1nx4hut = ( (
f1xhd02yjc * ) ssGetContStates ( S ) ) -> gjk0lxg443 ; _rtB -> nxj4n2kqk1 =
_rtP -> P_40 * kto1nx4hut ; kto1nx4hut = _rtB -> gnlqvhm4tr - _rtB ->
nxj4n2kqk1 ; nzhdnbh0x3 = _rtP -> P_41 * kto1nx4hut ; mkgxby3oif = ( (
f1xhd02yjc * ) ssGetContStates ( S ) ) -> axrdfhsgtz ; _rtB -> gbiuncg1uv =
nzhdnbh0x3 + mkgxby3oif ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
es2xilblr3 = _rtB -> gbiuncg1uv >= _rtP -> P_43 ? 1 : _rtB -> gbiuncg1uv >
_rtP -> P_44 ? 0 : - 1 ; } mkgxby3oif = _rtDW -> es2xilblr3 == 1 ? _rtP ->
P_43 : _rtDW -> es2xilblr3 == - 1 ? _rtP -> P_44 : _rtB -> gbiuncg1uv ; _rtB
-> jc4evkpev5 = mkgxby3oif / _rtB -> ehctirsryt ; _rtB -> l1kxjictvk =
hpyptyxxuz * a1werbeobb + pwshdupdri * an24lhwopd ; _rtB -> gtt5agigmr = _rtP
-> P_45 * _rtB -> l1kxjictvk ; _rtB -> mlpfh11sd0 = ( ( f1xhd02yjc * )
ssGetContStates ( S ) ) -> op3lv53a0k ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> fr5clhxz5p = _rtP -> P_47 * _rtB -> djsv5je2jp + _rtB -> ehctirsryt ;
} _rtB -> hzrj0qjkit = _rtB -> jc4evkpev5 / _rtB -> ehctirsryt * _rtP -> P_48
; mkgxby3oif = _rtB -> hzrj0qjkit + _rtB -> nxj4n2kqk1 ; _rtB -> ieodndrhxd =
_rtB -> fr5clhxz5p * mkgxby3oif + _rtP -> P_49 * _rtB -> jc4evkpev5 ; _rtB ->
n5z5peqthm = _rtP -> P_50 * _rtB -> nxj4n2kqk1 ; _rtB -> ndqlldi1m4 = ( (
f1xhd02yjc * ) ssGetContStates ( S ) ) -> p4rdpwdrcu ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> oiira2g3nc = _rtP -> P_52 * _rtB -> djsv5je2jp ; } _rtB
-> ihjdxvph4y = _rtB -> oiira2g3nc - _rtP -> P_53 * _rtB -> jc4evkpev5 *
mkgxby3oif ; ssCallAccelRunBlock ( S , 1 , 42 , SS_CALL_MDL_OUTPUTS ) ;
mkgxby3oif = _rtP -> P_54 * _rtB -> iudd2nyjpx ; a1werbeobb = _rtP -> P_55 *
_rtB -> nuplcm02ku ; _rtB -> ezrcmxca1i = a1werbeobb - mkgxby3oif ; _rtB ->
l10il0snrx = ( 0.0 - mkgxby3oif ) - a1werbeobb ; _rtB -> a1b5grmxt0 = ( _rtB
-> f4lpett4ja * _rtB -> ef1y24cz44 - _rtB -> a2azw0gorq * _rtB -> phetpcff13
) * _rtP -> P_56 ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> o23js3v2ei = ( ssGetTaskTime ( S , 1 )
>= _rtP -> P_57 ) ; _rtDW -> aevdpjqpp2 = ( ssGetTaskTime ( S , 1 ) >= _rtP
-> P_60 ) ; _rtDW -> a3ylnquutr = ( ssGetTaskTime ( S , 1 ) >= _rtP -> P_63 )
; } if ( _rtDW -> aevdpjqpp2 == 1 ) { nzhdnbh0x3 = _rtP -> P_62 ; } else {
nzhdnbh0x3 = _rtP -> P_61 ; } if ( nzhdnbh0x3 > _rtP -> P_66 ) { if ( _rtDW
-> o23js3v2ei == 1 ) { _rtB -> m24fg2mzzs = _rtP -> P_59 ; } else { _rtB ->
m24fg2mzzs = _rtP -> P_58 ; } } else if ( _rtDW -> a3ylnquutr == 1 ) { _rtB
-> m24fg2mzzs = _rtP -> P_65 ; } else { _rtB -> m24fg2mzzs = _rtP -> P_64 ; }
} ssCallAccelRunBlock ( S , 1 , 55 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
orgil0qlwu [ 0 ] = _rtB -> iudd2nyjpx ; _rtB -> orgil0qlwu [ 1 ] = _rtB ->
ezrcmxca1i ; _rtB -> orgil0qlwu [ 2 ] = _rtB -> l10il0snrx ;
ssCallAccelRunBlock ( S , 1 , 57 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> fuvcsrsaho
[ 0 ] = _rtB -> nxj4n2kqk1 ; _rtB -> fuvcsrsaho [ 1 ] = _rtB -> gnlqvhm4tr ;
ssCallAccelRunBlock ( S , 1 , 59 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> fuvcsrsaho
[ 0 ] = _rtB -> a1b5grmxt0 ; _rtB -> fuvcsrsaho [ 1 ] = _rtB -> m24fg2mzzs ;
ssCallAccelRunBlock ( S , 1 , 61 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> ltpx5pvyyg
= _rtP -> P_67 * _rtB -> jvtxtcpxfv ; _rtB -> msdtxubs1x = _rtP -> P_68 *
_rtB -> jac3ipg4e4 ; _rtB -> apyazjfrxt = _rtP -> P_69 * kto1nx4hut ; _rtB ->
jf4y21jcil = ( _rtB -> a1b5grmxt0 - _rtB -> m24fg2mzzs ) - _rtP -> P_70 *
_rtB -> nxj4n2kqk1 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { n3qi1whofz * _rtB ;
loikxjbxjg * _rtP ; _rtP = ( ( loikxjbxjg * ) ssGetDefaultParam ( S ) ) ;
_rtB = ( ( n3qi1whofz * ) _ssGetBlockIO ( S ) ) ; UNUSED_PARAMETER ( tid ) ;
}
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { n3qi1whofz * _rtB ; loikxjbxjg
* _rtP ; f1xhd02yjc * _rtX ; pqmvzr1kvu * _rtXdot ; _rtXdot = ( ( pqmvzr1kvu
* ) ssGetdX ( S ) ) ; _rtX = ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) ;
_rtP = ( ( loikxjbxjg * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz *
) _ssGetBlockIO ( S ) ) ; { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> higv254nrc
= _rtB -> hzrj0qjkit ; } { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> bujmkolqyo =
_rtB -> nxj4n2kqk1 ; } { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> gjk0lxg443 =
_rtB -> jf4y21jcil ; } { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> axrdfhsgtz =
_rtB -> apyazjfrxt ; } { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> op3lv53a0k =
_rtB -> ltpx5pvyyg ; } { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> p4rdpwdrcu =
_rtB -> msdtxubs1x ; } _rtXdot -> dlw0x3b0bn [ 0 ] = 0.0 ; _rtXdot ->
dlw0x3b0bn [ 1 ] = 0.0 ; _rtXdot -> dlw0x3b0bn [ 0U ] += _rtP -> P_0 [ 0 ] *
_rtX -> dlw0x3b0bn [ 0 ] ; _rtXdot -> dlw0x3b0bn [ 0U ] += _rtP -> P_0 [ 1 ]
* _rtX -> dlw0x3b0bn [ 1 ] ; _rtXdot -> dlw0x3b0bn [ 1U ] += _rtP -> P_0 [ 2
] * _rtX -> dlw0x3b0bn [ 0 ] ; _rtXdot -> dlw0x3b0bn [ 1U ] += _rtP -> P_0 [
3 ] * _rtX -> dlw0x3b0bn [ 1 ] ; _rtXdot -> dlw0x3b0bn [ 0U ] += _rtP -> P_1
[ 0 ] * _rtB -> g5b2vpe1rn [ 0 ] ; _rtXdot -> dlw0x3b0bn [ 0U ] += _rtP ->
P_1 [ 1 ] * _rtB -> g5b2vpe1rn [ 1 ] ; _rtXdot -> dlw0x3b0bn [ 1U ] += _rtP
-> P_1 [ 2 ] * _rtB -> g5b2vpe1rn [ 1 ] ; _rtXdot -> gbnpend52x [ 0 ] = 0.0 ;
_rtXdot -> gbnpend52x [ 1 ] = 0.0 ; _rtXdot -> gbnpend52x [ 0U ] += _rtP ->
P_7 [ 0 ] * _rtX -> gbnpend52x [ 0 ] ; _rtXdot -> gbnpend52x [ 0U ] += _rtP
-> P_7 [ 1 ] * _rtX -> gbnpend52x [ 1 ] ; _rtXdot -> gbnpend52x [ 1U ] +=
_rtP -> P_7 [ 2 ] * _rtX -> gbnpend52x [ 0 ] ; _rtXdot -> gbnpend52x [ 1U ]
+= _rtP -> P_7 [ 3 ] * _rtX -> gbnpend52x [ 1 ] ; _rtXdot -> gbnpend52x [ 0U
] += _rtP -> P_8 [ 0 ] * _rtB -> i4abazdcvg [ 0 ] ; _rtXdot -> gbnpend52x [
0U ] += _rtP -> P_8 [ 1 ] * _rtB -> i4abazdcvg [ 1 ] ; _rtXdot -> gbnpend52x
[ 1U ] += _rtP -> P_8 [ 2 ] * _rtB -> i4abazdcvg [ 1 ] ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { n3qi1whofz * _rtB ;
loikxjbxjg * _rtP ; d15n1ti4kq * _rtZCSV ; _rtZCSV = ( ( d15n1ti4kq * )
ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( ( loikxjbxjg * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz * ) _ssGetBlockIO ( S ) ) ;
_rtZCSV -> jzote1vmtp = ssGetT ( S ) - _rtP -> P_29 ; _rtZCSV -> ekna21tdsn =
ssGetT ( S ) - _rtP -> P_32 ; _rtZCSV -> dbeflneu4g = ssGetT ( S ) - _rtP ->
P_35 ; _rtZCSV -> agcox0kcw3 = _rtB -> gbiuncg1uv - _rtP -> P_43 ; _rtZCSV ->
mms4xniyb5 = _rtB -> gbiuncg1uv - _rtP -> P_44 ; _rtZCSV -> hmxvsyr3ws = _rtB
-> jdjzgac40n - _rtP -> P_15 ; _rtZCSV -> mrycfzaaqv = _rtB -> jdjzgac40n -
_rtP -> P_16 ; _rtZCSV -> pochufw241 = _rtB -> ddd22lsmde - _rtP -> P_18 ;
_rtZCSV -> ik1l41ldhn = _rtB -> ddd22lsmde - _rtP -> P_19 ; _rtZCSV ->
ggmoblpnht = _rtB -> fpp5ju02ph - _rtP -> P_20 ; _rtZCSV -> fc4mrczv10 = _rtB
-> fpp5ju02ph - _rtP -> P_21 ; _rtZCSV -> km2nrlbgzh = _rtB -> pw2esrru50 -
_rtP -> P_23 ; _rtZCSV -> m3rmbpnb5s = _rtB -> pw2esrru50 - _rtP -> P_24 ;
_rtZCSV -> fw0aeyzj1l = ssGetT ( S ) - _rtP -> P_57 ; _rtZCSV -> ha0uijnvr4 =
ssGetT ( S ) - _rtP -> P_60 ; _rtZCSV -> jyykezqlgh = ssGetT ( S ) - _rtP ->
P_63 ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 505899114U ) ; ssSetChecksumVal ( S , 1 , 883711611U ) ;
ssSetChecksumVal ( S , 2 , 90651755U ) ; ssSetChecksumVal ( S , 3 ,
2555492228U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status =
mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status
== 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ;
if ( slVerMat == NULL ) { status = 1 ; } else { status = mxGetString (
slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "8.3" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
ew10rzwqr2 ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( n3qi1whofz ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
loikxjbxjg ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & o2iu0a2jke ) ; } static void mdlInitializeSampleTimes (
SimStruct * S ) { } static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
