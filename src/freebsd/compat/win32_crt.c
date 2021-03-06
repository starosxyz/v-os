#include "win32_crt.h"
typedef void (WINAPI* MY_FUNC)(void);
MY_FUNC func;
int tmaintest()
{
    HMODULE  g_hDll = LoadLibrary("freebsdports.dll");
    if (g_hDll)
        func = (MY_FUNC)GetProcAddress(g_hDll, "port_test");
    if (func == NULL)
    {
        return -1;
    }
    func();
    return 0;
}
#if 0
int _fltused = 0x9875;



__declspec(thread) uint32_t _tls_index = 0;
BOOL WINAPI DllMain (
    HINSTANCE const instance,  // handle to DLL module
    DWORD     const reason,    // reason for calling function
    LPVOID    const reserved)  // reserved
{
    // Perform actions based on the reason for calling.
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        ++_tls_index;
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:
        // Perform any necessary cleanup.
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}
#if 0
uint32_t _tls_index()
{
    return 1;
}
#endif
int32_t __stdcall _DllMainCRTStartup(HMODULE self, uint32_t reason, void* reserved)
{
    // ...CRT init here...
    // Call into the client's entry point.
	tmaintest();
    int32_t res = DllMain(self, reason, reserved);
    return res;
}
#endif