#include<stdio.h>
#include<Windows.h>

int main() {
	SetConsoleTitle(L"INIT");
	printf("Where is the flag?");
	SleepEx(INFINITE,TRUE);
	getchar();
}
