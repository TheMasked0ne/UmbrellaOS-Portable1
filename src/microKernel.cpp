#include "MicroKernel.hpp"
#include "../shell/ShellProcess.hpp"

void MicroKernel::createProcess(int id, const std::string& name, bool isShell) {
    std::lock_guard<std::mutex> lock(tableMutex);
    if (isShell)
        processTable[id] = std::make_shared<ShellProcess>(id, name);
    else
        processTable[id] = std::make_shared<Process>(id, name);
}

std::shared_ptr<Process> MicroKernel::getProcess(int id) {
    std::lock_guard<std::mutex> lock(tableMutex);
    if (processTable.count(id)) return processTable[id];
    return nullptr;
}

void MicroKernel::sendMessage(int src, int dest, const std::string& data) {
    auto recipient = getProcess(dest);
    if (recipient) {
        recipient->sendMessage({src, dest, data});
    } else {
        std::cerr << "[Kernel] Error: Process " << dest << " not found.\n";
    }
}

void MicroKernel::shutdown() {
    std::lock_guard<std::mutex> lock(tableMutex);
    for (auto& [id, process] : processTable) {
        process->stop();
    }
}
