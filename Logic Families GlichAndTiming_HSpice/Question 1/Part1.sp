**Part 1**

.inc '32nm_bulk.pm'

.subckt NAND_Circuit in1 in2 out vdd gnd
TP1 out in1 vdd PMOS L=32nm W=32nm
TP2 out in2 vdd PMOS L=32nm W=32nm

TN1 out in1 q2 NMOS L=32nm W=32nm
TN2 q2 in2 gnd NMOS L=32nm W=32nm
C1 out gnd 20fF
.ends NAND_Circuit


.subckt inverter_Circuit in out vdd gnd
TP3 out in vdd PMOS L=32nm W=32nm
TN3 out in gnd NMOS L=32nm W=32nm
C1 out gnd 10fF
.ends inverter_Circuit

.subckt NOR_Circuit in1 in2 out vdd gnd
TPp1 q1 in1 vdd PMOS L=32nm W=32nm
TPp2 out in2 q1 PMOS L=32nm W=32nm

TNn1 out in1 gnd NMOS L=32nm W=32nm
TNn2 out in2 gnd NMOS L=32nm W=32nm
C1 out gnd 20fF
.ends NOR_Circuit

**Sources**
Vvin  vdd  gnd  1v
VSin s gnd 1v pulse 0v 1v 37n 0n 0n 3n 100n
VRin r gnd 1v pulse 0v 1v 29n 0n 0n 7n 100n
VCin c  gnd 1v pulse 1v 0v 0 0n 0n 10n 20n

**Circuit**
X1 s c w1 vdd gnd  NAND_Circuit
X2 r c w2 vdd gnd  NAND_Circuit

X3 w1 v1 vdd gnd  inverter_Circuit
X4 w2 v2 vdd gnd  inverter_Circuit

X5 v1 Q Q_bar vdd gnd  NOR_Circuit
X6 v2 Q_bar Q vdd gnd  NOR_Circuit

.tran 1ps 200ns
.op
.end
