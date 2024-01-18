#include "window.h"

int CALLBACK WinMain
(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)
{
    Ventana ventana(800, 400, "NOse");

    MSG msg;
    BOOL gResult;

    while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    if (gResult == -1)
    {
        return -1;
    }

    return msg.wParam;
}
