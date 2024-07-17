#include "JaGameObject.h"
#include "JaInput.h"
#include "JaTime.h"


namespace Ja
{
	GameObject::GameObject()
	{
		
	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
			//
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
		}
		//skdfjlsdfjsdlkj
	}

	void GameObject::LateUdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255)); // ÆÄ¶û »ý¼º

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));

		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 +mX, 100 +mY, 200 +mX, 200 +mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
		DeleteObject(redPen);

	}
}



