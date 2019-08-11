#include "Controller.h"

Controller* Controller::ptr = nullptr;

Controller::Controller(HINSTANCE& hInst)
{
	ptr = this;
}


BOOL Controller::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	//загрузка иконки
	HICON hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
	if (hIcon)
		SetClassLong(hwnd, GCL_HICON, (LONG)hIcon);

	editRows = GetDlgItem(hwnd, IDC_EDIT_ROWS);
	editCols = GetDlgItem(hwnd, IDC_EDIT_COLS);

	spinRows = GetDlgItem(hwnd, IDC_SPIN_ROWS);
	spinCols = GetDlgItem(hwnd, IDC_SPIN_COLS);

	buttonStart = GetDlgItem(hwnd, IDC_BUTTON_START);

	//установка диапазона для spin
	SNDMSG(spinRows, UDM_SETRANGE, 0, 9999);
	SNDMSG(spinCols, UDM_SETRANGE, 0, 9999);

	//установка лимита на длину текста
	Edit_LimitText(editRows, 4);
	Edit_LimitText(editCols, 4);

	//текст по умолчанию
	Edit_SetText(editRows, "20");
	Edit_SetText(editCols, "20");

	return TRUE;
}

VOID Controller::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

VOID Controller::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
	switch (id)
	{
		case IDC_BUTTON_START:
		{
			//выключение кнопки на время выполнения кода
			Button_Enable(buttonStart, FALSE);

			TCHAR buf[5]{};


			Edit_GetText(editRows, buf, 4);

			//int rows = atoi(buf);
			long rows = atol(buf);
			//int или long как удобнее

			Edit_GetText(editCols, buf, 4);
			//int cols = atoi(buf);
			long cols = atol(buf);

			//твой код после нажатия на кнопку////////


			/////////////////

			//
			Button_Enable(buttonStart, TRUE);
		}
		break;
	}
}







BOOL Controller::DlgProc(HWND hWnd, UINT mes, WPARAM wParam, LPARAM lParam)
{
	switch (mes)
	{
		HANDLE_MSG(hWnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hWnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hWnd, WM_COMMAND, ptr->Cls_OnCommand);

	}
	return FALSE;
}

