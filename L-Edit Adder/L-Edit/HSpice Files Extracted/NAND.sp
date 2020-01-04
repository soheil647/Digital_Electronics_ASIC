* Circuit Extracted by Tanner Research's L-Edit Version 8.30 / Extract Version 8.30 ;
* TDB File:  C:\Users\ssa\Desktop\Projects_Github\Digital_Electronics\L-Edit Adder\L-Edit\L-Edit Layout Files\NAND_Layout.tdb
* Cell:  Cell0	Version 1.08
* Extract Definition File:  ..\Tech\MHP_N05.EXT
* Extract Date and Time:  01/03/2020 - 17:57

* Warning:  Layers with Unassigned AREA Capacitance.
*   <n well wire>
*   <subs>
*   <poly wire>
*   <P Diff Resistor>
*   <N Well Resistor>
*   <N Diff Resistor>
*   <Poly Resistor>
*   <LPNP collector>
*   <LPNP emitter>
*   <allsubs>
*   <Metal1>
*   <Metal1-Tight>
*   <Metal2>
*   <Metal2-Tight>
* Warning:  Layers with Unassigned FRINGE Capacitance.
*   <pdiff>
*   <n well wire>
*   <subs>
*   <ndiff>
*   <poly wire>
*   <P Diff Resistor>
*   <N Well Resistor>
*   <N Diff Resistor>
*   <Poly Resistor>
*   <LPNP collector>
*   <LPNP emitter>
*   <allsubs>
*   <Pad Comment>
*   <AllMetal1>
*   <AllMetal2>
*   <Metal3>
*   <Metal1>
*   <Metal1-Tight>
*   <Metal2>
*   <Metal2-Tight>
* Warning:  Layers with Zero Resistance.
*   <n well wire>
*   <subs>
*   <poly wire>
*   <PMOS Capacitor>
*   <NMOS Capacitor>
*   <cap using Cap-Well>
*   <LPNP collector>
*   <LPNP emitter>
*   <allsubs>
*   <Pad Comment>
*   <Metal1>
*   <Metal1-Tight>
*   <Metal2>
*   <Metal2-Tight>

* NODE NAME ALIASES
*       2 = Output_NAND (80.5,18)
*       4 = Vdd (-21.5,60)

* Warning: Node 1 has zero nodal parasitic capacitance.
Cpar1 2 0 C=344.4395f
Cpar2 3 0 C=519.1795f
Cpar3 4 0 C=448.5905f
* Warning: Node 5 has zero nodal parasitic capacitance.

M4 2 1 4 4 PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M4 DRAIN GATE SOURCE BULK (62.5 30.5 65 40) 
M3 3 1 3 3 NMOS L=2.5u W=9.5u AD=147.25p PD=50u AS=128.25p PS=46u 
* M3 DRAIN GATE SOURCE BULK (62.5 -2.5 65 7) 
M2 2 5 4 4 PMOS L=2.5u W=9.5u AD=137.75p PD=48u AS=137.75p PS=48u 
* M2 DRAIN GATE SOURCE BULK (-8.5 30.5 -6 40) 
M1 2 5 3 3 NMOS L=2.5u W=9.5u AD=142.5p PD=49u AS=133p PS=47u 
* M1 DRAIN GATE SOURCE BULK (-8.5 -2.5 -6 7) 

* Total Nodes: 5
* Total Elements: 7
* Total Number of Shorted Elements not written to the SPICE file: 0
* Extract Elapsed Time: 0 seconds
.END
