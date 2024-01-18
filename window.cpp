#include "window.h"

Ventana::WindowClass Ventana::WindowClass::wndClass;

const wchar_t* Ventana::WindowClass::GetName() noexcept
{
    return L"Katiowa Direct3D Engine Ventana";
}

HINSTANCE Ventana::WindowClass::GetInstance() noexcept
{
    return wndClass.hInst;
}

Ventana::WindowClass::WindowClass() noexcept
    : hInst(GetModuleHandle(nullptr))
{
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(wc);
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = HandleMsgSetup;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = GetInstance();
    wc.hIcon = nullptr;
    wc.hCursor = nullptr;
    wc.hbrBackground = nullptr;
    wc.lpszMenuName = nullptr;
    wc.lpszClassName = GetName();
    wc.hIconSm = nullptr;
    RegisterClassEx(&wc);
}

Ventana::WindowClass::~WindowClass()
{
    UnregisterClass(GetName(), GetInstance());
}

Ventana::Ventana(int ancho, int alto, const char* Nombre) noexcept
    : ancho(ancho), alto(alto)
{
    RECT wr;
    wr.left = 100;
    wr.right = ancho + wr.left;
    wr.top = 100;
    wr.bottom = alto + wr.top;
    AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE);

    // Create Window
    hWnd = CreateWindow(
        WindowClass::GetName(),
        L"Katiowa Direct3D Engine Ventana",
        WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
        CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top,
        nullptr, nullptr, WindowClass::GetInstance(), this
    );

    // Show Window
    ShowWindow(hWnd, SW_SHOWDEFAULT);
}

Ventana::~Ventana()
{
    DestroyWindow(hWnd);
}

LRESULT CALLBACK Ventana::HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (msg == WM_NCCREATE)
    {
        const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
        Ventana* const pWnd = static_cast<Ventana*>(pCreate->lpCreateParams);
        SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
        SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Ventana::HandleMsgThunk));
        return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK Ventana::HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    Ventana* const pWnd = reinterpret_cast<Ventana*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
    return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
}

LRESULT Ventana::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept
{
    switch (msg)
    {
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hWnd, msg, wParam, lParam);
}
