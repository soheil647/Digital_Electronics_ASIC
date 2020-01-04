**Part2**

.inc '32nm_bulk.pm'


.subckt inverter in out vdd
TP3 out in vdd vdd PMOS L=32nm W=192nm
TN3 out in gnd gnd NMOS L=32nm W=96nm
C1 out gnd 10fF
.ends inverter

**Sources Voltages**
Vvin  vdd  gnd  1v
VDin d gnd 1v pulse 0v 1v 10n 80ps 80ps 150ps 100n
VClock clk  gnd 1v pulse 1v 0v 0n 80ps 80ps 10n 20n

***Circuit***
X1 clk clkbar vdd  inverter
tp1 q1 clkbar d vdd PMOS L=32nm W=192nm
tn1 d clk q1 gnd NMOS L=32nm W=96nm
C2 q1 gnd 10fF
X2 q1 q1_bar vdd  inverter
tp2 q2 clkbar q1bqr vdd PMOS L=32nm W=192nm
tn2 q1_bar clk q2 gnd NMOS L=32nm W=96nm
C3 q2 gnd 10fF
X3 q2 Qout vdd  inverter

.tran 1ps 200ns
.op
.end
