* No Inductance yet.
.param lumptype = 2
.param NumLumps = 5

.subckt Metal1_TLine p1  p2  l=0.01
txMetal1  p1 0  p2 0 r=88.9k l=1p c=118.4p g=0 length='l' 
+                   lumps='NumLumps' lumptype='lumptype'
.ends

.subckt Metal2_TLine p1  p2  l=0.01
txMetal2  p1 0  p2 0 r=77.8k l=1p c=86.9p g=0 length='l' 
+                   lumps='NumLumps' lumptype='lumptype'
.ends

.subckt Metal3_TLine p1  p2  l=0.01
txMetal3  p1 0  p2 0 r=20.0k l=1p c=41.5p g=0 length='l' 
+                   lumps='NumLumps' lumptype='lumptype'
.ends

.subckt ViaM1M2_Via n1 n2 
rcontact n1 n2 0.61
.ends

.subckt ViaM2M3_Via n1 n2 
rcontact n1 n2 0.62
.ends

.subckt Driver In Out myGND
M1 I1 In myGND myGND CMOSN L=0.6u W=8.4u AD=13.32p PD=20.4u AS=15.12p PS=20.4u
M2 I1 In DrvRecVDD DrvRecVDD CMOSP L=0.6u W=8.4u AD=15.12p PD=20.4u AS=25.92p PS=40.8u
M3 Out I1 myGND myGND CMOSN L=0.6u W=8.4u AD=13.32p PD=20.4u AS=15.12p PS=20.4u
M4 Out I1 DrvRecVDD DrvRecVDD CMOSP L=0.6u W=8.4u AD=15.12p PD=20.4u AS=25.92p PS=40.8u
.ends

.subckt Receiver In myGND
M1 Out In myGND myGND CMOSN L=0.6u W=8.4u AD=13.32p PD=20.4u AS=15.12p PS=20.4u
M2 Out In DrvRecVDD DrvRecVDD CMOSP L=0.6u W=8.4u AD=15.12p PD=20.4u AS=25.92p PS=40.8u 
.ends

* N56S SPICE LEVEL3 PARAMETERS

.MODEL CMOSN NMOS LEVEL=3 PHI=0.700000 TOX=1.0000E-08 XJ=0.200000U TPG=1
+ VTO=0.7812 DELTA=2.4510E-01 LD=4.0510E-08 KP=1.8847E-04 
+ UO=545.8 THETA=2.5170E-01 RSH=2.1290E+01 GAMMA=0.6200 
+ NSUB=1.3810E+17 NFS=7.0710E+11 VMAX=1.8610E+05 ETA=2.2420E-02 
+ KAPPA=9.6720E-02 CGDO=3.66E-10 CGSO=3.66E-10
+ CGBO=4.0161E-10 CJ=5.4E-04 MJ=0.6 CJSW=1.5000E-10 
+ MJSW=0.32 PB=0.99
* Weff = Wdrawn - Delta_W
* The suggested Delta_W is 4.1360E-07

.MODEL CMOSP PMOS LEVEL=3 PHI=0.700000 TOX=1.0000E-08 XJ=0.200000U TPG=-1
+ VTO=-0.9197 DELTA=2.4830E-01 LD=6.7120E-08 KP=4.4546E-05 
+ UO=129.0 THETA=1.7800E-01 RSH=3.4290E+00 GAMMA=0.5230 
+ NSUB=9.8260E+16 NFS=6.4990E+11 VMAX=3.0560E+05 ETA=1.7820E-02 
+ KAPPA=6.3410E+00 CGDO=3.66E-10 CGSO=3.66E-10
+ CGBO=4.2772E-10 CJ=9.3191E-04 MJ=0.51 CJSW=1.5E-10 
+ MJSW=0.193 PB=0.95
* Weff = Wdrawn - Delta_W
* The suggested Delta_W is 4.6180E-07

v_source driver.in  GND  
+  PULSE (0 voltage 'period/4' 'riseTime' 'riseTime' '(period/2)-riseTime' 'period') 

VDrvRecVDD DrvRecVDD 0 voltage

.GLOBAL DrvRecVDD