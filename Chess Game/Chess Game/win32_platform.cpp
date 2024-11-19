#include <windows.h>
#include <iostream>
#include "utilities.cpp"
using namespace std;

bool running = true;

struct renderState {
	int height, width;
	void* memory;

	BITMAPINFO bitmapInfo;
};

renderState currentRenderState;

#include "renderer.cpp"
#include "chess_piece.cpp"

LRESULT CALLBACK windowCallback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0;

	switch (uMsg) {
		case WM_CLOSE:
		case WM_DESTROY:
		{
			running = false;
		}	break;
		case WM_SIZE:
		{
			RECT rect;
			GetClientRect(hwnd, &rect);
			currentRenderState.width = rect.right - rect.left;
			currentRenderState.height = rect.bottom - rect.top;

			int bufferSize = currentRenderState.width * currentRenderState.height * sizeof(unsigned int);

			if (currentRenderState.memory) {
				VirtualFree(currentRenderState.memory, 0, MEM_RELEASE);
			}

			currentRenderState.memory = VirtualAlloc(0, bufferSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

			currentRenderState.bitmapInfo.bmiHeader.biSize = sizeof(currentRenderState.bitmapInfo.bmiHeader);
			currentRenderState.bitmapInfo.bmiHeader.biWidth = currentRenderState.width;
			currentRenderState.bitmapInfo.bmiHeader.biHeight = currentRenderState.width;
			currentRenderState.bitmapInfo.bmiHeader.biPlanes = 1;
			currentRenderState.bitmapInfo.bmiHeader.biBitCount = 32;
			currentRenderState.bitmapInfo.bmiHeader.biCompression = BI_RGB;


		}	break;
		default:
		{
			result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}

	return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	WNDCLASS windowClass = {};
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpszClassName = L"Chess";
	windowClass.lpfnWndProc = windowCallback;

	RegisterClass(&windowClass);
	
	HWND window = CreateWindow(windowClass.lpszClassName, L"Chess Game", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 600, 600, 0, 0, hInstance, 0);
	HDC hdc = GetDC(window);

	while (running == true) {
		//-- Input --//
		MSG message;

		while (PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		//-- Simulate --//
		// Grid
		clearScreen(0x000000);

		double gridSpaces = 8.0;
		double borderOffset = 0.001;

		for (int gridSpaceY = 0; gridSpaceY < gridSpaces; gridSpaceY++) {
			for (int gridSpaceX = 0; gridSpaceX < gridSpaces; gridSpaceX++) {
				int color = ((gridSpaceX + gridSpaceY) % 2 == 0) ? 0x4d4d4d : 0xc8c8c8;

				drawRectByScreenSize(
					gridSpaceX / gridSpaces + borderOffset, 
					gridSpaceY / gridSpaces + borderOffset, 
					(gridSpaceX + 1) / gridSpaces - borderOffset, 
					(gridSpaceY + 1) / gridSpaces - borderOffset, 
					color
				);
			}
		}

		//-- Render --//
		StretchDIBits(hdc, 0, 0, currentRenderState.width, currentRenderState.height, 0, 0, currentRenderState.width, currentRenderState.height, currentRenderState.memory, &currentRenderState.bitmapInfo, DIB_RGB_COLORS, SRCCOPY);
	}

	return 0;
};