#include "ldata.h"

void  HelloWorldMacro (void)
{
	LDialog_MsgBox ( "Hello, World!" );
}

int  UPI_Entry_Point ( void ) {
	LMacro_Register ( "Hello, World!", "HelloWorldMacro" );

	return 1;
}