#include <windows.h>
// #include <stdio.h>
#include <iostream>

HHOOK hHook;
// https://stackoverflow.com/questions/25450168/setwindowshookex-freezes-on-fast-input-or-keyboard-button-hold
// TODO: unstuck SetWindowsHookEx, duplicate keyup callbacks
// TODO: remember last key states?
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode < 0 || nCode != HC_ACTION )  // do not process message 
        return CallNextHookEx(hHook, nCode, wParam, lParam); 
 
    KBDLLHOOKSTRUCT* p = (KBDLLHOOKSTRUCT*)lParam;
    switch (wParam)
    {
        case WM_KEYDOWN:
        case WM_KEYUP:
        {
            std::cout << p->vkCode << " key\n";
            break;
        }
    }
    return CallNextHookEx(hHook, nCode, wParam, lParam );
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  hHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, hInstance, 0);
  MSG msg;
  while(GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return msg.wParam;
}