**Part3**

.inc '32nm_bulk.pm'

.subckt NAND2_Circuit in1 in2 out vdd gnd
TP1 out in1 vdd vdd PMOS L=32nm W=32nm
TP2 out in2 vdd vdd PMOS L=32nm W=32nm

TN1 out in1 q2 gnd NMOS L=32nm W=32nm
TN2 q2 in2 gnd gnd NMOS L=32nm W=32nm
C1 out gnd 10fF
.ends NAND2_Circuit

.subckt NAND3_Circuit in1 in2 in3 out vdd gnd
TP1 out in1 vdd vdd PMOS L=32nm W=32nm
TP2 out in2 vdd vdd PMOS L=32nm W=32nm
TP3 out in3 vdd vdd PMOS L=32nm W=32nm

TN1 out in1 q2 gnd NMOS L=32nm W=32nm
TN2 q2 in2 q3 gnd NMOS L=32nm W=32nm
TN3 q3 in3 gnd gnd NMOS L=32nm W=32nm

C1 out gnd 10fF
.ends NAND3_Circuit


**Sources Voltages**
Vvin  vdd  gnd  1v
VDin d gnd 1v pulse 0v 1v 0n 80p 80p 50n 100n
VClock clk  gnd 1v pulse 1v 0v 0p 80p 80p 20n 40n

***Main_Circuit***

C1 n4 n2 n1 vdd gnd NAND2_Circuit
C2 n1 clk n2 vdd gnd NAND2_Circuit
C3 n2 clk n4 n3 vdd gnd NAND3_Circuit
C4 d n3 n4 vdd gnd NAND2_Circuit
C5 n2 n6 n5 vdd gnd NAND2_Circuit
C6 n3 n5 n6 vdd gnd NAND2_Circuit



.tran 1ps 200ns
.op
.end
