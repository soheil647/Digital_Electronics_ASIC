//*************************************************************************
//* IDENT: $Id: upistub.c,v 1.10 2000/03/27 19:16:21 williams Exp $
//* Copyright © Tanner Research, Inc. 1999 All rights reserved
//* 
//* DESCRIPTION: 
//*************************************************************************

//*************************************************************************
//* INCLUDE FILES:
//*************************************************************************
#include "upistub.h"

/*                         UPI CALLS                     */

LTechnology LFile_GetTechnology( LFile file )
{
	LTechnology tech;

	tech = *CI_LFile_GetTechnology( file, &tech );

	return tech;
}

LStatus LBox_Set( LCell cell, LObject object, LRect box)
{	
	LStatus status;

	printf("\nEntered LBox_Set. with %ld, %ld\n", box.x0, box.y0 );
	status = CI_LBox_Set( cell, object, &box, status );
	return status;
}

LRect LBox_GetRect( LObject object )
{
	LRect rect;

	rect = *CI_LBox_GetRect( object, &rect );

	return rect;
}

LStatus LFile_SetPalette(LFile file, LColor *palette, short index)
{
	LStatus status;
	long l_index;

	l_index = index;
	status = CI_LFile_SetPalette(file, palette, l_index, status);

	return status;
}

LStatus LObject_SetGDSIIDataType(LObject pObject, short iGDSIIDataType)
{
	LStatus eStatus;
	long lGDSIIDataType = iGDSIIDataType;
	
	eStatus = CI_LObject_SetGDSIIDataType(pObject, lGDSIIDataType, eStatus);

	return(eStatus);
} // End of Function:  LObject_SetGDSIIDataType

short LWire_GetMiterAngle( LObject object )
{
	long pass_long_value;
	short ret_short_value;
	
	ret_short_value = CI_LWire_GetMiterAngle( object, pass_long_value );

	return ret_short_value;
}

short LObject_GetGDSIIDataType(LObject pObject)
{
	long lPassLongValue;
	short iReturnShortValue;
	
	iReturnShortValue = CI_LObject_GetGDSIIDataType(pObject, lPassLongValue);

	return(iReturnShortValue);
} // End of Function:  LObject_GetGDSIIDataType

LStatus LCell_SetView(LCell cell, LRect view)
{
	LStatus status;

	status = CI_LCell_SetView(cell, &view, status);
	return status;
}

LRect LCell_GetMbb(LCell cell)
{
	LRect rect;

	rect = *CI_LCell_GetMbb(cell, &rect);

	return rect;
}

LRect LCell_GetMbbAll(LCell cell)
{
	LRect rect;

	rect = *CI_LCell_GetMbbAll(cell, &rect);

	return rect;
}

LRect LCell_GetView(LCell cell)
{
	LRect rect;

	rect = *CI_LCell_GetView(cell, &rect);

	return rect;
}


LRect LObject_GetMbb( LObject object )
{
	LRect rect;

	rect = *CI_LObject_GetMbb( object, &rect );

	return rect;
}

LRect LCircle_GetRect( LObject object )
{
	LRect rect;

	rect = *CI_LCircle_GetRect( object, &rect );

	return rect;
}

LPoint LCircle_GetCenter( LObject object )
{
	LPoint point;

	point = *CI_LCircle_GetCenter( object, &point );

	return point;
}

LObject LCircle_New( LCell cell, LLayer layer, LPoint center,
						  LCoord radius )
{
	LObject object;

	object = CI_LCircle_New(cell, layer, &center, radius, object);

	return object;
}

LStatus LCircle_Set( LCell cell, LObject object, LPoint center,
						  LCoord radius)
{
	LStatus status;
	
	status = CI_LCircle_Set(cell, object, &center, radius, status);

	return status;
}

LRect LPort_GetMbb(LPort port)
{
	LRect rect;

	rect = *CI_LPort_GetMbb( port, &rect );

	return rect;
}

LRect LPort_GetRect( LPort port )
{
	LRect rect;

	rect = *CI_LPort_GetRect( port, &rect );

	return rect;
}

LStatus LPort_Set(LCell cell, LPort port, LRect rect)
{
	LStatus status;

	status = CI_LPort_Set(cell, port, &rect, status);
	
	return status;
}

LRect LInstance_GetMbb(LInstance instance)
{
	LRect rect;

	rect = *CI_LInstance_GetMbb( instance, &rect );

	return rect;
}
	
LTransform LInstance_GetTransform(LInstance instance)
{
	LTransform transform;

	transform = *CI_LInstance_GetTransform(instance, &transform);

	return transform;
}

LTransform_Ex99 LInstance_GetTransform_Ex99(LInstance instance)
{
	LTransform_Ex99 transform;

	transform = *CI_LInstance_GetTransform_Ex99(instance, &transform);

	return transform;
}

LPoint LInstance_GetRepeatCount(LInstance instance)
{
	LPoint point;
	
	point = *CI_LInstance_GetRepeatCount( instance, &point );

	return point;
}

LPoint LInstance_GetDelta(LInstance instance)
{
	LPoint point;

	point = *CI_LInstance_GetDelta(instance, &point);

	return point;
}

LInstance LInstance_New(LCell cell, LCell instance_cell,
								LTransform transform, LPoint repeat_cnt,
								LPoint delta)
{
	LInstance instance;

	instance = CI_LInstance_New(cell, instance_cell, &transform,
										 &repeat_cnt, &delta, instance);

	return instance;
}

LInstance LInstance_New_Ex99(LCell cell, LCell instance_cell,
								LTransform_Ex99 transform, LPoint repeat_cnt,
								LPoint delta)
{
	LInstance instance;

	instance = CI_LInstance_New_Ex99(cell, instance_cell, &transform,
										 &repeat_cnt, &delta, instance);

	return instance;
}

LStatus LInstance_Set(LCell cell, LInstance instance, 
							 LTransform transform, LPoint repeat_cnt,
							 LPoint delta)
{
	LStatus status;

	status = CI_LInstance_Set(cell, instance, &transform,
									  &repeat_cnt, &delta, status);

	return status;
}

LStatus LInstance_Set_Ex99(LCell cell, LInstance instance, 
							 LTransform_Ex99 transform, LPoint repeat_cnt,
							 LPoint delta)
{
	LStatus status;

	status = CI_LInstance_Set_Ex99(cell, instance, &transform,
									  &repeat_cnt, &delta, status);

	return status;
}
							 
void LObject_Transform( LObject object, LTransform transform )
{
	CI_LObject_Transform( object, &transform );
}

//*************************************************************************
// Function Name    : LPoint_Set
// Parameters       : lX - X coordinate.
//                    lY - Y coordinate.
// Description      : Creates an LPoint from the x and y coordinates.
// Returns          : The newly created LPoint.
//*************************************************************************
//  Revision History
//   07/29/1999 - NJW - Created function.
//*************************************************************************
LPoint LPoint_Set(LCoord lX, LCoord lY)
{
	LPoint ptReturnPoint;
	
	ptReturnPoint = *CI_LPoint_Set( lX, lY, &ptReturnPoint);

	return(ptReturnPoint);
} // End of Function:  LPoint_Set

//*************************************************************************
// Function Name    : LPoint_Add
// Parameters       : ptA - Point 1.
//                    ptB - Point 2.
// Description      : Adds two points.
// Returns          : The resultant point.
//*************************************************************************
//  Revision History
//   07/29/1999 - NJW - Created function.
//*************************************************************************
LPoint LPoint_Add(LPoint ptA, LPoint ptB)
{
	LPoint ptReturnPoint;
	
	ptReturnPoint = *CI_LPoint_Add(ptA, ptB, &ptReturnPoint);

	return(ptReturnPoint) ;
} // End of Function:  LPoint_Add

//*************************************************************************
// Function Name    : Upi_LPointSubtract
// Parameters       : ptA - Point 1.
//                    ptB - Point 2.
// Description      : Subtracts two points.
// Returns          : The resultant point.
//*************************************************************************
//  Revision History
//   07/29/1999 - NJW - Created function.
//*************************************************************************
LPoint LPoint_Subtract(LPoint ptA, LPoint ptB)
{
	LPoint ptReturnPoint;
	
	ptReturnPoint = *CI_LPoint_Subtract(ptA, ptB, &ptReturnPoint);

	return(ptReturnPoint) ;
} // End of Function:  LPoint_Subtract

LRect LRect_Set(LCoord x0, LCoord y0, LCoord x1, LCoord y1)
{
	LRect ret_rect;
	
	ret_rect = *CI_LRect_Set( x0, y0, x1, y1, &ret_rect );

	return ret_rect;
}

LTransform LTransform_Set(LCoord xtrans, LCoord ytrans, 
								  LOrientation orient, LMagnification mag)
{
	LTransform ret_transform;
	
	ret_transform = *CI_LTransform_Set( xtrans, ytrans, &orient, 
												  &mag, &ret_transform );

	return ret_transform;
}

LTransform LTransform_Set_Ex99(LCoord xtrans, LCoord ytrans, 
								  LOrientation_Ex99 orient, LMagnification mag)
{
	LTransform_Ex99 ret_transform;
	
	ret_transform = *CI_LTransform_Set_Ex99( xtrans, ytrans, &orient, 
												  &mag, &ret_transform );

	return ret_transform;
}

LTransform LTransform_Zero(void)
{
	LTransform ret_transform;

	ret_transform = *CI_LTransform_Zero( &ret_transform );

	return ret_transform;
}

LTransform_Ex99 LTransform_Zero_Ex99(void)
{
	LTransform_Ex99 ret_transform;

	ret_transform = *CI_LTransform_Zero_Ex99( &ret_transform );

	return ret_transform;
}

LTransform LTransform_Add( LTransform transform_to_be_added,
								  LTransform current_transform)
{
	LTransform ret_transform;

	ret_transform = *CI_LTransform_Add( &transform_to_be_added,
												  &current_transform, &ret_transform );

	return ret_transform;
}

LTransform_Ex99 LTransform_Add_Ex99(LTransform_Ex99 transform_to_be_added,
												LTransform_Ex99 current_transform)
{
	LTransform_Ex99 ret_transform;

	ret_transform = *CI_LTransform_Add_Ex99( &transform_to_be_added,
												  &current_transform, &ret_transform );

	return ret_transform;
}

LTransform LTransform_Subtract( LTransform transform_to_be_subtracted,
								  LTransform current_transform)
{
	LTransform ret_transform;

	ret_transform = *CI_LTransform_Subtract( &transform_to_be_subtracted,
												  &current_transform, &ret_transform );

	return ret_transform;
}

LTransform_Ex99 LTransform_Subtract_Ex99( LTransform_Ex99 transform_to_be_subtracted,
														LTransform_Ex99 current_transform)
{
	LTransform_Ex99 ret_transform;

	ret_transform = *CI_LTransform_Subtract_Ex99( &transform_to_be_subtracted,
												  &current_transform, &ret_transform );

	return ret_transform;
}

LPoint LPoint_Transform( LPoint point, LTransform transform )
{
	LPoint ret_point;
	
	ret_point = *CI_LPoint_Transform( &point, &transform, &ret_point );

	return ret_point;
}

LPoint LPoint_Transform_Ex99(LPoint point, LTransform_Ex99 transform)
{
	LPoint ret_point;
	
	ret_point = *CI_LPoint_Transform_Ex99( &point, &transform, &ret_point );

	return ret_point;
}

LRect LRect_Transform( LRect rect, LTransform transform )
{
	LRect ret_rect;
	
	ret_rect = *CI_LRect_Transform( &rect, &transform, &ret_rect );

	return ret_rect;
}

LRect LRect_Transform_Ex99(LRect rect, LTransform_Ex99 transform )
{
	LRect ret_rect;
	
	ret_rect = *CI_LRect_Transform_Ex99( &rect, &transform, &ret_rect );

	return ret_rect;
}

LPoint LCursor_GetPosition( void )
{
	LPoint point;

	point = *CI_LCursor_GetPosition( &point );

	return point;
}

//   01/27/1999 - LingTu - 
LPoint LCursor_GetSnappedPosition( void )
{
	LPoint point;

	point = *CI_LCursor_GetSnappedPosition( &point );

	return point;
}

LPoint LCursor_GetPositionEx99(int iSnapped, int iPauseForInput, const char* szMessage)
{
	LPoint TempPoint;
	TempPoint = *CI_LCursor_GetPositionEx99(iSnapped, iPauseForInput, szMessage, &TempPoint);
	return(TempPoint);
} // End of Function:  LCursor_GetPositionEx99

/*                        L-COMP CALLS                    */

/*LPoint LC_SetPosition(LCoord xpos, LCoord ypos)
{
	LPoint retpoint;

	retpoint = *CI_LC_SetPosition(xpos, ypos, &retpoint);

	return retpoint;
}

LPoint LC_SetXYPosition(LCoord xpos, LCoord ypos)
{
	LPoint retpoint;

	retpoint = *CI_LC_SetXYPosition(xpos, ypos, &retpoint);

	return retpoint;
}

LPoint LC_GetPosition(void)
{
	LPoint retpoint;

	retpoint = *CI_LC_GetPosition(&retpoint);

	return retpoint;
}

LPoint LC_Push(void)
{
	LPoint retpoint;

	retpoint = *CI_LC_Push(&retpoint);

	return retpoint;
}

LPoint LC_Pop(void)
{
	LPoint retpoint;

	retpoint = *CI_LC_Pop(&retpoint);

	return retpoint;
}

LPoint LC_StackRoll(int num)
{
	LPoint retpoint;

	retpoint = *CI_LC_StackRoll(num, &retpoint);

	return retpoint;
}

LPoint LC_WirePoint(LPoint point)
{
	LPoint retpoint;

	retpoint = *CI_LC_WirePoint( &point, &retpoint );

	return retpoint;
}

LObject LC_Box(char *layername, LPoint ll, LPoint ur)
{
	LObject obj;

	obj = CI_LC_Box(layername, &ll, &ur, obj);

	return obj;
}

LObject LC_Circle(char *layername, LPoint center, LCoord radius)
{
	LObject obj;

	obj = CI_LC_Circle(layername, &center, radius, obj);

	return obj;
}

LPort LC_Port(char *layer, LPoint ll, LPoint ur, char *portname)
{
	LPort retport;

	retport = CI_LC_Port(layer, &ll, &ur, portname, retport);

	return retport;
}

LPoint LC_PolygonPoint(LPoint point)
{
	LPoint retpoint;

	retpoint = *CI_LC_PolygonPoint( &point, &retpoint);

	return retpoint;
}
*/

	

LPoint	LVertex_GetPoint( LVertex vertex)
{
	LPoint ret_point;
	
	ret_point = *CI_LVertex_GetPoint(vertex, &ret_point);

	return ret_point;
}

LStatus	LVertex_SetPoint( LVertex vertex, LPoint point )
{
	LStatus status;
	
	status = CI_LVertex_SetPoint(vertex, &point);
	
	return status;
}

LStatus	LVertex_Add( LObject object, LVertex prev_vertex, LPoint point )
{
	LStatus status;
	
	status = CI_LVertex_Add(object, prev_vertex, &point);
	
	return status;
}

LObject LTorus_New(LCell cell, LLayer layer, LPoint center, 
										double startangle, double stopangle,
										LCoord radius1, LCoord radius2)
{
	LObject object;
	object = CI_LTorus_New(cell, layer, &center, &startangle, &stopangle, radius1, radius2, object);
	return object;
}

LStatus LTorus_Set(LCell cell, LObject object, LPoint center, 
										double startangle, double stopangle,
										LCoord radius1, LCoord radius2)
{
	LStatus status;
	status = CI_LTorus_Set(cell, object, &center, &startangle, &stopangle, radius1, radius2);
	return status;
}

LPoint LTorus_GetCenter(LObject object)
{
	LPoint center;
	center = *CI_LTorus_GetCenter(object, &center);
	return center;
}

LObject LPie_New(LCell cell, LLayer layer, LPoint center, 
										double startangle, double stopangle,
										LCoord radius)
{
	LObject object;
	object = CI_LPie_New(cell, layer, &center, &startangle, &stopangle, radius, object);
	return object;
}

LStatus LPie_Set(LCell cell, LObject object, LPoint center, 
										double startangle, double stopangle,
										LCoord radius)
{
	LStatus status;
	status = CI_LPie_Set(cell, object, &center, &startangle, &stopangle, radius);
	return status;
}

LPoint LPie_GetCenter(LObject object)
{
	LPoint center;
	center = *CI_LPie_GetCenter(object, &center);
	return center;
}

LStatus LVertex_AddCurve(LObject object, LVertex vertex, LPoint center, LArcDirection dir)
{
	LStatus status;
	status = CI_LVertex_AddCurve(object, vertex, &center, &dir);
	return status;
}

LStatus LVertex_SetCurve(LVertex vertex, LPoint center, LArcDirection dir)
{
	LStatus status;
	status = CI_LVertex_SetCurve(vertex, &center, &dir);
	return status;
}

DPoint LVertex_GetCurveExactCenter(LObject object, LVertex vertex, LCoord radius, LArcDirection *dir)
{
	DPoint center;
	center = *CI_LVertex_GetCurveExactCenter(object, vertex, radius, dir, &center);
	return center;
}
