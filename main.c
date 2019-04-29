#include <windows.h>


int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, 2);
	CopyMemory(GlobalLock(hMem), "\n", 2);
	GlobalUnlock(hMem);
	
	OpenClipboard(0);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
	
	MessageBox(NULL, TEXT("Done!"), TEXT("Message"), MB_OK);
	
	return 0;
}
