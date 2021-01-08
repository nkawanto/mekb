#include <windows.h>

HHOOK hHook;

LRESULT CALLBACK LowLevelKeyboardProc( int nCode, WPARAM wParam, LPARAM lParam )
{
    if (nCode < 0 || nCode != HC_ACTION )  // do not process message 
        return CallNextHookEx( g_hKeyboardHook, nCode, wParam, lParam); 
 
    KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
    switch (wParam)
    {
        case WM_KEYDOWN:
        case WM_KEYUP:
        {
            cout << p->vkCode << " key\n";
            break;
        }
    }
    return CallNextHookEx( g_hKeyboardHook, nCode, wParam, lParam );
}