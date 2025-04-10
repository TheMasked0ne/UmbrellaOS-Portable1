#pragma once
#include "../process/Process.hpp"

class ShellProcess : public Process {
public:
    ShellProcess(int pid, const std::string& pname);
    void startShell();

protected:
    void handleMessage(const Message& msg) override;
};
