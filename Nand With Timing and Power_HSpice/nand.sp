*Cmos NAND*
.include "C:\Users\ssa\Desktop\HSpice_CA2\45nm.pm"

.vec "C:\Users\ssa\Desktop\HSpice_CA2\VectorTest.txt"

.param      Lmin=45n
+beta=0.4
+wp=2*Lmin*beta
+wn=2*Lmin
+vddVoltage=1v
+vinVoltage=1v
+VoltA=1v
+VoltB=1v
+VoltC=1v

mpmos_1 out A  vdd vdd pmos w=90n  l=45n
mpmos_2 out B  vdd vdd pmos w=90n  l=45n
mpmos_3 out C  vdd vdd pmos w=90n  l=45n
mnmos_1 out A  NAB NAB nmos w=135n l=45n
mnmos_2 NAB B  NBC NBC nmos w=135n l=45n
mnmos_3 NBC C  gnd gnd nmos w=135n l=45n


Vvoltagesource_1 vdd gnd vddVoltage


.tran 1ps 200ps 
.meas tran average_power avg SRC_power

.END
