#pragma once
#include "katioWin.h"

class Ventana
{
private:
    class WindowClass
    {
    public:
        static const wchar_t* GetName() noexcept;
        static HINSTANCE GetInstance() noexcept;
    private:
        WindowClass() noexcept;
        ~WindowClass() noexcept;
        WindowClass(const WindowClass&) = delete;
        WindowClass& operator=(const WindowClass&) = delete;
        static WindowClass wndClass;
        HINSTANCE hInst;
    };

public:
    Ventana(int ancho, int alto, const char* Nombre) noexcept;
    ~Ventana();
    Ventana(const Ventana&) = delete;
    Ventana& operator=(const Ventana&) = delete;

private:
    static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) noexcept;

private:
    int ancho;
    int alto;
    HWND hWnd;
};