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
			//Ű������
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
			//Ű�� �ȴ���
			else
			{   //���� ��
				if (keys[i].bPressed == true)
				{
					keys[i].State = eKeyState::Up;
				}
				else // �ƹ��͵� ��ȭ������
				{
					keys[i].State = eKeyState::None;
				}
				keys[i].bPressed = false;
			}
		}
	}

	
}
