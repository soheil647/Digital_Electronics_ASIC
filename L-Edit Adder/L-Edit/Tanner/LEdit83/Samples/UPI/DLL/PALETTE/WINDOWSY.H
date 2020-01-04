
// File:  windowsy.h
// Dr. Bruce E. Krell
// copyright, 1995

/****** Message crackers ****************************************************/

#define HANDLE_DLG_MSG(hwnd, message, fn)    \
    case (message): return HANDLE_DLG_##message((hwnd), (wParam), (lParam), (fn))

/* void Cls_OnCompacting(HWND hwnd, UINT compactRatio) */
#define HANDLE_DLG_WM_COMPACTING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), FALSE)

/* void Cls_OnWinIniChange(HWND hwnd, LPCTSTR lpszSectionName) */
#define HANDLE_DLG_WM_WININICHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCTSTR)(lParam)), FALSE)

/* void Cls_OnSysColorChange(HWND hwnd) */
#define HANDLE_DLG_WM_SYSCOLORCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* BOOL Cls_OnQueryNewPalette(HWND hwnd) */
#define HANDLE_DLG_WM_QUERYNEWPALETTE(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), FALSE)

/* void Cls_OnPaletteIsChanging(HWND hwnd, HWND hwndPaletteChange) */
#define HANDLE_DLG_WM_PALETTEISCHANGING(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), FALSE)

/* void Cls_OnPaletteChanged(HWND hwnd, HWND hwndPaletteChange) */
#define HANDLE_DLG_WM_PALETTECHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), FALSE)

/* void Cls_OnFontChange(HWND hwnd) */
#define HANDLE_DLG_WM_FONTCHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnSpoolerStatus(HWND hwnd, UINT status, int cJobInQueue) */
#define HANDLE_DLG_WM_SPOOLERSTATUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)(short)LOWORD(lParam)), FALSE)

/* void Cls_OnDevModeChange(HWND hwnd, LPCTSTR lpszDeviceName) */
#define HANDLE_DLG_WM_DEVMODECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCTSTR)(lParam)), FALSE)

/* void Cls_OnTimeChange(HWND hwnd) */
#define HANDLE_DLG_WM_TIMECHANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnPower(HWND hwnd, int code) */
#define HANDLE_DLG_WM_POWER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), FALSE)

/* BOOL Cls_OnQueryEndSession(HWND hwnd) */
#define HANDLE_DLG_WM_QUERYENDSESSION(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), FALSE)

/* void Cls_OnEndSession(HWND hwnd, BOOL fEnding) */
#define HANDLE_DLG_WM_ENDSESSION(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), FALSE)

/* void Cls_OnQuit(HWND hwnd, int exitCode) */
#define HANDLE_DLG_WM_QUIT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam)), FALSE)

/* BOOL Cls_OnCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) */
#define HANDLE_DLG_WM_CREATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCREATESTRUCT)(lParam)) ? FALSE : (LRESULT)-1L)

/* BOOL Cls_OnNCCreate(HWND hwnd, LPCREATESTRUCT lpCreateStruct) */
#define HANDLE_DLG_WM_NCCREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (LPCREATESTRUCT)(lParam))

/* void Cls_OnDestroy(HWND hwnd) */
#define HANDLE_DLG_WM_DESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnNCDestroy(HWND hwnd) */
#define HANDLE_DLG_WM_NCDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnShowWindow(HWND hwnd, BOOL fShow, UINT status) */
#define HANDLE_DLG_WM_SHOWWINDOW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (UINT)(lParam)), FALSE)

/* void Cls_OnSetRedraw(HWND hwnd, BOOL fRedraw) */
#define HANDLE_DLG_WM_SETREDRAW(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), FALSE)

/* void Cls_OnEnable(HWND hwnd, BOOL fEnable) */
#define HANDLE_DLG_WM_ENABLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam)), FALSE)

/* void Cls_OnSetText(HWND hwnd, LPCTSTR lpszText) */
#define HANDLE_DLG_WM_SETTEXT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPCTSTR)(lParam)), FALSE)

/* INT Cls_OnGetText(HWND hwnd, int cchTextMax, LPTSTR lpszText) */
#define HANDLE_DLG_WM_GETTEXT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (int)(wParam), (LPTSTR)(lParam))

/* INT Cls_OnGetTextLength(HWND hwnd) */
#define HANDLE_DLG_WM_GETTEXTLENGTH(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)(hwnd)

/* BOOL Cls_OnWindowPosChanging(HWND hwnd, LPWINDOWPOS lpwpos) */
#define HANDLE_DLG_WM_WINDOWPOSCHANGING(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (LPWINDOWPOS)(lParam))

/* void Cls_OnWindowPosChanged(HWND hwnd, const LPWINDOWPOS lpwpos) */
#define HANDLE_DLG_WM_WINDOWPOSCHANGED(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const LPWINDOWPOS)(lParam)), FALSE)

/* void Cls_OnMove(HWND hwnd, int x, int y) */
#define HANDLE_DLG_WM_MOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), FALSE)

/* void Cls_OnSize(HWND hwnd, UINT state, int cx, int cy) */
#define HANDLE_DLG_WM_SIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), FALSE)

/* void Cls_OnClose(HWND hwnd) */
#define HANDLE_DLG_WM_CLOSE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* BOOL Cls_OnQueryOpen(HWND hwnd) */
#define HANDLE_DLG_WM_QUERYOPEN(hwnd, wParam, lParam, fn) \
    MAKELRESULT((BOOL)(fn)(hwnd), FALSE)

/* void Cls_OnGetMinMaxInfo(HWND hwnd, LPMINMAXINFO lpMinMaxInfo) */
#define HANDLE_DLG_WM_GETMINMAXINFO(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (LPMINMAXINFO)(lParam)), FALSE)

/* void Cls_OnPaint(HWND hwnd) */
#define HANDLE_DLG_WM_PAINT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* BOOL Cls_OnEraseBkgnd(HWND hwnd, HDC hdc) */
#define HANDLE_DLG_WM_ERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))

/* BOOL Cls_OnIconEraseBkgnd(HWND hwnd, HDC hdc) */
#define HANDLE_DLG_WM_ICONERASEBKGND(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HDC)(wParam))

/* void Cls_OnNCPaint(HWND hwnd, HRGN hrgn) */
#define HANDLE_DLG_WM_NCPAINT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HRGN)(wParam)), FALSE)

/* UINT Cls_OnNCCalcSize(HWND hwnd, BOOL fCalcValidRects, NCCALCSIZE_PARAMS * lpcsp) */
#define HANDLE_DLG_WM_NCCALCSIZE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(0), (NCCALCSIZE_PARAMS *)(lParam))

/* UINT Cls_OnNCHitTest(HWND hwnd, int x, int y) */
#define HANDLE_DLG_WM_NCHITTEST(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam))

/* HICON Cls_OnQueryDragIcon(HWND hwnd) */
#define HANDLE_DLG_WM_QUERYDRAGICON(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)

#ifdef _INC_SHELLAPI
/* void Cls_OnDropFiles(HWND hwnd, HDROP hdrop) */
#define HANDLE_DLG_WM_DROPFILES(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HDROP)(wParam)), FALSE)
#endif  /* _INC_SHELLAPI */

/* void Cls_OnActivate(HWND hwnd, UINT state, HWND hwndActDeact, BOOL fMinimized) */
#define HANDLE_DLG_WM_ACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)LOWORD(wParam), (HWND)(lParam), (BOOL)HIWORD(wParam)), FALSE)

/* void Cls_OnActivateApp(HWND hwnd, BOOL fActivate, DWORD dwThreadId) */
#define HANDLE_DLG_WM_ACTIVATEAPP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(wParam), (DWORD)(lParam)), FALSE)

/* BOOL Cls_OnNCActivate(HWND hwnd, BOOL fActive, HWND hwndActDeact, BOOL fMinimized) */
#define HANDLE_DLG_WM_NCACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (BOOL)(wParam), FALSE, FALSE)

/* void Cls_OnSetFocus(HWND hwnd, HWND hwndOldFocus) */
#define HANDLE_DLG_WM_SETFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), FALSE)

/* void Cls_OnKillFocus(HWND hwnd, HWND hwndNewFocus) */
#define HANDLE_DLG_WM_KILLFOCUS(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), FALSE)

/* void Cls_OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags) */
#define HANDLE_DLG_WM_KEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), FALSE)

/* void Cls_OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags) */
#define HANDLE_DLG_WM_KEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), FALSE)

/* void Cls_OnChar(HWND hwnd, TCHAR ch, int cRepeat) */
#define HANDLE_DLG_WM_CHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (TCHAR)(wParam), (int)(short)LOWORD(lParam)), FALSE)

/* void Cls_OnDeadChar(HWND hwnd, TCHAR ch, int cRepeat) */
#define HANDLE_DLG_WM_DEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (TCHAR)(wParam), (int)(short)LOWORD(lParam)), FALSE)

/* void Cls_OnSysKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags) */
#define HANDLE_DLG_WM_SYSKEYDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), TRUE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), FALSE)

/* void Cls_OnSysKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags) */
#define HANDLE_DLG_WM_SYSKEYUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), FALSE, (int)(short)LOWORD(lParam), (UINT)HIWORD(lParam)), FALSE)

/* void Cls_OnSysChar(HWND hwnd, TCHAR ch, int cRepeat) */
#define HANDLE_DLG_WM_SYSCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (TCHAR)(wParam), (int)(short)LOWORD(lParam)), FALSE)

/* void Cls_OnSysDeadChar(HWND hwnd, TCHAR ch, int cRepeat) */
#define HANDLE_DLG_WM_SYSDEADCHAR(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (TCHAR)(wParam), (int)(short)LOWORD(lParam)), FALSE)

/* void Cls_OnMouseMove(HWND hwnd, int x, int y, UINT keyFlags) */
#define HANDLE_DLG_WM_MOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define HANDLE_DLG_WM_LBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define HANDLE_DLG_WM_LBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnLButtonUp(HWND hwnd, int x, int y, UINT keyFlags) */
#define HANDLE_DLG_WM_LBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define HANDLE_DLG_WM_RBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define HANDLE_DLG_WM_RBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnRButtonUp(HWND hwnd, int x, int y, UINT flags) */
#define HANDLE_DLG_WM_RBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnMButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define HANDLE_DLG_WM_MBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnMButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags) */
#define HANDLE_DLG_WM_MBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnMButtonUp(HWND hwnd, int x, int y, UINT flags) */
#define HANDLE_DLG_WM_MBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnNCMouseMove(HWND hwnd, int x, int y, UINT codeHitTest) */
#define HANDLE_DLG_WM_NCMOUSEMOVE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnNCLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define HANDLE_DLG_WM_NCLBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnNCLButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define HANDLE_DLG_WM_NCLBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnNCLButtonUp(HWND hwnd, int x, int y, UINT codeHitTest) */
#define HANDLE_DLG_WM_NCLBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnNCRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define HANDLE_DLG_WM_NCRBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnNCRButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define HANDLE_DLG_WM_NCRBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnNCRButtonUp(HWND hwnd, int x, int y, UINT codeHitTest) */
#define HANDLE_DLG_WM_NCRBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnNCMButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define HANDLE_DLG_WM_NCMBUTTONDOWN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), FALSE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnNCMButtonDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT codeHitTest) */
#define HANDLE_DLG_WM_NCMBUTTONDBLCLK(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), TRUE, (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* void Cls_OnNCMButtonUp(HWND hwnd, int x, int y, UINT codeHitTest) */
#define HANDLE_DLG_WM_NCMBUTTONUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam), (UINT)(wParam)), FALSE)

/* int Cls_OnMouseActivate(HWND hwnd, HWND hwndTopLevel, UINT codeHitTest, UINT msg) */
#define HANDLE_DLG_WM_MOUSEACTIVATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))

/* void Cls_OnCancelMode(HWND hwnd) */
#define HANDLE_DLG_WM_CANCELMODE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnTimer(HWND hwnd, UINT id) */
#define HANDLE_DLG_WM_TIMER(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam)), FALSE)

/* void Cls_OnInitMenu(HWND hwnd, HMENU hMenu) */
#define HANDLE_DLG_WM_INITMENU(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam)), FALSE)

/* void Cls_OnInitMenuPopup(HWND hwnd, HMENU hMenu, UINT item, BOOL fSystemMenu) */
#define HANDLE_DLG_WM_INITMENUPOPUP(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HMENU)(wParam), (UINT)LOWORD(lParam), (BOOL)HIWORD(lParam)), FALSE)

/* void Cls_OnMenuSelect(HWND hwnd, HMENU hmenu, int item, HMENU hmenuPopup, UINT flags) */
#define HANDLE_DLG_WM_MENUSELECT(hwnd, wParam, lParam, fn)                  \
    ((fn)((hwnd), (HMENU)(lParam),  \
    (int)(LOWORD(wParam)),          \
    (HIWORD(wParam) & MF_POPUP) ? GetSubMenu((HMENU)lParam, LOWORD(wParam)) : FALSE, \
    (UINT)(((short)HIWORD(wParam) == -1) ? 0xFFFFFFFF : HIWORD(wParam))), FALSE)

/* DWORD Cls_OnMenuChar(HWND hwnd, UINT ch, UINT flags, HMENU hmenu) */
#define HANDLE_DLG_WM_MENUCHAR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(LOWORD(wParam)), (UINT)HIWORD(wParam), (HMENU)(lParam))

/* void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify) */
#define HANDLE_DLG_WM_COMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(LOWORD(wParam)), (HWND)(lParam), (UINT)HIWORD(wParam)), FALSE)

/* void Cls_OnHScroll(HWND hwnd, HWND hwndCtl, UINT code, int pos) */
#define HANDLE_DLG_WM_HSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(lParam), (UINT)(LOWORD(wParam)), (int)(short)HIWORD(wParam)), FALSE)

/* void Cls_OnVScroll(HWND hwnd, HWND hwndCtl, UINT code, int pos) */
#define HANDLE_DLG_WM_VSCROLL(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(lParam), (UINT)(LOWORD(wParam)),  (int)(short)HIWORD(wParam)), FALSE)

/* void Cls_OnCut(HWND hwnd) */
#define HANDLE_DLG_WM_CUT(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnCopy(HWND hwnd) */
#define HANDLE_DLG_WM_COPY(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnPaste(HWND hwnd) */
#define HANDLE_DLG_WM_PASTE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnClear(HWND hwnd) */
#define HANDLE_DLG_WM_CLEAR(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnUndo(HWND hwnd) */
#define HANDLE_DLG_WM_UNDO(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* HANDLE Cls_OnRenderFormat(HWND hwnd, UINT fmt) */
#define HANDLE_DLG_WM_RENDERFORMAT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HANDLE)(fn)((hwnd), (UINT)(wParam))

/* void Cls_OnRenderAllFormats(HWND hwnd) */
#define HANDLE_DLG_WM_RENDERALLFORMATS(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnDestroyClipboard(HWND hwnd) */
#define HANDLE_DLG_WM_DESTROYCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnDrawClipboard(HWND hwnd) */
#define HANDLE_DLG_WM_DRAWCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* void Cls_OnPaintClipboard(HWND hwnd, HWND hwndCBViewer, const LPPAINTSTRUCT lpPaintStruct) */
#define HANDLE_DLG_WM_PAINTCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const LPPAINTSTRUCT)GlobalLock((HGLOBAL)(lParam))), GlobalUnlock((HGLOBAL)(lParam)), FALSE)

/* void Cls_OnSizeClipboard(HWND hwnd, HWND hwndCBViewer, const LPRECT lprc) */
#define HANDLE_DLG_WM_SIZECLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (const LPRECT)GlobalLock((HGLOBAL)(lParam))), GlobalUnlock((HGLOBAL)(lParam)), FALSE)

/* void Cls_OnVScrollClipboard(HWND hwnd, HWND hwndCBViewer, UINT code, int pos) */
#define HANDLE_DLG_WM_VSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (int)(short)HIWORD(lParam)), FALSE)

/* void Cls_OnHScrollClipboard(HWND hwnd, HWND hwndCBViewer, UINT code, int pos) */
#define HANDLE_DLG_WM_HSCROLLCLIPBOARD(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (int)(short)HIWORD(lParam)), FALSE)

/* void Cls_OnAskCBFormatName(HWND hwnd, int cchMax, LPTSTR rgchName) */
#define HANDLE_DLG_WM_ASKCBFORMATNAME(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (LPTSTR)(lParam)), FALSE)

/* void Cls_OnChangeCBChain(HWND hwnd, HWND hwndRemove, HWND hwndNext) */
#define HANDLE_DLG_WM_CHANGECBCHAIN(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (HWND)(lParam)), FALSE)

/* BOOL Cls_OnSetCursor(HWND hwnd, HWND hwndCursor, UINT codeHitTest, UINT msg) */
#define HANDLE_DLG_WM_SETCURSOR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(BOOL)(fn)((hwnd), (HWND)(wParam), (UINT)LOWORD(lParam), (UINT)HIWORD(lParam))

/* void Cls_OnSysCommand(HWND hwnd, UINT cmd, int x, int y) */
#define HANDLE_DLG_WM_SYSCOMMAND(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (int)(short)LOWORD(lParam), (int)(short)HIWORD(lParam)), FALSE)

/* HWND Cls_MDICreate(HWND hwnd, const LPMDICREATESTRUCT lpmcs) */
#define HANDLE_DLG_WM_MDICREATE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (LPMDICREATESTRUCT)(lParam))

/* void Cls_MDIDestroy(HWND hwnd, HWND hwndDestroy) */
#define HANDLE_DLG_WM_MDIDESTROY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), FALSE)

/* NOTE: Usable only by MDI client windows */
/* void Cls_MDIActivate(HWND hwnd, BOOL fActive, HWND hwndActivate, HWND hwndDeactivate) */
#define HANDLE_DLG_WM_MDIACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (BOOL)(lParam == (LPARAM)hwnd), (HWND)(lParam), (HWND)(wParam)), FALSE)

/* void Cls_MDIRestore(HWND hwnd, HWND hwndRestore) */
#define HANDLE_DLG_WM_MDIRESTORE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), FALSE)

/* HWND Cls_MDINext(HWND hwnd, HWND hwndCur, BOOL fPrev) */
#define HANDLE_DLG_WM_MDINEXT(hwnd, wParam, lParam, fn) \
    (LRESULT)(HWND)(fn)((hwnd), (HWND)(wParam), (BOOL)lParam)

/* void Cls_MDIMaximize(HWND hwnd, HWND hwndMaximize) */
#define HANDLE_DLG_WM_MDIMAXIMIZE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam)), FALSE)

/* BOOL Cls_MDITile(HWND hwnd, UINT cmd) */
#define HANDLE_DLG_WM_MDITILE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))

/* BOOL Cls_MDICascade(HWND hwnd, UINT cmd) */
#define HANDLE_DLG_WM_MDICASCADE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(fn)((hwnd), (UINT)(wParam))

/* void Cls_MDIIconArrange(HWND hwnd) */
#define HANDLE_DLG_WM_MDIICONARRANGE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* HWND Cls_MDIGetActive(HWND hwnd) */
#define HANDLE_DLG_WM_MDIGETACTIVE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd)

/* HMENU Cls_MDISetMenu(HWND hwnd, BOOL fRefresh, HMENU hmenuFrame, HMENU hmenuWindow) */
#define HANDLE_DLG_WM_MDISETMENU(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)((hwnd), (BOOL)(wParam), (HMENU)(wParam), (HMENU)(lParam))

/* void Cls_OnChildActivate(HWND hwnd) */
#define HANDLE_DLG_WM_CHILDACTIVATE(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

/* BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam) */
#define HANDLE_DLG_WM_INITDIALOG(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HWND)(wParam), (lParam)) ? FALSE : TRUE) 

/* HWND Cls_OnNextDlgCtl(HWND hwnd, HWND hwndSetFocus, BOOL fNext) */
#define HANDLE_DLG_WM_NEXTDLGCTL(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HWND)(fn)((hwnd), (HWND)(wParam), (BOOL)(lParam))

/* void Cls_OnParentNotify(HWND hwnd, UINT msg, HWND hwndChild, int idChild) */
#define HANDLE_DLG_WM_PARENTNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)LOWORD(wParam), (HWND)(lParam), (UINT)HIWORD(wParam)), FALSE)

/* void Cls_OnEnterIdle(HWND hwnd, UINT source, HWND hwndSource) */
#define HANDLE_DLG_WM_ENTERIDLE(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (UINT)(wParam), (HWND)(lParam)), FALSE)

/* UINT Cls_OnGetDlgCode(HWND hwnd, LPMSG lpmsg) */
#define HANDLE_DLG_WM_GETDLGCODE(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(fn)(hwnd, (LPMSG)(lParam))

/* HBRUSH Cls_OnCtlColor(HWND hwnd, HDC hdc, HWND hwndChild, int type) */
#define HANDLE_DLG_WM_CTLCOLORMSGBOX(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_MSGBOX)

#define HANDLE_DLG_WM_CTLCOLOREDIT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_EDIT)

#define HANDLE_DLG_WM_CTLCOLORLISTBOX(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_LISTBOX)

#define HANDLE_DLG_WM_CTLCOLORBTN(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_BTN)

#define HANDLE_DLG_WM_CTLCOLORDLG(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_DLG)

#define HANDLE_DLG_WM_CTLCOLORSCROLLBAR(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_SCROLLBAR)

#define HANDLE_DLG_WM_CTLCOLORSTATIC(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HBRUSH)(fn)((hwnd), (HDC)(wParam), (HWND)(lParam), CTLCOLOR_STATIC)

/* void Cls_OnSetFont(HWND hwndCtl, HFONT hfont, BOOL fRedraw) */
#define HANDLE_DLG_WM_SETFONT(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (HFONT)(wParam), (BOOL)(lParam)), FALSE)

/* HFONT Cls_OnGetFont(HWND hwnd) */
#define HANDLE_DLG_WM_GETFONT(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(UINT)(HFONT)(fn)(hwnd)

/* void Cls_OnDrawItem(HWND hwnd, const DRAWITEMSTRUCT * lpDrawItem) */
#define HANDLE_DLG_WM_DRAWITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DRAWITEMSTRUCT *)(lParam)), FALSE)

/* void Cls_OnMeasureItem(HWND hwnd, MEASUREITEMSTRUCT * lpMeasureItem) */
#define HANDLE_DLG_WM_MEASUREITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (MEASUREITEMSTRUCT *)(lParam)), FALSE)

/* void Cls_OnDeleteItem(HWND hwnd, const DELETEITEMSTRUCT * lpDeleteItem) */
#define HANDLE_DLG_WM_DELETEITEM(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (const DELETEITEMSTRUCT *)(lParam)), FALSE)

/* int Cls_OnCompareItem(HWND hwnd, const COMPAREITEMSTRUCT * lpCompareItem) */
#define HANDLE_DLG_WM_COMPAREITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (const COMPAREITEMSTRUCT *)(lParam))

/* int Cls_OnVkeyToItem(HWND hwnd, UINT vk, HWND hwndListbox, int iCaret) */
#define HANDLE_DLG_WM_VKEYTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)LOWORD(wParam), (HWND)(lParam), (int)(short)HIWORD(wParam))

/* int Cls_OnCharToItem(HWND hwnd, UINT ch, HWND hwndListbox, int iCaret) */
#define HANDLE_DLG_WM_CHARTOITEM(hwnd, wParam, lParam, fn) \
    (LRESULT)(DWORD)(int)(fn)((hwnd), (UINT)LOWORD(wParam), (HWND)(lParam), (int)(short)HIWORD(wParam))

/* void Cls_OnQueueSync(HWND hwnd) */
#define HANDLE_DLG_WM_QUEUESYNC(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)

#if (WINVER >= 0x030a)
/* void Cls_OnCommNotify(HWND hwnd, int cid, UINT flags) */
#define HANDLE_DLG_WM_COMMNOTIFY(hwnd, wParam, lParam, fn) \
    ((fn)((hwnd), (int)(wParam), (UINT)LOWORD(lParam)), FALSE)
#endif

#define WM_PAINTDIALOG WM_USER + 0x500

/* void Cls_OnDialogPaint(HWND hwnd); */
#define HANDLE_DLG_WM_PAINTDIALOG(hwnd, wParam, lParam, fn) \
    ((fn)(hwnd), FALSE)
