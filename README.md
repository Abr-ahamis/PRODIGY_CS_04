# PRODIGY_CS_04

## Simple Python and C Keyloggers

### Overview
This repository contains two simple keylogger implementations:

1. **C Keylogger for Windows**
   - Uses the Windows API (`windows.h` and `SetWindowsHookEx`) to capture keystrokes and log them to a file.
2. **Python Keylogger**
   - Uses the `pynput` library to capture keystrokes and logs them (with timestamps) to a file.

Both examples are minimal and meant to help you understand how keylogging works. They can be extended or modified for authorized security testing and educational demonstrations.

---

## Contents
- `keylogger.c` — C implementation for Windows.
- `keylogger.py` — Python implementation using `pynput`.
- `setup_requirements.py` — Script to set up a virtual environment and install dependencies.
- `README.md` — This file.

---

## Installation
Clone the repository:
```bash
git clone https://github.com/Abr-ahamis/PRODIGY_CS_04.git
cd PRODIGY_CS_04
```

---

## C Keylogger

### Requirements
- **Operating System**: Windows
- **Compiler**: A Windows-based C compiler such as Microsoft Visual Studio or MinGW.
- **SDK**: Windows SDK (for `windows.h` and related libraries).
- **Privileges**: Administrator rights may be required to install a global hook.

### Compilation
#### Using MinGW on Windows:
```bash
gcc keylogger.c -o keylogger.exe -luser32 -lkernel32
```
#### Using MinGW on Linux (Cross-compilation for Windows):
```bash
sudo apt-get install mingw-w64
x86_64-w64-mingw32-gcc keylogger.c -o keylogger.exe -luser32 -lkernel32
```
#### Using Visual Studio:
- Create a new Win32 Console Application project.
- Add `keylogger.c` to the project.
- Build the solution.

### Execution
Run the compiled `keylogger.exe` on your Windows system. The program will run in the background and log all keystrokes to a file named `keylog.txt` in the same directory.

To stop the keylogger, terminate the process via Task Manager or modify the code to include an exit condition.

---

## Python Keylogger

### Requirements
- **Operating System**: Windows, Linux, macOS
- **Python**: Python 3.x
- **Library**: `pynput`

### Setup (Automatic)
Run the provided setup script to create a virtual environment and install dependencies:
```bash
python3 setup_requirements.py
```
or 
Give execute permissions to the script:
```bash
chmod +x setup_venv.sh
```
Run the script:
```bash
./setup_venv.sh

```
### Setup (Manual)
If you prefer to set up manually, install `pynput`:
```bash
pip install pynput
```

### Execution
Save the script as `keylogger.py`, then run:
```bash
python keylogger.py
```
The keylogger will capture keystrokes and append them (with timestamps) to `keylog.txt`.

To stop the keylogger: Press the **ESC** key.

---

## Ethical and Legal Considerations
### **Use Responsibly**
Only run this tool on systems for which you have explicit permission.

### **Educational Purposes Only**
This code is intended for learning and authorized testing. Misuse may result in legal consequences.

### **Privacy Notice**
Unauthorized keylogging is a violation of privacy laws. Always respect the privacy and data protection rights of others.

---

## Additional Notes
### Background Execution
- **C Keylogger**: Consider compiling it as a Windows GUI application to hide the console window.
- **Python Keylogger**: On Windows, run the script with `pythonw keylogger.py` to suppress the console window.

### Customization
- Improve timestamp formatting.
- Implement periodic emailing of logs (`smtplib` in Python).
- Add key filtering or advanced logging features.

---

## Contributions
Feel free to contribute improvements or additional features via pull requests or by opening an issue.

---

## Legal Notice
This software is provided **"as-is"** without any warranty. The authors assume no responsibility for any misuse or damage caused by the use of this code. Always adhere to ethical guidelines and legal requirements when using or modifying this tool.

