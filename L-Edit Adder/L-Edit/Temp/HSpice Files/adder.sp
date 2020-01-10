* Circuit Extracted by Tanner Research's L-Edit Version 8.30 / Extract Version 8.30 ;
* TDB File:  C:\Users\ssa\Desktop\L-Edit Adder\L-Edit\L-Edit Layout Files\Adder_Layout.tdb
* Cell:  Cell0	Version 1.55
* Extract Definition File:  ..\Tech\MHP_N05.EXT
* Extract Date and Time:  01/10/2020 - 22:25

* Warning:  Layers with Unassigned AREA Capacitance.
*   <poly wire>
*   <allsubs>
*   <LPNP collector>
*   <n well wire>
*   <LPNP emitter>
*   <subs>
*   <N Diff Resistor>
*   <P Diff Resistor>
*   <Poly Resistor>
*   <N Well Resistor>
*   <Metal1>
*   <Metal1-Tight>
*   <Metal2>
*   <Metal2-Tight>
* Warning:  Layers with Unassigned FRINGE Capacitance.
*   <poly wire>
*   <ndiff>
*   <Pad Comment>
*   <AllMetal1>
*   <allsubs>
*   <LPNP collector>
*   <n well wire>
*   <LPNP emitter>
*   <subs>
*   <N Diff Resistor>
*   <P Diff Resistor>
*   <pdiff>
*   <Poly Resistor>
*   <N Well Resistor>
*   <AllMetal2>
*   <Metal3>
*   <Metal1>
*   <Metal1-Tight>
*   <Metal2>
*   <Metal2-Tight>
* Warning:  Layers with Zero Resistance.
*   <cap using Cap-Well>
*   <poly wire>
*   <Pad Comment>
*   <allsubs>
*   <LPNP collector>
*   <n well wire>
*   <LPNP emitter>
*   <subs>
*   <NMOS Capacitor>
*   <PMOS Capacitor>
*   <Metal1>
*   <Metal1-Tight>
*   <Metal2>
*   <Metal2-Tight>

* NODE NAME ALIASES
*       4 = Cin (92,219.5)
*       6 = Cin_Bar (23,218.5)
*       7 = Sum (34.5,182.5)
*       9 = Input_B (-199.5,217.5)
*       11 = GND (-74.5,-13)
*       13 = B_Bar (-268,218)
*       14 = Vdd (-237.5,248)
*       17 = Input_A (-418,224.5)
*       21 = Cout (-30,37)
*       23 = A_Bar (-339.5,217.5)

***************Params************
.param Vdd_voltage=1v
**************Sub Circuits*******
.subckt mynot inA outY vddD gndD
M1p outY inA vddD vddD pmos L=1.25u W=3u AD=6.75p PD=10.5u AS=8.625p PS=11.75u
M2n outY inA gndD gndD nmos L=1.25u  W=1.5u AD=3.9375p PD=8.25u AS=3.75p PS=8u
.ends mynot

**************Circuit************
Cpar1 1 0 C=650.991f
Cpar2 2 0 C=228.14675f
Cpar3 3 0 C=658.06f
Cpar4 Cin 0 C=1.53f
Cpar5 5 0 C=148.0635f
Cpar6 Cin_Bar 0 C=2.25f
Cpar7 Sum 0 C=407.2275f
Cpar8 8 0 C=158.388f
Cpar9 Input_B 0 C=1.35f
Cpar10 10 0 C=148.0635f
Cpar11 GND 0 C=2.6195838p
Cpar12 12 0 C=324.05875f
Cpar13 B_Bar 0 C=2.25f
Cpar14 Vdd 0 C=2.3978013p
Cpar15 15 0 C=160.60225f
Cpar16 16 0 C=442.65625f
Cpar17 Input_A 0 C=2.34f
Cpar18 18 0 C=154.81075f
Cpar19 19 0 C=338.36775f
Cpar20 20 0 C=152.80725f
Cpar21 Cout 0 C=315.56425f
Cpar22 22 0 C=154.81075f
Cpar23 A_Bar 0 C=2.25f

M1 1 Cin Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M1 DRAIN GATE SOURCE BULK (85 198 90 207.5)
M2 Sum Cin_Bar 1 1 PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M2 DRAIN GATE SOURCE BULK (13 198 18 207.5)
M3 Sum 2 1 1 PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M3 DRAIN GATE SOURCE BULK (-59.5 198 -54.5 207.5)
M4 1 16 Vdd Vdd PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u
* M4 DRAIN GATE SOURCE BULK (-129.5 198 -124.5 207.5)
M5 3 Input_B Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M5 DRAIN GATE SOURCE BULK (-205.5 198 -200.5 207.5)
M6 16 A_Bar 3 3 PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u
* M6 DRAIN GATE SOURCE BULK (-349.5 198 -344.5 207.5)
M7 3 B_Bar 16 3 PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M7 DRAIN GATE SOURCE BULK (-277 198 -272 207.5)
M8 3 Input_A Vdd Vdd PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u
* M8 DRAIN GATE SOURCE BULK (-420 198 -415 207.5)
M9 19 Cin Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M9 DRAIN GATE SOURCE BULK (85 120.5 90 130)
M10 18 Cin GND GND NMOS L=5u W=9.5u AD=137.75p PD=48u AS=114p PS=43u
* M10 DRAIN GATE SOURCE BULK (85 87.5 90 97)
M11 8 Cin GND GND NMOS L=5u W=9.5u AD=137.75p PD=48u AS=114p PS=43u
* M11 DRAIN GATE SOURCE BULK (85 165 90 174.5)
M12 19 16 Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M12 DRAIN GATE SOURCE BULK (12.5 119.5 17.5 129)
M13 19 16 18 GND NMOS L=5u W=9.5u AD=118.75p PD=44u AS=133p PS=47u
* M13 DRAIN GATE SOURCE BULK (12.5 86.5 17.5 96)
M14 Sum 2 5 GND NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M14 DRAIN GATE SOURCE BULK (-59.5 165 -54.5 174.5)
M15 5 Cin_Bar GND GND NMOS L=5u W=9.5u AD=133p PD=47u AS=118.75p PS=44u
* M15 DRAIN GATE SOURCE BULK (13 165 18 174.5)
M16 Sum 16 8 GND NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M16 DRAIN GATE SOURCE BULK (-129.5 165 -124.5 174.5)
M17 2 16 Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M17 DRAIN GATE SOURCE BULK (-182 113.5 -177 123)
M18 2 16 GND GND NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M18 DRAIN GATE SOURCE BULK (-182 85.5 -177 95)
M19 15 Input_B GND GND NMOS L=5u W=9.5u AD=137.75p PD=48u AS=114p PS=43u
* M19 DRAIN GATE SOURCE BULK (-205.5 165 -200.5 174.5)
M20 12 A_Bar Vdd Vdd PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u
* M20 DRAIN GATE SOURCE BULK (-349.5 119 -344.5 128.5)
M21 Vdd B_Bar 12 Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M21 DRAIN GATE SOURCE BULK (-277 120 -272 129.5)
M22 16 A_Bar 10 GND NMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u
* M22 DRAIN GATE SOURCE BULK (-349.5 165 -344.5 174.5)
M23 12 A_Bar 22 GND NMOS L=5u W=9.5u AD=114p PD=43u AS=137.75p PS=48u
* M23 DRAIN GATE SOURCE BULK (-349.5 86 -344.5 95.5)
M24 GND B_Bar 10 GND NMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u
* M24 DRAIN GATE SOURCE BULK (-277 165 -272 174.5)
M25 GND B_Bar 22 GND NMOS L=5u W=9.5u AD=118.75p PD=44u AS=133p PS=47u
* M25 DRAIN GATE SOURCE BULK (-277 87 -272 96.5)
M26 16 Input_A 15 GND NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M26 DRAIN GATE SOURCE BULK (-420 165 -415 174.5)
M27 Cout 19 Vdd Vdd PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u
* M27 DRAIN GATE SOURCE BULK (-48.5 48 -43.5 57.5)
M28 20 19 GND GND NMOS L=5u W=9.5u AD=133p PD=47u AS=118.75p PS=44u
* M28 DRAIN GATE SOURCE BULK (-48.5 20 -43.5 29.5)
M29 Cout 12 Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u
* M29 DRAIN GATE SOURCE BULK (-121.5 47 -116.5 56.5)
M30 Cout 12 20 GND NMOS L=5u W=9.5u AD=118.75p PD=44u AS=133p PS=47u
* M30 DRAIN GATE SOURCE BULK (-121.5 19 -116.5 28.5)

X1 Input_A A_Bar Vdd Gnd mynot
X2 Input_B B_Bar Vdd Gnd mynot
X4 Cin Cin_Bar Vdd Gnd mynot

VSupply   Vdd Gnd DC Vdd_voltage
VA        Input_A          gnd      Pulse      0v     Vdd_voltage       0ns     80ps    80ps  1000ns   2000ns
VB        Input_B          gnd      Pulse      0v     Vdd_voltage       0ns     80ps    80ps  1500ns   3000ns
VCin      Cin        gnd      Pulse      0v     Vdd_voltage       0ns     80ps    80ps  1900ns   3800ns

************Analysis********
.TRAN 1ns 4000ns 0.1ps

* Total Nodes: 23
* Total Elements: 53
* Total Number of Shorted Elements not written to the SPICE file: 0
* Extract Elapsed Time: 0 seconds
.END
