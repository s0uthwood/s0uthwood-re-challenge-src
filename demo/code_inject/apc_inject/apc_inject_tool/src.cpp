#include<stdio.h>
#include<windows.h>

void main() {
    // 1. Find Window.
    HWND hWnd = ::FindWindow(NULL, TEXT("INIT"));
    if (NULL == hWnd) {
        return;
    }
    /* 2. To Get Thread PID, the common method is use the process PID as the program to be injected, 
     *    so that it is not limited to window. 
     *    Here is a simple way to write, process PIDs can be obtained by snapshot traversal.
     */
    DWORD dwPid = 0;
    DWORD dwTid = 0;
    dwTid = GetWindowThreadProcessId(hWnd, &dwPid);

    // 3. Open Process
    HANDLE hProcess = NULL;
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (NULL == hProcess) {
        return;
    }
    // 4. Request Remote Memory if succeed.
    void* lpAddr = NULL;
    lpAddr = VirtualAllocEx(hProcess, 0, 0x1000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (NULL == lpAddr) {
        return;
    }
    // 5. Path to dll. Here write the path to the current directory.
    char szBuf[] = "chall.dll";
    BOOL bRet = WriteProcessMemory(hProcess, lpAddr, szBuf, strlen(szBuf) + 1, NULL);
    if (!bRet) {
        return;
    }
     //6. Open thread handle according to Tid.
    HANDLE hThread = NULL;
    hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, dwTid);
    if (NULL == hThread) {
        return;
    }
    // 7. Insert a callback function into APC queue.
    QueueUserAPC((PAPCFUNC)LoadLibraryA, hThread, (ULONG_PTR)lpAddr);

    CloseHandle(hThread);
    CloseHandle(hProcess);
}
