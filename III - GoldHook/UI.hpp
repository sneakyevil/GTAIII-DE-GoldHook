#pragma once
#pragma warning( disable : 4838 4309 )

#include <shellapi.h>
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")

#include "3rdParty/ImGui/imgui.h"
#include "3rdParty/ImGui/imgui_internal.h"
#include "3rdParty/ImGui/imgui_impl_dx11.h"
#include "3rdParty/ImGui/imgui_impl_win32.h"

namespace UI
{
    namespace Data
    {
        HWND m_hWindow = 0;
        ID3D11Device* m_pDevice = nullptr;
        ID3D11DeviceContext* m_pDeviceContext = nullptr;
        ID3D11RenderTargetView* m_pRenderTargetView = nullptr;
    }

    void InitColors()
    {
        ImGuiStyle& m_iStyle = ImGui::GetStyle();

        m_iStyle.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
        m_iStyle.Colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
        m_iStyle.Colors[ImGuiCol_WindowBg] = ImVec4(0.29f, 0.34f, 0.26f, 1.00f);
        m_iStyle.Colors[ImGuiCol_ChildBg] = ImVec4(0.29f, 0.34f, 0.26f, 1.00f);
        m_iStyle.Colors[ImGuiCol_PopupBg] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
        m_iStyle.Colors[ImGuiCol_Border] = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
        m_iStyle.Colors[ImGuiCol_BorderShadow] = ImVec4(0.14f, 0.16f, 0.11f, 0.52f);
        m_iStyle.Colors[ImGuiCol_FrameBg] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
        m_iStyle.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.27f, 0.30f, 0.23f, 1.00f);
        m_iStyle.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.30f, 0.34f, 0.26f, 1.00f);
        m_iStyle.Colors[ImGuiCol_TitleBg] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
        m_iStyle.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
        m_iStyle.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
        m_iStyle.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
        m_iStyle.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
        m_iStyle.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.28f, 0.32f, 0.24f, 1.00f);
        m_iStyle.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.25f, 0.30f, 0.22f, 1.00f);
        m_iStyle.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.23f, 0.27f, 0.21f, 1.00f);
        m_iStyle.Colors[ImGuiCol_CheckMark] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
        m_iStyle.Colors[ImGuiCol_SliderGrab] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
        m_iStyle.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
        m_iStyle.Colors[ImGuiCol_Button] = ImVec4(0.29f, 0.34f, 0.26f, 0.40f);
        m_iStyle.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
        m_iStyle.Colors[ImGuiCol_ButtonActive] = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
        m_iStyle.Colors[ImGuiCol_Header] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
        m_iStyle.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.35f, 0.42f, 0.31f, 0.6f);
        m_iStyle.Colors[ImGuiCol_HeaderActive] = ImVec4(0.54f, 0.57f, 0.51f, 0.50f);
        m_iStyle.Colors[ImGuiCol_Separator] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
        m_iStyle.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
        m_iStyle.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
        m_iStyle.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.19f, 0.23f, 0.18f, 0.00f);
        m_iStyle.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.54f, 0.57f, 0.51f, 1.00f);
        m_iStyle.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
        m_iStyle.Colors[ImGuiCol_Tab] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
        m_iStyle.Colors[ImGuiCol_TabHovered] = ImVec4(0.54f, 0.57f, 0.51f, 0.78f);
        m_iStyle.Colors[ImGuiCol_TabActive] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
        m_iStyle.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.24f, 0.27f, 0.20f, 1.00f);
        m_iStyle.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.35f, 0.42f, 0.31f, 1.00f);
        m_iStyle.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
        m_iStyle.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
        m_iStyle.Colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.78f, 0.28f, 1.00f);
        m_iStyle.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
        m_iStyle.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
        m_iStyle.Colors[ImGuiCol_DragDropTarget] = ImVec4(0.73f, 0.67f, 0.24f, 1.00f);
        m_iStyle.Colors[ImGuiCol_NavHighlight] = ImVec4(0.59f, 0.54f, 0.18f, 1.00f);
        m_iStyle.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
        m_iStyle.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
        m_iStyle.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

        m_iStyle.FrameBorderSize = 1.f;
        m_iStyle.WindowRounding = 0.f;
        m_iStyle.ChildRounding = 0.f;
        m_iStyle.FrameRounding = 0.f;
        m_iStyle.PopupRounding = 0.f;
        m_iStyle.ScrollbarRounding = 0.f;
        m_iStyle.GrabRounding = 0.f;
        m_iStyle.TabRounding = 0.f;
    }

    bool m_bInit = true;
    void Init(IDXGISwapChain* m_pSwap)
    {
        ImGui::CreateContext();

        m_pSwap->GetDevice(__uuidof(Data::m_pDevice), reinterpret_cast<void**>(&(Data::m_pDevice)));
        Data::m_pDevice->GetImmediateContext(&Data::m_pDeviceContext);

        ID3D11Texture2D* m_pRenderTargetTexture = nullptr;
        if (SUCCEEDED(m_pSwap->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&m_pRenderTargetTexture))))
        {
            Data::m_pDevice->CreateRenderTargetView(m_pRenderTargetTexture, nullptr, &Data::m_pRenderTargetView);
            m_pRenderTargetTexture->Release();
        }

        ImGui_ImplWin32_Init(Data::m_hWindow);
        ImGui_ImplDX11_Init(Data::m_pDevice, Data::m_pDeviceContext);
        ImGui_ImplDX11_CreateDeviceObjects();

        InitColors();
        ImGuiIO& m_iIO = ImGui::GetIO();
        m_iIO.IniFilename = PROJECT_NAME".ini";
        m_iIO.LogFilename = 0;
        m_iIO.MouseDrawCursor = true;
    }

    namespace Settings
    {
        namespace Local
        {
            bool m_bSemiGodMode = false;
            bool m_bUnlockAllCars = false;
        }

        namespace Vehicle
        {
            int m_iSpawn = 0;

            bool m_bLockOurCar = false;
        }
    }

    void GameUpdate()
    {
        static bool m_bFlip = false; m_bFlip = !m_bFlip;
        if (!m_bFlip) // Save one frame of pure shit
            return;
        
        if (Settings::Local::m_bSemiGodMode)
        {
            Game::m_pPlayers->m_pLocal->m_fHealth = 100.f;

            if (Game::m_pPlayers->m_pLocal->m_bInCar && Game::m_pPlayers->m_pLocal->m_pVehicle)
                Game::m_pPlayers->m_pLocal->m_pVehicle->m_fHealth = 1000.f;
        }

        if (Settings::Local::m_bUnlockAllCars)
        {
            if (Game::m_pPlayers->m_pLocal->m_pVehicle && !Game::m_pPlayers->m_pLocal->m_bInCar)
                Game::m_pPlayers->m_pLocal->m_pVehicle->m_uCarLock = 1Ui8;
        }

        if (Game::m_pPlayers->m_pLocal->m_bInCar && Game::m_pPlayers->m_pLocal->m_pVehicle)
        {
            if (Settings::Vehicle::m_bLockOurCar)
                Game::m_pPlayers->m_pLocal->m_pVehicle->m_uCarLock = 2Ui8;
        }
    }

    bool m_bOpen = true;
    bool m_bIsLoaded = true;
    typedef long(__stdcall* m_tPresent)(IDXGISwapChain*, UINT, UINT); m_tPresent m_oPresent;
    long __stdcall Present(IDXGISwapChain* m_pSwap, UINT m_uSync, UINT m_uFlags)
    {
        if (m_bInit)
        {
            Init(m_pSwap);
            m_bInit = false;
        }

        bool m_bLocalValid = Game::m_pPlayers->m_pLocal != nullptr;
        if (m_bLocalValid)
            GameUpdate();

        if (m_bOpen)
        {
            ImGui_ImplDX11_NewFrame();
            ImGui_ImplWin32_NewFrame();
            ImGui::NewFrame();

            ImGui::SetNextWindowSize(ImVec2(300.f, 160.f));
            ImGui::SetNextWindowPos(ImVec2(0.f, 0.f), ImGuiCond_FirstUseEver);
            if (ImGui::Begin(PROJECT_NAME, &m_bIsLoaded, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
            {
                static const char* m_pTabs[] = { "Local", "Vehicle" };
                if (ImGui::BeginTabBar("##TabBar", ImGuiTabBarFlags_NoTooltip | ImGuiTabBarFlags_FittingPolicyScroll))
                {
                    int m_iTabs = sizeof(m_pTabs) / sizeof(m_pTabs[0]);
                    for (int i = 0; m_iTabs > i; ++i)
                    {
                        if (ImGui::BeginTabItem(m_pTabs[i]))
                        {
                            if (ImGui::BeginChild("##TabChild", ImVec2(0.f, 0.f), true))
                            {
                                switch (i)
                                {
                                    case 0:
                                    {
                                        if (ImGui::Button("Give Health") && m_bLocalValid)
                                            Game::m_pPlayers->m_pLocal->m_fHealth = 100.f;

                                        ImGui::SameLine();

                                        if (ImGui::Button("Give Armor") && m_bLocalValid)
                                            Game::m_pPlayers->m_pLocal->m_fArmor = 100.f;

                                        ImGui::Checkbox("Semi-God Mode", &Settings::Local::m_bSemiGodMode);
                                        ImGui::Checkbox("Unlock All Cars", &Settings::Local::m_bUnlockAllCars);

                                        static int m_iWantedLevel = 0;
                                        if (m_bLocalValid)
                                            m_iWantedLevel = static_cast<int>(Game::m_pPlayers->m_pLocal->m_pWantedLevel->m_uWantedLevel);

                                        ImGui::SetNextItemWidth(128.f);
                                        if (ImGui::SliderInt("Wanted Level", &m_iWantedLevel, 0, 6) && m_bLocalValid)
                                            reinterpret_cast<void(__fastcall*)(void*, int)>(Game::Functions::m_uUpdateWantedLevel)(Game::m_pPlayers->m_pLocal->m_pWantedLevel, m_iWantedLevel);
                                    }
                                    break;
                                    case 1:
                                    {
                                        static const char* m_pVehicles[] = { "Landstalker", "Idaho", "Stinger", "Linerunner", "Perennial", "Sentinel", "Patriot", "Fire Truck", "Trashmaster", "Stretch", "Manana", "Infernus", "Blista", "Pony", "Mule", "Cheetah", "Ambulance", "FBI Car", "Moonbeam", "Esperanto", "Taxi", "Kuruma", "Bobcat", "Mr. Whoopee", "BF Injection", "Manana - Corpse", "Police Car", "Enforcer", "Securicar", "Banshee", "Predator", "Bus", "Rhino", "Barracks OL", "Train", "Dodo", "Coach", "Cabbie", "Stallion", "Rumpo", "RC Bandit", "BellyUp", "Mr. Wongs", "Mafia Sentinel", "Yardie Lobo", "Yakuza Stinger", "Diablo Stallion", "Cartel Cruiser", "Hoods Rumpo XL", "Air Train", "Dead Dodo", "Speeder", "Reefer", "Panlantic", "Flatbed", "Yankee", "Borgnine Taxi", "Toyz Van", "Ghost" };
                                        static int m_iVehicleSpawn = 0;
                                        ImGui::Combo("##VehicleSpawn", &m_iVehicleSpawn, m_pVehicles, IM_ARRAYSIZE(m_pVehicles));
                                        ImGui::SameLine();
                                        if (ImGui::Button("Spawn") && m_bLocalValid)
                                        {
                                            static int m_iVehicleIDs[] = { 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 148, 149, 150 };
                                            Settings::Vehicle::m_iSpawn = m_iVehicleIDs[m_iVehicleSpawn];
                                        }

                                        if (ImGui::Button("Repair") && m_bLocalValid)
                                        {
                                            if (Game::m_pPlayers->m_pLocal->m_bInCar && Game::m_pPlayers->m_pLocal->m_pVehicle)
                                            {
                                                Game::m_pPlayers->m_pLocal->m_pVehicle->m_fHealth = 1000.f;
                                                reinterpret_cast<void(__fastcall*)(void*)>(Game::Functions::m_uFixDamagedVehicle)(Game::m_pPlayers->m_pLocal->m_pVehicle);
                                            }
                                        }

                                        ImGui::Checkbox("Lock Our Car", &Settings::Vehicle::m_bLockOurCar);
                                    }
                                    break;
                                }

                                ImGui::EndChild();
                            }

                            ImGui::EndTabItem();
                        }
                    }

                    ImGui::EndTabBar();
                }

                ImGui::End();
            }

            ImGui::EndFrame();
            ImGui::Render();
            Data::m_pDeviceContext->OMSetRenderTargets(1, &Data::m_pRenderTargetView, 0);
            ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
        }

        return m_oPresent(m_pSwap, m_uSync, m_uFlags);
    }
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
namespace UI_WndProc
{
    int m_iForceCheatHandle = 0;

    typedef LRESULT(__stdcall* m_tHook)(HWND, UINT, WPARAM, LPARAM); m_tHook m_oHook;
    LRESULT __stdcall Hook(const HWND m_hWindow, UINT m_uMsg, WPARAM m_wParam, LPARAM m_lParam)
    {
        if (m_iForceCheatHandle > 0)
        {
            CallWindowProcA(m_oHook, m_hWindow, WM_KEYDOWN, VK_END, 0);
            CallWindowProcA(m_oHook, m_hWindow, WM_KEYUP, VK_END, 0);
            m_iForceCheatHandle--;
        }

        ImGui_ImplWin32_WndProcHandler(m_hWindow, m_uMsg, m_wParam, m_lParam);

        if (m_uMsg == WM_KEYUP && m_wParam == VK_INSERT)
            UI::m_bOpen = !UI::m_bOpen;

        if (UI::m_bOpen)
        {
            if (m_uMsg == WM_LBUTTONUP)
                m_iForceCheatHandle = 10;

            return 1;
        }

        return CallWindowProcA(m_oHook, m_hWindow, m_uMsg, m_wParam, m_lParam);
    }
}