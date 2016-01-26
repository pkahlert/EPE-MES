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
real_T an24lhwopd ; real_T nxj4n2kqk1 ; real_T bk3xp4jcuj ; real_T
currentTime ; real_T pwshdupdri ; real_T a1werbeobb ; real_T lcp133phbl ;
n3qi1whofz * _rtB ; loikxjbxjg * _rtP ; ew10rzwqr2 * _rtDW ; _rtDW = ( (
ew10rzwqr2 * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( loikxjbxjg * )
ssGetDefaultParam ( S ) ) ; _rtB = ( ( n3qi1whofz * ) _ssGetBlockIO ( S ) ) ;
if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> ehctirsryt = _rtP -> P_25 ; _rtB
-> djsv5je2jp = _rtP -> P_26 * _rtB -> ehctirsryt ; } hpyptyxxuz = ( (
f1xhd02yjc * ) ssGetContStates ( S ) ) -> higv254nrc ; pwshdupdri =
muDoubleScalarCos ( hpyptyxxuz ) ; an24lhwopd = ( ( f1xhd02yjc * )
ssGetContStates ( S ) ) -> bujmkolqyo ; a1werbeobb = muDoubleScalarCos (
an24lhwopd ) ; hpyptyxxuz = muDoubleScalarSin ( hpyptyxxuz ) ; an24lhwopd =
muDoubleScalarSin ( an24lhwopd ) ; _rtB -> p5dsurc2ww = pwshdupdri *
a1werbeobb - hpyptyxxuz * an24lhwopd ; if ( ssIsSampleHit ( S , 1 , 0 ) ) {
currentTime = ssGetTaskTime ( S , 1 ) ; if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> bng4gctcqn = ( currentTime >= _rtP -> P_29 ) ; } currentTime =
ssGetTaskTime ( S , 1 ) ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
etbenh3omx = ( currentTime >= _rtP -> P_32 ) ; } currentTime = ssGetTaskTime
( S , 1 ) ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> fry5fbmgyd = (
currentTime >= _rtP -> P_35 ) ; } if ( _rtDW -> etbenh3omx == 1 ) {
currentTime = _rtP -> P_34 ; } else { currentTime = _rtP -> P_33 ; } if (
currentTime > _rtP -> P_38 ) { if ( _rtDW -> bng4gctcqn == 1 ) { _rtB ->
gnlqvhm4tr = _rtP -> P_31 ; } else { _rtB -> gnlqvhm4tr = _rtP -> P_30 ; } }
else if ( _rtDW -> fry5fbmgyd == 1 ) { _rtB -> gnlqvhm4tr = _rtP -> P_37 ; }
else { _rtB -> gnlqvhm4tr = _rtP -> P_36 ; } } nxj4n2kqk1 = ( ( f1xhd02yjc *
) ssGetContStates ( S ) ) -> gjk0lxg443 ; nxj4n2kqk1 *= _rtP -> P_40 ; _rtB
-> awrqd1osjy = _rtP -> P_41 * nxj4n2kqk1 ; lcp133phbl = _rtB -> gnlqvhm4tr -
_rtB -> awrqd1osjy ; bk3xp4jcuj = ( ( f1xhd02yjc * ) ssGetContStates ( S ) )
-> axrdfhsgtz ; _rtB -> ndn2yfj5qf = _rtP -> P_42 * lcp133phbl + bk3xp4jcuj ;
if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> es2xilblr3 = _rtB -> ndn2yfj5qf >=
_rtP -> P_44 ? 1 : _rtB -> ndn2yfj5qf > _rtP -> P_45 ? 0 : - 1 ; } _rtB ->
bvmr0tikah = _rtDW -> es2xilblr3 == 1 ? _rtP -> P_44 : _rtDW -> es2xilblr3 ==
- 1 ? _rtP -> P_45 : _rtB -> ndn2yfj5qf ; _rtB -> p0kvbjqymx = _rtB ->
bvmr0tikah / _rtB -> ehctirsryt ; _rtB -> kg2zz2lqpm = hpyptyxxuz *
a1werbeobb + pwshdupdri * an24lhwopd ; _rtB -> crghnbtphu = _rtP -> P_46 *
_rtB -> kg2zz2lqpm ; _rtB -> dsungriyr4 = ( ( f1xhd02yjc * ) ssGetContStates
( S ) ) -> op3lv53a0k ; if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB ->
noby0j0fdy = _rtP -> P_48 * _rtB -> djsv5je2jp + _rtB -> ehctirsryt ; } _rtB
-> iagl0fr2wv = _rtB -> p0kvbjqymx / _rtB -> ehctirsryt * _rtP -> P_49 ; _rtB
-> bdeji2xcuh = _rtB -> iagl0fr2wv + _rtB -> awrqd1osjy ; _rtB -> cqgyv3dfh5
= _rtB -> noby0j0fdy * _rtB -> bdeji2xcuh + _rtP -> P_50 * _rtB -> p0kvbjqymx
; _rtB -> g4coyt2a3v = _rtP -> P_51 * _rtB -> awrqd1osjy ; _rtB -> d4y3tsozqm
= ( ( f1xhd02yjc * ) ssGetContStates ( S ) ) -> p4rdpwdrcu ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> oh414kdkcp = _rtP -> P_53 * _rtB ->
djsv5je2jp ; } _rtB -> dyful3wc0y = _rtB -> oh414kdkcp - _rtP -> P_54 * _rtB
-> p0kvbjqymx * _rtB -> bdeji2xcuh ; ssCallAccelRunBlock ( S , 1 , 43 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 1 , 44 ,
SS_CALL_MDL_OUTPUTS ) ; bk3xp4jcuj = _rtP -> P_55 * _rtB -> iudd2nyjpx ;
a1werbeobb = _rtP -> P_56 * _rtB -> nuplcm02ku ; _rtB -> bdeji2xcuh =
a1werbeobb - bk3xp4jcuj ; _rtB -> ihvo0vc3sv = ( 0.0 - bk3xp4jcuj ) -
a1werbeobb ; _rtB -> elagz1qr0a = ( _rtB -> f4lpett4ja * _rtB -> ef1y24cz44 -
_rtB -> a2azw0gorq * _rtB -> phetpcff13 ) * _rtP -> P_57 ; if ( ssIsSampleHit
( S , 1 , 0 ) ) { currentTime = ssGetTaskTime ( S , 1 ) ; if (
ssIsMajorTimeStep ( S ) ) { _rtDW -> o23js3v2ei = ( currentTime >= _rtP ->
P_58 ) ; } currentTime = ssGetTaskTime ( S , 1 ) ; if ( ssIsMajorTimeStep ( S
) ) { _rtDW -> aevdpjqpp2 = ( currentTime >= _rtP -> P_61 ) ; } currentTime =
ssGetTaskTime ( S , 1 ) ; if ( ssIsMajorTimeStep ( S ) ) { _rtDW ->
a3ylnquutr = ( currentTime >= _rtP -> P_64 ) ; } if ( _rtDW -> aevdpjqpp2 ==
1 ) { currentTime = _rtP -> P_63 ; } else { currentTime = _rtP -> P_62 ; } if
( currentTime > _rtP -> P_67 ) { if ( _rtDW -> o23js3v2ei == 1 ) { _rtB ->
iosnrluljo = _rtP -> P_60 ; } else { _rtB -> iosnrluljo = _rtP -> P_59 ; } }
else if ( _rtDW -> a3ylnquutr == 1 ) { _rtB -> iosnrluljo = _rtP -> P_66 ; }
else { _rtB -> iosnrluljo = _rtP -> P_65 ; } } ssCallAccelRunBlock ( S , 1 ,
57 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 1 , 58 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 1 , 59 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 1 , 60 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 1 , 61 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> cz2lxw3h0l = _rtB -> elagz1qr0a - _rtB ->
iosnrluljo ; ssCallAccelRunBlock ( S , 1 , 63 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 1 , 64 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> dm2uxklxw5
[ 0 ] = _rtB -> iudd2nyjpx ; _rtB -> dm2uxklxw5 [ 1 ] = _rtB -> bdeji2xcuh ;
_rtB -> dm2uxklxw5 [ 2 ] = _rtB -> ihvo0vc3sv ; ssCallAccelRunBlock ( S , 1 ,
66 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> g24rp0kqf4 [ 0 ] = _rtB -> gnlqvhm4tr ;
_rtB -> g24rp0kqf4 [ 1 ] = _rtB -> awrqd1osjy ; ssCallAccelRunBlock ( S , 1 ,
68 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> g24rp0kqf4 [ 0 ] = _rtB -> elagz1qr0a ;
_rtB -> g24rp0kqf4 [ 1 ] = _rtB -> iosnrluljo ; ssCallAccelRunBlock ( S , 1 ,
70 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> od0fgnpjyd = _rtP -> P_68 * _rtB ->
jvtxtcpxfv ; _rtB -> k235il1kfx = _rtP -> P_69 * _rtB -> jac3ipg4e4 ; _rtB ->
la25ixd5n3 = _rtP -> P_70 * lcp133phbl ; _rtB -> pirgymb50v = _rtB ->
cz2lxw3h0l - _rtP -> P_71 * nxj4n2kqk1 ; UNUSED_PARAMETER ( tid ) ; }
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
= _rtB -> iagl0fr2wv ; } { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> bujmkolqyo =
_rtB -> awrqd1osjy ; } { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> gjk0lxg443 =
_rtB -> pirgymb50v ; } { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> axrdfhsgtz =
_rtB -> la25ixd5n3 ; } { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> op3lv53a0k =
_rtB -> od0fgnpjyd ; } { ( ( pqmvzr1kvu * ) ssGetdX ( S ) ) -> p4rdpwdrcu =
_rtB -> k235il1kfx ; } _rtXdot -> dlw0x3b0bn [ 0 ] = 0.0 ; _rtXdot ->
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
P_35 ; _rtZCSV -> agcox0kcw3 = _rtB -> ndn2yfj5qf - _rtP -> P_44 ; _rtZCSV ->
mms4xniyb5 = _rtB -> ndn2yfj5qf - _rtP -> P_45 ; _rtZCSV -> hmxvsyr3ws = _rtB
-> jdjzgac40n - _rtP -> P_15 ; _rtZCSV -> mrycfzaaqv = _rtB -> jdjzgac40n -
_rtP -> P_16 ; _rtZCSV -> pochufw241 = _rtB -> ddd22lsmde - _rtP -> P_18 ;
_rtZCSV -> ik1l41ldhn = _rtB -> ddd22lsmde - _rtP -> P_19 ; _rtZCSV ->
ggmoblpnht = _rtB -> fpp5ju02ph - _rtP -> P_20 ; _rtZCSV -> fc4mrczv10 = _rtB
-> fpp5ju02ph - _rtP -> P_21 ; _rtZCSV -> km2nrlbgzh = _rtB -> pw2esrru50 -
_rtP -> P_23 ; _rtZCSV -> m3rmbpnb5s = _rtB -> pw2esrru50 - _rtP -> P_24 ;
_rtZCSV -> fw0aeyzj1l = ssGetT ( S ) - _rtP -> P_58 ; _rtZCSV -> ha0uijnvr4 =
ssGetT ( S ) - _rtP -> P_61 ; _rtZCSV -> jyykezqlgh = ssGetT ( S ) - _rtP ->
P_64 ; } static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal
( S , 0 , 3169558509U ) ; ssSetChecksumVal ( S , 1 , 1128706716U ) ;
ssSetChecksumVal ( S , 2 , 1095758405U ) ; ssSetChecksumVal ( S , 3 ,
2953672842U ) ; { mxArray * slVerStructMat = NULL ; mxArray * slStrMat =
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
