*Cmos Invertor*

.include "C:\Users\ssa\Desktop\HSpice_Inverter\45nm_PTM.txt"

.param      Lmin=45n
+beta=0.4
+wp=2*Lmin*beta
+wn=2*Lmin
+vddVoltage=1v
+vinVoltage=1v

mpmos_1 out in vdd vdd pmos w=180n l=45n
mnmos_1 out in gnd gnd nmos w=90n l=45n
C out gnd 20f

Vvoltagesource_1 vdd gnd dc vddVoltage
Vvoltagesource_2 in gnd dc pulse( vinVoltage  0 0 10p 10p 20n 100n)



***************** TRAN ********************
.tran 1ns 22ns 0.1ps
.end