#include <Windows.h>       // Include Windows API functions and types
#include "MinHook.h"       // Include MinHook library for API hooking

// Define a function pointer type for the original 'DoOutro' function
typedef void(__thiscall* DoOutro_t)(void*);

// Variable to hold the address of the original 'DoOutro' function
DoOutro_t OriginalDoOutro = nullptr;

// Declaration of the hooked version of 'DoOutro' function
void __fastcall HookedDoOutro(void* thisPtr);

// Function to set up the hook
static void SetupHook() {
    // Initialize the MinHook library
    MH_Initialize();

    // Create a hook on the 'DoOutro' function at address 0x005008b0
    // Replace it with 'HookedDoOutro' and store the original function address in 'OriginalDoOutro'
    MH_CreateHook(reinterpret_cast<LPVOID>(0x005008b0), &HookedDoOutro, reinterpret_cast<LPVOID*>(&OriginalDoOutro));

    // Enable the created hook
    MH_EnableHook(reinterpret_cast<LPVOID>(0x005008b0));
}

// Implementation of the hooked 'DoOutro' function
void __fastcall HookedDoOutro(void* thisPtr) {
    // Skip the 'DoOutro' function that displays the website at the end of the game
    // Immediately terminate the process with exit code 0
    HANDLE hProcess = GetCurrentProcess();   // Get a handle to the current process
    TerminateProcess(hProcess, 0);          // Terminate the process with exit code 0
}

// DLL entry point function
static BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:   // Called when the DLL is loaded into a process
        SetupHook();           // Set up the hook on the 'DoOutro' function
        break;
    case DLL_PROCESS_DETACH:   // Called when the DLL is unloaded from a process
        // Disable and uninitialize the hook
        MH_DisableHook(reinterpret_cast<LPVOID>(0x005008b0));
        MH_Uninitialize();
        break;
    }
    return TRUE;   // Return TRUE to indicate successful DLL initialization
}