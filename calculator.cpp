#include <windows.h>
#include<cstdlib>
#include <stdio.h>
/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND, UINT,WPARAM,LPARAM);
HWND textf,button1,b2,b3,b4,box1,box2; 
char text1[20],text2[20];
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_CREATE:

			textf = CreateWindow("STATIC","Please input two numbers ",WS_VISIBLE | WS_CHILD | WS_BORDER,20,20,200,20,hwnd,NULL,NULL,NULL);
			
			box1= CreateWindow("EDIT","",WS_VISIBLE | WS_CHILD|WS_BORDER,60,45,100,20,hwnd,NULL,NULL,NULL);
			box2= CreateWindow("EDIT","",WS_VISIBLE | WS_CHILD|WS_BORDER,60,75,100,20,hwnd,NULL,NULL,NULL);
			button1 = CreateWindow("Button","+",WS_VISIBLE | WS_CHILD|WS_BORDER,20,120,20,20,hwnd,(HMENU) 1,NULL,NULL);
			b2=	CreateWindow("Button","-",WS_VISIBLE | WS_CHILD|WS_BORDER,60,120,20,20,hwnd,(HMENU) 2,NULL,NULL);
			b3=	CreateWindow("Button","*",WS_VISIBLE | WS_CHILD|WS_BORDER,100,120,20,20,hwnd,(HMENU) 3,NULL,NULL);
			b4=	CreateWindow("Button","/",WS_VISIBLE | WS_CHILD|WS_BORDER,140,120,20,20,hwnd,(HMENU) 4,NULL,NULL);
			
			break;
		case WM_COMMAND:
			switch(LOWORD(wParam)){
				case 1:
				int inp1;
				int inp2;
				double n1;
				double n2;
				inp1= GetWindowText(box1, &text1[0],20);
				inp2= GetWindowText(box2, &text2[0],20);
				n1 = atof(text1);
				n2 = atof(text2);
				char p[100];
				sprintf(p, "%f", n1+n2);
				
				::MessageBox(hwnd,p,"Result",MB_OK);

			break;
				case 2:
				int inpa1;
				int inpa2;
				double na1;
				double na2;
				inpa1= GetWindowText(box1, &text1[0],20);
				inpa2= GetWindowText(box2, &text2[0],20);
				na1 = atof(text1);
				na2 = atof(text2);
				char m[100];
				sprintf(m, "%f", na1-na2);
				
				::MessageBox(hwnd,m,"Result",MB_OK);	

			break;
				case 3:
				int inpu1;
				int inpu2;
				double nu1;
				double nu2;
				inpu1= GetWindowText(box1, &text1[0],20);
				inpu2= GetWindowText(box2, &text2[0],20);
				nu1 = atof(text1);
				nu2 = atof(text2);
				char x[100];
				sprintf(x, "%f", nu1*nu2);
				
				::MessageBox(hwnd,x,"Result",MB_OK);

			break;
				case 4:
				int inpx1;
				int inpx2;
				double nx1;
				double nx2;
				inpx1= GetWindowText(box1, &text1[0],20);
				inpx2= GetWindowText(box2, &text2[0],20);
				nx1 = atof(text1);
				nx2 = atof(text2);
				char f[100];
				sprintf(f, "%f", nx1/nx2);
				
				::MessageBox(hwnd,f,"Result",MB_OK);

			break;
			}
				break;	
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;	
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = CreateSolidBrush(RGB(244, 0, 150));
	wc.lpszClassName = "WindowClass";
	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My Calculator",WS_VISIBLE|WS_SYSMENU,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		250, /* width */
		200, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	ShowWindow(hwnd, nCmdShow);

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
