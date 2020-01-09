* Circuit Extracted by Tanner Research's L-Edit Version 8.30 / Extract Version 8.30 ;
* TDB File:  C:\Users\ssa\Desktop\L-Edit Adder\L-Edit\L-Edit Layout Files\Adder_Layout.tdb
* Cell:  Cell0	Version 1.49
* Extract Definition File:  ..\Tech\MHP_N05.EXT
* Extract Date and Time:  01/09/2020 - 15:47

* Warning:  Layers with Unassigned AREA Capacitance.
*   <poly wire>
*   <allsubs>
*   <LPNP collector>
*   <n well wire>
*   <LPNP emitter>
*   <N Diff Resistor>
*   <subs>
*   <Poly Resistor>
*   <P Diff Resistor>
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
*   <pdiff>
*   <N Diff Resistor>
*   <subs>
*   <Poly Resistor>
*   <P Diff Resistor>
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
*       5 = Cin_Bar (23,218.5)
*       6 = Sum (34.5,182.5)
*       7 = Input_B (-199.5,217.5)
*       9 = B_Bar (-268,218)
*       10 = Vdd (-237.5,248)
*       12 = Input_A (-418,224.5)
*       15 = Cout (-30,37)
*       16 = A_Bar (-339.5,217.5)

Cpar1 1 0 C=650.991f
Cpar2 2 0 C=228.14675f
Cpar3 3 0 C=658.06f
Cpar4 Cin 0 C=1.53f
Cpar5 Cin_Bar 0 C=2.25f
Cpar6 Sum 0 C=407.2275f
Cpar7 Input_B 0 C=1.35f
Cpar8 8 0 C=324.05875f
Cpar9 B_Bar 0 C=2.25f
Cpar10 Vdd 0 C=2.3978013p
Cpar11 11 0 C=442.65625f
Cpar12 Input_A 0 C=2.34f
Cpar13 13 0 C=3.7137618p
Cpar14 14 0 C=338.36775f
Cpar15 Cout 0 C=315.56425f
Cpar16 A_Bar 0 C=2.25f

M1 1 Cin Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M1 DRAIN GATE SOURCE BULK (85 198 90 207.5) 
M2 Sum Cin_Bar 1 1 PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M2 DRAIN GATE SOURCE BULK (13 198 18 207.5) 
M3 Sum 2 1 1 PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M3 DRAIN GATE SOURCE BULK (-59.5 198 -54.5 207.5) 
M4 1 11 Vdd Vdd PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u 
* M4 DRAIN GATE SOURCE BULK (-129.5 198 -124.5 207.5) 
M5 3 Input_B Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M5 DRAIN GATE SOURCE BULK (-205.5 198 -200.5 207.5) 
M6 11 A_Bar 3 3 PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u 
* M6 DRAIN GATE SOURCE BULK (-349.5 198 -344.5 207.5) 
M7 3 B_Bar 11 3 PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M7 DRAIN GATE SOURCE BULK (-277 198 -272 207.5) 
M8 3 Input_A Vdd Vdd PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u 
* M8 DRAIN GATE SOURCE BULK (-420 198 -415 207.5) 
M9 14 Cin Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M9 DRAIN GATE SOURCE BULK (85 120.5 90 130) 
M10 13 Cin 13 13 NMOS L=5u W=9.5u AD=137.75p PD=48u AS=114p PS=43u 
* M10 DRAIN GATE SOURCE BULK (85 87.5 90 97) 
M11 13 Cin 13 13 NMOS L=5u W=9.5u AD=137.75p PD=48u AS=114p PS=43u 
* M11 DRAIN GATE SOURCE BULK (85 165 90 174.5) 
M12 14 11 Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M12 DRAIN GATE SOURCE BULK (12.5 119.5 17.5 129) 
M13 14 11 13 13 NMOS L=5u W=9.5u AD=118.75p PD=44u AS=133p PS=47u 
* M13 DRAIN GATE SOURCE BULK (12.5 86.5 17.5 96) 
M14 Sum 2 13 13 NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M14 DRAIN GATE SOURCE BULK (-59.5 165 -54.5 174.5) 
M15 13 Cin_Bar 13 13 NMOS L=5u W=9.5u AD=133p PD=47u AS=118.75p PS=44u 
* M15 DRAIN GATE SOURCE BULK (13 165 18 174.5) 
M16 Sum 11 13 13 NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M16 DRAIN GATE SOURCE BULK (-129.5 165 -124.5 174.5) 
M17 2 11 Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M17 DRAIN GATE SOURCE BULK (-182 113.5 -177 123) 
M18 2 11 13 13 NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M18 DRAIN GATE SOURCE BULK (-182 85.5 -177 95) 
M19 13 Input_B 13 13 NMOS L=5u W=9.5u AD=137.75p PD=48u AS=114p PS=43u 
* M19 DRAIN GATE SOURCE BULK (-205.5 165 -200.5 174.5) 
M20 8 A_Bar Vdd Vdd PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u 
* M20 DRAIN GATE SOURCE BULK (-349.5 119 -344.5 128.5) 
M21 Vdd B_Bar 8 Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M21 DRAIN GATE SOURCE BULK (-277 120 -272 129.5) 
M22 11 A_Bar 13 13 NMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u 
* M22 DRAIN GATE SOURCE BULK (-349.5 165 -344.5 174.5) 
M23 8 A_Bar 13 13 NMOS L=5u W=9.5u AD=114p PD=43u AS=137.75p PS=48u 
* M23 DRAIN GATE SOURCE BULK (-349.5 86 -344.5 95.5) 
M24 13 B_Bar 13 13 NMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u 
* M24 DRAIN GATE SOURCE BULK (-277 165 -272 174.5) 
M25 13 B_Bar 13 13 NMOS L=5u W=9.5u AD=118.75p PD=44u AS=133p PS=47u 
* M25 DRAIN GATE SOURCE BULK (-277 87 -272 96.5) 
M26 11 Input_A 13 13 NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M26 DRAIN GATE SOURCE BULK (-420 165 -415 174.5) 
M27 Cout 14 Vdd Vdd PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u 
* M27 DRAIN GATE SOURCE BULK (-48.5 48 -43.5 57.5) 
M28 13 14 13 13 NMOS L=5u W=9.5u AD=133p PD=47u AS=118.75p PS=44u 
* M28 DRAIN GATE SOURCE BULK (-48.5 20 -43.5 29.5) 
M29 Cout 8 Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M29 DRAIN GATE SOURCE BULK (-121.5 47 -116.5 56.5) 
M30 Cout 8 13 13 NMOS L=5u W=9.5u AD=118.75p PD=44u AS=133p PS=47u 
* M30 DRAIN GATE SOURCE BULK (-121.5 19 -116.5 28.5) 

* Total Nodes: 16
* Total Elements: 46
* Total Number of Shorted Elements not written to the SPICE file: 0
* Extract Elapsed Time: 0 seconds
.END
