#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <string>
#include <map>
using namespace std;
void mouseClick(HWND hwnd, double x, double y) {
	SetFocus(hwnd);
	SetCursorPos(x, y);

	INPUT Input = { 0 };
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &Input, sizeof(INPUT));

	ZeroMemory(&Input, sizeof(INPUT));
	Input.type = INPUT_MOUSE;
	Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &Input, sizeof(INPUT));
}

int main(void) {
	HWND GameHWND = FindWindowA(0, "VALORANT  ");
	char class_name[100];
	char title[100];
	RECT windowSize;
	RECT WBounds;
	DWORD dwPid;
	HANDLE TargetProcess;
	GetClassNameA(GameHWND, class_name, sizeof(class_name));
	GetWindowTextA(GameHWND, title, sizeof(title));
	GetWindowRect(GameHWND, &windowSize);
	GetClientRect(GameHWND, &WBounds);
	GetWindowThreadProcessId(GameHWND, &dwPid);
	TargetProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, dwPid);
	cout << "Title: " << title << endl;
	cout << "ClassName: " << class_name << endl;
	cout << "Pid: " << dwPid << endl;
	cout << "TargetProcess: " << TargetProcess << endl;
	//AGENT 813 892
	//LOCK BUTTON 972 811
	POINT p;
	while (1) {
		if (GetAsyncKeyState(18)) { //18 is ALT KEY
			//GetCursorPos(&p);
			//cout << p.x << " " << p.y << endl;
			mouseClick(GameHWND, 890, 892);
			Sleep(10);
			mouseClick(GameHWND, 972, 811);
			Sleep(10);
		}
	}
}
