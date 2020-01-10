* Circuit Extracted by Tanner Research's L-Edit Version 8.30 / Extract Version 8.30 ;
* TDB File:  D:\Ali-Drive-D\lessons\Digital Electric Circuits\CA5\L-Edit\Tech\Layout1.tdb
* Cell:  Cell0	Version 1.136
* Extract Definition File:  MHP_N05.EXT
* Extract Date and Time:  12/09/2019 - 21:18

* Warning:  Layers with Unassigned AREA Capacitance.
*   <allsubs>
*   <LPNP collector>
*   <n well wire>
*   <LPNP emitter>
*   <poly wire>
*   <subs>
*   <N Well Resistor>
*   <P Diff Resistor>
*   <Poly Resistor>
*   <N Diff Resistor>
*   <Metal1>
*   <Metal1-Tight>
*   <Metal2>
*   <Metal2-Tight>
* Warning:  Layers with Unassigned FRINGE Capacitance.
*   <Pad Comment>
*   <AllMetal1>
*   <allsubs>
*   <LPNP collector>
*   <n well wire>
*   <LPNP emitter>
*   <poly wire>
*   <ndiff>
*   <subs>
*   <N Well Resistor>
*   <P Diff Resistor>
*   <pdiff>
*   <Poly Resistor>
*   <N Diff Resistor>
*   <AllMetal2>
*   <Metal3>
*   <Metal1>
*   <Metal1-Tight>
*   <Metal2>
*   <Metal2-Tight>
* Warning:  Layers with Zero Resistance.
*   <Pad Comment>
*   <allsubs>
*   <LPNP collector>
*   <n well wire>
*   <LPNP emitter>
*   <cap using Cap-Well>
*   <poly wire>
*   <subs>
*   <PMOS Capacitor>
*   <NMOS Capacitor>
*   <Metal1>
*   <Metal1-Tight>
*   <Metal2>
*   <Metal2-Tight>

* WARNING: Node/Element Name Conflicts Found.  The following are the
*              Node/Element names that have been renamed.
* Node 1 has been modified to 1_1
* Node 2 has been modified to 2_1
* Node 3 has been modified to 3_1
***************library***********
.inc '0.5micron.lib'
***************Params************
.param Vdd_voltage=1v
**************Sub Circuits*******
.subckt mynot inA outY vddD gndD 
M1p outY inA vddD vddD pmos L=1.25u W=3u AD=6.75p PD=10.5u AS=8.625p PS=11.75u 
M2n outY inA gndD gndD nmos L=1.25u  W=1.5u AD=3.9375p PD=8.25u AS=3.75p PS=8u 
.ends mynot
**************Circuit************
Cpar1 3_1 0 C=23.107125f
Cpar2 Cout 0 C=23.3505f
Cpar3 3 0 C=67.963687f
Cpar4 4 0 C=67.963687f
Cpar5 Vdd 0 C=171.81637f
Cpar6 6 0 C=7.617375f
Cpar7 7 0 C=6.9615f
Cpar8 2_1 0 C=23.002125f
Cpar9 9 0 C=8.577f
* Warning: Node Cinnot has zero nodal parasitic capacitance.
Cpar10 11 0 C=9.2649375f
* Warning: Node 1not has zero nodal parasitic capacitance.
* Warning: Node Cin has zero nodal parasitic capacitance.
Cpar11 14 0 C=8.206875f
Cpar12 Sum 0 C=43.171875f
Cpar13 1_1 0 C=43.150125f
* Warning: Node Bnot has zero nodal parasitic capacitance.
Cpar14 18 0 C=10.473188f
* Warning: Node Anot has zero nodal parasitic capacitance.
Cpar15 20 0 C=9.21375f
Cpar16 Gnd 0 C=130.48913f
* Warning: Node B has zero nodal parasitic capacitance.
* Warning: Node A has zero nodal parasitic capacitance.

M1 Vdd A 3_1 Vdd PMOS L=1.25u W=3u AD=8.25p PD=11.5u AS=7.125p PS=10.75u 
* M1 DRAIN GATE SOURCE BULK (203.5 -128 208.5 -116) 
M2 3_1 B Vdd Vdd PMOS L=1.25u W=3u AD=10.125p PD=12.75u AS=5.25p PS=9.5u 
* M2 DRAIN GATE SOURCE BULK (149 -127 154 -115) 
M3 Vdd 3_1 Cout Vdd PMOS L=1.25u W=3u AD=7.875p PD=11.25u AS=7.5p PS=11u 
* M3 DRAIN GATE SOURCE BULK (30 -128 35 -116) 
M4 Cout 2_1 Vdd Vdd PMOS L=1.25u W=3u AD=10.5p PD=13u AS=4.875p PS=9.25u 
* M4 DRAIN GATE SOURCE BULK (-24 -127.5 -19 -115.5) 
M5 Vdd 1_1 2_1 Vdd PMOS L=1.25u W=3u AD=6.75p PD=10.5u AS=8.625p PS=11.75u 
* M5 DRAIN GATE SOURCE BULK (-164 -128 -159 -116) 
M6 Vdd Cin 2_1 Vdd PMOS L=1.25u W=3u AD=6.375p PD=10.25u AS=9p PS=12u 
* M6 DRAIN GATE SOURCE BULK (-218 -128.5 -213 -116.5) 
M7 3 Cinnot Sum 3 PMOS L=1.25u W=6u AD=13.5p PD=16.5u AS=16.5p PS=17.5u 
* M7 DRAIN GATE SOURCE BULK (-396 -124 -391 -100) 
M8 Sum 1not 3 3 PMOS L=1.25u W=6u AD=15p PD=17u AS=15p PS=17u 
* M8 DRAIN GATE SOURCE BULK (-462 -123.5 -457 -99.5) 
M9 Vdd Cin 3 Vdd PMOS L=1.25u W=6u AD=16.5p PD=17.5u AS=13.5p PS=16.5u 
* M9 DRAIN GATE SOURCE BULK (-565.5 -125.5 -560.5 -101.5) 
M10 3 1_1 Vdd Vdd PMOS L=1.25u W=6u AD=15.75p PD=17.25u AS=14.25p PS=16.75u 
* M10 DRAIN GATE SOURCE BULK (-625 -124 -620 -100) 
M11 4 Bnot 1_1 4 PMOS L=1.25u W=6u AD=12p PD=16u AS=18p PS=18u 
* M11 DRAIN GATE SOURCE BULK (-749 -127 -744 -103) 
M12 4 Anot 1_1 4 PMOS L=1.25u W=6u AD=17.25p PD=17.75u AS=12.75p PS=16.25u 
* M12 DRAIN GATE SOURCE BULK (-815 -125.5 -810 -101.5) 
M13 4 A Vdd Vdd PMOS L=1.25u W=6u AD=12.75p PD=16.25u AS=17.25p PS=17.75u 
* M13 DRAIN GATE SOURCE BULK (-978 -126 -973 -102) 
M14 Vdd B 4 Vdd PMOS L=1.25u W=6u AD=14.25p PD=16.75u AS=15.75p PS=17.25u 
* M14 DRAIN GATE SOURCE BULK (-918.5 -126 -913.5 -102) 
M15 Gnd A 6 Gnd NMOS L=1.25u W=3u AD=8.625p PD=11.75u AS=6.75p PS=10.5u 
* M15 DRAIN GATE SOURCE BULK (203.5 -184 208.5 -172) 
M16 3_1 B 6 Gnd NMOS L=1.25u W=3u AD=9.75p PD=12.5u AS=5.625p PS=9.75u 
* M16 DRAIN GATE SOURCE BULK (149 -184.5 154 -172.5) 
M17 Gnd 3_1 7 Gnd NMOS L=1.25u W=3u AD=9p PD=12u AS=6.375p PS=10.25u 
* M17 DRAIN GATE SOURCE BULK (30 -184 35 -172) 
M18 Cout 2_1 7 Gnd NMOS L=1.25u W=3u AD=10.5p PD=13u AS=4.875p PS=9.25u 
* M18 DRAIN GATE SOURCE BULK (-24 -186 -19 -174) 
M19 Gnd 1_1 9 Gnd NMOS L=1.25u W=3u AD=7.5p PD=11u AS=7.875p PS=11.25u 
* M19 DRAIN GATE SOURCE BULK (-164 -184 -159 -172) 
M20 9 Cin 2_1 Gnd NMOS L=1.25u W=3u AD=6.375p PD=10.25u AS=9p PS=12u 
* M20 DRAIN GATE SOURCE BULK (-218 -185 -213 -173) 
M21 Gnd Cinnot 11 Gnd NMOS L=1.25u W=3u AD=6.75p PD=10.5u AS=8.625p PS=11.75u 
* M21 DRAIN GATE SOURCE BULK (-396 -217 -391 -205) 
M22 Sum 1not 11 Gnd NMOS L=1.25u W=3u AD=8.625p PD=11.75u AS=6.75p PS=10.5u 
* M22 DRAIN GATE SOURCE BULK (-462 -218 -457 -206) 
M23 Gnd Cin 14 Gnd NMOS L=1.25u W=3u AD=8.25p PD=11.5u AS=7.125p PS=10.75u 
* M23 DRAIN GATE SOURCE BULK (-565.5 -218 -560.5 -206) 
M24 Sum 1_1 14 Gnd NMOS L=1.25u W=3u AD=8.625p PD=11.75u AS=6.75p PS=10.5u 
* M24 DRAIN GATE SOURCE BULK (-625 -218 -620 -206) 
M25 Gnd Bnot 18 Gnd NMOS L=1.25u W=3u AD=5.625p PD=9.75u AS=9.75p PS=12.5u 
* M25 DRAIN GATE SOURCE BULK (-749 -219.5 -744 -207.5) 
M26 18 Anot 1_1 Gnd NMOS L=1.25u W=3u AD=7.875p PD=11.25u AS=7.5p PS=11u 
* M26 DRAIN GATE SOURCE BULK (-815 -219.5 -810 -207.5) 
M27 1_1 A 20 Gnd NMOS L=1.25u W=3u AD=7.875p PD=11.25u AS=7.5p PS=11u 
* M27 DRAIN GATE SOURCE BULK (-978 -219 -973 -207) 
M28 Gnd B 20 Gnd NMOS L=1.25u W=3u AD=7.125p PD=10.75u AS=8.25p PS=11.5u 
* M28 DRAIN GATE SOURCE BULK (-918.5 -219 -913.5 -207) 


X1 A Anot Vdd Gnd mynot
X2 B Bnot Vdd Gnd mynot
X3 1_1 1not Vdd Gnd mynot
X4 Cin Cinnot Vdd Gnd mynot

VSupply   Vdd Gnd DC Vdd_voltage
VA        A          gnd      Pulse      0v     Vdd_voltage       0ns     80ps    80ps  1000ns   2000ns
VB        B          gnd      Pulse      0v     Vdd_voltage       0ns     80ps    80ps  1500ns   3000ns
VCin      Cin        gnd      Pulse      0v     Vdd_voltage       0ns     80ps    80ps  1900ns   3800ns

************Analysis********
.TRAN 1ns 4000ns 0.1ps

.end


* Total Nodes: 23
* Total Elements: 44
* Total Number of Shorted Elements not written to the SPICE file: 0
* Extract Elapsed Time: 0 seconds
.END
