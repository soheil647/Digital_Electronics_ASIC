* SPICE written by the Tanner Research schematic editor, S-Edit
* Version: 2.0 Beta 3     Oct 24, 1997  16:31:49

* Main circuit: sreson
V1 N5 0 5 
XComb1 N5 ltm N8 lte comb NG=18 GAP=3e-006 X0=1e-005 W=4e-006 L=2e-005 NF=9 RMIN=1e-005 DIR=1
XComb2 N7 rtm N6 rte comb NG=18 GAP=3e-006 X0=1e-005 W=4e-006 L=2e-005 NF=9 RMIN=1e-005 DIR=1
XFSpring3 N2 botm N3 bote fspring L=0.0001 W=2e-006 NSP=8 RF=1 NSQ0=2 MF=4 A0=1.76e-012 X0=0 RMIN=1e-005
XFSpring4 N4 topm N1 tope fspring L=0.0001 W=2e-006 NSP=8 RF=1 NSQ0=2 MF=4 A0=1.76e-012 X0=0 RMIN=1e-005
XMass5 ltm rtm botm topm lte rte bote tope plate4 L=0.0002 W=0.0002
* End of main circuit: sreson
.END
