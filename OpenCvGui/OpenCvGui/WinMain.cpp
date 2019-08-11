#include "Controller.h"

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpszCmdLine, int nCmdShow)
{
	Controller dlg(hInst);

	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG_MAIN), NULL, (DLGPROC)Controller::DlgProc);
}