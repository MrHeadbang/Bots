#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>
#include <map>
#include <random>
using namespace std;
int rangeRandomAlg2(int min, int max) {
	int n = max - min + 1;
	int remainder = RAND_MAX % n;
	int x;
	do {
		x = rand();
	} while (x >= RAND_MAX - remainder);
	return min + x % n;
}
int randTime()
{
	return rangeRandomAlg2(1000, 7500);
}
void move(HWND hwnd, int key)
{
	PostMessage(hwnd, WM_KEYDOWN, key, MapVirtualKey(key, MAPVK_VK_TO_VSC));
	Sleep(randTime());
	PostMessage(hwnd, WM_KEYUP, key, MapVirtualKey(key, MAPVK_VK_TO_VSC));
}

int main()
{
	srand(time(NULL));
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
	
	while (true) {
		int keys[] = {0x57, 0x53 , 0x41, 0x44};
		move(GameHWND, keys[rangeRandomAlg2(0, 3)]);
		Sleep(rangeRandomAlg2(500, 3000));
	}
}
