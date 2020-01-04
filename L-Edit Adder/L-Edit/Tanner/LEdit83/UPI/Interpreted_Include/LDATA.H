//*************************************************************************
//* IDENT: ldata.h
//* Copyright © Tanner Research, Inc. 2000 All rights reserved
//* 
//* DESCRIPTION: UPI Link Library Header file 
//*************************************************************************

#if !defined(__LDATA_H)
#define __LDATA_H

#define UpiMajorVersion 2
#define UpiMinorVersion 1

#if defined(MAKE_DLL)
// ********************************
// Automatically link with the library
// ********************************
#ifdef _DEBUG
#ifdef UPI_MACRO_USING_MFC
#define UPILINK_FILE "upilinkds.lib"
#else			// UPI_MACRO_USING_MFC
#define UPILINK_FILE "upilinkd.lib"
#endif		// UPI_MACRO_USING_MFC
#else		// _DEBUG
#ifdef UPI_MACRO_USING_MFC
#define UPILINK_FILE "upilinks.lib"
#else			// UPI_MACRO_USING_MFC
#define UPILINK_FILE "upilink.lib"
#endif		// UPI_MACRO_USING_MFC
#endif	// _DEBUG
#if !defined(UPILINK_NOAUTOLINK)
#pragma comment( lib, UPILINK_FILE )
#endif	// UPILINK_NOAUTOLINK

// 03/09/1999 - RDB - Force the inclusion of the init function linked into a
//	UPI macro even if it does not call any UPI functions.
//#pragma comment(linker, "/Include:_Init_Upi_Functions@8")

#define LEDITAPI _stdcall
#ifndef _UPI_PACKING
#define _UPI_PACKING    8 
#endif	// _UPI_PACKING
#else	// MAKE_DLL
#define LEDITAPI
#endif// MAKE_DLL

#ifdef _UPI_PACKING
#pragma pack(push, _UPI_PACKING)
#endif

typedef struct {
	char prompt[40];
	char value[21];
} LDialogItem;

typedef enum 
{
	LSelectionTool = 0, 
	LBoxTool, 
	LPolygon90Tool, 
	LPolygon45Tool, 
	LPolygonAATool,
	LWire90Tool, 
	LWire45Tool, 
	LWireAATool,
	LCircleTool, 
	LPieWedgeTool, 
	LTorusTool,
	LPortTool, 
	LRuler90Tool, 
	LRuler45Tool, 
	LRulerAATool, 
	LInstanceTool,
	LBPRRoute90Tool,
	LBPRRoute45Tool,
	LBPRRouteAATool
} UPIDrawingToolType;

extern long LEDITAPI LUpi_GetSerialNumber(void);
extern void LEDITAPI LUpi_InsertMenuItemSeparator(char *menu);
extern void LEDITAPI LUpi_SetSelectionTool(void);
extern UPIDrawingToolType LEDITAPI LUpi_SetDrawingTool(UPIDrawingToolType eTool);

extern void LEDITAPI LDialog_MsgBox( char *msg );
extern void LEDITAPI LDialog_AlertBox( char *msg );
extern int  LEDITAPI LDialog_YesNoBox( char *msg );
extern int  LEDITAPI LDialog_InputBox( char *title, char *s, char *ibuf );
extern int  LEDITAPI LDialog_MultiLineInputBox(char *title, LDialogItem ibuf[],
												  int total_entries);
extern int  LEDITAPI LDialog_MultiLineMsgBox(char *ibuf[], int total_entries);
extern void LEDITAPI LMacro_Register(char *macro_desc, char *function_name );
extern void LEDITAPI LMacro_BindToHotKey(int keycode, char *macro_desc,
										char *function_name );
extern unsigned int LEDITAPI LMacro_BindToMenu(char *menu, char *macro_desc,
										char *function_name);
extern int	LEDITAPI LMacro_IsLoaded(char *dll_path);
extern void	LEDITAPI LMacro_UnLoad(char *dll_path);
extern int	LEDITAPI LMacro_Load(char *dll_path);

extern void LEDITAPI LDisplay_Refresh(void);
extern void LEDITAPI LStatusBar_SetMsg(char *msg );

extern int LEDITAPI LDialog_PickList(char *title, char *picklist[], int total_entries,
												 int default_choice);

#if defined(MAKE_DLL)
extern void LEDITAPI LWindow_GetParameters( void **phInst, void **phWnd,
											  void **phLib);
#endif

#if defined( UNIX_DLL )
#define KEYGROUP_NUM    (48)
#define KEYGROUP_ALPHA  (97)
#define KEYGROUP_FKEYS  (187)
#else
#define KEYGROUP_NUM    ((unsigned short)0x0100)
#define KEYGROUP_ALPHA  ((unsigned short)0x0200)
#define KEYGROUP_FKEYS  ((unsigned short)0x0300)
#define KEYGROUP_CURSOR ((unsigned short)0x0400)
#define KEYGROUP_MISC   ((unsigned short)0x0500)
#endif

#define KEY_0           ((unsigned short)(KEYGROUP_NUM+0))
#define KEY_1           ((unsigned short)(KEYGROUP_NUM+1))
#define KEY_2           ((unsigned short)(KEYGROUP_NUM+2))
#define KEY_3           ((unsigned short)(KEYGROUP_NUM+3))
#define KEY_4           ((unsigned short)(KEYGROUP_NUM+4))
#define KEY_5           ((unsigned short)(KEYGROUP_NUM+5))
#define KEY_6           ((unsigned short)(KEYGROUP_NUM+6))
#define KEY_7           ((unsigned short)(KEYGROUP_NUM+7))
#define KEY_8           ((unsigned short)(KEYGROUP_NUM+8))
#define KEY_9           ((unsigned short)(KEYGROUP_NUM+9))

#define KEY_A           ((unsigned short)(KEYGROUP_ALPHA+0))
#define KEY_B           ((unsigned short)(KEYGROUP_ALPHA+1))
#define KEY_C           ((unsigned short)(KEYGROUP_ALPHA+2))
#define KEY_D           ((unsigned short)(KEYGROUP_ALPHA+3))
#define KEY_E           ((unsigned short)(KEYGROUP_ALPHA+4))
#define KEY_F           ((unsigned short)(KEYGROUP_ALPHA+5))
#define KEY_G           ((unsigned short)(KEYGROUP_ALPHA+6))
#define KEY_H           ((unsigned short)(KEYGROUP_ALPHA+7))
#define KEY_I           ((unsigned short)(KEYGROUP_ALPHA+8))
#define KEY_J           ((unsigned short)(KEYGROUP_ALPHA+9))
#define KEY_K           ((unsigned short)(KEYGROUP_ALPHA+10))
#define KEY_L           ((unsigned short)(KEYGROUP_ALPHA+11))
#define KEY_M           ((unsigned short)(KEYGROUP_ALPHA+12))
#define KEY_N           ((unsigned short)(KEYGROUP_ALPHA+13))
#define KEY_O           ((unsigned short)(KEYGROUP_ALPHA+14))
#define KEY_P           ((unsigned short)(KEYGROUP_ALPHA+15))
#define KEY_Q           ((unsigned short)(KEYGROUP_ALPHA+16))
#define KEY_R           ((unsigned short)(KEYGROUP_ALPHA+17))
#define KEY_S           ((unsigned short)(KEYGROUP_ALPHA+18))
#define KEY_T           ((unsigned short)(KEYGROUP_ALPHA+19))
#define KEY_U           ((unsigned short)(KEYGROUP_ALPHA+20))
#define KEY_V           ((unsigned short)(KEYGROUP_ALPHA+21))
#define KEY_W           ((unsigned short)(KEYGROUP_ALPHA+22))
#define KEY_X           ((unsigned short)(KEYGROUP_ALPHA+23))
#define KEY_Y           ((unsigned short)(KEYGROUP_ALPHA+24))
#define KEY_Z           ((unsigned short)(KEYGROUP_ALPHA+25))

#define KEY_F1          ((unsigned short)(KEYGROUP_FKEYS+0))
#define KEY_F2          ((unsigned short)(KEYGROUP_FKEYS+1))
#define KEY_F3          ((unsigned short)(KEYGROUP_FKEYS+2))
#define KEY_F4          ((unsigned short)(KEYGROUP_FKEYS+3))
#define KEY_F5          ((unsigned short)(KEYGROUP_FKEYS+4))
#define KEY_F6          ((unsigned short)(KEYGROUP_FKEYS+5))
#define KEY_F7          ((unsigned short)(KEYGROUP_FKEYS+6))
#define KEY_F8          ((unsigned short)(KEYGROUP_FKEYS+7))
#define KEY_F9          ((unsigned short)(KEYGROUP_FKEYS+8))
#define KEY_F10         ((unsigned short)(KEYGROUP_FKEYS+9))
#define KEY_F11         ((unsigned short)(KEYGROUP_FKEYS+10))
#define KEY_F12         ((unsigned short)(KEYGROUP_FKEYS+11))
#define KEY_F13         ((unsigned short)(KEYGROUP_FKEYS+12))
#define KEY_F14         ((unsigned short)(KEYGROUP_FKEYS+13))
#define KEY_F15         ((unsigned short)(KEYGROUP_FKEYS+14))
#define KEY_F16         ((unsigned short)(KEYGROUP_FKEYS+15))
#define KEY_F17         ((unsigned short)(KEYGROUP_FKEYS+16))
#define KEY_F18         ((unsigned short)(KEYGROUP_FKEYS+17))
#define KEY_F19         ((unsigned short)(KEYGROUP_FKEYS+18))
#define KEY_F20         ((unsigned short)(KEYGROUP_FKEYS+19))
#define KEY_F21         ((unsigned short)(KEYGROUP_FKEYS+20))
#define KEY_F22         ((unsigned short)(KEYGROUP_FKEYS+21))
#define KEY_F23         ((unsigned short)(KEYGROUP_FKEYS+22))
#define KEY_F24         ((unsigned short)(KEYGROUP_FKEYS+23))
#define KEY_F25         ((unsigned short)(KEYGROUP_FKEYS+24))
#define KEY_F26         ((unsigned short)(KEYGROUP_FKEYS+25))

#if !defined( UNIX_DLL )
#define KEY_DOWN        ((unsigned short)(KEYGROUP_CURSOR+0))
#define KEY_UP          ((unsigned short)(KEYGROUP_CURSOR+1))
#define KEY_LEFT        ((unsigned short)(KEYGROUP_CURSOR+2))
#define KEY_RIGHT       ((unsigned short)(KEYGROUP_CURSOR+3))
#define KEY_HOME        ((unsigned short)(KEYGROUP_CURSOR+4))
#define KEY_END         ((unsigned short)(KEYGROUP_CURSOR+5))
#define KEY_PAGEUP      ((unsigned short)(KEYGROUP_CURSOR+6))
#define KEY_PAGEDOWN    ((unsigned short)(KEYGROUP_CURSOR+7))

#define KEY_RETURN      ((unsigned short)(KEYGROUP_MISC+0))
#define KEY_ESCAPE      ((unsigned short)(KEYGROUP_MISC+1))
#define KEY_TAB         ((unsigned short)(KEYGROUP_MISC+2))
#define KEY_BACKSPACE   ((unsigned short)(KEYGROUP_MISC+3))
#define KEY_SPACE       ((unsigned short)(KEYGROUP_MISC+4))
#define KEY_INSERT      ((unsigned short)(KEYGROUP_MISC+5))
#define KEY_DELETE      ((unsigned short)(KEYGROUP_MISC+6))

#define KEY_ADD         ((unsigned short)(KEYGROUP_MISC+7))
#define KEY_SUBTRACT    ((unsigned short)(KEYGROUP_MISC+8))
#define KEY_MULTIPLY    ((unsigned short)(KEYGROUP_MISC+9))
#define KEY_DIVIDE      ((unsigned short)(KEYGROUP_MISC+10))
#define KEY_POINT       ((unsigned short)(KEYGROUP_MISC+11))
#define KEY_COMMA       ((unsigned short)(KEYGROUP_MISC+12))
#define KEY_LESS        ((unsigned short)(KEYGROUP_MISC+13))
#define KEY_GREATER     ((unsigned short)(KEYGROUP_MISC+14))
#define KEY_EQUAL       ((unsigned short)(KEYGROUP_MISC+15))
#else /* Unix */
#define KEY_DOWN        (208)
#define KEY_UP          (200)
#define KEY_LEFT        (203)
#define KEY_RIGHT       (205)
#define KEY_HOME        (199)
#define KEY_END         (207)
#define KEY_PAGEUP      (201)
#define KEY_PAGEDOWN    (209)

#define KEY_RETURN      (13)
#define KEY_ESCAPE      (27)
#define KEY_TAB         (9)
#define KEY_BACKSPACE   (8)
#define KEY_SPACE       (32)
#define KEY_DELETE      (211)

#define KEY_ADD         (43)
#define KEY_SUBTRACT    (45)
#define KEY_MULTIPLY    (42)
#define KEY_DIVIDE      (47)
#define KEY_POINT       (46)
#define KEY_COMMA       (44)
#define KEY_LESS        (60)
#define KEY_GREATER     (62)
#define KEY_EQUAL       (61)
#endif /* of if !UNIX_DLL */

typedef enum {
	LStatusOK = 0,
	LTooManyInits,
	LOpenError,
	LCloseError,
	LCreateError,
	LSaveError,
	LBadFile,
	LBadCell,
	LBadLayer,
	LBadParameters,
	LBadObject,
	LBadHierarchy,
	LTmError,
	LUserDataError,
	LCellOverWritten,
	LLayerMapsDifferent,
	LNamedCellExists,
	LCopyProtViolation, 
	LNoSelection,
	LVertexNotFound,
	LCantDeleteVertex,
	LPropertyNotFound,
	LPropertyHasNoValue,
	LPropertyTypeMismatch,
	LBufferTooSmall,
	LSystemError,					// System errors like cannot load DLL.
	LPropertyConversionError,	// Error occurred during the export or import of properties to/from a file.
	LUserAbort,						// User aborted the operation such as DRC, Extract, etc.
	LExists,							// Item added already exists (LDrcRule, LLayer, etc.)
	LLayerNotEmpty,				// 06/13/2000 - NJW - Layer has objects on it.
	LParameterOutOfRange			//MP:10-26-00 
} LStatus;

typedef long LCoord;
typedef unsigned long LLen;
typedef struct {
    LCoord y, x;
} LPoint;

typedef struct { 
    LCoord y0, x0;
    LCoord y1, x1;
} LRect;

/* double point */
typedef struct {
	double x;
	double y;
} DPoint;

typedef long int LOrientation;
typedef float LOrientation_Ex99;	//hj
#define LNormalOrientation      0
#define LRotate0                0
#define LRotate90              90
#define LRotate180            180
#define LRotate270            270
#define LRotate0MirrorX       -360
#define LRotate90MirrorX      -90
#define LRotate180MirrorX    -180
#define LRotate270MirrorX    -270

typedef struct LMagnification {
	LLen num;
	LLen denom;
} LMagnification;

typedef struct {
    LPoint				translation;
    LOrientation		orientation;
	 LMagnification	magnification;
} LTransform;
//hj
typedef struct {
    LPoint				translation;
    LOrientation_Ex99		orientation;
	LMagnification	magnification;
} LTransform_Ex99;

typedef enum 
{
	LDo_Not_Flag = 0,
	LFlag = 1,
	LFix = 2
} 
LAmbiguousFillType;

typedef struct 
{
	int FlagSelfIntersection;
	LAmbiguousFillType PolygonsWithAmbiguousFills;
	int FlagIgnoredObjects;
	int FlagOffGridObjects;
	double GridSize;
	int UseLocatorUnits;
} 
LDesignRuleFlags;

// LPoint Functions.
extern LPoint LEDITAPI LPoint_Set(LCoord lX, LCoord lY);
extern LPoint LEDITAPI LPoint_Add(LPoint ptA, LPoint ptB);
extern LPoint LEDITAPI LPoint_Subtract(LPoint ptA, LPoint ptB);

extern LRect	LEDITAPI LRect_Set( LCoord x0, LCoord y0, LCoord x1, LCoord y1 );

extern LTransform	LEDITAPI LTransform_Set( LCoord xtrans, LCoord ytrans,
				       LOrientation orient, LMagnification mag );
extern LTransform	LEDITAPI LTransform_Zero( void );
extern LTransform	LEDITAPI LTransform_Add( LTransform transform_to_be_added,
											 LTransform current_transform );
extern LTransform	LEDITAPI LTransform_Subtract( LTransform transform_to_be_subtracted, 
					    LTransform current_transform );
extern LPoint		LEDITAPI LPoint_Transform( LPoint point, LTransform transform );
extern LRect		LEDITAPI LRect_Transform( LRect rect, LTransform transform );

//hj
extern LTransform_Ex99	LEDITAPI LTransform_Set_Ex99( LCoord xtrans, LCoord ytrans,
				       LOrientation_Ex99 orient, LMagnification mag );
extern LTransform_Ex99	LEDITAPI LTransform_Zero_Ex99( void );
extern LTransform_Ex99	LEDITAPI LTransform_Add_Ex99( LTransform_Ex99 transform_to_be_added,
											 LTransform_Ex99 current_transform );
extern LTransform_Ex99	LEDITAPI LTransform_Subtract_Ex99( LTransform_Ex99 transform_to_be_subtracted, 
					    LTransform_Ex99 current_transform );
extern LPoint		LEDITAPI LPoint_Transform_Ex99( LPoint point, LTransform_Ex99 transform );
extern LRect		LEDITAPI LRect_Transform_Ex99( LRect rect, LTransform_Ex99 transform );


/*heejung need for l-comp*/
extern LStatus	LUPI_InitSystem( int* argc, char** argv );

typedef struct _LFile *LFile;

extern void LEDITAPI LDialog_File(const char* szDefaultName, const char* szTitle, char* szFileNameBuffer, 
												  const char* szFiltersForBrowser, int iBrowseType, const char* szMessage, 
												  const char* szOkText, const char* szDefaultExt, const char* szTypeList, 
												  const LFile pFile);

typedef enum {
	MICRONS, MILLIMETERS, CENTIMETERS, MILS, INCHES, LAMBDA, OTHER
} tech_unit_type;

typedef struct _LTechnology {
    const char*	name;
	 tech_unit_type unit_type;
    const char*	unit_name;
    long	num;
    long	denom;
    long	lambda_num;
    long	lambda_denom;
} LTechnology;

typedef enum {
    LTdbFile, LCifFile, LGdsFile, LV6TdbFile
} LFileType;

extern LFile	LEDITAPI LFile_GetList( void );
extern LFile	LEDITAPI LFile_GetNext( LFile file );
extern LFile	LEDITAPI  LFile_Find( const char* name );
extern LFile	LEDITAPI  LFile_Open( const char* filename, LFileType type );
extern LStatus	LEDITAPI  LFile_Save( LFile file );
extern LStatus	LEDITAPI  LFile_SaveAs( LFile file, const char* name, LFileType type );
extern LStatus	LEDITAPI  LFile_Close( LFile file );
extern char*	LEDITAPI  LFile_GetName( LFile file, char* name, const int maxlen );
extern int	LEDITAPI  LFile_IsChanged( LFile file );
extern LTechnology	LEDITAPI  LFile_GetTechnology( LFile file );
extern char*	LEDITAPI  LFile_SetTechnologyName( LFile file, char* name );
extern LStatus LEDITAPI  LFile_SetTechnologyUnitNum( LFile file, long num );
extern LStatus LEDITAPI  LFile_SetTechnologyUnitDenom( LFile file, long denom );
extern LStatus LEDITAPI  LFile_SetTechnologyLambdaNum( LFile file, long num );
extern LStatus LEDITAPI  LFile_SetTechnologyLambdaDenom( LFile file, long denom );
extern LStatus LEDITAPI  LFile_SetTechnology( LFile file, LTechnology *ltechnology );
extern LFile	LEDITAPI  LFile_New( LFile setup_file, char* name );
extern LStatus		LEDITAPI  LFile_DeleteUserData( LFile file );
extern LStatus		LEDITAPI  LFile_SetUserData( LFile file, void* dataPointer );
extern void*		LEDITAPI  LFile_GetUserData( LFile file );
extern char*	LEDITAPI  LFile_GetAuthor( LFile file, char* author, const int maxlen );
extern char*	LEDITAPI  LFile_SetAuthor( LFile file, char* author );
extern char*	LEDITAPI  LFile_GetOrganization(LFile file, char* org, const int maxlen);
extern char*	LEDITAPI  LFile_SetOrganization( LFile file, char* org );
extern char*	LEDITAPI  LFile_GetInfoText( LFile file, char* info, const int maxlen );
extern char*	LEDITAPI  LFile_SetInfoText( LFile file, char* info );
extern int		LEDITAPI  LFile_GetLock( LFile file );
extern int		LEDITAPI  LFile_SetLock( LFile file, int set );
extern void		LEDITAPI  LFile_GetLayoutVersion( LFile file, long* major, long* minor );
extern void		LEDITAPI  LFile_SetLayoutVersion( LFile file, long major, long minor );
extern void		LEDITAPI  LFile_GetSetupVersion( LFile file, long* major, long* minor );
extern void		LEDITAPI  LFile_SetSetupVersion( LFile file, long major, long minor );

typedef struct _LCell *LCell;

extern LStatus		LEDITAPI  LFile_SetFabricationCell( LFile file, LCell cell );
extern LCell      LEDITAPI  LFile_GetFabricationCell( LFile file );
extern LStatus		LEDITAPI  LFile_SetLastCurrent(LFile file, LCell cell);

/* clears the undo list for a file -heejung 7/23/98 */
extern LStatus	LEDITAPI LCell_ClearUndoLists( LCell cell );

extern LCell	LEDITAPI  LCell_GetList( LFile file );
extern LCell	LEDITAPI  LCell_GetNext( LCell cell );
extern LCell	LEDITAPI  LCell_Find( LFile file, const char* name );
extern char*	LEDITAPI  LCell_GetName( LCell cell, char* name, const int maxlen );
extern LRect	LEDITAPI  LCell_GetMbb( LCell cell );
extern LRect	LEDITAPI  LCell_GetMbbAll( LCell cell );
extern LFile	LEDITAPI  LCell_GetFile( LCell cell );
extern LCell	LEDITAPI  LCell_New( LFile file, char* name );
extern LStatus	LEDITAPI  LCell_Delete( LCell cell );
extern LStatus LEDITAPI  LCell_SetName( LFile file, LCell cell, const char* newname );
extern LStatus		LEDITAPI  LCell_DeleteUserData( LCell cell );
extern LStatus		LEDITAPI  LCell_SetUserData( LCell cell, void* dataPointer );
extern void*		LEDITAPI  LCell_GetUserData( LCell cell );
extern LStatus		LEDITAPI  LCell_Copy( LFile sourceFile, LCell sourceCell, 
										LFile destFile, char* destCellName );
extern char*	LEDITAPI  LCell_GetAuthor( LCell cell, char* author, const int maxlen );
extern char*	LEDITAPI  LCell_SetAuthor( LCell cell, char* author );
extern char*	LEDITAPI  LCell_GetOrganization(LCell cell, char* org, const int maxlen);
extern char*	LEDITAPI  LCell_SetOrganization( LCell cell, char* org );
extern char*	LEDITAPI  LCell_GetInfoText( LCell cell, char* info, const int maxlen );
extern char*	LEDITAPI  LCell_SetInfoText( LCell cell, char* info );
extern int		LEDITAPI  LCell_GetLock( LCell cell );
extern int		LEDITAPI  LCell_SetLock( LCell, int set );
extern LStatus	LEDITAPI  LCell_SetView(LCell cell, LRect view);
extern LRect	LEDITAPI  LCell_GetView(LCell cell);

typedef struct _LLayer *LLayer;

extern LLayer	LEDITAPI  LLayer_GetList( LFile file );
extern LLayer	LEDITAPI  LLayer_GetNext( LLayer layer );
extern LLayer	LEDITAPI  LLayer_Find( LFile file, const char* name );
extern char*	LEDITAPI  LLayer_GetName( LLayer layer, char* name, const int maxlen );
typedef enum {
	GridLayer, OriginLayer, CellOutlineLayer, ErrorLayer, IconLayer,
	FirstMaskLayer, DragBoxLayer
} LSpecialLayer;
extern LLayer LEDITAPI  LLayer_GetSpecial( LFile file, LSpecialLayer specialLayer );
extern LStatus LEDITAPI  LLayer_SetSpecial( LFile file, LSpecialLayer specialLayer,
										  LLayer layer );
extern double LEDITAPI  LLayer_GetCap( LLayer layer );
extern double	LEDITAPI  LLayer_GetRho( LLayer layer );
extern LStatus	LEDITAPI  LLayer_SetCap( LLayer layer, double cap );
extern LStatus	LEDITAPI  LLayer_SetRho( LLayer layer, double rho );

typedef struct _LCore *LCore;

extern LCore	LEDITAPI  LCore_GetCore( LFile file );
extern double	LEDITAPI  LCore_GetLLHCap( LCore core );
extern LStatus	LEDITAPI  LCore_SetLLHCap( LCore core, double LLHCap );
extern double	LEDITAPI  LCore_GetLLVCap( LCore core );
extern LStatus	LEDITAPI  LCore_SetLLVCap( LCore core, double LLVCap );

/* Type identifier for objects */
typedef enum {
   LBox, 
	LCircle, 
	LWire, 
	LPolygon,
	LTorus,
	LPie,
   LOtherObject,
	LObjInstance,
	LObjPort,
	LObjRuler
} LShapeType;

typedef enum {
    LOrthogonal, 
	LFortyFive, 
	LAllAngle,
	LCurved,
    LNonGeometric,
    LManhattan = LOrthogonal,
    LBoston = LFortyFive
} LGeomType;

// For clockwise or counterclockwise arc
typedef enum {
	CW, 
	CCW
} LArcDirection;

typedef enum {
    LCapButt=0, 
	 LCapRound, 
	 LCapExtend
} LCapType;

typedef enum {
    LJoinMiter=0, 
	 LJoinRound, 
	 LJoinBevel, 
	 LJoinLayout
} LJoinType;

typedef struct {
    LCoord	width;
    LJoinType	join;
    LCapType	cap;
    short	miter_angle;
} LWireConfig;

typedef enum {
    LSetWireWidth	= 1 << 0,
    LSetWireJoin		= 1 << 1,
    LSetWireCap		= 1 << 2,
    LSetWireMiterAngle	= 1 << 3,
    LSetWireAll		= -1
} LWireConfigBits;

typedef union _LObject *LObject;
typedef struct _LInstance *LInstance;

extern LObject	LEDITAPI  LObject_GetList( LCell cell, LLayer layer );
extern LObject	LEDITAPI  LObject_GetNext( LObject object );
extern LRect	LEDITAPI  LObject_GetMbb( LObject object );
extern LShapeType LEDITAPI LObject_GetShape( LObject object);
extern LGeomType LEDITAPI LObject_GetGeometry( LObject object);
extern LStatus LEDITAPI LObject_Delete( LCell cell, LObject object);
extern LLayer LEDITAPI LObject_GetLayer(LCell cell, LObject object);
extern LStatus LEDITAPI LObject_ChangeLayer(LCell pCell, LObject pObject, LLayer pNewLayer);
extern double LEDITAPI LObject_Area(LObject object);
extern double LEDITAPI LObject_Perimeter(LObject object);
extern void	LEDITAPI LObject_Transform(LObject object, LTransform transform);
extern void	LEDITAPI LObject_Transform_Ex99(LObject object, LTransform_Ex99 transform);

extern LRect	LEDITAPI LBox_GetRect( LObject object );
extern LObject	LEDITAPI LBox_New( LCell cell, LLayer layer, 
			 LCoord x0, LCoord y0, LCoord x1, LCoord y1 );
extern LStatus	LEDITAPI LBox_Set( LCell cell, LObject object, LRect box );

extern LRect	LEDITAPI LCircle_GetRect( LObject object );
extern LPoint	LEDITAPI LCircle_GetCenter( LObject object );
extern LCoord	LEDITAPI LCircle_GetRadius( LObject object );
extern LObject	LEDITAPI LCircle_New( LCell cell, LLayer layer, 
			    LPoint center, LCoord radius );
extern LStatus	LEDITAPI LCircle_Set( LCell cell, LObject object, LPoint center,
			    LCoord radius );

typedef struct _LVertex *LVertex;

extern LVertex	LEDITAPI LObject_GetVertexList( LObject object );
extern LVertex	LEDITAPI LVertex_GetNext( LVertex vertex );
extern LPoint	LEDITAPI LVertex_GetPoint( LVertex vertex);
extern LStatus	LEDITAPI LVertex_SetPoint( LVertex vertex, LPoint point );
extern LStatus	LEDITAPI LVertex_Add( LObject object, LVertex prev_vertex, LPoint point );
extern LStatus	LEDITAPI LVertex_Delete(LObject object, LVertex vertex);

extern long	LEDITAPI LVertex_GetCount( LObject object );
extern long	LEDITAPI LVertex_GetArray( LObject object, LPoint point_arr[],
			       const int maxpoints );

extern LCoord LEDITAPI LWire_GetWidth( LObject object );
extern double LEDITAPI LWire_GetLength(LObject pObject);
extern double LEDITAPI LWire_GetSquares(LObject pObject);
extern double LEDITAPI LWire_GetResistance(LObject pObject);

extern LJoinType	LEDITAPI LWire_GetJoinType( LObject object );
extern LCapType		LEDITAPI LWire_GetCapType( LObject object );
extern short		LEDITAPI LWire_GetMiterAngle( LObject object );
extern LObject		LEDITAPI LWire_New( LCell cell, LLayer layer,
								LWireConfig* config, LWireConfigBits bits,
								LPoint point_arr[], const int npoints );

extern LObject	LEDITAPI LPolygon_New( LCell cell, LLayer layer,
			     LPoint point_arr[], const int npoints );

typedef struct _LPort *LPort;

extern LPort	LEDITAPI  LPort_GetList( LCell cell );
extern LPort	LEDITAPI  LPort_GetNext( LPort port );
extern LLayer	LEDITAPI  LPort_GetLayer( LPort port );
extern LRect	LEDITAPI  LPort_GetMbb( LPort port );
extern LRect	LEDITAPI  LPort_GetRect( LPort port );
extern char*	LEDITAPI  LPort_GetText( LPort port, char* text, const int maxlen );
extern LCoord LEDITAPI LPort_GetTextSize(LPort pPort);
extern LStatus LEDITAPI LPort_SetTextSize(LPort pPort, LCoord lcTextSize);
extern LPort	LEDITAPI  LPort_New( LCell cell, LLayer layer, char* text,
			  LCoord x0, LCoord y0, LCoord x1, LCoord y1 );
extern LStatus	LEDITAPI  LPort_Set( LCell cell, LPort port, LRect rect );
extern LStatus	LEDITAPI  LPort_SetText( LCell cell, LPort port, char* text, 
										LCoord textSize );
extern LStatus LEDITAPI  LPort_Delete( LCell cell, LPort port );
extern LPort 	LEDITAPI  LPort_Find( LCell cell, const char* text );
extern LPort	LEDITAPI  LPort_FindNext( LPort port, const char* text );

extern LInstance	LEDITAPI  LInstance_GetList( LCell cell );
extern LInstance	LEDITAPI  LInstance_GetNext( LInstance instance );
extern LRect		LEDITAPI  LInstance_GetMbb( LInstance instance );
extern LCell		LEDITAPI  LInstance_GetCell( LInstance instance );
extern LTransform	LEDITAPI  LInstance_GetTransform( LInstance instance );
extern LTransform_Ex99	LEDITAPI  LInstance_GetTransform_Ex99( LInstance instance );	//hj
extern LPoint		LEDITAPI  LInstance_GetRepeatCount( LInstance instance );
extern LPoint		LEDITAPI  LInstance_GetDelta( LInstance instance );
extern char*		LEDITAPI  LInstance_GetName( LInstance instance, char* name, 
											const int maxlen );
extern LStatus		LEDITAPI  LInstance_SetName( LCell cell, LInstance instance, 
												char* name );
extern LInstance	LEDITAPI  LInstance_New( LCell cell, LCell instance_cell,
				      LTransform transform,
				      LPoint repeat_cnt, LPoint delta );
extern LStatus		LEDITAPI  LInstance_Set( LCell cell, LInstance instance,
				      LTransform transform,
				      LPoint repeat_cnt, LPoint delta );
//hj
extern LInstance	LEDITAPI  LInstance_New_Ex99( LCell cell, LCell instance_cell,
				      LTransform_Ex99 transform,
				      LPoint repeat_cnt, LPoint delta );
extern LStatus		LEDITAPI  LInstance_Set_Ex99( LCell cell, LInstance instance,
				      LTransform_Ex99 transform,
				      LPoint repeat_cnt, LPoint delta );

extern LStatus		LEDITAPI  LInstance_Delete( LCell cell, LInstance instance );
extern LInstance	LEDITAPI  LInstance_Find( LCell cell, const char* name );
extern LInstance	LEDITAPI  LInstance_FindNext( LInstance instance, const char* name );

extern void LEDITAPI LDRC_Run( LCell inCell, LRect* onArea, char* errfile,
							 int writeErrorPorts, int writeErrorObjects );
extern LCoord LEDITAPI LFile_GetBinSize(LFile file);
extern void LEDITAPI LFile_SetBinSize(LFile file, LCoord size);

typedef struct _LExtractOptions
{
   // Data
   // General Options
   char		 szExtDefnFile[256];      // Extract definition file - Input.
   char		 szExtOutFile[256];       // Extract SPICE output file - Output.
   double    dExtractBinSize;         // Bin size.  (Locator Units)
	int		 iNodeHighlight;			  // Enable Node highlighting capability. (0 - False, Otherwise True).

   // Output Options
   int		 iWriteNodeNames;         // Write Node names in comments. (0 - False, Otherwise True).
   int       iWriteDeviceCoord;       // Write device coordinates in comments. (0 - False, Otherwise True).
   int       iWriteShortedDevices;    // Write shorted devices in comments. (0 - False, Otherwise True).
   int       iWriteParasiticCap;      // Write parasitic capacitances. (0 - False, Otherwise True).
   double    dParasiticCutoff;        // Cutoff value for parasitic capacitors. (0 - False, Otherwise True).
   int       iWriteNodesAs;           // Write nodes as (integers or names). (0 - Integers, Otherwise Names).
   int       iWriteSciNotation;       // Write values in scientific notation. (0 - False, Otherwise True).
   int       iWriteVerboseSPICE;      // Write R, L, C with verbose style (R=, L=, C=). (0 - False, Otherwise True).
	int		 iWriteSubCktDefs;		  // Write empty subcircuit definitions. (0 - False, Otherwise True).
   char		*szExtIncludeStmt;        // SPICE include statement.
   int       iLabelAllDevices;        // Create ports for all devices. (0 - False, Otherwise True).
   LLayer    oDeviceLabelLayer;       // Place device labels on this layer.

   // Subcircuit Options
   int       iSubCktRecognition;      // Recognize subcircuit instances. (0 - False, Otherwise True).
   LLayer    oSubCktRecogLayer;       // Subcircuit recognition layer.
   int       iUseSubCktNetlistFmt;    // Write netlist as a subcircuit. (0 - False, Otherwise True).
   int       iFlagImproperOverlaps;   // Flag improper overlaps. (0 - False, Otherwise True).
   LLayer    oIgnoreConnPortLayer;    // Ignore connection ports on this layer.
   char		 szIgnoreConnPort[256];   // Ignore connection ports with this name.
   char		 szIgnoreCrossPort[256];  // Ignore cross ports with this name.

	// Miscellaneous
	long		 lMaxIncludeStmtLen;		  // Length of the Include Statement string.
} LExtractOptions;

extern LStatus LEDITAPI LExtract_Run( LCell topCell, char *extDefFile, 
									 char *spiceOutFile, int writeNodeName,
									 int writeNodeCapacitance );
extern LStatus LEDITAPI LExtract_Run_Ex98(LCell topCell, LExtractOptions* ExtOptions);
extern LStatus LEDITAPI LExtract_GetOptions_Ex98(LCell oCell, LExtractOptions *ExtOptions);
extern LStatus LEDITAPI LExtract_Run_Dialog( LCell cell );  /* heejung 7/20/98*/

extern void LEDITAPI LCSV_Run( LCell inCell );  /* heejung 7/98*/


typedef struct _LEnvironemnt {
	short MenuBackgroundColor;	
	short MenuForegroundColor;
	short MenuSelectColor;
	short AlertBackgroundColor;
	long  DefaultPortTextSize;
	int DropDownMenus;
	int ActivePushRubberbanding;
	int AutoPanning;
	int StatusBar;
	int HideInsides;
	short HorizontalPixels;
	short VerticalPixels;
} LEnvironment;

extern LEnvironment* LEDITAPI LFile_GetEnvironment( LFile file,
													  LEnvironment *lenvironment);
extern LStatus LEDITAPI LFile_SetEnvironment( LFile file, LEnvironment *lenvironment );

typedef struct _LSelectionParam {
	long selection_range;
	long deselect_distance_2;
	long deselect_distance_1;
	long lambda_edit_range;
	long pixel_edit_range;
	int select_draws;
} LSelectionParam;

extern LSelectionParam* LEDITAPI LFile_GetSelectionParam( LFile file, 
													 LSelectionParam *param );
extern LStatus LEDITAPI LFile_SetSelectionParam( LFile file, LSelectionParam *param );

typedef enum {
	LSnapping,
	LSmooth
} LCursorType;

typedef struct {
	long displayed_grid_size; 
	long min_grid_pixels;
	long mouse_snap_grid_size;
	LCursorType cursor_type;
	long locator_scaling;
} LGrid;

// Curve setup parameters
typedef struct {
	int max_segment_per_curve;
	long max_length_of_segment;
	int display_as_approx;
} LCurve;

extern LGrid* LEDITAPI LFile_GetGrid( LFile file, LGrid *grid );
extern LStatus LEDITAPI LFile_SetGrid( LFile file, LGrid *grid );

// For curve setup setting
extern LCurve* LEDITAPI LFile_GetCurveSetup(LFile file, LCurve *curve);
extern LStatus LEDITAPI LFile_SetCurveSetup(LFile file, LCurve *curve);

typedef struct {
	int poly_to_rect;
	int port_rect;
} LCIFParam;

extern LCIFParam* LEDITAPI LFile_GetCIFParameters( LFile file, LCIFParam *cifparam );
extern LStatus LEDITAPI LFile_SetCIFParameters( LFile file, LCIFParam *cifparam );

typedef struct {
	int upcase_cell_name;
	short circle_to_polygon_sides;
	int use_default_units;  
} LGDSParam;

extern LGDSParam* LEDITAPI LFile_GetGDSParameters( LFile file, LGDSParam *gdsparam );
extern LStatus LEDITAPI LFile_SetGDSParameters( LFile file, LGDSParam *gdsparam );

typedef enum {
	LHidden,
	LVisible
} LLayerViewStatus;

extern LStatus LEDITAPI  LLayer_SetName( LLayer layer, const char *name );
extern LLayer LEDITAPI  LLayer_PrecedingLayer( LFile file, char *name, LLayer precReserved );
extern LLayer LEDITAPI  LLayer_PrecedingLayerEx99( LFile file, LLayer layer ); //   01/27/1999 - LingTu - 
extern LStatus LEDITAPI  LLayer_New( LFile file, LLayer preceding_layer, char *name );
extern LStatus LEDITAPI  LLayer_Delete( LFile file, LLayer layer );

typedef struct {
	long defaultWireWidth;
	short defaultWireMiterAngle;
	LCapType capType;
	LJoinType joinType;
} LWireParam;

typedef struct {
	char CIFName[7];
	short GDSNumber;
	double cap;
	double rho;
	int lock;
	LLayerViewStatus viewStatus;
	LWireParam wireParam;
} LLayerParam;

extern LLayerParam* LEDITAPI LLayer_GetParameters( LLayer layer, LLayerParam *param );
extern LStatus LEDITAPI  LLayer_SetParameters( LLayer layer, LLayerParam *param );

typedef unsigned char LStipple[8];

typedef enum {
	LSet=16,
	LClear=8
} LPassMode;

typedef enum {
	LObjectPass, LPortPass,
	LTextPass
} LPassType; 

typedef struct _LPassParam {
	unsigned char ColorIndex; 
	LPassMode WriteMode;
	LStipple Stipple;
} LPassParam;

typedef struct _LPass *LPass; 

extern LPass LEDITAPI LPass_GetList( LLayer layer, LPassType passType );
extern LPass LEDITAPI LPass_GetNext( LPass pass );
extern LPass LEDITAPI LPass_New( LPass precedingPass, LPass pass );
extern LPassParam* LEDITAPI LPass_GetParameters( LPass pass, LPassParam *param );
extern LStatus LEDITAPI LPass_SetParameters( LPass pass, LPassParam *param );

typedef struct {
	short LRed;
	short LBlue;
	short LGreen;
} LColor;

typedef LColor LPalette[16];

/* MP:11-20-00 Begin 2000 rendering attributes */

typedef enum _LOutlineStyle
{
	osUnknown = -1,
	osFirstOutlineStyle = 0,
	osSolid = 0, 
	osDotted = 1,
	osShort = 2, 
	osShortDot = 3,
	osLongDot = 4, 
	osLong = 5, 
	osLongDotDot = 6,
	osLongShortShort = 7,
	osLongLongShort = 8,
	osLastOutlineStyle = 8
}
LOutlineStyle;

#define NumberOfOutlineStyles (osLastOutlineStyle+1)

typedef enum _LRenderingMode
{
	rmPaint = 0,
	rmAdd = 1,
	rmSubtract = 2
}
LRenderingMode;

typedef enum _LOutlineUnitType
{
	utPixels = 0,
	utLocatorUnits = 1
}
LOutlineUnitType;

typedef struct _LRenderingAttribute
{
	LRenderingMode mMode;
	unsigned int 	mPass;
	LStipple			mFillPattern;
	unsigned int 	mFillColorIndex;
	LStipple			mOutlinePattern;
	unsigned int 	mOutlineColorIndex;
	LOutlineStyle	mOutlineStyle;
	LOutlineUnitType	mOutlineWidthUnits;
	unsigned int	mOutlineWidth;
	unsigned char	mbBGprevPass;
}
LRenderingAttribute;

typedef LRenderingAttribute *LLRenderingAttribute;

typedef enum _LRenderingAttributeIndex
{
	raiFirstRenderingAttribute = 0,
	raiObject = 0,
	raiSelectedObject = 1,
	raiPortBox = 2,
	raiSelectedPortBox = 3,
	raiPortText = 4,
	raiSelectedPortText = 5,
	raiWireCenterline = 6,
	raiSelectedWireCenterline = 7,
	raiLastRenderingAttribute = 7
}
LRenderingAttributeIndex;

#define NumberOfRenderingAttributes  (raiLastRenderingAttribute+1)

extern LStatus LEDITAPI LLayer_GetRenderingObjectName(LLayer layer, 
	LRenderingAttributeIndex index, char *nameBuf, int nameBufSize);

extern LStatus LEDITAPI LLayer_GetRenderingAttribute(LLayer layer, 
	LRenderingAttributeIndex index, LLRenderingAttribute pRA);

extern LStatus LEDITAPI LLayer_SetRenderingAttribute(LLayer layer, 
	LRenderingAttributeIndex index, LLRenderingAttribute pRA);

/* MP:11-20-00 End 2000 rendering attributes */

/* MP:10-02-00 */
extern LStatus LEDITAPI LFile_GetColorPalette( LFile file, LColor *pColor, int index );
extern int LEDITAPI LFile_GetColorPaletteNumColors( LFile file );
extern const char * LEDITAPI LFile_GetColorPaletteSortBy( LFile file );
extern LStatus LEDITAPI LFile_SetColorPalette( LFile file, const LColor *pColor, int index );
extern LStatus LEDITAPI LFile_SetColorPaletteNumColors( LFile file, int numcolors );
extern LStatus LEDITAPI LFile_SetColorPaletteSortBy( LFile file, const char *sortby );

extern LColor* LEDITAPI LFile_GetPalette( LFile file, LColor *lpalette );	//OBSOLETE
extern LStatus LEDITAPI  LFile_SetPalette( LFile file, LColor *lpalette, short index );	//OBSOLETE

typedef struct _LDrcRule *LDrcRule;

typedef enum 
{
	LMIN_WIDTH, LEXACT_WIDTH, LOVERLAP, LEXTENSION, LNOT_EXISTS, LSPACING,
	LSURROUND, LDENSITY
} LDrcRuleType;

typedef struct _LDesignRuleParam {
	int enable; 
	char *name;
	LDrcRuleType rule_type;
	int ignore_coincidences;
	int ignore_intersections;
	int ignore_enclosures; 
	int ignore_45_acute_angles; 
	char *layer1;
	char *layer2;
	long distance;
	int use_internal_units; 
} LDesignRuleParam;

extern  LStatus LEDITAPI LDrcRule_SetRuleSet( LFile file, char *rule_set );
extern  LStatus LEDITAPI LDrcRule_SetTolerance( LFile file, long tolerance );
extern LDrcRule LEDITAPI LDrcRule_GetList( LFile file );
extern LDrcRule LEDITAPI LDrcRule_GetNext( LDrcRule rule );
extern LDrcRule LEDITAPI LDrcRule_Find( LFile file, LDrcRuleType rule_type,
										 char *layer1, char *layer2);
extern LDesignRuleParam* LEDITAPI LDrcRule_GetParameters( LDrcRule rule,
																 LDesignRuleParam *param);
extern LStatus LEDITAPI LDrcRule_SetParameters( LFile file, LDrcRule rule,
																 LDesignRuleParam *param);
extern LStatus LEDITAPI LDrcRule_Delete( LFile file, LDrcRule rule);
extern LDrcRule LEDITAPI LDrcRule_Add( LFile file, LDrcRule preceding_rule,
										LDesignRuleParam *param);

extern void LEDITAPI LDrc_OverrideGrowComputationValue(LCoord l);

typedef struct _LDerivedLayerParam 
{
	int enable_evaluation;  
	char *name;
	char *src_layer1;
	char *src_layer2;
	char *src_layer3;
	int layer1_not_op; 
	long layer1_grow_amount;
	int layer2_not_op; 
	long layer2_grow_amount;
	int layer3_not_op; 
	long layer3_grow_amount;
	int layer1_bool_layer2;
	int layer2_bool_layer3; 
} LDerivedLayerParam;

typedef enum 
{
	LDOT_Bool=0,
	LDOT_Area=1,
  	LDOT_Select=2,
	LDOT_Density=3
} LDerivationType;

typedef struct _LDerivedLayerBoolOperation 
{
	char *src_layer1;
	char *src_layer2;
	char *src_layer3;
	int layer1_not_op; 
	long layer1_grow_amount;
	int layer2_not_op; 
	long layer2_grow_amount;
	int layer3_not_op; 
	long layer3_grow_amount;
	int layer1_bool_layer2;
	int layer2_bool_layer3;  
} LDerivedLayerBoolOperation;

typedef enum
{
  	LDOST_Inside=0,
 	LDOST_Outside,
 	LDOST_Hole,
  	LDOST_Cut,
 	LDOST_Touch,
 	LDOST_Enclose,
 	LDOST_Overlap,
  	LDOST_Vertex,
  	LDOST_Density
} LSelectOperationRelationType;

typedef struct _LDerivedLayerSelectOperation 
{
	char *layer1;
	char *layer2;
	int not_flag; 
	int range_enabled_flag;
   int n1;
	int n2;
   double d1;
	double d2;
	LSelectOperationRelationType relation_type;	 
} LDerivedLayerSelectOperation;

typedef struct _LDerivedLayerDensityOperation 
{
	char *layer1;
	char *layer2;
	int not_flag; 
   double d1;
	double d2;
} LDerivedLayerDensityOperation;

typedef enum
{
  LDOAT_Range=0,
  LDOAT_EQ=1
} LAreaCheckType;

typedef enum
{
  LDOUT_LocatorUnits=0,
  LDOUT_TechnologyUnits=1
} LAreaUnitType;

typedef struct _LDerivedLayerAreaOperation 
{
	char *layer1;
	int not_flag; 
   double n1;
	double n2;
	double area;
	LAreaCheckType area_check_type;	 
	LAreaUnitType area_unit_type;
} LDerivedLayerAreaOperation;

typedef union _LDerivedLayerOperation 
{
	LDerivedLayerBoolOperation boolean;
	LDerivedLayerSelectOperation select;
	LDerivedLayerAreaOperation area;	 
	LDerivedLayerDensityOperation density;
} LDerivedLayerOperation;

typedef struct _LDerivedLayerParamEx830 
{
	char *name;
	int enable_evaluation;  
	LDerivationType  derivation_type;
	LDerivedLayerOperation operation; 
} LDerivedLayerParamEx830;

typedef LDerivedLayerParamEx830 LDerivedLayerParamEx00;

extern LDerivedLayerParamEx00* LEDITAPI LLayer_GetDerivedParametersEx00(LLayer  layer, LDerivedLayerParamEx00 *param);
extern LDerivedLayerParamEx830* LEDITAPI LLayer_GetDerivedParametersEx830(LLayer  layer, LDerivedLayerParamEx830 *param);
extern LStatus LEDITAPI LLayer_SetDerivedParametersEx00(LFile file, LLayer layer, LDerivedLayerParamEx00 *param);
extern LStatus LEDITAPI LLayer_SetDerivedParametersEx830(LFile file, LLayer layer, LDerivedLayerParamEx830 *param);

extern LLayer LEDITAPI  LLayer_GetDerivedList( LFile file );
extern LLayer LEDITAPI  LLayer_GetDerivedNext( LLayer layer );
int  LEDITAPI  LLayer_IsDerived( LLayer layer );
LDerivedLayerParam* LEDITAPI LLayer_GetDerivedParameters( LLayer layer, LDerivedLayerParam *param);
LStatus LEDITAPI  LLayer_SetDerivedParameters( LFile file, LLayer layer, LDerivedLayerParam *param);
LStatus LEDITAPI  LLayer_EnableAllDerived( LFile file );
LStatus LEDITAPI  LLayer_DisableAllDerived( LFile file );

/* MP:12-12-00 */
extern LStatus LEDITAPI LFile_GetDesignRuleFlags( LFile file, LDesignRuleFlags *pDrcFlags );
extern LStatus LEDITAPI LFile_SetDesignRuleFlags( LFile file, LDesignRuleFlags *pDrcFlags );

typedef struct _LSelection  *LSelection;

extern LSelection LEDITAPI  LSelection_GetList( void );
extern LObject LEDITAPI  LSelection_GetObject(LSelection selection );
extern LSelection LEDITAPI  LSelection_GetNext(LSelection selection );
extern LSelection  LEDITAPI  LSelection_SelectAll( void );
extern void LEDITAPI  LSelection_DeselectAll( void );
extern  LStatus LEDITAPI  LSelection_AddObject( LObject obj  );
extern LStatus LEDITAPI  LSelection_RemoveObject( LObject obj );
extern LStatus LEDITAPI  LSelection_AddAllObjectsOnLayer( LLayer layer );
extern LStatus LEDITAPI  LSelection_RemoveAllObjectsOnLayer( LLayer layer );
extern LStatus LEDITAPI  LSelection_AddAllObjectsInRect( LRect *box );
extern LStatus LEDITAPI  LSelection_RemoveAllObjectsInRect( LRect *box );
extern LStatus LEDITAPI  LSelection_Move( long dx, long dy );
extern LStatus LEDITAPI  LSelection_Cut( void );
extern LStatus LEDITAPI  LSelection_Copy( void );
extern LStatus LEDITAPI  LSelection_Clear( void );
extern LStatus LEDITAPI  LSelection_Paste( void );
extern LStatus LEDITAPI  LSelection_PasteToLayer( LLayer layer);
extern LStatus LEDITAPI  LSelection_Duplicate( void );
extern LStatus LEDITAPI  LSelection_Group( char *group_cell_name  );
extern LStatus LEDITAPI  LSelection_UnGroup( void );
extern LStatus LEDITAPI  LSelection_ChangeLayer( LLayer srcLayer, LLayer dstLayer );
extern LStatus LEDITAPI  LSelection_Merge( void );
extern LStatus LEDITAPI  LSelection_SliceHorizontal( LPoint *point );
extern LStatus LEDITAPI  LSelection_SliceVertical( LPoint *point );
extern LStatus LEDITAPI  LSelection_Rotate( void );
extern LStatus LEDITAPI  LSelection_FlipHorizontal( void );
extern LStatus LEDITAPI  LSelection_FlipVertical( void );
extern LStatus LEDITAPI  LSelection_Flatten( void );

extern LStatus LEDITAPI LCell_GenerateLayers(LCell pCell, int iBinSize);
extern LStatus LEDITAPI LCell_GenerateLayersEx99(LCell pCell, int iBinSize, LLayer pLayer);

extern LStatus LEDITAPI  LCell_ClearGenerateLayers( LCell cell );
extern LCell   LEDITAPI  LCell_Flatten( LCell cell );
extern LObject LEDITAPI LPolygon_WireToPolygon( LCell cell, LLayer layer,
													LObject object );
extern LObject LEDITAPI LPolygon_CircleToPolygon( LCell cell, LLayer layer,
													  LObject object, int NumSides );
extern LStatus LEDITAPI LPolygon_StraightenAllCurves(LCell cell, LObject object);
extern LStatus LEDITAPI LPolygon_RemoveAllCurves(LObject object);
extern int	LEDITAPI LPolygon_HasCurve(LObject object);

extern LCell LEDITAPI LCell_GetVisible(void);
extern LCell LEDITAPI  LCell_GetLastVisible(LFile file);
extern LStatus LEDITAPI  LCell_MakeVisible(LCell cell);
extern LStatus LEDITAPI  LCell_MakeVisibleNoRefresh(LCell cell);
extern LStatus LEDITAPI  LCell_HomeView(LCell cell);
extern int   LEDITAPI  LCell_IsChanged( LCell cell );//   01/27/1999 - LingTu - 
extern LPoint LEDITAPI LCursor_GetPosition( void );
extern LPoint LEDITAPI LCursor_GetSnappedPosition( void );//   01/27/1999 - LingTu - 
extern LPoint LEDITAPI LCursor_GetPositionEx99(int iSnapped, int iPauseForInput, const char* szMessage);
extern LStatus LEDITAPI  LLayer_SetCurrent(LFile file, LLayer layer);
extern LLayer LEDITAPI  LLayer_GetCurrent(LFile file);

typedef struct _LPropItem *LPropItem;

typedef enum {
        LPROP, LPROP_ITEM, LPROP_NONE
} LPropItemType;


typedef struct _LProp *LProp;

typedef enum {
        LPT_INT, LPT_FLOAT, LPT_BOOL, LPT_STRING, LPT_EQN, 
		LPT_LINK, LPT_BLOB, LPT_GROUP, LPT_UNKNOWN
} LPropType ;
typedef short LPropCount;
typedef long LPropAttrib;
typedef enum {LFALSE=0,LTRUE=1} LBoolean;
#define Lboolean LBoolean 
typedef union LpropertyVal {
        int LintVal;
        float LfloatVal;
        Lboolean LboolVal;
        char* LstrVal;
} LPropVal;

extern LStatus LEDITAPI	LProp_AddExtractProp( LCell Cell_Now, char *propName,
						LPropType type, 
						LPropVal value, LPropCount count, LPropAttrib attrib );

extern LStatus LEDITAPI  LUpi_SetQuietMode(int val);
extern int LEDITAPI LUpi_InQuietMode( void );

typedef struct _LWindow *LWindow;

typedef enum {
	 UNKNOWN = 0,
    CELL_BROWSER,
	 TEXT,
    LAYOUT,
	 CROSS_SECTION
} LWindowType;

typedef float FeCoordReal;
typedef float FeSolutionReal;

extern LWindow LEDITAPI LWindow_GetVisible();
extern LStatus LEDITAPI LWindow_MakeVisible(LWindow wnd);
extern LStatus LEDITAPI LWindow_Close(LWindow wnd);
extern LStatus LEDITAPI LWindow_CloseAll();
extern int LEDITAPI LWindow_IsLast(LWindow wnd);
extern LWindowType LEDITAPI LWindow_GetType(LWindow wnd);
extern LCell LEDITAPI LWindow_GetCell(LWindow wnd);
extern LFile LEDITAPI LWindow_GetFile(LWindow wnd);

extern void LEDITAPI LFile_DisplayCellBrowser( LFile file );
extern LWindow LEDITAPI LFile_OpenCell( LFile file, char *cell_name );

/* Thermal functionality */
/* must be duplicated in upi/ltherm.c */
/* See headers/tdata.h : ThermalRegionSetupRec */
#define LBC_TEMP        1
#define LBC_THETA       2
#define LBC_CONVECTION  3
#define LBC_FLUX        4
#define LBC_NONE        5

/* must be duplicated in upi/ltherm.c */
/* chosen arbitrarily */
#define LSIDE_XMIN      1
#define LSIDE_XMAX      2
#define LSIDE_YMIN      4
#define LSIDE_YMAX      8
#define LSIDE_ZMIN     16
#define LSIDE_ZMAX     32
#define LSIDE_ALL      63

typedef struct RegionRec *LRegion;


/* This section is generated by an m4 input file.  Do not edit by hand.
   ledit/upi/thermal.m4 */
/* m4 -Dheader.upi thermal.m4 */
extern int LTherm_IsOutOfDate (LCell cell);
extern void LTherm_RunSol (LCell cell);
extern void LTherm_Plot (LCell cell);
extern LStatus LTherm_GetAmbient (LCell cell, double *ambient);
extern LStatus LTherm_SetAmbient (LCell cell, double ambient);
extern LStatus LTherm_GetThermalTransfer (LCell cell, double *top, double *bottom, double *sides);
extern LStatus LTherm_SetThermalTransfer (LCell cell, double top, double bottom, double sides);
extern int LObject_IsThermal (LObject thermal);
extern LStatus LObject_InitThermal (LCell cell, LObject thermal);
extern LObject LTherm_FindName (LCell cell, const char *name);
extern LObject * LTherm_FindNames (LCell cell, const char *name, int *num);
extern const char * LTherm_GetName (LObject thermal);
extern const char * LTherm_SetName (LObject thermal, const char *name);
extern LStatus LTherm_GetHeat (LObject thermal, double *heat, int *enabled);
extern LStatus LTherm_SetHeat (LCell cell, LObject thermal, double heat, int enabled);
extern LStatus LTherm_GetConductivity (LObject thermal, double *conductivity);
extern LStatus LTherm_SetConductivity (LCell cell, LObject thermal, double conductivity);
extern LStatus LTherm_GetIsotropy (LObject thermal, double *x, double *y, double *z);
extern LStatus LTherm_SetIsotropy (LCell cell, LObject thermal, double x, double y, double z);
extern LStatus LTherm_GetRank (LObject thermal, long *rank);
extern LStatus LTherm_SetRank (LCell cell, LObject thermal, long rank);
extern LStatus LTherm_GetZPlacement (LObject thermal, double *baseline, double *thickness);
extern LStatus LTherm_SetZPlacement (LCell cell, LObject thermal, double baseline, double thickness);
extern LStatus LTherm_GetBC (LObject thermal, int side, int *flag, double *value);
extern LStatus LTherm_SetBC (LCell cell, LObject thermal, int side, int flag, double value);
/* Regions functions */
extern LStatus LTherm_GetMaxMinTemp (LRegion reg, double *tmax, double *tmin);
extern const char * LTherm_RegionName (LRegion reg);
extern LRegion * LTherm_FindRegions (LCell cell, const char *name, int *num);
extern LRegion * LTherm_ObjectsRegions (LCell cell, LObject foo, int *count);
extern LObject LTherm_RegionsObject (LCell cell, LRegion reg);
extern LStatus LTherm_GetTemp (LCell cell, float *temp, double x, double y, double z);
extern void LEDITAPI LTherm_Dispose(void *foo);

typedef enum {
	L_unassigned=0, 
	L_none, 
	L_int, 
	L_real, 
	L_bool, 
	L_string, 
	L_enum, 
	L_byte,
	L_ptr,	
	L_blob
} LPropertyType;

typedef struct _LEntity *LEntity;

extern LStatus	LEDITAPI LEntity_PropertyExists(const LEntity entity, const char* name);
extern LStatus LEDITAPI LEntity_GetPropertyType(const LEntity entity, const char* name, LPropertyType* type);
extern unsigned int	LEDITAPI LEntity_GetPropertyValueSize(const LEntity entity, const char* name);
extern LStatus	LEDITAPI LEntity_GetPropertyValue(const LEntity entity, const char* name, void* value, unsigned int max_size);
extern LStatus	LEDITAPI LEntity_AssignProperty(LEntity entity, const char* name, LPropertyType type, const void* value);
extern LStatus	LEDITAPI LEntity_AssignBlobProperty(LEntity entity, const char* name, const void* value, unsigned int size);
extern LStatus	LEDITAPI LEntity_DeleteProperty(LEntity entity, const char* name);
extern LStatus	LEDITAPI LEntity_DeleteAllProperties(LEntity entity);
extern LStatus	LEDITAPI LEntity_CopyAllProperties(LEntity target_entity, LEntity source_entity);
extern const char* LEDITAPI LEntity_GetFirstProperty(const LEntity entity);
extern const char* LEDITAPI LEntity_GetNextProperty();
extern void LEDITAPI LEntity_SetCurrentProperty(const char* name);
extern LStatus	LEDITAPI LEntity_BrowseProperties(LEntity entity);
extern LStatus	LEDITAPI LEntity_LoadBlobProperty(LEntity entity, const char* name, const char* file_name);
extern LStatus	LEDITAPI LEntity_SaveBlobProperty(const LEntity entity, const char* name, const char* file_name);

typedef enum
{
   LUndefinedCellType, 
   LDieCellType,
   LDiscreteCellType, 
   LIORingCellType,
   LViaCellType,
   LArtificialPinType,
	LBlockCellType,
	LSPRCoreCellType
} LCellType;

extern char* LEDITAPI LFile_BPR_GetCellName(LFile file,char* name, const int maxname);
extern LCellType LEDITAPI LCell_GetType(LCell cell);

typedef struct _LNet *LNet;
typedef struct _LNetVertex *LNetVertex;

extern LNet LEDITAPI LCell_GetNetList(LCell pCell);
extern LNet LEDITAPI LNet_GetNext(LNet pNet);
extern char* LEDITAPI LNet_GetName(LNet pNet, char* name, const int maxname);
extern LNetVertex LEDITAPI LNet_GetNetVertexList(LNet pNet);
extern LNetVertex LEDITAPI LNetVertex_GetNext(LNetVertex pNetVertex);
extern LPort LEDITAPI LNetVertex_GetPort(LNetVertex pNetVertex);

extern LPort LEDITAPI LInstance_GetNetVertexPort(LInstance pInstance);
extern char* LEDITAPI LPort_GetNetName(LPort pPort, char* name, const int maxname);

// Define Curve UPIs
extern int	   LEDITAPI LVertex_HasCurve(LVertex vertex);
extern LStatus LEDITAPI LVertex_AddCurve(LObject object, LVertex vertex, LPoint center, LArcDirection dir);
extern LStatus LEDITAPI LVertex_RemoveCurve(LObject object, LVertex vertex);
extern LStatus LEDITAPI LVertex_GetCurve(LVertex vertex, LPoint *center, LArcDirection *dir);
extern LStatus LEDITAPI LVertex_SetCurve(LVertex vertex, LPoint center, LArcDirection dir);
extern LStatus LEDITAPI LVertex_GetCurveEX(LObject object, LVertex vertex, LPoint *center, LCoord *radius, LPoint *start, LPoint *end, LArcDirection *dir);
extern DPoint  LEDITAPI LVertex_GetCurveExactCenter(LObject object, LVertex vertex, LCoord radius, LArcDirection *dir);

// Define Torus UPIs
extern LObject LEDITAPI LTorus_New(LCell cell, LLayer layer, LPoint center, 
										double startangle, double stopangle,
										LCoord radius1, LCoord radius2);
extern LStatus LEDITAPI LTorus_Set(LCell cell, LObject object, LPoint center, 
										double startangle, double stopangle,
										LCoord radius1, LCoord radius2);
extern LPoint LEDITAPI LTorus_GetCenter(LObject object);
extern LCoord LEDITAPI LTorus_GetStartAngle(LObject object);
extern LCoord LEDITAPI LTorus_GetStopAngle(LObject object);
extern LCoord LEDITAPI LTorus_GetInnerRadius(LObject object);
extern LCoord LEDITAPI LTorus_GetOuterRadius(LObject object);

// Define Pie UPIs
extern LObject LEDITAPI LPie_New(LCell cell, LLayer layer, LPoint center, 
										double startangle, double stopangle,
										LCoord radius);
extern LStatus LEDITAPI LPie_Set(LCell cell, LObject object, LPoint center, 
										double startangle, double stopangle,
										LCoord radius);
extern LPoint LEDITAPI LPie_GetCenter(LObject object);
extern LCoord LEDITAPI LPie_GetStartAngle(LObject object);
extern LCoord LEDITAPI LPie_GetStopAngle(LObject object);
extern LCoord LEDITAPI LPie_GetRadius(LObject object);

// Utility Macros.
#if !defined(NULL)
#define NULL 0
#endif

#if defined(MAKE_DLL)

#if !defined(_TANNER_H)

#include <assert.h>
template <class T> inline bool Assigned(T* Ptr) {return(Ptr != NULL);};
template <class T> inline bool NotAssigned(T* Ptr) {return(Ptr == NULL);};

#endif

#else

#define Assigned(Ptr) ((Ptr) != NULL)
#define NotAssigned(Ptr) ((Ptr) == NULL)
#define DisplayLine(lLineNumber)	sprintf(sMsg,  "At Line Number %ld.", lLineNumber); LDialog_MsgBox(sMsg);
#define assert(x) (x)
typedef int bool;
#define false 0
#define true  1

#endif

#define WORLD_MAX ((LCoord) 0x1fffffffL)

#define MAX_LAYER_NAME 256
#define MAX_CELL_NAME 256
#define MAX_TDBFILE_NAME 256

#define LOK 1
#define LCANCEL 0

#define LYES 1
#define LNO 0

//	Because many UPI functions where initially created with char * instead 
//		of const char *, users need to cast the const away before passing the 
//		variable to the function.  This macro does that.
#define FixNonConstForUPI(x) ((char*)(x))


// New Documentation

/**@name File Functions*/
//@{
	/** Gets the visible (active) TDB file.
		@doc

		Example
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{
				char szFileName[256];
				LFile_GetName(pFile, szFileName, 255);
				// More Processing
				// ... 
			}
		@return Returns a pointer to the active TDB file; otherwise NULL.  If the visible file is a text file, then NULL is returned.
		@version Available in L-Edit v8.2 and later versions.
		@see File Functions.	
	*/
	extern LFile LEDITAPI LFile_GetVisible(void);

	/** Converts a value in Internal Units to Locator Units based on the grid mapping of a TDB file.
		@doc

		Example
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{
				double dWidth = LFile_IntUtoLocU(pFile, 1000);
				// More Processing
				// ... 
			}
		@return Returns the value (lcValue) in Locator Units.
		@param pFile Specified TDB File.
		@param lcValue	Value in Internal Units.
		@version Available in L-Edit v8.2 and later versions.
		@see LFile Functions, LFile_LocUtoIntU, Technology Setup Functions, LFile, LCoord.
	*/
	extern double LEDITAPI LFile_IntUtoLocU(LFile pFile, LCoord lcValue);

	/** Converts a value in Locator Units to Internal Units based on the grid mapping of a TDB file.
		@doc
		This function will round the value if it cannot represent the value exactly in Internal Units.  For example, if the mapping is 1 LU = 10 IU, and the value is 0.25 then it will be rounded to 0.3.

		Example
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{
				LCoord lcWidth = LFile_LocUtoIntU(pFile, 25.75);		
				// More Processing
				// ... 
			}
		@return Returns the value (dValue) in Internal Units.
		@param pFile Specified TDB File.
		@param dValue Value in Locator Units.
		@version Available in L-Edit v8.2 and later versions.
		@see File Functions, LFile_IntUtoLocU, Technology Setup Functions, LFile
	*/
	extern LCoord LEDITAPI LFile_LocUtoIntU(LFile pFile, double dValue);

	/** Marks the file as changed.
		@doc  Marks the file as changed.  This will also increment the minor version.

		Example

		@return Nothing.
		@param pTDBFile The file to mark as changed.		
		@version Available in L-Edit v8.2 and later versions.
		@see LFile Functions, LFile_IsChanged, LFile
	*/
	extern void LEDITAPI LFile_SetChanged(LFile pTDBFile);

	/** Resolves a path that is relative to a TDB file to an absolute path.
		@doc Resolves a path that is relative to a TDB file to an absolute path.  Absolute paths are 
				not modified.  Use this function to resolve a path that might be relative to the TDB 
				file, such as the extract definition file, DRC error file, or a file returned from LDialog_File.

		Example

		@return LBufferTooSmall if the buffer was too small, LStatusOK otherwise.
		@param pTDBFile The TDB file that the path might be relative to.
		@param szRelativeFileName Path that is either absolute or relative to the TDB file.
		@param szAbsoluteFileNameBuffer Buffer in which to store the absolute path.
		@param iBufferSize Size of the buffer.
		@version Available in L-Edit v8.2 and later versions.
		@see LFile Functions, LDialog_File, LFile
	*/
	extern LStatus LEDITAPI LFile_GetResolvedFileName(LFile pTDBFile, const char* szRelativeFileName, char* szAbsoluteFileNameBuffer, int iBufferSize);

	/**
		@Get/Set DRC flags
	*/

	extern LStatus LEDITAPI LFile_GetDesignRuleFlags(LFile file, LDesignRuleFlags *pDrcFlags);

	extern LStatus LEDITAPI LFile_SetDesignRuleFlags(LFile file, LDesignRuleFlags *pDrcFlags);

//@} File Functions


/**@name Object Functions*/
//@{
	/** Converts a LObject to a LInstance if possible.

		@return If pObject is a LInstance then a LInstance, NULL otherwise.
		@param pObject Object to convert.
		@version Available in L-Edit v8.1 and later versions.
		@see LObject, LInstance, LObject Functions, LInstance Functions.
	*/
	extern LInstance LEDITAPI LObject_GetInstance(LObject pObject);

	/** Retrieves the GDSII data type of an object..
		@doc

		Example
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{
				// Get the GDSII Data Type of the first object in the selected.
				LSelection pSelection = LSelection_GetList();
				if(Assigned(pSelection))
				{
					LObject pObject = LSelection_GetObject(pSelection);
					if(Assigned(pObject))
					{
						short iObjectDataType = LObject_GetGDSIIDataType(pObject);
						// More Processing
						// ... 
					}
				}
			}
		@return The GDSII data type if successful, -1 if an error occurred such as pObject is NULL or pObject is an Instance.
		@param pObject Specified object.		
		@version Available in L-Edit v8.2 and later versions.
		@see Object Functions, LObject_SetGDSIIDataType, Edit Objects, LObject, LStatus
	*/
	extern short LEDITAPI LObject_GetGDSIIDataType(LObject pObject);

	/** Sets the GDSII data type of an object..
		@doc

		Example
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{
				LCell pCell = LCell_Find(pFile, "MyCell");
				LLayer pLayer = LLayer_Find(pFile, "Poly");
				if(Assigned(pCell) && Assigned(pLayer))
				{
					LObject pObject;
					// Set the GDSII data type of each object on Poly in cell MyCell to 12.
					for(pObject = LObject_GetList(pCell, pLayer);
						 Assigned(pObject);
						 pObject = LObject_GetNext(pObject))
					{
						if(LObject_SetGDSIIDataType(pObject, 12) != LStatusOK)
						{
							// Some problem occurred.
							break;
						}
					}
				}
			}
		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values: LBadObject - One or more of the following: pObject is NULL, pObject is an instance.
		@param pObject Specified object.
		@param GDSIIDataType GDSII data type.
		@version Available in L-Edit v8.2 and later versions.
		@see Object Functions, LObject_GetGDSIIDataType, Edit Objects, LObject, LStatus
	*/
	extern LStatus LEDITAPI LObject_SetGDSIIDataType(LObject pObject, short iGDSIIDataType);

	/** Changes the layer of an object to a different layer.
		@doc Changes the layer of an object to a different layer.  After this function is called, the pObject pointer is no longer valid for getting the next object (LObject_GetNext) (see example below).

		Example
			LCell	pCell = LCell_GetVisible(); 		// The current cell.
			if(NotAssigned(pCell))
			{
				LDialog_AlertBox("ERROR:  Could not find a Visible Cell.");
				return;
			}

			LFile	pTDBFile = LCell_GetFile(pCell);		// The TDB current file.
			if(NotAssigned(pTDBFile))
			{
				LDialog_AlertBox("ERROR:  Could not get the TDB file from the Visible Cell.");
				return;
			}

			// Change all objects on Poly to Metal1.
			LLayer pPoly = LLayer_Find(pTDBFile, "Poly");
			LLayer pMetal1 = LLayer_Find(pTDBFile, "Metal1");
			if(Assigned(pPoly) && Assigned(pMetal1))
			{
				LObject pObject = NULL, pNextObject = NULL;
				for(pObject = LObject_GetList(pCell, pPoly); Assigned(pObject); pObject = pNextObject)
				{
					// After the LObject_ChangeLayer call, the pObject pointer will no longer be valid.
					//		So get the next object before you change the layer.
					pNextObject = LObject_GetNext(pObject);
					if(LObject_ChangeLayer(pCell, pObject, pMetal1) == LStatusOK)
					{
						// The layer was changed to Metal1.
					}
				} // endfor(pObject = LObject_GetList(pCell, pPoly); Assigned(pObject); pObject = pNextObject)
			}  // endif(Assigned(pLayer))

		@return LStatusOK if successful.  If an error occurs, LStatus contains the error type with possible values: LBadCell - pCell is NULL.  LBadObject - pObject is NULL, pObject is an instance, or object is corrupted.  LBadLayer - pLayer is NULL.
		@param pCell Cell which contains the object.
		@param pObject Object to change the layer of
		@param pNewLayer New layer.
		@version Available in L-Edit v8.3 and later versions.
		@see Object Functions, LStatus, LCell, LObject, LLayer, LObject_GetLayer, Edit Objects
	*/
	extern LStatus LEDITAPI LObject_ChangeLayer(LCell pCell, LObject pObject, LLayer pNewLayer);
//@} Object Functions


/**@name Selection Functions*/
//@{
	/** Gets the layer of a given selection element.

		@return Pointer to the layer if successful, NULL if the selection element is an instance or the operation was not successful.
		@param pSelection Pointer to the selection element.
		@version Available in L-Edit v6.6 and later versions.
		@see LLayer, LSelection, LSelection Functions.
	*/
	extern LLayer LEDITAPI LSelection_GetLayer(LSelection pSelection);
//@} Selection Functions


/**@name Entity Functions*/
//@{

	/** Converts a string to a valid property name.
		@doc
		Converts a string to a valid property name by replacing all underscores (_) with double underscores (__) and all invalid characters to _## where ## is the two digit ASCII number in hexadecimal for that character.  A valid property name can consists of letters, numbers, spaces, and underscores.

		Example
			char szPropertyName[256];
			if(LEntity_StringToValidPropertyName("Metal 1 & Metal 2 - DRC", szPropertyName, 255) == LStatusOK)
			{
				// szPropertyName now equals "Metal 1 _038 Metal 2 _045 DRC"

				LFile pFile = LFile_GetVisible();
				if(Assigned(pFile))
				{
					int iData = 5;
					if(LEntity_AssignProperty((LEntity)pFile, szPropertyName, L_int, &iData) == LStatusOK)
					{
						// More Processing
						// ... 
					}
				} // endif(Assigned(pFile))
			} // endif(LEntity_StringToValidPropertyName("Metal 1 & Metal 2 - DRC", szPropertyName, 255) == LStatusOK)

		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values:  LBadParameters - One or more of the following: szString is NULL, szPropertyName is NULL, iBufferSize < 2.
		@param szString String to convert.
		@param szPropertyName String buffer to store the result in.
		@param iBufferSize Size of the szPropertyName string buffer.
		@version Available in L-Edit v8.2 and later versions.
		@see LEntity Functions, LEntity_ValidPropertyNameToString, Properties, LStatus
	*/
	extern LStatus LEDITAPI LEntity_StringToValidPropertyName(const char* szString, char* szPropertyName, int iBufferSize);

	/** Converts a property name to a string.
		@doc
		Converts a property name to a string by replacing all double underscores (__) with single underscores (_) and converting _## to the ASCII character whose number is ## in hexadecimal.  A valid property name can consists of letters, numbers, spaces, and underscores.  This function is used in conjunction with LEntity_StringToValidPropertyName to store strings with invalid characters as property names.

		Example
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{
				// Get the first property.
				const char* pszPropertyName = LEntity_GetFirstProperty((LEntity)pFile);

				char szString[256];
				if(LEntity_ValidPropertyNameToString(pszPropertyName, szString, 255) == LStatusOK)
				{
					// szString now equals "Metal 1 & Metal 2 - DRC"

					// More Processing
					// ... 		
				} // endif(LEntity_ValidPropertyNameToString(pszPropertyName, szString, 255) == LStatusOK)
			} // endif(Assigned(pFile))
		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values:  LBadParameters - One or more of the following: szString is NULL, szPropertyName is NULL, iBufferSize < 2.
		@param szPropertyName Property name to convert.
		@param szString String buffer to store the result in.
		@param iBufferSize Size of the szString string buffer.
		@version Available in L-Edit v8.2 and later versions.
		@see LEntity Functions, LEntity_StringToValidPropertyName, Properties, LStatus
	*/
	extern LStatus LEDITAPI LEntity_ValidPropertyNameToString(const char* szPropertyName, char* szString, int iBufferSize);

	/** Write properties to a text file. 
		@doc
		Write properties from the indicated property subtree on the specified entity (File, Cell, Layer, or Object) to a text file in TTX format.

		Example
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{
				if(LEntity_WritePropertiesToFile((LEntity)pFile, "MyProperties", "MyProp.ttx") == LStatusOK)
				{
					// More Processing
					// ...
				}
			} // endif(Assigned(pFile))

		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values:  LBadObject - if pEntity is NULL, LBadParameters - if szFilename is NULL, LCreateError - if the file szFilename could not be created, LSystemError - if tpropprs.dll could be not loaded, LPropertyConversionError - if an error occurred during the exporting of the properties to a file.
		@param pEntity Entity that has the properties to write to the file.
		@param szPath Path to the property subtree to write to the file.  If szPath = NULL, then all properties are written to the file.
		@param szFileName Export filename.		
		@version Available in L-Edit v8.2 and later versions.
		@see LEntity Functions, LEntity_ReadPropertiesFromFile, Properties, LEntity, LStatus
	*/
	extern LStatus LEDITAPI LEntity_WritePropertiesToFile(const LEntity pEntity, const char* szPath, const char* szFilename);

	/** Reads properties from a text file. 
		@doc
		Reads a text file with property information in TTX format and assigns the properties to the indicated property subtree on the specified entity (File, Cell, Layer, or Object).

		Example
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{			
				if(LEntity_ReadPropertiesFromFile((LEntity)pFile, "MyProperties", "MyProp.ttx") == LStatusOK)
				{
					// More Processing
					// ...
				}
			} // endif(Assigned(pFile))

		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values:  LBadObject - if pEntity is NULL, LBadParameters - if szFilename is NULL, LCreateError - if the file szFilename could not be opened for reading, LSystemError - if tpropprs.dll could not be loaded, LPropertyConversionError - if an error occurred during the importing of the properties from a file.
		@param pEntity Entity on which to store the properties read from the file.
		@param szPath Path to the property subtree at which to store the properties read from the file.  If szPath = NULL, then the properties will be stored on the root of the property tree.
		@param szFileName Import filename.
		@version Available in L-Edit v8.2 and later versions.
		@see LEntity Functions, LEntity_WritePropertiesFromFile, Properties, LEntity, LStatus
	*/
	extern LStatus LEDITAPI LEntity_ReadPropertiesFromFile(LEntity pEntity, const char* szPath, const char* szFilename);	
//@} Entity Functions


/**@name Layer Functions*/
//@{

	/** Extended layer parameter structure.
		@doc LLayerParam_Ex00 is an extended layer parameter structure that stores the parameters of a layer such as CIF name, GDSII layer number, GDSII layer data type, area and fringe capacitance, resistivity, default wire parameters, and lock and hidden states.

		Example<p>
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{
				if(LLayer_New(pFile, LLayer_GetList(pFile), "Metal1") == LStatusOK)
				{
					LLayer pLayer = LLayer_Find(pFile, "Metal1");
					if(Assigned(pLayer))
					{
						LLayerParam_Ex00 LayerParameters;
						strcpy(LayerParameters.CIFName, "CMF");
						LayerParameters.GDSNumber =49;
						LayerParameters.GDSDataType = -1;
						LayerParameters.AreaCapacitance = 36;
						LayerParameters.FringeCapacitance = 0.086;
						LayerParameters.Resistivity = 0.08;
						LayerParameters.Locked = LFALSE;
						LayerParameters.Hidden = LFALSE;			
						LayerParameters.WireParam.defaultWireWidth = LFile_LocUtoIntU(pFile, 1.5);
						LayerParameters.WireParam.defaultWireMiterAngle = 90;
						LayerParameters.WireParam.capType = LCapExtend;
						LayerParameters.WireParam.joinType = LJoinLayout;

						if(LLayer_SetParameters_Ex00(pLayer, &LayerParameters) == LStatusOK)
						{
							// More Processing
							// ... 
						}
					}
				}
			}
		@version Available in L-Edit v8.2 and later versions.
		@see Layer Functions, LLayer_GetParameters_Ex00, LLayer_SetParameters_Ex00, LBoolean, LWireParam, Setup>Layers
	*/
	typedef struct {
		/// CIF layer name.  It can be 6 characters or less.
		char CIFName[7];
		/// GDSII layer number. -32,768 <= GDSNumber <= 32,767.  The GDSII standard requires 0 <= GDSNumber <= 255.
		short GDSNumber;
		/// GDSII data type. -32,768 <= GDSDataType <= 32,767.  The GDSII standard requires 0 <= GDSNumber <= 255. A value of -1 indicates an unassigned GDSII data type.
		short GDSDataType;
		/// Area capacitance in aF/Sq. micron from the layer to the substrate.  0 <= AreaCapacitance or AreaCapacitance = -1.  A value of -1 indicates an unassigned area capacitance.
		double AreaCapacitance;
		/// Fringe capacitance in fF/micron from the layer to the substrate.  0 <= FringeCapacitance or FringeCapacitance = -1.  A value of -1 indicates an unassigned fringe capacitance.
		double FringeCapacitance;
		/// Sheet resistance of the layer in ohms/square. 0 <= Resistivity.
		double Resistivity;
		/// Indicates whether the layer is locked.
		LBoolean Locked;
		/// Indicates whether the layer is hidden.
		LBoolean Hidden;
		/// Default wire parameters of the layer.
		LWireParam WireParam;
	} LLayerParamEx830;
	
	typedef LLayerParamEx830 LLayerParam_Ex00;

	/** Retrieves the parameters of a layer.
		@doc
		Retrieves the parameters of a layer such as CIF name, GDSII layer number, GDSII layer data type, area and fringe capacitance, resistivity, default wire parameters, and lock and hidden states.

		Example
			double dAreaCap;
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{
				LLayer pLayer = LLayer_Find(pFile, "Poly");
				if(Assigned(pLayer))
				{
					LLayerParam_Ex00 LayerParameters;
					if(LLayer_GetParameters_Ex00(pLayer, &LayerParameters) == LStatusOK)
					{
						dAreaCap = LayerParameters.AreaCapacitance;				
						// More Processing
						// ... 
					}
				}
			}
		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values:  LBadLayer - pLayer is NULL, LBadParameters - pLayerParam is NULL.
		@param pLayer Specified layer.
		@param pLayerParam Pointer to an extended layer parameter structure.  This structure will be used for returning data.
		@version Available in L-Edit v8.2 and later versions.
		@see Layer Functions, LLayer, LLayerParam_Ex00, LLayer_SetParameters_Ex00, LStatus, Setup>Layers.
	*/
	extern LStatus LEDITAPI LLayer_GetParameters_Ex00(LLayer pLayer, LLayerParam_Ex00* pLayerParam);
	extern LStatus LEDITAPI LLayer_GetParametersEx830(LLayer pLayer, LLayerParamEx830* pLayerParam);
	
	/** Sets the parameters of a layer.
		@doc
		Sets the parameters of a layer such as CIF name, GDSII layer number, GDSII layer data type, area and fringe capacitance, resistivity, default wire parameters, and lock and hidden states.

		Example
			LFile pFile = LFile_GetVisible();
			if(Assigned(pFile))
			{
				LLayer pLayer = LLayer_Find(pFile, "Poly");
				if(Assigned(pLayer))
				{
					LLayerParam_Ex00 LayerParameters;
					if(LLayer_GetParameters_Ex00(pLayer, &LayerParameters) == LStatusOK)		{
						LayerParameters.AreaCapacitance = 500.3;
						if(LLayer_SetParameters_Ex00(pLayer, &LayerParameters) == LStatusOK)
						{
							// More Processing
							// ...
						}
					}
				}
			}
		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values: LBadLayer - pLayer is NULL, LBadParameters - One or more of the following: pLayerParam is NULL, Area Capacitance (pLayerParam->AreaCapacitance) < 0 and pLayerParam->AreaCapacitance ? -1, Fringe Capacitance (pLayerParam->FringeCapacitance) < 0 and pLayerParam->FringeCapacitance ? -1, Resistivity (pLayerParam-> Resistivity) < 0, Invalid wire parameters.
		@param pLayer Specified layer.
		@param pLayerParam Pointer to an extended layer parameter structure containing the new layer parameters.
		@version Available in L-Edit v8.2 and later versions.
		@see Layer Functions, LLayer, LLayerParam_Ex00, LLayer_GetParameters_Ex00, LStatus, Setup>Layers. 
	*/
	extern LStatus LEDITAPI LLayer_SetParameters_Ex00(LLayer pLayer, LLayerParam_Ex00* pLayerParam);
	extern LStatus LEDITAPI LLayer_SetParametersEx830(LLayer pLayer, LLayerParamEx830* pLayerParam);

	/** Frees the memory associated with the derived layer parameter structure.
		@doc Frees the memory associated with the derived layer parameter structure that was allocated by L-Edit
				during a LLayer_GetDerivedParameters call.  Do not call Layer_DestroyDerivedParameter if 
				LDrcRule_GetParameter has not been previously called with pDesignRuleParam.
		Example
			LFile pTDBFile = LFile_GetVisible();
			if(Assigned(pTDBFile))
			{
				LLayer pLayer = LLayer_Find(pTDBFile, "PolyCnt_And_NotPoly");
				if(Assigned(pLayer))
				{
					LDerivedLayerParam pDerivedLayerParam;
					if(Assigned(LLayer_GetDerivedParameters(pLayer, &pDerivedLayerParam)))
					{
						long lGrow = pDerivedLayerParam.layer1_grow_amount;

						// More Processing
						// ... 		

						LLayer_DestroyDerivedParameter(&pDerivedLayerParam);
					}
				} // endif(Assigned(pLayer))
			} // endif(Assigned(pTDBFile))


		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values:  LBadParameters - pDerivedLayerParam is NULL.
		@param pDerivedLayerParam Pointer to a derived layer parameter structure.
		@version Available in L-Edit v8.2 and later versions.
		@see Derived Layer Functions, LDerivedLayerParam, LStatus.
	*/
	extern LStatus LEDITAPI LLayer_DestroyDerivedParameter(LDerivedLayerParam* pDerivedLayerParam);
//@} Layer Functions


/**@name Cell Functions*/
//@{
		
	/** Generates a layer or all layers in the specified cell.
		@doc
		
		Example
			LCell pCell = LCell_GetVisible();
			if(Assigned(pCell))
			{
				LFile pFile = LCell_GetFile(pCell);
				if(Assigned(pFile))
				{
					LLayer pLayer = LLayer_Find(pFile, "ndiff");
					if(Assigned(pLayer))
					{
						if(LCell_GenerateLayersEx00(pCell, LFile_LocUtoIntU(pFile, 100), pLayer, LTRUE, LFALSE) == LStatusOK)
						{
							// More Processing
							// ... 
						}
					}
					else
					{
						LDialog_AlertBox("Cannot find layer \"ndiff\"");
					} // endif(Assigned(pLayer))
				} // endif(Assigned(pFile))
			}
	
		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values: LBadCell - pCell is NULL, LBadParameters - iBinSize is <= 0.
		@param pCell Cell to generate the layers in.
		@param iBinSize Bin size for generating layers.
		@param pLayer Layer to generate. If pLayer is NULL then all layers are generated.
		@param bDeletePreviousDerivedLayers If LTRUE all existing derived layers will be deleted.
		@param bMergeObjectsAfterGeneration If LTRUE causes objects on the same generated layer to be merged upon completion of the process, which can significantly increase the processing time for more complex layouts.
		@version Available in L-Edit v8.2 and later versions.
		@see Generated Layer Functions, LCell, LLayer, LBoolean, Generate Layers, LStatus
	*/
	extern LStatus LEDITAPI LCell_GenerateLayersEx00(LCell pCell, int iBinSize, LLayer pLayer, LBoolean bDeletePreviousDerivedLayers, LBoolean bMergeObjectsAfterGeneration);
	extern LStatus LEDITAPI LCell_GenerateLayersEx830(LCell pCell, int iBinSize, LLayer pLayer, LBoolean bDeletePreviousDerivedLayers, LBoolean bMergeObjectsAfterGeneration);

	/** Runs DRC on the entire cell or a specified area of a cell.
		@doc
		The user can specify the bin size, the DRC error file, and whether to place 
		error ports and objects during DRC.  If Quietmode is on, then the RUN DRC 
		dialog and warning dialogs will not appear.

		Example
			LCell pCell = LCell_GetVisible();
			if(Assigned(pCell))
			{
				LFile pFile = LCell_GetFile(pCell);
				if(Assigned(pFile))
				{
					if(LCell_RunDRCEx00(pCell, NULL, LFile_LocUtoIntU(pFile, 100), NULL, LTRUE, LFALSE) == LStatusOK)
					{
						// More Processing
						// ...
					}
				} // endif(Assigned(pFile))

			} // endif(Assigned(pCell))
	
		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values:  LBadCell - pCell is NULL, LSystemError - L-Edit could not find an active cell layout window or open one, LUserAbort - If the user canceled DRC while it was running.
		@param pCell Cell to run DRC on.
		@param pDRCArea Rectangular area to perform DRC on.  If pDRCArea is NULL, then DRC is performed on the entire cell.
		@param lcBinSize Bin size in Internal Units.
		@param szErrorFile Name of the file to write DRC error to.  If szErrorFile is NULL, no errors are written to a file.
		@param bWriteErrorPorts Instructs L- Edit to place an error port on the specified error layer at the location of each DRC violation.  An error port consists of the name of the violated design rule and a bracketed expression; the expression indicates the spacing or nature of the error and the rule distance.
		@param bWriteErrorObjects Instructs L- Edit to place marker objects on the specified error layer at the location of each violation.
		@version Available in L-Edit v8.2 and later versions.
		@see DRC Functions, LCell, LRect, LCoord, LBoolean, LStatus, DRC
	*/
	extern LStatus LEDITAPI LCell_RunDRCEx00(LCell pCell, LRect* pDRCArea, LCoord lcBinSize, const char* szErrorFile, LBoolean bWriteErrorPorts, LBoolean bWriteErrorObjects);

#define LDrcFlagWriteErrors 				1
#define LDrcFlagWriteErrorPorts			2
#define LDrcFlagWriteErrorObjects 		4
#define LDrcFlagWriteTimingStatistics	8
	extern LStatus LEDITAPI LCell_RunDRCEx01(LCell pCell, LRect* pDRCArea, LCoord lcBinSize, const char* szErrorFile, int flags);
	extern LStatus LEDITAPI LCell_RunDRCEx830(LCell pCell, LRect* pDRCArea, LCoord lcBinSize, const char* szErrorFile, int flags);

	/** Marks the cell as changed.
		@doc  Marks the cell as changed.  This will also increment the minor version.

		Example

		@return Nothing.
		@param pCell The cell to mark as changed.		
		@version Available in L-Edit v8.2 and later versions.
		@see LCell Functions, LCell_IsChanged, LCell
	*/
	extern void LEDITAPI LCell_SetChanged(LCell pCell);

//@} Cell Functions


/**@name DRC Functions*/
//@{

	/** Frees the memory associated with the design rule parameter structure.
		@doc Frees the memory associated with the design rule parameter structure that was allocated by L-Edit 
				during a LDrcRule_GetParameter call.  Do not call LDrcRule_DestoryParameter if LDrcRule_GetParameter 
				has not been previously called with pDesignRuleParam.

		Example
			LFile pTDBFile = LFile_GetVisible();
			if(Assigned(pTDBFile))
			{
				LDrcRule pDRCRule = LDrcRule_Find(pTDBFile, LSPACING, "Poly", NULL);
				if(Assigned(pDRCRule))
				{
					LDesignRuleParam pDesignRuleParameter;
					if(Assigned(LDrcRule_GetParameters(pDRCRule, &pDesignRuleParameter)))
					{
						long lDist = pDesignRuleParameter.distance;

						// More Processing
						// ... 		

						LDrcRule_DestroyParameter(&pDesignRuleParameter);
					}
				} // endif(Assigned(pDRCRule))
			} // endif(Assigned(pTDBFile))

		@return LStatusOK if successful. If an error occurs, LStatus contains the error value with possible values:  LBadParameters - pLayerParam is NULL.
		@param pDesignRuleParam Pointer to a design rule parameter structure.
		@version Available in L-Edit v8.2 and later versions.
		@see DRC Functions, LDesignRuleParam, LStatus.
	*/
	extern LStatus LEDITAPI LDrcRule_DestroyParameter(LDesignRuleParam* pDesignRuleParam);
//@} DRC Functions

/**@name Application Functions*/
//@{

	/** Gets the flag indicating whether to hide small instance insides.
		@doc This gets the Hide instance insides if less than application setting on the Setup Application>Rendering tab.

		Example
			// Save the setting.
			LBoolean bHideInsides = LApp_GetHideSmallInstanceInsides();

			LApp_SetHideSmallInstanceInsides(LTRUE);
			// More Processing
			// ... 

			// Reset the setting.
			LApp_SetHideSmallInstanceInsides(bHideInsides);

		@return LTRUE if the instance insides less than a certain pixel size are hidden, LFALSE to show them.
		@version Available in L-Edit v8.3 and later versions.
		@see Setup Application, LApp_SetHideSmallInstanceInsides, LApp_GetHideInstanceInsidesIfLessThanNumOfPixels, LApp_SetHideInstanceInsidesIfLessThanNumOfPixels, LStatus, LBoolean
	*/
	extern LBoolean LEDITAPI LApp_GetHideSmallInstanceInsides(void);

	/** Sets the flag indicating whether to hide small instance insides.
		@doc This sets the Hide instance insides if less than application setting on the Setup Application>Rendering tab.

		Example
			// Save the setting.
			LBoolean bHideInsides = LApp_GetHideSmallInstanceInsides();

			LApp_SetHideSmallInstanceInsides(LTRUE);
			// More Processing
			// ... 

			// Reset the setting.
			LApp_SetHideSmallInstanceInsides(bHideInsides);

		@return Always LStatusOK.		
		@param bHideSmallInstanceInsides LTRUE to hide instance insides, LFALSE to show instance insides.
		@version Available in L-Edit v8.3 and later versions.
		@see Setup Application, LApp_GetHideSmallInstanceInsides, LApp_GetHideInstanceInsidesIfLessThanNumOfPixels, LApp_SetHideInstanceInsidesIfLessThanNumOfPixels, LStatus, LBoolean
	*/
	extern LStatus LEDITAPI LApp_SetHideSmallInstanceInsides(LBoolean bHideSmallInstanceInsides);

	/** Gets the pixel size for hiding instance inside.
		@doc This function stores the results in pptPixelSize.  If an instance is smaller than pptPixelSize then its insides are hidden.  This gets the Hide instance insides if less than - Horizontal and Vertical parameter on the Setup Application>Rendering tab.

		Example
			// Save the setting.
			LPoint ptCurrentPixelSize;
			if(LApp_GetHideInstanceInsidesIfLessThanNumOfPixels(&ptCurrentPixelSize) == LStatusOK)
			{
				LPoint ptNewPixelSize;

				ptNewPixelSize.x = 5;
				ptNewPixelSize.y = 5;
				if(LApp_SetHideInstanceInsidesIfLessThanNumOfPixels(&ptNewPixelSize) == LStatusOK)
				{
					// More Processing
					// ... 

					// Reset the setting.
					LApp_SetHideInstanceInsidesIfLessThanNumOfPixels(&ptCurrentPixelSize);
				} // endif(LApp_SetHideInstanceInsidesIfLessThanNumOfPixels(&ptNewPixelSize) == LStatusOK)
			} // endif(LApp_GetHideInstanceInsidesIfLessThanNumOfPixels(&ptCurrentPixelSize) == LStatusOK)

		@return LStatusOK if successful.  If an error occurs, LStatus contains the error type with possible values:  LBadParameter - pptPixelSize is NULL.
		@param pptPixelSize Horizontal number of pixels and vertical number of pixels.
		@version Available in L-Edit v8.3 and later versions.
		@see Setup Application, LApp_GetHideSmallInstanceInsides, LApp_SetHideSmallInstanceInsides, LApp_SetHideInstanceInsidesIfLessThanNumOfPixels, LStatus, LBoolean
	*/
	extern LStatus LEDITAPI LApp_GetHideInstanceInsidesIfLessThanNumOfPixels(LPoint* pptPixelSize);

	/** Sets the pixel size for hiding instance inside.
		@doc If an instance is smaller than pptPixelSize then its insides are hidden.  This sets the Hide instance insides if less than - Horizontal and Vertical parameter on the Setup Application>Rendering tab.

		Example
			// Save the setting.
			LPoint ptCurrentPixelSize;
			if(LApp_GetHideInstanceInsidesIfLessThanNumOfPixels(&ptCurrentPixelSize) == LStatusOK)
			{
				LPoint ptNewPixelSize;

				ptNewPixelSize.x = 5;
				ptNewPixelSize.y = 5;
				if(LApp_SetHideInstanceInsidesIfLessThanNumOfPixels(&ptNewPixelSize) == LStatusOK)
				{
					// More Processing
					// ... 

					// Reset the setting.
					LApp_SetHideInstanceInsidesIfLessThanNumOfPixels(&ptCurrentPixelSize);
				} // endif(LApp_SetHideInstanceInsidesIfLessThanNumOfPixels(&ptNewPixelSize) == LStatusOK)
			} // endif(LApp_GetHideInstanceInsidesIfLessThanNumOfPixels(&ptCurrentPixelSize) == LStatusOK)

		@return LStatusOK if successful.  If an error occurs, LStatus contains the error type with possible values:  LBadParameter - pptPixelSize is NULL, pptPixelSize->x < 0, pptPixelSize->y < 0, pptPixelSize->x > 32000, or pptPixelSize->y > 32000.
		@param pptPixelSize Horizontal number of pixels and vertical number of pixels.
		@version Available in L-Edit v8.3 and later versions.
		@see Setup Application, LApp_GetHideSmallInstanceInsides, LApp_SetHideSmallInstanceInsides LApp_GetHideInstanceInsidesIfLessThanNumOfPixels, LStatus, LBoolean
	*/
	extern LStatus LEDITAPI LApp_SetHideInstanceInsidesIfLessThanNumOfPixels(const LPoint* pptPixelSize);
	
	/** Gets the flag indicating whether to hide small objects.
		@doc This gets the Hide objects smaller than application setting on the Setup Application>Rendering tab.

		Example
			// Save the setting.
			LBoolean bHideObjects = LApp_GetHideSmallObjects();

			LApp_SetHideSmallObjects(LTRUE);
			// More Processing
			// ... 

			// Reset the setting.
			LApp_SetHideSmallObjects(bHideObjects);

		@return LTRUE if the objects smaller than a certain pixel size are hidden, LFALSE to show them.
		@version Available in L-Edit v8.3 and later versions.
		@see Setup Application, LApp_SetHideSmallObjects, LApp_GetHideObjectsSmallerThanNumOfPixels, LApp_SetHideObjectsSmallerThanNumOfPixels, LStatus, LBoolean
	*/
	extern LBoolean LEDITAPI LApp_GetHideSmallObjects(void);

	/** Sets the flag indicating whether to hide small objects.
		@doc This sets the Hide objects smaller than application setting on the Setup Application>Rendering tab.

		Example
			// Save the setting.
			LBoolean bHideObjects = LApp_GetHideSmallObjects();

			LApp_SetHideSmallObjects(LTRUE);
			// More Processing
			// ... 

			// Reset the setting.
			LApp_SetHideSmallObjects(bHideObjects);

		@return Always LStatusOK.
		@param bHideSmallObjects LTRUE if the objects smaller than a certain pixel size are hidden, LFALSE to show them.
		@version Available in L-Edit v8.3 and later versions.
		@see Setup Application, LApp_GetHideSmallObjects, LApp_GetHideObjectsSmallerThanNumOfPixels, LApp_SetHideObjectsSmallerThanNumOfPixels, LStatus, LBoolean
	*/
	extern LStatus LEDITAPI LApp_SetHideSmallObjects(LBoolean bHideSmallObjects);

	/** Gets the pixel size for hiding objects.
		@doc   If an object is smaller than returned number of pixels then it is not rendered.  This gets the Hide objects smaller than - Pixels parameter on the Setup Application>Rendering tab.

		Example
			// Save the setting.
			int iCurrentPixelSize = LApp_GetHideObjectsSmallerThanNumOfPixels();

			if(LApp_SetHideObjectsSmallerThanNumOfPixels(5) == LStatusOK)
			{
				// More Processing
				// ... 

				// Reset the setting.
				LApp_SetHideObjectsSmallerThanNumOfPixels(iCurrentPixelSize);
			} // endif(LApp_SetHideObjectsSmallerThanNumOfPixels(5) == LStatusOK)

		@return The number of pixels below which objects will be hidden.		
		@version Available in L-Edit v8.3 and later versions.
		@see Setup Application, LApp_GetHideSmallObjects, LApp_SetHideSmallObjects, LApp_SetHideObjectsSmallerThanNumOfPixels, LStatus
	*/
	extern int LEDITAPI LApp_GetHideObjectsSmallerThanNumOfPixels(void);

	/** Sets the pixel size for hiding objects.
		@doc   If an object is smaller than iPixelSize then it is not rendered.  This sets the Hide objects smaller than - Pixels parameter on the Setup Application>Rendering tab.

		Example
			// Save the setting.
			int iCurrentPixelSize = LApp_GetHideObjectsSmallerThanNumOfPixels();

			if(LApp_SetHideObjectsSmallerThanNumOfPixels(5) == LStatusOK)
			{
				// More Processing
				// ... 

				// Reset the setting.
				LApp_SetHideObjectsSmallerThanNumOfPixels(iCurrentPixelSize);
			} // endif(LApp_SetHideObjectsSmallerThanNumOfPixels(5) == LStatusOK)

		@return LStatusOK if successful.  If an error occurs, LStatus contains the error type with possible values:  LBadParameter - iPixelSize < 0 or iPixelSize > 32000.
		@param iPixelSize The number of pixels below which objects will be hidden.
		@version Available in L-Edit v8.3 and later versions.
		@see Setup Application, LApp_GetHideSmallObjects, LApp_SetHideSmallObjects, LApp_GetHideObjectsSmallerThanNumOfPixels, LStatus
	*/
	extern LStatus LEDITAPI LApp_SetHideObjectsSmallerThanNumOfPixels(int iPixelSize);
	
	extern LBoolean LEDITAPI LApp_GetCacheInstances(void);
	extern LStatus LEDITAPI LApp_SetCacheInstances(LBoolean bCacheInstances);
	extern int LEDITAPI LApp_GetCacheInstancesSmallerThanNumOfPixels(void);
	extern LStatus LEDITAPI LApp_SetCacheInstancesSmallerThanNumOfPixels(int iPixelSize);
	extern LBoolean LEDITAPI LApp_GetInterruptableRendering(void);
	extern LStatus LEDITAPI LApp_SetInterruptableRendering(LBoolean bInterruptRendering);
	extern LBoolean LEDITAPI LApp_GetRedrawAllWindows(void);
	extern LStatus LEDITAPI LApp_SetRedrawAllWindows(LBoolean bRedrawAllWindows);
	extern LBoolean LEDITAPI LApp_GetFillObjectsDuringDrawing(void);
	extern LStatus LEDITAPI LApp_SetFillObjectsDuringDrawing(LBoolean bFillObjectDuringDrawing);

//@} Application  Functions

	/** .
		@doc

		Example

		@return 
		@param Arg Description
		@version Available in L-Edit v8.3 and later versions.
		@see 
	*/

#ifdef _UPI_PACKING
#pragma pack(pop)
#endif

#endif // #ifndef __LDATA_H
