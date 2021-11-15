#pragma once

namespace SDK
{
	namespace Math
	{
		class CVector3
		{
		public:
			float x, y, z;
		};
	}

	namespace Player
	{
		class CWantedLevel
		{
		public:
			int m_iChaos;
			char m_cPad0[0x8];
			float m_fCrimeSensitivity;
			char m_cPad1[0x8];
			unsigned char m_uWantedLevel;
		};
	}

	class CEntity
	{
	public:
		char m_cEntityPad[0x38];
		Math::CVector3 m_vPosition;
	};

	class CVehicle : CEntity
	{
	public:
		char m_cPad0[0x2DC];
		float m_fHealth;
		unsigned char m_uCurrentGear;
		char m_cPad1[0x23];
		unsigned char m_uCarLock;
	};

	class CPed : CEntity
	{
	public:
		char m_cPad0[0x3E4];
		float m_fHealth;
		float m_fArmor;
		char m_cPad1[0x60];
		CVehicle* m_pVehicle;
		bool m_bInCar;
		char m_cPad2[0x30F];
		Player::CWantedLevel* m_pWantedLevel;

	};

	class CPlayers
	{
	public:
		CPed* m_pLocal;
		CPed* m_pReplay;
	};
}

namespace Game
{
	static uintptr_t m_uBase = reinterpret_cast<uintptr_t>(GetModuleHandleA(0));
	static SDK::CPlayers* m_pPlayers = reinterpret_cast<SDK::CPlayers*>(m_uBase + 0x4C01710);

	namespace Functions
	{
		static uintptr_t m_uSpawnRhino = m_uBase + 0xF07A00;
		static uintptr_t m_uCheatHandle = m_uBase + 0xF0C5C0;
		static uintptr_t m_uUpdateWantedLevel = m_uBase + 0xF28160;
		static uintptr_t m_uFixDamagedVehicle = m_uBase + 0xFCE240;
	}

	namespace Globals
	{
		static void* m_pSpawnRhino_Vehicle = reinterpret_cast<void*>(m_uBase + 0x522C0A8);
	}
}