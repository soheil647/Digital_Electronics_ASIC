* Circuit Extracted by Tanner Research's L-Edit Version 8.30 / Extract Version 8.30 ;
* TDB File:  J:\ShippingFiles\tech\lvs_ccd\morb20cc.tdb
* Cell:  morb20cc	Version 1.06
* Extract Definition File:  morb20cc.ext

.model NMOS
.model PMOS
.model NMOSP2
.model PMOSP2

* NODE NAME ALIASES
*       3 = Shield (41,47)
*       5 = OUT (86,47)
*       8 = Gnd (87,78)
*       11 = Vdd (135,78)

X1 1 17 18 Gnd BNP1S0A2
* X1 G A1 A2 B (37 87 43 91) 
X2 7 Shield 9 Gnd BNP1S2A0
* X2 G S1 S2 B (37 60 40 63) 
X3 9 OUT 2 Gnd BNP1S2A0
* X3 G S1 S2 B (51 52 81 55) 
X4 10 13 6 Gnd BNP1S2A0
* X4 G S1 S2 B (33 73 36 76) 
X5 13 2 9 Gnd BNP1S2A0
* X5 G S1 S2 B (46 67 49 70) 
M1 16 Gnd Gnd Gnd NMOS L=6u W=3u AD=3p PD=5u AS=39p PS=26u 
* M1 DRAIN GATE SOURCE BULK (93 85 99 88) 
M2 Vdd 1 4 Vdd PMOSP2 L=4u W=3u AD=39p PD=26u AS=39p PS=26u 
* M2 DRAIN GATE SOURCE BULK (129 85 133 88) 
X6 12 13 17 Gnd BNP2S1A1
* X6 G S1 A1 B (37 82 43 85) 
X7 15 14 18 Gnd BNP2S1A1
* X7 G S1 A1 B (37 93 43 98) 
M3 4 1 16 Gnd NMOSP2 L=4u W=3u AD=39p PD=26u AS=3p PS=5u 
* M3 DRAIN GATE SOURCE BULK (101 85 105 88) 

* Total Nodes: 18
* Total Elements: 10
* Total Number of Shorted Elements not written to the SPICE file: 0
* Extract Elapsed Time: 0 seconds
.END
