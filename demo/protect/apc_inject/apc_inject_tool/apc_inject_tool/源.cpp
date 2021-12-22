#include<stdio.h>
#include<windows.h>

void main() {
    //1.查找窗口
    HWND hWnd = ::FindWindow(NULL, TEXT("INIT"));
    if (NULL == hWnd)
    {
        return;
    }
    /*2.获得进程的PID,当然通用的则是你把进程PID当做要注入的程序,这样不局限
    于窗口了.这里简单编写,进程PID可以快照遍历获取
    */
    DWORD dwPid = 0;
    DWORD dwTid = 0;
    dwTid = GetWindowThreadProcessId(hWnd, &dwPid);

    //3.打开进程
    HANDLE hProcess = NULL;
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (NULL == hProcess)
    {
        return;
    }
    //4.成功了,申请远程内存
    void* lpAddr = NULL;
    lpAddr = VirtualAllocEx(hProcess, 0, 0x1000, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (NULL == lpAddr)
    {
        return;
    }
    //5.写入我们的DLL路径,这里我写入当前根目录下的路径
    char szBuf[] = "chall.dll";
    BOOL bRet = WriteProcessMemory(hProcess, lpAddr, szBuf, strlen(szBuf) + 1, NULL);
    if (!bRet)
    {
        return;
    }
    //6.根据线程Tid,打开线程句柄
    HANDLE hThread = NULL;
    hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, dwTid);
    if (NULL == hThread)
    {
        return;
    }
    //7.给APC队列中插入回调函数
    QueueUserAPC((PAPCFUNC)LoadLibraryA, hThread, (ULONG_PTR)lpAddr);

    CloseHandle(hThread);
    CloseHandle(hProcess);
}