//*************************************************************************
//* IDENT: $Id: upistub.h,v 1.9 2000/03/27 19:16:21 williams Exp $
//* Copyright © Tanner Research, Inc. 1999 All rights reserved
//* 
//* DESCRIPTION: Proxy functions for the Interpreter.
//*************************************************************************

#if !defined(__UPISTUB_H)
#define __UPISTUB_H

//*************************************************************************
//* INCLUDE FILES:
//*************************************************************************


//*************************************************************************
//* FORWARD DECLARATIONS:
//*************************************************************************


//*************************************************************************
//* GLOBAL CONSTANTS:
//*************************************************************************


//*************************************************************************
//* TYPES AND CLASSES:
//*************************************************************************


//*************************************************************************
//* EXTERN DATA:
//*************************************************************************


//*************************************************************************
//* EXTERN FUNCTIONS:
//*************************************************************************
extern LTechnology* CI_LFile_GetTechnology(LFile file, LTechnology* ltech);
extern LStatus CI_LBox_Set(LCell cell, LObject object, LRect* rect, LStatus status);
extern LRect* CI_LBox_GetRect(LObject object, LRect* rect);
extern LObject CI_LCircle_New(LCell cell, LLayer layer, LPoint* center, LCoord radius, LObject object);
extern LStatus CI_LFile_SetPalette(LFile file, LColor* palette, LStatus status, long l_index);
extern LStatus CI_LObject_SetGDSIIDataType(LObject pObject, long lGDSIIDataType, LStatus eStatus);
extern long CI_LWire_GetMiterAngle(LObject object, long ret_value);
extern long CI_LObject_GetGDSIIDataType(LObject pObject, long lReturnValue);
extern LRect* CI_LCell_GetMbb(LCell cell, LRect* rect);
extern LRect* CI_LCell_GetMbbAll(LCell cell, LRect* rect);
extern LRect* CI_LCell_GetView(LCell cell, LRect* rect);
extern LStatus CI_LCell_SetView(LCell cell, LRect* rect, LStatus status);
extern LRect* CI_LObject_GetMbb(LObject object, LRect* rect);
extern LRect* CI_LCircle_GetRect(LObject object, LRect* rect);
extern LPoint* CI_LCircle_GetCenter(LObject object, LPoint* point);
extern LStatus CI_LCircle_Set(LCell cell, LObject object, LPoint* center, LCoord radius, LStatus status);
extern LRect* CI_LPort_GetMbb(LPort port, LRect* rect);
extern LRect* CI_LPort_GetRect(LPort port, LRect* rect);
extern LStatus	CI_LPort_Set(LCell cell, LPort port, LRect *rect, LStatus status);
extern LRect* CI_LInstance_GetMbb(LInstance instance, LRect* rect);
extern LTransform* CI_LInstance_GetTransform(LInstance instance, LTransform* transform);
extern LTransform_Ex99* CI_LInstance_GetTransform_Ex99(LInstance instance, LTransform_Ex99* transform);
extern LPoint* CI_LInstance_GetRepeatCount(LInstance instance, LPoint* point);
extern LPoint* CI_LInstance_GetDelta(LInstance instance,  LPoint* point);
extern LInstance CI_LInstance_New(LCell cell, LCell instance_cell, LTransform *transform,LPoint* repeat_cnt, LPoint* delta, LInstance instance);
extern LStatus CI_LInstance_Set(LCell cell, LInstance instance, LTransform *transform, LPoint* repeat_cnt, LPoint* delta, LStatus status);
extern void CI_LObject_Transform(LObject object, LTransform* transform);
extern LInstance CI_LInstance_New_Ex99(LCell cell, LCell instance_cell, LTransform_Ex99 *transform, LPoint* repeat_cnt, LPoint* delta, LInstance instance);
extern LStatus CI_LInstance_Set_Ex99(LCell cell, LInstance instance,	LTransform_Ex99 *transform, LPoint* repeat_cnt, LPoint* delta, LStatus status);
extern void CI_LObject_Transform_Ex99(LObject object, LTransform_Ex99* transform);

// LPoint Functions
extern LPoint*	CI_LPoint_Set(LCoord lX, LCoord lY, LPoint* ret_point);
extern LPoint*	CI_LPoint_Add(LPoint ptA, LPoint ptB, LPoint* ptReturnPoint);
extern LPoint*	CI_LPoint_Subtract(LPoint ptA, LPoint ptB, LPoint* ptReturnPoint);

extern LRect* CI_LRect_Set(LCoord x0, LCoord y0, LCoord x1, LCoord y1, LRect* ret_rect);
extern LTransform* CI_LTransform_Set(LCoord xtrans, LCoord ytrans, LOrientation* orient, LMagnification* mag, LTransform* ret_transform);
extern LTransform* CI_LTransform_Zero(LTransform* ret_transform);
extern LTransform* CI_LTransform_Add(LTransform* transform_to_be_added, LTransform* current_transform, LTransform* ret_transform);
extern LTransform* CI_LTransform_Subtract(LTransform* transform_to_be_subtracted, LTransform* current_transform, LTransform* ret_transform);
extern LPoint*	CI_LPoint_Transform(LPoint* point, LTransform* transform, LPoint* ret_point);
extern LRect* CI_LRect_Transform(LRect* rect, LTransform* transform, LRect* ret_rect);
extern LTransform_Ex99*	CI_LTransform_Set_Ex99(LCoord xtrans, LCoord ytrans, LOrientation_Ex99* orient, LMagnification* mag, LTransform_Ex99* ret_transform);
extern LTransform_Ex99*	CI_LTransform_Zero_Ex99(LTransform_Ex99* ret_transform);
extern LTransform_Ex99*	CI_LTransform_Add_Ex99(LTransform_Ex99* transform_to_be_added, LTransform_Ex99* current_transform, LTransform_Ex99* ret_transform);
extern LTransform_Ex99*	CI_LTransform_Subtract_Ex99(LTransform_Ex99* transform_to_be_subtracted,  LTransform_Ex99* current_transform, LTransform_Ex99* ret_transform);
extern LPoint* CI_LPoint_Transform_Ex99(LPoint* point, LTransform_Ex99* transform, LPoint* ret_point);
extern LRect* CI_LRect_Transform_Ex99(LRect* rect, LTransform_Ex99* transform, LRect* ret_rect);
extern LPoint* CI_LCursor_GetPosition(LPoint *ret_point);
extern LPoint* CI_LCursor_GetSnappedPosition(LPoint *ret_point);
extern LPoint* CI_LCursor_GetPositionEx99(int iSnapped, int iPauseForInput, const char* szMessage, LPoint* pReturnPoint);
extern LPoint*	CI_LVertex_GetPoint(LVertex vertex, LPoint *ret_point);
extern LStatus	CI_LVertex_SetPoint(LVertex vertex, LPoint *ret_point);
extern LStatus	CI_LVertex_Add(LObject object, LVertex prev_vertex, LPoint* point);
extern LStatus CI_LVertex_AddCurve(LObject object, LVertex vertex, LPoint *center, LArcDirection *dir);
extern LStatus CI_LVertex_SetCurve(LVertex vertex, LPoint *center, LArcDirection *dir);
extern DPoint *CI_LVertex_GetCurveExactCenter(LObject object, LVertex vertex, LCoord radius, LArcDirection *dir, DPoint *center);
extern LObject CI_LTorus_New(LCell cell, LLayer layer, LPoint *center, double *startangle, double *stopangle, LCoord radius1, LCoord radius2, LObject object);
extern LStatus CI_LTorus_Set(LCell cell, LObject object, LPoint *center, double *startangle, double *stopangle, LCoord radius1, LCoord radius2);
extern LPoint *CI_LTorus_GetCenter(LObject object, LPoint *center);
extern LObject CI_LPie_New(LCell cell, LLayer layer, LPoint *center, double *startangle, double *stopangle, LCoord radius, LObject object);
extern LStatus CI_LPie_Set(LCell cell, LObject object, LPoint *center, double *startangle, double *stopangle, LCoord radius);
extern LPoint *CI_LPie_GetCenter(LObject object, LPoint *center);

#endif // #ifndef __UPISTUB_H
