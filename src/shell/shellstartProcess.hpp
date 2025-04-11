#pragma once
#include "Process.hpp"
#include <string>

class ShellProcess : public Process {
public:
    ShellProcess(int pid, const std::string& pname);
    void startShell();

protected:
    void handleMessage(const Message& msg) override;
};
