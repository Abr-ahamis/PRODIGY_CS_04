# PRODIGY_CS_04
## Simple Python Keylogger
------------------------
### This keylogger records every keystroke (including special keys) and logs them with timestamps to a file named 'keylog.txt'. It uses the pynput library to capture keyboard events.

## Simple Windows Keylogger in C
#### This program installs a low-level keyboard hook using SetWindowsHookEx.
#### Every keystroke is recorded to "keylog.txt" with a basic textual representation.
    

### Overview
This repository contains two simple keylogger implementations:

## C Keylogger for Windows:
Uses the Windows API (via windows.h and SetWindowsHookEx) to capture keystrokes and log them to a file.

### Python Keylogger:
Uses the pynput library to capture keystrokes and logs them (with timestamps) to a file.

Both examples are minimal and meant to help you understand how keylogging works. They can be extended or modified for authorized security testing and educational demonstrations.

### Contents
keylogger.c — C implementation for Windows.

keylogger.py — Python implementation using pynput.

README.md — This file.

### Intallation
```bash
git clone https://github.com/Abr-ahamis/PRODIGY_CS_04.git
```
```bash
cd PRODIGY_CS_04
```

## C Keylogger
Operating System: Windows

Compiler: A Windows-based C compiler such as Microsoft Visual Studio or MinGW.

SDK: Windows SDK must be installed (for windows.h and related libraries).

Privileges: Administrator rights may be required to install a global hook.

## Python Keylogger
Python: Python 3.x

#### this will Create a virtual environment called env in the current directory.

Activate the virtual environment.

Upgrade pip to the latest version.

Install the required libraries (pip install pynput).
```bash
python3 setup_requirements.py
```
or for manual
```bash
pip install pynput
```
## How to Use
C Keylogger
Compilation:

On Windows with MinGW:
Open a Command Prompt, navigate to the folder containing keylogger.c, and run:

```bash
gcc keylogger.c -o keylogger.exe -luser32 -lkernel32
```
### or 

```bash
sudo apt-get install mingw-w64
```
```bash
x86_64-w64-mingw32-gcc keylogger.c -o keylogger.exe -luser32 -lkernel32
```
Using Visual Studio:
Create a new Win32 Console Application project, add keylogger.c to your project, and build the solution.

Execution:

Run keylogger.exe on your Windows system.

The program will run in the background and log all keystrokes to a file named keylog.txt in the same directory.

To stop the keylogger, you may need to terminate the process via Task Manager or add your own logic to exit.

## Python Keylogger
Installation:

Ensure Python 3.x is installed.

Install the pynput library:
```bash
pip install pynput
```
Execution:

Save the Python script as keylogger.py.

Open a terminal, navigate to the script's directory, and run:

```bash
python keylogger.py
```
The keylogger will capture keystrokes and append them (with timestamps) to keylog.txt.

Stopping the keylogger: Press the ESC key to exit the program.

## Ethical and Legal Considerations
Use Responsibly:
Only run this tool on systems for which you have explicit permission.

## Educational Purposes Only:
This code is intended for learning and authorized testing. Misuse may result in legal consequences.

## Privacy:
Unauthorized keylogging is a violation of privacy laws. Always respect the privacy and data protection rights of others.

## Additional Notes
Background Execution:

For the C keylogger, consider compiling as a Windows GUI application (using the .pyw technique or similar) to hide the console window.

For the Python keylogger, on Windows you can run:


pythonw keylogger.py

to suppress the console window.

## Customization:
Both implementations are basic. You can add features such as:

Timestamp formatting or more detailed logging.

Periodic emailing of logs using modules like smtplib in Python.

Additional key filtering or formatting.

## Contributions:
Feel free to contribute improvements or additional features via pull requests or by opening an issue.

## Legal Notice
This software is provided "as-is" without any warranty. The authors assume no responsibility for any misuse or damage caused by the use of this code. Always adhere to ethical guidelines and legal requirements when using or modifying this tool.

