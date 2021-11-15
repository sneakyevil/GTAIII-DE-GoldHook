#pragma once

namespace Hooks
{
	typedef int(__fastcall* m_tSetCursorPos)(int, int); m_tSetCursorPos m_oSetCursorPos;
	int __fastcall SetCursorPos(int X, int Y)
	{
		if (UI::m_bOpen) return 1;

		return m_oSetCursorPos(X, Y);
	}

	namespace GameFunctions
	{
		typedef int(__fastcall* m_tCheatHandle)(void*, char, char); m_tCheatHandle m_oCheatHandle;
		int __fastcall CheatHandle(void* ecx, char c1, char c2)
		{
			CheatThread();
			return m_oCheatHandle(ecx, c1, c2);
		}
	}
}