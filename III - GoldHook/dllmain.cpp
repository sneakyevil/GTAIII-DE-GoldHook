#define PROJECT_NAME "GoldHook"

#include <intrin.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Psapi.h>
#include <string>
#include <vector>
#include "3rdParty/MinHook.h"

#include "GameSDK.hpp"
#include "UI.hpp"
#include "CheatThread.hpp"
#include "Hooks.hpp"

namespace Hook
{
    void Add(uintptr_t m_uAddress, void* m_pHook, void** m_pOriginal = nullptr)
    {
        void* m_pFunction = reinterpret_cast<void*>(m_uAddress);
        MH_CreateHook(m_pFunction, m_pHook, m_pOriginal);
        MH_EnableHook(m_pFunction);
    }

    void AddExport(const char* m_pModule, const char* m_pName, void* m_pHook, void** m_pOriginal = nullptr)
    {
        HMODULE m_hModule = GetModuleHandleA(m_pModule);
        if (!m_hModule)
            return;

        uintptr_t m_uFunction = reinterpret_cast<uintptr_t>(GetProcAddress(m_hModule, m_pName));
        if (!m_uFunction)
            return;

        Add(m_uFunction, m_pHook, m_pOriginal);
    }
}

uintptr_t GetPresentAddress()
{
    DXGI_SWAP_CHAIN_DESC m_dSwapChainDesc;
    RtlZeroMemory(&m_dSwapChainDesc, sizeof(m_dSwapChainDesc));

    m_dSwapChainDesc.BufferCount = 2;
    m_dSwapChainDesc.BufferDesc.Width = 0;
    m_dSwapChainDesc.BufferDesc.Height = 0;
    m_dSwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    m_dSwapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
    m_dSwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
    m_dSwapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
    m_dSwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    m_dSwapChainDesc.OutputWindow = UI::Data::m_hWindow;
    m_dSwapChainDesc.SampleDesc.Count = 1;
    m_dSwapChainDesc.SampleDesc.Quality = 0;
    m_dSwapChainDesc.Windowed = TRUE;
    m_dSwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;

    const D3D_FEATURE_LEVEL m_dFeatureLevel[1] = { D3D_FEATURE_LEVEL_11_0 };
    IDXGISwapChain* m_pSwapChain = nullptr;
    if (D3D11CreateDeviceAndSwapChain(0, D3D_DRIVER_TYPE_HARDWARE, 0, 0, m_dFeatureLevel, 1, D3D11_SDK_VERSION, &m_dSwapChainDesc, &m_pSwapChain, &UI::Data::m_pDevice, nullptr, &UI::Data::m_pDeviceContext) != S_OK)
        return 0ULL;

    void** m_pVTable = *reinterpret_cast<void***>(m_pSwapChain);
    m_pSwapChain->Release();

    return reinterpret_cast<uintptr_t>(m_pVTable[8]);
}

DWORD __stdcall Thread(void* m_pReserved)
{
    UI::Data::m_hWindow = FindWindowA("UnrealWindow", 0);
    if (UI::Data::m_hWindow)
    {
        uintptr_t m_uPresentAddress = GetPresentAddress();
        if (m_uPresentAddress)
        {
            MH_Initialize();

            UI_WndProc::m_oHook = WNDPROC(SetWindowLongPtrA(UI::Data::m_hWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&UI_WndProc::Hook)));
            Hook::Add(m_uPresentAddress, UI::Present, (void**)&UI::m_oPresent);

            Hook::AddExport("user32", "SetCursorPos", Hooks::SetCursorPos, (void**)&Hooks::m_oSetCursorPos);
            Hook::Add(Game::Functions::m_uCheatHandle, Hooks::GameFunctions::CheatHandle, (void**)&Hooks::GameFunctions::m_oCheatHandle);

            while (1)
            {
                if (!UI::m_bIsLoaded) break;

                Sleep(1);
            }

            MH_DisableHook(MH_ALL_HOOKS);
            SetWindowLongPtrA(UI::Data::m_hWindow, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(UI_WndProc::m_oHook));

            MH_Uninitialize();
        }
        else
            MessageBoxA(0, "Bruh, we couldn't hook UI... (Make sure your game runs under DX11)", PROJECT_NAME, MB_OK | MB_ICONERROR);
    }
    else
        MessageBoxA(0, "Bruh, the fucking game window wasn't found...", PROJECT_NAME, MB_OK | MB_ICONERROR);

    if (UI::Data::m_pDevice)
    {
        ImGui_ImplDX11_Shutdown();
        ImGui_ImplWin32_Shutdown();
        ImGui::DestroyContext();

        Sleep(100);
    }

    FreeLibraryAndExitThread(reinterpret_cast<HMODULE>(m_pReserved), 0x0);
    return 0x0;
}

int __stdcall DllMain(HMODULE m_hModule, DWORD m_dCall, void* m_pReserved)
{
    if (m_dCall == DLL_PROCESS_ATTACH)
    {
        CreateThread(0, 0, Thread, m_hModule, 0, 0);
    }

    return 1;
}