* Circuit Extracted by Tanner Research's L-Edit Version 8.30 / Extract Version 8.30 ;
* TDB File:  C:\Users\ssa\Desktop\Projects_Github\Digital_Electronics\L-Edit Adder\L-Edit\L-Edit Layout Files\Adder_Layout.tdb
* Cell:  Cell0	Version 1.28
* Extract Definition File:  ..\Tech\MHP_N05.EXT
* Extract Date and Time:  01/09/2020 - 13:49

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
*       4 = Gnd (-211.5,-13.5)
*       4 = Sum (120.5,184.5)
*       10 = Vdd (-237.5,248)
*       14 = Cout (-30,37)

Cpar1 1 0 C=672.9835f
Cpar2 2 0 C=697.0705f
* Warning: Node 3 has zero nodal parasitic capacitance.
Cpar3 Gnd 0 C=3.8477467p
Cpar4 5 0 C=228.14675f
Cpar5 6 0 C=414.8005f
Cpar6 7 0 C=484.71175f
* Warning: Node 8 has zero nodal parasitic capacitance.
Cpar7 9 0 C=358.102f
Cpar8 Vdd 0 C=2.4666858p
* Warning: Node 11 has zero nodal parasitic capacitance.
* Warning: Node 12 has zero nodal parasitic capacitance.
Cpar9 13 0 C=347.16475f
Cpar10 Cout 0 C=315.56425f
* Warning: Node 15 has zero nodal parasitic capacitance.
* Warning: Node 16 has zero nodal parasitic capacitance.

M1 6 3 1 1 PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M1 DRAIN GATE SOURCE BULK (14.5 198 17 207.5) 
M2 1 12 Vdd Vdd PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M2 DRAIN GATE SOURCE BULK (86.5 198 89 207.5) 
M3 6 5 1 1 PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M3 DRAIN GATE SOURCE BULK (-59.5 198 -54.5 207.5) 
M4 1 7 Vdd Vdd PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u 
* M4 DRAIN GATE SOURCE BULK (-129.5 198 -124.5 207.5) 
M5 2 8 Vdd Vdd PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M5 DRAIN GATE SOURCE BULK (-204 198 -201.5 207.5) 
M6 7 15 2 2 PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M6 DRAIN GATE SOURCE BULK (-276 198 -273.5 207.5) 
M7 7 16 2 2 PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M7 DRAIN GATE SOURCE BULK (-348.5 198 -346 207.5) 
M8 2 11 Vdd Vdd PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M8 DRAIN GATE SOURCE BULK (-419 198 -416.5 207.5) 
M9 13 12 Vdd Vdd PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M9 DRAIN GATE SOURCE BULK (86.5 120.5 89 130) 
M10 13 7 Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M10 DRAIN GATE SOURCE BULK (12.5 119.5 17.5 129) 
M11 Gnd 12 Gnd Gnd NMOS L=2.5u W=9.5u AD=147.25p PD=50u AS=128.25p PS=46u 
* M11 DRAIN GATE SOURCE BULK (86.5 87.5 89 97) 
M12 Gnd 12 Gnd Gnd NMOS L=2.5u W=9.5u AD=147.25p PD=50u AS=128.25p PS=46u 
* M12 DRAIN GATE SOURCE BULK (86.5 165 89 174.5) 
M13 13 7 Gnd Gnd NMOS L=5u W=9.5u AD=118.75p PD=44u AS=133p PS=47u 
* M13 DRAIN GATE SOURCE BULK (12.5 86.5 17.5 96) 
M14 Gnd 3 Gnd Gnd NMOS L=2.5u W=9.5u AD=142.5p PD=49u AS=133p PS=47u 
* M14 DRAIN GATE SOURCE BULK (14.5 165 17 174.5) 
M15 6 5 Gnd Gnd NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M15 DRAIN GATE SOURCE BULK (-59.5 165 -54.5 174.5) 
M16 5 7 Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M16 DRAIN GATE SOURCE BULK (-182 113.5 -177 123) 
M17 5 7 Gnd Gnd NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M17 DRAIN GATE SOURCE BULK (-182 85.5 -177 95) 
M18 6 7 Gnd Gnd NMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M18 DRAIN GATE SOURCE BULK (-129.5 165 -124.5 174.5) 
M19 9 15 Vdd Vdd PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M19 DRAIN GATE SOURCE BULK (-276 120 -273.5 129.5) 
M20 Gnd 8 Gnd Gnd NMOS L=2.5u W=9.5u AD=147.25p PD=50u AS=128.25p PS=46u 
* M20 DRAIN GATE SOURCE BULK (-204 165 -201.5 174.5) 
M21 Gnd 15 Gnd Gnd NMOS L=2.5u W=9.5u AD=142.5p PD=49u AS=133p PS=47u 
* M21 DRAIN GATE SOURCE BULK (-276 165 -273.5 174.5) 
M22 Gnd 15 Gnd Gnd NMOS L=2.5u W=9.5u AD=147.25p PD=50u AS=128.25p PS=46u 
* M22 DRAIN GATE SOURCE BULK (-276 87 -273.5 96.5) 
M23 9 16 Vdd Vdd PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M23 DRAIN GATE SOURCE BULK (-348.5 119 -346 128.5) 
M24 7 16 Gnd Gnd NMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M24 DRAIN GATE SOURCE BULK (-348.5 165 -346 174.5) 
M25 9 16 Gnd Gnd NMOS L=2.5u W=9.5u AD=128.25p PD=46u AS=147.25p PS=50u 
* M25 DRAIN GATE SOURCE BULK (-348.5 86 -346 95.5) 
M26 7 11 Gnd Gnd NMOS L=2.5u W=9.5u AD=142.5p PD=49u AS=133p PS=47u 
* M26 DRAIN GATE SOURCE BULK (-419 165 -416.5 174.5) 
M27 Cout 13 Vdd Vdd PMOS L=5u W=9.5u AD=123.5p PD=45u AS=128.25p PS=46u 
* M27 DRAIN GATE SOURCE BULK (-48.5 48 -43.5 57.5) 
M28 Gnd 13 Gnd Gnd NMOS L=5u W=9.5u AD=133p PD=47u AS=118.75p PS=44u 
* M28 DRAIN GATE SOURCE BULK (-48.5 20 -43.5 29.5) 
M29 Cout 9 Vdd Vdd PMOS L=5u W=9.5u AD=128.25p PD=46u AS=123.5p PS=45u 
* M29 DRAIN GATE SOURCE BULK (-121.5 47 -116.5 56.5) 
M30 Cout 9 Gnd Gnd NMOS L=5u W=9.5u AD=118.75p PD=44u AS=133p PS=47u 
* M30 DRAIN GATE SOURCE BULK (-121.5 19 -116.5 28.5) 

* Total Nodes: 16
* Total Elements: 40
* Total Number of Shorted Elements not written to the SPICE file: 0
* Extract Elapsed Time: 0 seconds
.END
