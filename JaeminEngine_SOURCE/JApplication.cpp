#include "JApplication.h"
#include "JaInput.h"
#include "JaTime.h"

namespace Ja
{

	Application::Application()
		: mHwnd(nullptr)
		,mHdc(nullptr)
		,mSpeed(0.0f)
		,mWidth(0)
		,mHeight(0)
		, mBackHdc(NULL)
		,mBackBitmap(NULL)

	{

	}
	Application ::~Application()
	{

	}

	
	void Application::Intialize(HWND hwnd,UINT width,UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0 , width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false); //상단바 메뉴

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, rect.right - rect.left, rect.bottom - rect.top, 0);

		ShowWindow(mHwnd,true);

		//윈도우 해상도에 맞는 백버퍼(도화지)생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		
		//백버퍼를 가르킬 dc생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0, 0);
		Input::Initailize();
		Time::Initailize();
	}
	
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		mPlayer.Update();
		Input::Update();
		Time::Update();

		
	}

	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		/// Backbuffer에 있는걸 원본에 복사하여 쓴다
		BitBlt(mHdc, 0, 0, mWidth , mHeight  , mBackHdc, 0, 0, SRCCOPY);

	}

}