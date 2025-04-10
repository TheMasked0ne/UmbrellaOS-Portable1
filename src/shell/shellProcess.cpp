#include "ShellProcess.hpp"
#include <iostream>

ShellProcess::ShellProcess(int pid, const std::string& pname)
    : Process(pid, pname) {}

void ShellProcess::handleMessage(const Message& msg) {
    std::cout << "[Shell] " << msg.data << "\n";
}

void ShellProcess::startShell() {
    std::string input;
    while (running) {
        std::cout << ">> ";
        std::getline(std::cin, input);
        if (input == "exit") {
            stop();
            break;
        }
        sendMessage({id, id, "You typed: " + input});
    }
}
