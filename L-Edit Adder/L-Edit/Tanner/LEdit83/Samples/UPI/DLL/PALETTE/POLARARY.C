#include <math.h>
#include <string.h>
#include <stdio.h>
#include "ldata.h"

int CalculatePolar_Radius( LInstance instance, int nInstances )
{
	LRect instance_mbb;
	int instance_width;
	double angle = 0;
	double radius = -1;
	char STR[50];
	double pi = 3.1415926535;

	if (!instance)
		return -1;

	instance_mbb = LInstance_GetMbb( instance );
	instance_width = instance_mbb.x1 - instance_mbb.x0;

	angle = (2.0*pi)/nInstances;
	radius = instance_width/(2 * tan(angle/2.0));

	/*sprintf(STR,"W = %d, R=%f", instance_width, radius);
	LDialog_MsgBox(STR);*/
	return (int)(radius+1);
}

void	PlaceAndCenterInstance( LCell cell,  LInstance instance,
										int polar_radius )
{
	LRect mbb;
	LTransform transform;
	LPoint repeat_cnt;
	LPoint delta;
	long dx = 0;
	long dy = 0;
	long width =0;

	mbb = LInstance_GetMbb( instance );
	width = (mbb.x1 - mbb.x0);
	dx = -mbb.x0 - width/2.0;
	dy = -mbb.y0 + polar_radius;
	
	transform = LInstance_GetTransform( instance );
	transform.translation.x += dx;
	transform.translation.y += dy;
	
	repeat_cnt = LInstance_GetRepeatCount( instance);
	delta = LInstance_GetDelta( instance );
	LInstance_Set( cell, instance, transform, repeat_cnt, delta );
}

void PolarArrayMacro( void )
{
	char STR[50];
	char MSG[50];
	LFile cFile;
	LCell cCell;
	LCell iCell;
	LCell tempCell; /* Temporary cell used for proper instance positioning*/
	LInstance tempInstance;
	LTransform transform;
	LPoint repeat_cnt;
	LPoint delta;
	int nInstances; /* No of instances in the polar array */
	int polar_radius;
	LInstance newInstance;
	int i;
	int rotation_angle;
	LWindow tempCellWindow;
	LWindow original_cell_window;


	strcpy(STR,"pcell");
	
	if ( LDialog_InputBox("Cell Name", "Enter Name of the Cell to be instanced",
								 STR) == 0 )
		return;

	cCell = LCell_GetVisible();
	original_cell_window = LWindow_GetVisible();

	cFile = LCell_GetFile( cCell );
	if ( !cCell || !cFile )
		return;
	
	/* Check that the cell to be instanced exists */
	iCell = LCell_Find( cFile, STR );
	if ( !iCell ){
		sprintf(MSG,"Cell %s does not exist", STR);
		LDialog_AlertBox(MSG);
		return;
	}

	/* Create a temporary cell */
	tempCell = LCell_New(cFile, "*tmpCell*");
	tempCellWindow = LWindow_GetVisible();

	if (!tempCell){
		LDialog_AlertBox("Error in creating the temporary cell");
		return;
	}

	/* Create an instance of iCell in temporary cell */
	transform = LTransform_Zero();
	repeat_cnt = LPoint_Set( 1, 1);
	delta = LPoint_Set( 0, 0 );
	tempInstance = LInstance_New( tempCell, iCell, transform,
											repeat_cnt, delta);

	strcpy(STR,"3");	
	if ( LDialog_InputBox("Create Polar Array",
								 "Number of instances in the polar array", STR) == 0 )
		return;
	
	sscanf(STR,"%d",&nInstances);

	if ( nInstances <= 2 ){
		LDialog_AlertBox(" Minimun number of instances should be 3 ");
		return;
	}

	/* Calculate the radius of polar array */
      polar_radius =  CalculatePolar_Radius( tempInstance, nInstances );
		sprintf(STR,"Polar Radius =%d", polar_radius);
		LDialog_MsgBox(STR);

	/* Properly place and center the instance */
		PlaceAndCenterInstance( tempCell, tempInstance, polar_radius );

		LWindow_Close(tempCellWindow);
		LWindow_MakeVisible(original_cell_window);
	/* Create instances of temp cell in the current Cell */
		LSelection_DeselectAll();
		rotation_angle = 360/nInstances;
		for ( i=0; i<nInstances; i++){
			transform = LTransform_Zero();
			repeat_cnt = LPoint_Set( 1, 1);
			delta = LPoint_Set( 0, 0 );			
			newInstance = LInstance_New( cCell, tempCell, transform,
											repeat_cnt, delta);
			transform.orientation = i * rotation_angle;
			LInstance_Set( cCell, newInstance, transform,
											repeat_cnt, delta);
			LSelection_AddObject( (LObject) newInstance);
		}
		LSelection_UnGroup();
		LSelection_DeselectAll();
		/* Delete the temporary Cell */
		LCell_Delete( tempCell );
		LCell_HomeView(cCell);
}





