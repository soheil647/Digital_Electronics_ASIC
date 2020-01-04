*Cmos Invertor*

.include "C:\Users\ssa\Desktop\HSpice_Inverter\45nm_PTM.txt"

.param      Lmin=45n
+beta=0.4
+wp=2*Lmin*beta
+wn=2*Lmin
+vddVoltage=0v
+vinVoltage=0.4v
+vssVoltage=0v

mnmos_1 vdd vgg vss vss nmos w=1u l=100n

Vvoltagesource_1 vdd 0 dc vddVoltage
Vvoltagesource_2 vgg 0 dc vinVoltage
Vvoltagesource_3 vss 0 dc vssVoltage



***************** TRAN ********************
.DC vddVoltage 0 1 0.01
.end