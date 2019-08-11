#pragma once
#include "Header.h"

class Controller
{
private:
	HWND editRows;
	HWND editCols;

	HWND spinRows;
	HWND spinCols;

	HWND buttonStart;
public:
	Controller(HINSTANCE& hInst);
	static Controller* ptr;
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wParam, LPARAM lParam);

	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	VOID Cls_OnClose(HWND hwnd);
	VOID Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
};