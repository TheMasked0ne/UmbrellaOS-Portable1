# UmbrellaOS-Portable1

UmbrellaOS
Welcome to UmbrellaOS v0.1!
UmbrellaOS is a lightweight, portable, neo-Minimalist Themed operating system built with simplicity and modularity in mind. Inspired by the classic feel of SSH terminals, UmbrellaOS was spawned. bringing back the charm of retro computing while incorporating modern principles such as microkernel architecture and process-based modularity and abbreviated text and syntax.

Features
- Microkernel Architecture: Highly efficient and portable design with robust inter-process communication (IPC).
- Neo-Minimal Aesthetic: ASCII art welcome screen and terminal-based interface for a classic and underground deep cut of a computing experience.
- Modular Processes: Includes FileSystemService and ShellProcess modules for easy expansion.
- Intuitive Shell: UmbrellaOS offers a simple command-line interface (CLI) for interacting with processes and managing the system.
- File Management: Create, write, read, and list files dynamically through the FileSystemService.


Getting Started
Requirements:
- Compiler: C++ compiler supporting modern standards (e.g., GCC, Clang, MSVC).
- Libraries: Standard C++ libraries (<iostream>, <string>, <map>, etc.).
- Operating System: Linux, Windows, or macOS (portable design).
- Clone the UmbrellaOS repository
- Compile the source code:g++ -std=c++17 -o UmbrellaOS main.cpp ShellProcess.cpp FileSystemService.cpp MicroKernel.cpp

- Run UmbrellaOS:./UmbrellaOS



Using the Shell
Once you boot UmbrellaOS, you'll be greeted with an ASCII-art welcome message and the following prompt:
Zoso>>


Shell Commands:
Type the following commands to interact with the system:
- help: View available commands.
- ls: List all files in the system.
- read <filename>: Display the contents of a file.
- write <filename> <content>: Write content to a file.
- exit: Shut down the shell.

Examples:
Zoso>> write hello.txt Hello, UmbrellaOS!
Zoso>> read hello.txt
Zoso>> ls
Zoso>> exit



Architecture Overview
UmbrellaOS is built using the Microkernel Design Pattern:
- Kernel: Provides lightweight process management and IPC capabilities.
- Processes: Independent components, such as the ShellProcess and FileSystemService, communicate via message queues.
- Modularity: Easy to extend with additional processes for future functionality (e.g., networking, graphics, etc.).


Future Goals
- Expand CLI features with commands like delete and rename for file management.
- Introduce persistent storage to save files across sessions.
- Develop networking support for remote file sharing.
- Enhance the retro aesthetic with themed color schemes and additional ASCII art.

- Still in progress(Contribute or pls be paitent. (thx.)



