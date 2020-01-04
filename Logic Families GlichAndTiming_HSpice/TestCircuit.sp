**Part2**

.inc '32nm_bulk.pm'


.subckt inverter in out vdd gnd
TP3 out in vdd PMOS L=32nm W=96nm
TN3 out in gnd NMOS L=32nm W=192nm
C1 out gnd 10fF
.ends inverter



**Sources Voltages**
Vvin  vdd  gnd  1v
VDin d gnd 1v pulse 0v 1v 0n 80ps 80ps 20n 100n
VClock clk  gnd 1v pulse 1v 0v 0n 80ps 80ps 10n 20n

**Circuit**
C2 clk clk_bar vdd gnd  inverter
.tran 1ns 200ns
.op
.end
