// microKernel.hpp v 0.1

#pragma once
#include "Process.hpp"
#include "shellstartProcess.hpp"
#include "filesystemService.hpp"
#include <map>
#include <memory>
#include <mutex>

class MicroKernel {
private:
    std::map<int, std::shared_ptr<Process>> processTable;
    std::mutex tableMutex;

public:
    void createProcess(int id, const std::string& name, bool isShell = false);
    std::shared_ptr<Process> getProcess(int id);
    void sendMessage(int src, int dest, const std::string& data);
    void shutdown();
};
