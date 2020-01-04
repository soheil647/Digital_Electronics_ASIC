module Hello_World_module {

#include "ldata.h"

void  HelloWorldMacro (void)
{
	LDialog_MsgBox ( "Hello, World!" );
}

void  hello_world_macro_register ( void ) {
	LMacro_Register ( "Hello, World!", "HelloWorldMacro" );
}

}  /* End of Module hierarchy */

hello_world_macro_register();
