#include "ShellProcess.hpp"
#include <iostream>
#include <algorithm>
#include <string>

// Helper Function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void startShell() override {
    std::string input;
    std::cout << R"(
***     .--.                 .--.
     .:' .  '.             .'  . '.
    / .'' :: .\           / .'' :: .\
   /.'   ::   '.         /.'   ::   '.
  ||    ::::    ||       ||    ::::    ||
  \'.   ::   .'         '.   ::   .'
   \  '. :: .'           '. :: .'
    '.  '::'               '::'
      '--'                 '--'

    Welcome to UmbrellaOS! v0.1 ***
)" << std::endl;

    std::cout << "Type 'Pls-Assist' for a list of commands.\n";

    while (running) {
        std::cout << "Zoso>> ";
        std::getline(std::cin, input);
        input = toLower(input); // Normalize input

        if (input == "exit") {
            stop();
            break;
        } else if (input == "pls-assist") {
            std::cout << "Commands:\n"
                      << " help\n"
                      << " ls\n"
                      << " read <filename>\n"
                      << " write <filename> <content>\n"
                      << " exit\n";
        } else if (input.starts_with("write ") || input.starts_with("read ") || input == "ls") {
            sendMessage({id, 3, input}); // IPC command handling
        } else {
            std::cout << "[Shell] Unknown command. Type 'Pls-Assist' for help.\n";
        }
    }
}

ShellProcess::ShellProcess(int pid, const std::string& pname)
    : Process(pid, pname) {}

void ShellProcess::handleMessage(const Message& msg) {
    std::cout << "[Shell] " << msg.data << "\n";
}
