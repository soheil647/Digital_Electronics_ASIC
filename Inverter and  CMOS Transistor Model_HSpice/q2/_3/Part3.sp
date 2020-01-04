*Cmos Invertor*

.include "C:\Users\ssa\Desktop\HSpice_Inverter\45nm_PTM.txt"

.param      Lmin=45n
+beta=0.4
+wp=2*Lmin*beta
+wn=2*Lmin
+vddVoltage=0v
+vinVoltage=1v
+vssVoltage=0v

.model nmos_simple NMOS (LEVEL=1
+ VT0=0.377 KN=2.39e-004 LAMBDA=0.394 PHI=0.6)

mnmos_1 vdd vgg vss vss nmos_simple w=1u l=100n

Vvoltagesource_1 vdd 0 dc vddVoltage
Vvoltagesource_2 vgg 0 dc vinVoltage
Vvoltagesource_3 vss 0 dc vssVoltage



***************** TRAN ********************
.DC vddVoltage 0 1 0.01
.end