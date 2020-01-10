*****Libraries*****
.protect
.inc '0.5micron.lib'
.unprotect

*****Sources*****

VAin A gnd 1v pulse 0v 1v 0 0p 0p 30n 60n
VBin B  gnd 1v pulse 0v 1v 10n 0p 0p 20n 60n
VCin1 Cin  gnd 1v pulse 0v 1v 20n 0p 0p 10n 60n
VCout1 Cout  gnd 1v pulse 0v 1v 5p 80p 80p 10n 20n
Vsum  S gnd 1v pulse 1v 0v 8p 80p 80p 10n 30n



.tran 1ps 200ns
.op
.end
