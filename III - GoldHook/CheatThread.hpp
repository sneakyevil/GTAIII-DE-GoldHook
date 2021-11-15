DWORD m_dDummy = 0x0;

static void CheatThread()
{
	if (UI::Settings::Vehicle::m_iSpawn != 0)
	{
		static void* m_pCarID = reinterpret_cast<void*>(Game::Functions::m_uSpawnRhino + 0x6C);
		if (VirtualProtect(m_pCarID, 1, PAGE_EXECUTE_READWRITE, &m_dDummy))
		{
			*reinterpret_cast<unsigned char*>(m_pCarID) = static_cast<unsigned char>(UI::Settings::Vehicle::m_iSpawn);

			memset(Game::Globals::m_pSpawnRhino_Vehicle, 0, sizeof(uintptr_t));
			reinterpret_cast<void(__fastcall*)()>(Game::Functions::m_uSpawnRhino)();
			/*
			* Yes tho, its easy to call func with patched vehicle id to spawn then fucking reverse the whole shit...
			*/

			UI::Settings::Vehicle::m_iSpawn = 0;
		}
	}
}