#pragma once
#include "CommonInclude.h"
#include "JaGameObject.h"


namespace Ja
{

	class Application
	{
	public:
		Application();
		~Application();

		void Intialize(HWND hwnd,UINT width,UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();


	private :
		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
		
		float mSpeed;
		
		GameObject mPlayer;


	};
}

