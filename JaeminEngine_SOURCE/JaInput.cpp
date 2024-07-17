#include "JaInput.h"


namespace Ja
{
	std::vector<Input::Key>Input::keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R' , 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M', 
		VK_LEFT,VK_RIGHT,VK_DOWN,VK_UP,
	};

	void Input::Initailize()
	{

		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.State = eKeyState::None;
			key.keyCode = (eKeyCode)i;
			keys.push_back(key);
		}

	}
	
	

	void Input::Update()
	{
		for (size_t i = 0; i < keys.size(); i++)
		{
			//키가눌림
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (keys[i].bPressed == true)
				{
					keys[i].State = eKeyState::Pressed;
				}
				else
				{
					keys[i].State = eKeyState::Down;
				}
				keys[i].bPressed = true;

			}
			//키가 안눌림
			else
			{   //딸각 업
				if (keys[i].bPressed == true)
				{
					keys[i].State = eKeyState::Up;
				}
				else // 아무것도 변화가없음
				{
					keys[i].State = eKeyState::None;
				}
				keys[i].bPressed = false;
			}
		}
	}

	
}
