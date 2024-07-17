#pragma once
#include "CommonInclude.h"

namespace Ja
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};


	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, Left, Right , Down, UP,
		End,
	};
	class Input
	{


	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState State;
			bool bPressed;
		};

		static void Initailize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return keys[(UINT)code].State == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return keys[(UINT)code].State == eKeyState::Up;  }
		static bool GetKey(eKeyCode code) { return keys[(UINT)code].State == eKeyState::Pressed; }


	private:
	


		static std::vector<Key> keys;

	};

}

